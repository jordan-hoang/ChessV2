# ChessV2

ChessV2 is a fun chess game I developed, now featuring a fully playable React frontend. 
The game leverages a C++ backend with Boost.Beast for WebSocket communication. 
(For reference, ChessV1 was text-based only.)


## Building with CMake

1. Clone the repository.

        git clone git@github.com:jordan-hoang/ChessV2.git

2. Create a new directory for building.

        mkdir build

3. Change into the new directory.

        cd build

4. Run CMake with the path to the source.

        cmake ../

5. Run make inside the build directory:

        make

After building, you’ll have the ChessV2 executable inside the build directory. 
Running it will start the Server, it can be modified easily to take Text Input.




![image](https://user-images.githubusercontent.com/36338184/117098456-60893f00-ad23-11eb-9d73-97e0274c440b.png)

The lower-case characthers such as 'p' means it is a "White Pawn" while "P" corresponds to a "Black Pawn"



![image](https://user-images.githubusercontent.com/36338184/117097523-c1634800-ad20-11eb-890a-065a2ac8cc13.png)


To make a move specify the initial position of the piece followed by a comma and then the ending position of the piece.
So for example to move the left-most white pawn 2 squares forward we would type in. ONLY for textbased version.

"a6,a4"   (In chess algebraic notation it is column first than row)

A React frontend currently serves as the GUI and you would click on pieces to move them. 
Currently it's left click 2x. But I will probably add a drag and drop feature.

### Dependencies
This project requires:

1. C++17 or newer
2. PythonInterp (For googletest)
3. CMake >= 3.1
4. Boost.Beast (for WebSocket communication)
5. npm (for running the React frontend)

### Current Plans 

Frontend Polish: The React frontend will receive more polish for better usability and visual appeal.

EnPassant and castling don't work in the frontend still, they do work in the chessServer, fix that.

Multiplayer Networking: The goal is to add multiplayer functionality to allow two players to play online.


### Possible additions I may add.

AI: Implement minmax algorithm, so the server can play against you.

Replay Game: Can save a copy of your game in CAN notation and use it to watch a playthrough of that game, perhaps
make it so that you can start in the middle of a game at some situation? Maybe make a Chess Snapshot feature.

Spectator feature: Can watch other players games, perhaps even add a takeover feature?