# ChessV2

A Chess game I made for fun, currently working on making a React frontend for this particular application.

<br />

## Building with CMake

1. Clone the repository.

        git clone https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019.git

2. Create a new directory for building.

        mkdir build

3. Change into the new directory.

        cd build

4. Run CMake with the path to the source.

        cmake ../

5. Run make inside the build directory:

        make

This produces a "ChessV2" executable inside of the directory inside of build and it can be run to played a text-based version of chess where the commands are entered using Chess Algebraic Notation. In the future a React frontend will be created as a GUI instead of having a text based game. If you want to run unit tests they are shuold be inside of ChessV2/build/test/runAllTests executable.

When running the application you should something that looks like this.....

![image](https://user-images.githubusercontent.com/36338184/117098456-60893f00-ad23-11eb-9d73-97e0274c440b.png)

The lower-case characthers such as 'p' means it is a "White Pawn" while "P" corresponds to a "Black Pawn"



![image](https://user-images.githubusercontent.com/36338184/117097523-c1634800-ad20-11eb-890a-065a2ac8cc13.png)


To make a move specify the initial position of the piece followed by a comma and then the ending position of the piece.
So for example to move the left-most white pawn 2 squares forward we would type in.

"a6,a4"   (In chess algebraic notation it is column first than row)

In the future a React frontend would serve as the GUI and clicking will be included instead of having to type out manually the Chess Coordinates.


### Dependencies
This project requires:

1. C++17 or newer
2. PythonInterp (For googletest)
3. CMake >= 3.1
