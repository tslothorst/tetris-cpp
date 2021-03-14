# Tetris made in C++

## Introduction
This game is made with the help of [the tutorial](https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/) written by Javier López López (javilop.com)

## Updated for C++17
A few aspects of the game have been updated to use C++17 standards. I no longer rely on `#DEFINE` but use `constexpr` to replace this in the self made game files. The SDL libraries are excluded since these are used 'as is'.

Code in the tutorial:
```cpp
#define BOARD_LINE_WIDTH 6          // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16               // Width and Height of each block of a piece
#define BOARD_POSITION 320          // Center position of the board from the left of the screen
#define BOARD_WIDTH 10              // Board width in blocks 
#define BOARD_HEIGHT 20             // Board height in blocks
#define MIN_VERTICAL_MARGIN 20      // Minimum vertical margin for the board limit      
#define MIN_HORIZONTAL_MARGIN 20    // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5              // Number of horizontal and vertical blocks of a matrix piece
 ```

 My replacement:
 ```cpp
constexpr int BoardLineWith = 6;				// Width of each of the two lines that delimit the board
constexpr int BlockSize = 16;					// Width and Height of each block of a piece
constexpr int BoardPosition = 320;				// Center position of the board from the left of the screen
constexpr int BoardWidth = 10;					// Board width in blocks
constexpr int BoardHeight = 20;					// Board height in blocks
constexpr int MinVerticalMargin = 20;			// Minimum vertical margin for the board limit
constexpr int MinHorizontalMargin = 20;			// Minimum horizontal margin for the board limit
constexpr int PieceBlocks = 5;					// Number of horizontal and vertical blocks of a matrix piece
```

With `constexpr` we no longer use the preprocessor macro to replace all instances. This way we don't have to worry about reserved words in the code used by the preprocessor. Also we know all these variables have been set before compile time since they provide some of the basic values needed for the game. 

This game still uses raw pointers, these need to be updated to be smart pointers. 

## SDL included
In the repository is included SDL v1.2.15 and SDL GfxPrimitives (version unknown). If you want to do this tutorial yourself this library is hard to come by these days. 