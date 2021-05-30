import openSocket from 'socket.io-client';
const  socket = openSocket('http://localhost:3000');




function subscribeToTimer(cb) {
  socket.on('timer', timestamp => cb(null, timestamp));


  socket.on('help', function(modeNumber) {
      let msg = "help23";
      console.log("Recieved help message from chess.js. Sending to C++ server where message is 2nd parameter : " + msg);
  });

  socket.emit('subscribeToTimer', 1000);

}




function sendCommandToServer(command, options){
    socket.emit(command, options);
}


export { subscribeToTimer };