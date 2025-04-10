// Game.js
import React, { useState, useEffect } from 'react';
import Board from './Board';


///// Initial Board state is not defined.


const Game = () => {
    // Define the initial state for the chessboard.
    /** These are just some examples, to help you.....
     *
     * const [counter, setCounter] = useState(0);
     *
     * const increment = () => {
     *     setCounter(prevCounter => prevCounter + 1); // Increment by 1
     * };
     *
     *
     *  You have to do prevCounter => prevCounter + 1, instead of just doing prevCounter + 1;
     *  You need to pass a function since everything is ASYNC.
     *  Basically uou are queuing this to happen and react will decide.
     *  You don't directly modify the state.
     *
     *  Using arrow functions removes the word function and removes the return.
     *
     * function increment() {
     *     setCounter(prevCounter => prevCounter + 1);
     * }
     *
     * This is the new "functional approach to modern react"
     *  It's called array destructuring in JS.
     *
     *  It does 2 things,
     *  board is a state variable and setBoard is used to update the state of the board"
     *
     *  passing down onClick props (or any event handlers)
     *
     *  You can't use setBoard directly, you'll need to create a function that uses it and then have that function
     *  become an onClick event for a element down below.
     */
    const createInitialBoard = () => {

        const board = [];
        const pieceTypes = ['rook', 'knight', 'bishop', 'queen', 'king', 'bishop', 'knight', 'rook'];

        // First 2 rows (black pieces)
        for (let i = 0; i < 2; i++) {
            const row = [];
            for (let j = 0; j < 8; j++) {
                row.push(i === 1 ? { name: 'pawn', color: 'black' } : { name: pieceTypes[j], color: 'black' });
            }
            board.push(row);
        }

        // Empty rows (middle part of the board)
        for (let i = 2; i < 6; i++) {
            const row = Array(8).fill(null); // Empty rows
            board.push(row);
        }

        // Last two rows (black pieces)
        for (let i = 6; i < 8; i++) {
            const row = [];
            for (let j = 0; j < 8; j++) {
                row.push(i === 6 ? { name: 'pawn', color: 'white' } : { name: pieceTypes[j], color: 'white' });
            }
            board.push(row);
        }


        return board;
    };

    // Determines whose turn it is, is either black or white. Probably can use boolean here but w/e.
    const [board, setBoard] = useState(createInitialBoard); // This will call createInitialBoard only once
    const [currentTurn, setCurrentTurn] = useState('white');
    const [playerColor, setPlayerColor] = useState('');
    const [socket, setSocket] = useState(null);
    const [moveHistory, setMoveHistory] = useState([]); // Track the history of moves

    // Establish WebSocket connection on mount,..??
    useEffect(() => {
        const ws = new WebSocket("ws://localhost:8080"); // Change to your backend WebSocket URL

        ws.onopen = () => {
            console.log("Connected to WebSocket server");
        };

        // Receives message from the server.
        ws.onmessage = (event) => {
            console.log("Received message from server: ", event.data);
            handleServerResponse(event);
        };

        ws.onerror = (error) => {
            console.error("WebSocket Error:", error);
        };

        ws.onclose = () => {
            console.log("WebSocket connection closed");
        };

        setSocket(ws);

        // Clean up function in useEffect. USe effect has it's on syntax, google if u need.
        return () => {
            ws.close(); // Cleanup when the component unmounts
        };
    }, []);


    const createPieceType = (myChar) => {
        if(myChar === '-'){
            return null;
        }

        let pieceColor = (myChar === myChar.toLowerCase()) ? 'white' : 'black';
        const pieceNames = {
            'p': 'pawn',
            'r': 'rook',
            'n': 'knight',
            'b': 'bishop',
            'q': 'queen',
            'k': 'king'
        };

        myChar = myChar.toLowerCase();
        let name = pieceNames[myChar];
        return { name: name, color: pieceColor };

    }

    // Parses the boards data and constructs a new ChessBoard to return.
    const parseBoardData = (boardData) => {
        console.log("MY DATA IS : " + boardData); /// It's a string of the board's state.
        console.log(Array.isArray(boardData));
        const board = [];
        const pieceTypes = ['rook', 'knight', 'bishop', 'queen', 'king', 'bishop', 'knight', 'rook'];

        let counter = 0;
        for(let i = 0; i < 8; i++){
            let row = [];
            for(let j = 0; j < 8; j++){
                let piece = createPieceType(boardData[counter]);
                row.push(piece);
                counter++;
            }
            board.push(row);
        }

        return board;
    }

    const handleServerResponse = (response) => {
        console.log("handleServerResponse called in Game.js");
        // The response.data is just a string that is sent back by the server!!!
        // But response data is correct.
        const jsonResponse = JSON.parse(response.data);

        if(jsonResponse.client_role !== undefined){
            console.log("ASSIGN CLIENT ROLE HERE!" + jsonResponse.client_role);
            setPlayerColor(jsonResponse.client_role);
            return;
        }



        let boardData = parseBoardData(jsonResponse.board[0]);
        setBoard(boardData);

        // setCurrentTurn( currentTurn === 'white' ? 'black' : 'white' );  for visual.
        console.log("TURN IS ::::::: " + jsonResponse.turn);

        setCurrentTurn( jsonResponse.turn ? 'white' : 'black' ); /// DO SOMETHING HERE

        if(!jsonResponse.valid){
            console.log("invalid move!");
            return;
        }

    };

    //Returns true if successful false if it isn't. Don't know if it's need however. Maybe just void.
    const handleMove = (from, to) => {
        if(!socket){ return; }
        // Sends the move down below.
        const moveData = JSON.stringify({
            type: "move",
            from,
            to
        });

        console.log(moveData);

        socket.send(moveData);

    }

    return (
        <div>
            <div style={{textAlign: "center"}}>
                <h1> Chess Game </h1>
                <div style={{marginTop: "20px"}}>
                    >
                    <Board
                        board={board}
                        onMove={handleMove}
                        curTurn={currentTurn}
                    />
                </div>

            </div>

            <div>
                <div style={{marginTop: "10px"}}> It is currently {currentTurn}'s turn</div>
                <div style={{marginTop: "10px"}}> You control the  {playerColor}'s pieces</div>
            </div>

        </div>
    );

};

export default Game;
