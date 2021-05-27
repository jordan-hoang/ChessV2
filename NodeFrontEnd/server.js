"use strict"
// Server for HTTP and loading other server modules
// Install modules:
//   $ npm install express@4
//
// Launch server with:
//   $ node server.js
// 
let PORT_NUMBER = 3000;

const fs = require('fs');
const express = require('express');
const http = require('http');

const app = express();
const server = http.createServer(app);
const { Server } = require("socket.io"); // https://stackoverflow.com/questions/25187903/what-do-curly-braces-around-javascript-variable-name-mean
const io = new Server(server); // Our server this doesn't work anymore.... you can also do const io = require("socket.io")(server)


app.use(express.static(__dirname + '/public')); // Allows mime to serve and load js and css

// Serves the webpage, to the user when the reach the root directory.
app.get('/', (request, response) => {
	
  let path = __dirname + "/public/index.html";

  fs.stat(path, (error, stats) => {
	if (error) {
	  console.log(error);
	  send404(response);
	}
	else {	 
		if(stats.isFile){
			response.sendFile(__dirname + "/public/index.html");
		} else {
			send404(response);
		}
	}
  });
  
});

function send404(response) {
	response.writeHead(404, {'Content-Type': 'text/plain'});
	response.write('Error 404: resource not found.');
	response.end();
}

server.listen(PORT_NUMBER, () => {
  console.log('listening on *:3000');
});


var procServer = require('./lib/chess_server');
procServer.listen(io);
