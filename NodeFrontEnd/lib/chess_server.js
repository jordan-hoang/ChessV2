"use strict";
/*
 * Respond to commands over a websocket to access the C++ program
 */
var fs       = require('fs');
var socketio = require('socket.io');
var io; 
var dgram    = require('dgram');


// Exporting a function called listen, so it can be called from another file.
exports.listen = function(server) {
	io = server;
	io.on('connection', (socket) => {
		handleCommand(socket);
	});
};


// Handles set up for code
function handleCommand(socket) {
	console.log("Setting up socket handlers.");

	// Send the string 'help' to the C++ app
	socket.on('help', function(modeNumber){
		console.log("Recieved help command");
		relayToLocalPort(socket, 'help', "mode-reply");
	});

	// Send the string 'help' to the C++ app
	socket.on('undo', function(modeNumber){
		console.log("Recieved undo command");
		relayToLocalPort(socket, 'undo', "mode-reply");
	});

};




/**
 * Sends a message to the C++ application
 * @param {*} socket 
 * @param {*} data - The data / string you are sending to the application
 * @param {*} replyCommandName - "Relays to localPort, so in this case it would be 'mode-reply', 'volume-reply' "
 */
function relayToLocalPort(socket, data, replyCommandName) {
	console.log(" relaying to local port command / C++ application: " + data);
	
	// Info for connecting to the local process via UDP
	var PORT = 3000;	// Port of local application
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
