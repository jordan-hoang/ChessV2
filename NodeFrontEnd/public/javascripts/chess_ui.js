"use strict";
// Client-side interactions with the browser for web interface

// Make connection to server when web page is fully loaded.
var socket = io.connect();


var communicationsTimeout = null;
$(document).ready(function() {
	setupServerMessageHandlers(socket);
	
	// Setup the button clicks:
	$('#help_button').click(function() {
		sendCommandToServer('help');
	});

	$('#undo_button').click(function() {
		sendCommandToServer('undo');
	});

	// sendCommandToServer('move', 5) triggers the move socket
	// But sends move 5
	$('#move_button').click(function() {
		sendCommandToServer('move', 5); //Send to the 'move' socket the number 5 as well
	});

});

var hideErrorTimeout;

// For messages coming from C++ application
function setupServerMessageHandlers(socket) {


	socket.on('help-reply', function(message) {
		console.log("chess.js_ Received Reply: help from somehwere " + message);
		console.log("chess.js_ Wok wok wok");
	});

	//undo-reply is the message from chess_server.js
	socket.on('undo-reply', function(message) {
		console.log("chess.js_ Got 'undo' command " + message);
		console.log("chess.js_ ununununnun");
		// Do whatever 'undo' is supposed to do here!
	});

	socket.on('mode-movepiece', function(message) {
		console.log("Receive MOVE COMMAND: mode-movepiece , message is: " + message);
		var name = "Unknown!";

        
	})


}

// Sends a command to the chess_server.js
function sendCommandToServer(command, options) {
	// Unused for now....
	// if (communicationsTimeout == null) {
	// 	communicationsTimeout = setTimeout(errorHandler, 1000, 
	// 			"ERROR: Unable to communicate to HTTP server. Is nodeJS server running?");
	// }

	//Lets say you click on 'help' button which then goes to sendCommandToServer.
	socket.emit(command, options);
}

