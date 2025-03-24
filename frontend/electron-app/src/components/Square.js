import React from 'react';

const Square = ({ piece, onClick }) => {



    return (
        <div
            style={{
                width: '50px',
                height: '50px',
                backgroundColor: piece ? 'gray' : 'white',
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center',
                border: '1px solid black'
            }}
            onClick={onClick} // Trigger move function when clicked.
        >


            {/*If valid piece than do this. */}
            {piece && <img src={piece.image} alt={piece.piece} style={{ width: '40px', height: '40px' }}/>}


        </div>
    );



};

export default Square;