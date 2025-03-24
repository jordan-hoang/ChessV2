// Game.js
import React, { useState } from 'react';
import Board from './Board';


///// Initial Board state is not defined.


const Game = () => {
    // Define the initial state for the chessboard.

    const createInitialBoard = () => {

        const board = [];
        const pieceTypes = ['rook', 'knight', 'bishop', 'queen', 'king', 'bishop', 'knight', 'rook'];


        // First 2 rows (black pieces)
        for (let i = 0; i < 2; i++) {
            const row = [];
            for (let j = 0; j < 8; j++) {
                row.push(i === 1 ? { piece: 'pawn', color: 'white' } : { piece: pieceTypes[j], color: 'white' });
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
                row.push(i === 6 ? { piece: 'pawn', color: 'black' } : { piece: pieceTypes[j], color: 'black' });
            }
            board.push(row);
        }

        return board;
    };



    const [curentTurn, setCurrentTurn] = useState('white');

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
    const [board, setBoard] = useState(createInitialBoard()); // Assume initialBoardState is an array of pieces

    //Returns true if successful false if it isn't. Don't know if it's need however. Maybe just void.
    const handleMove = (from, to) => {

        // Ping the ChessServer here to determine if the move is valid!
        const newBoard = board.map(row => [...row]); // Deep copy

        // Note that special moves exist...... Such as castle and enpassant.
        newBoard[to.row][to.col] = newBoard[from.row][from.col]; // Move piece to new position
        newBoard[from.row][from.col] = null; // Clear old position
        setBoard(newBoard);

        // Toggle the turn.
        setCurrentTurn( curentTurn === 'white' ? 'black' : 'white' );
        return true;
    }


    return (
        <div>
            <h1>Chess Game Component</h1>
            <Board board={board} onMove={handleMove} />
        </div>
    );

};

export default Game;
