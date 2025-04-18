import React, {useState} from 'react';
import Square from './Square';
import './Board.css';



// The board is passed from Game.js to here.
// currentTurn = black || white.
// onMove is clicklistener.
const Board = ( {board, onMove, currentTurn, playColor} ) => {

    //
    const [selectedSquare, setSelectedSquare] = useState(null);

    // Contains all possible error cases.
    const hasSquareError = (row, col) => {

        // Clicking on the empty square cannot be the first move.
        if(!selectedSquare && board[row][col] === null){
            console.log("Empty Piece");
            return true;
        }

        // Cannot move ontop of itself.
        if(selectedSquare && selectedSquare.row === row && selectedSquare.col === col){
            console.log("INVALID MOVE!");
            setSelectedSquare(null);
            return true;
        }

        /// The second square cannot be your own piece as well, must be an enemy!
        return false;
    }

    const handleSquareClick = (row, col) => {

        if(hasSquareError(row, col)){
            console.log("handleSquareClick returning early");
            setSelectedSquare(null); // Reset selection after move
            return;
        }

        if(!selectedSquare){
            console.log("Selected first square")
            setSelectedSquare({ row, col }); // First square we select.
            return;
        }

        // It's row, col???
        console.log("handleSquareClick - board.js move is : " + selectedSquare);

        onMove(selectedSquare, { row, col });
        setSelectedSquare(null); // Reset selection after move

    };

    const getSquareClass = (row, col) => {
        return (row + col) % 2 ? "lightSquare" : "darkSquare";
    }

    return (

        <div className={`chessBoardWrapper ${playColor === 'black' ? 'blackPerspective' : ''}`}>

            {/* Map is used to titerate or transform arrays, basically another way of doing for loop
                board.map(element, index, originalArray), it returns a new array.
                This basically is a double for loop
            */}
            {board.map((row, rowIndex) =>
                row.map((myPiece, colIndex) => (
                    //  Key is a string and needs to be unique.
                    <Square
                        chessTileColor={ getSquareClass(rowIndex, colIndex) }
                        key={ `${rowIndex} - ${colIndex}` }
                        piece= {myPiece}
                        onClick={() => handleSquareClick(rowIndex, colIndex)}
                    />
                ))
            )}

        </div>

    );
};

export default Board;
