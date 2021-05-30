import React from "react";
import io from 'socket.io-client';

const ENDPOINT = "http://localhost:3000"; // The address of the chess server / Node.js
const socket = io(ENDPOINT);


socket.on('react_help', function(msg){
    console.log("react_help socket recieved msg : " + msg);
});

socket.on('react_move', function(msg){
    console.log("react_move msg we recieved is.... : " + msg);
});


class Game extends React.Component {
  
    constructor(props){
        super(props);
        console.log("Constructor for Game called!"); // Perhaps we can have our listeners launch here
        // Private variables go here
        this.state = {
            squares: Array(81).fill(null),  // Our chessboard
        }
    }

    // Triggers when help button is clicked. Emits something to the server.
    handleHelpClick(){
        socket.emit("react_help", "Hello world")
    }

    render() 
    {
        return (
            <div className="App">
                <p className="App-intro">
                    This is the timer value: {this.state.timestamp}
                </p>

                <button type="button" onClick = { () => this.handleHelpClick() } > Help </button>
            </div>
        );
    }

}


export default Game;