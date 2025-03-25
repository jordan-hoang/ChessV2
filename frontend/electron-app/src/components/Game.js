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


    const handleServerResponse = (response) => {

        console.log("handleServerResponse CALLED!");

        // The response.data is just a string that is sent back by the server!!!
        // We sent back True so it's all good. Not sure what response.valid is?!
        // But response data is correct.

        const jsonResponse = JSON.parse(response.data)
        if (jsonResponse.valid) {

            const newBoard = board.map(row => row.map(square => {
                if (square === null) {
                    return null; // If the square is empty, just return null
                }
                return { ...square }; // Otherwise, make a copy of the piece object
            }));


            const from = jsonResponse.from;
            const to = jsonResponse.to;

            newBoard[to.row][to.col] = newBoard[from.row][from.col]; // Move piece to new position
            newBoard[from.row][from.col] = null; // Clear old position

            setBoard(prevBoard => {
                // Deep copy using JSON methods
                const newBoard = JSON.parse(JSON.stringify(prevBoard));  // Deep copy of the board

                const from = jsonResponse.from;
                const to = jsonResponse.to;

                console.log(from);
                console.log(to);

                // Move the piece to the new position
                newBoard[to.row][to.col] = newBoard[from.row][from.col];
                newBoard[from.row][from.col] = null; // Clear the old position

                return newBoard; // Return the new board to trigger re-render
            });


            setCurrentTurn( currentTurn === 'white' ? 'black' : 'white' );

        }




        else {
            console.log("Invalid move.");
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

        socket.send(moveData);
    }


    return (
        <div>
            <h1>Chess Game Component</h1>
            <Board
                board={board}
                onMove={handleMove}
                curTurn = {currentTurn}
            />
        </div>
    );

};

export default Game;
