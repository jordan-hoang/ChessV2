"use strict";
/*
 * Respond to commands over a websocket to access the C++ program
 */
var fs       = require('fs');
var socketio = require('socket.io');
var io; 
var dgram    = require('dgram');


// Exporting a function called listen, so it can be called from another file. a.k.a server.js
exports.listen = function(server) {
	io = server;
	io.on('connection', (socket) => {
		handleCommand(socket);
        handleReactCommand(socket);
	});
};

// Handles set up for code. It recieves a message from the C++ server, and the sends it to the Chess.js
function handleCommand(socket) {
	console.log("Setting up socket handlers.");

	// Sends a message on the 
	socket.on('help', function(modeNumber){
		let msg = "help23"
		console.log("Recieved help message from chess.js. Sending to C++ server where message is 2nd parameter : " + msg);
		relayToLocalPort(socket, msg, "help-reply"); // the third parameter is the socket you are sending it too!
	});

	// 'undo' corresponds to the undo from our C++ application
	socket.on('undo', function(modeNumber){
		console.log("Recieved undo command from server");
		relayToLocalPort(socket, 'undo', "undo-reply");
	});

	socket.on('move', function(moveCoordinates){
		
		//modeNumber is the 'move' you are going to make so, chess_ui.js
		//should send something like a7,a6!

		console.log("Move command recieved!"); // Sending to C++ server....??
		console.log("Mode_number is : " + moveCoordinates); // modeNumber is options from sendCommandToServer

		relayToLocalPort(socket, 'move ' + moveCoordinates, "mode-movepiece");
	});

};

// Handles set up for code. It recieves a message from the React server, and the sends it to the Chess.js
function handleReactCommand(socket) {

    // On receiving a message from react....
	socket.on('react_help', function(moveCoordinates){
		
		//modeNumber is the 'move' you are going to make so, chess_ui.js
		//should send something like a7,a6!
		relayToReact(socket, 'move ' + moveCoordinates, "react_move");
	});

};


/**
 * Sends a message to the C++ application
 * @param {*} socket 
 * @param {*} data - The data / string you are sending to server
 * @param {*} replyCommandName - " The socket you are communicating to. Incorrect name will not send anything!
 */
function relayToLocalPort(socket, data, replyCommandName) {
	console.log(" relaying to local port command / C++ application: " + data);
	
	// Info for connecting to the local process via UDP
	var PORT = 3000;	// Port of chess application
	var HOST = '127.0.0.1';
	var buffer = new Buffer(data);

	var client = dgram.createSocket('udp4');

	// Sends a UDP message towards C++
	client.send(buffer, 0, buffer.length, PORT, HOST, function(err, bytes) {
	    if (err) 
	    	throw err;
	    console.log('UDP message sent to C++ application' + HOST +':'+ PORT);
	});
	
	// Not super important
	// client.on('listening', function () {
	//     var address = client.address();
	//     console.log('UDP Client: listening on ' + address.address + ":" + address.port);
	// });
	/**
	 * 
	 * @param {*} message - The message you recieved from the C++ application
	 */
	client.on('message', function (message, remote) {
	    console.log(" J_UDP Client: message Rx : " + remote.address + ':' + remote.port +' -: ' + message);

	    var reply = message.toString('utf8')
		console.log(" J ReplyCommandName : " + replyCommandName + "\n");
		console.log("");

	    socket.emit(replyCommandName, reply);
	    client.close();

	});

	client.on("UDP Client: close", function() {
	    console.log("closed");
	});

	client.on("UDP Client: error", function(err) {
	    console.log("error: ",err);
	});	

}


/**
 * Sends a message to....??
 * @param {*} socket 
 * @param {*} data 
 * @param {*} replyCommandName 
 */
function relayToReact(socket, data, replyCommandName) {
	console.log("_sending to react data : " + data);
    socket.emit("react_move", data);
    console.log();
    // Success
}



