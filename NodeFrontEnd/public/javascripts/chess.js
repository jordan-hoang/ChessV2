"use strict";
// Client-side interactions with the browser for web interface

// Make connection to server when web page is fully loaded.
var socket = io.connect();
var communicationsTimeout = null;
$(document).ready(function() {
	setupServerMessageHandlers(socket);
	
	// Setup a repeating function (every 1s)
	// window.setInterval(function() {sendCommandToServer('read-uptime')}, 1000);
	// window.setInterval(function() {sendCommandToServer('volume')}, 1000);
	// window.setInterval(function() {sendCommandToServer('mode')}, 1000);
	// window.setInterval(function() {sendCommandToServer('tempo')}, 1000);
	
	// Start off by "polling" the volume, mode, and tempo:
	// sendCommandToServer('volume'); 
	// sendCommandToServer('mode');
	// sendCommandToServer('tempo');

	// Setup the button clicks:
	$('#help_button').click(function() {
		sendCommandToServer('help');
	});

	$('#undo_button').click(function() {
		sendCommandToServer('undo');
	});



});

var hideErrorTimeout;

// For messages coming from C++ application
function setupServerMessageHandlers(socket) {
	// // Hide error display:
	// $('#error-box').hide(); 
	
	console.log("chess.js         _ "+socket);

	// 
	socket.on('mode-reply', function(message) {
		console.log("chess.js_ Received Reply: mode-reply " + message);
		console.log("chess.js_ Wok wok wok");
	});


	// For m	
	// socket.on('mode-reply', function(message) {
	// 	console.log("Receive Reply: mode-reply " + message);
	// 	var name = "Unknown!";
	// 	switch(Number(message)) {
	// 	case 0: name = "None"; break;
	// 	case 1: name = "Rock 1"; break;
	// 	case 2: name = "Rock 2"; break;
	// 	}
	// 	$('#modeid').text(name);
	// 	clearServerTimeout();
	// });
	
	// socket.on('volume-reply', function(message) {
	// 	console.log("Receive Reply: volume-reply " + message);
	// 	volume = Number(message);
	// 	$('#volumeid').val(message);
	// 	clearServerTimeout();
	// });
	
	// socket.on('tempo-reply', function(message) {
	// 	console.log("Receive Reply: tempo-reply " + message);
	// 	tempo = Number(message);
	// 	$('#tempoid').val(message);
	// 	clearServerTimeout();
	// });
	
	// socket.on('play-reply', function(message) {
	// 	console.log("Receive Reply: play-reply " + message);
	// 	clearServerTimeout();
	// });
	
	// socket.on('uptime-reply', function(message) {
	// 	var times = message.split(" ");
	// 	var seconds = Number(times[0]);
		
	// 	var hours = Math.floor(seconds/60/60);
	// 	var minutes = Math.floor((seconds / 60) % 60);
	// 	seconds = Math.floor(seconds % 60);
		
	// 	var display = "Device up for: " + hours + ":" + minutes + ":" + seconds + "(H:M:S)";
		
	// 	$('#status').html(display);
	// 	clearServerTimeout();
	// });
	
	// socket.on('beatbox-error', errorHandler);


}

// Sends a command to the chess_server.js
function sendCommandToServer(command, options) {
	// Unused for now....
	// if (communicationsTimeout == null) {
	// 	communicationsTimeout = setTimeout(errorHandler, 1000, 
	// 			"ERROR: Unable to communicate to HTTP server. Is nodeJS server running?");
	// }
	socket.emit(command, options);
}

