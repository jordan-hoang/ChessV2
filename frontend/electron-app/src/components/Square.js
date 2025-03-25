import React from 'react';

const Square = ({ piece, onClick }) => {


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
        <div
            style={{
                width: '60px',
                height: '60px',
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center',
                border: '1px solid black',
            }}
            onClick={onClick} // Trigger move function when clicked
        >
            {/* Render image if there's a piece */}
            {piece && (
                <div
                    style={{
                        width: '80%',
                        height: '80%',
                        backgroundImage: `url('${getPieceUrl()}')`,
                        backgroundSize: "contain",
                        backgroundRepeat: "no-repeat",
                        backgroundPosition: "center"
                    }}
                />
            )}
        </div>
    );


};

export default Square;