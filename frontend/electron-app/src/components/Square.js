import React from 'react';
import './Square.css';

const Square = ({ piece, onClick, chessTileColor }) => {


    // Get the correct coordinates for the piece
    // Function to get the background position for the piece
    const getPieceUrl = () => {
        if (!piece) {
            return 'none';
        }

        // piece: 'pawn', color: 'black'
        return `/images/Pieces/${piece.color}/${piece.color}_${piece.name}.png`;
    };


    return (
        <div className= {`square ${chessTileColor}`} onClick={onClick}>
            {/* Render image if there's a piece */}
            {piece && (
                <div className={`piece`}
                    style={{
                        backgroundImage: `url('${getPieceUrl()}')`,
                    }}
                />
            )}
        </div>
    );


};

export default Square;