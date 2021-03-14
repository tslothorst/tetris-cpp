#pragma once
#include "pieces.h"

constexpr int BoardLineWith = 6;				// Width of each of the two lines that delimit the board
constexpr int BlockSize = 16;					// Width and Height of each block of a piece
constexpr int BoardPosition = 320;				// Center position of the board from the left of the screen
constexpr int BoardWidth = 10;					// Board width in blocks
constexpr int BoardHeight = 20;					// Board height in blocks
constexpr int MinVerticalMargin = 20;			// Minimum vertical margin for the board limit
constexpr int MinHorizontalMargin = 20;			// Minimum horizontal margin for the board limit
constexpr int PieceBlocks = 5;					// Number of horizontal and vertical blocks of a matrix piece

class board
{
public:
	board(pieces* pPieces, int pScreenHeight);

	int GetXPosInPixels(int pPos);
	int GetYPosInPixels(int pPos);
	bool IsFreeBlock(int pX, int pY);
	bool IsPossibleMove(int pX, int pY, int pPiece, int pRotation);
	void StorePiece(int pX, int pY, int pPiece, int pRotation);
	void DeletePossibleLines();
	bool IsGameOver();

private:
	enum{PosFree, PosFilled};				// PosFree: free position of the board; PosFilled: filled position of the board
	int mBoard[BoardWidth][BoardHeight];	// Board that contains the pieces
	pieces* mPieces;
	int mScreenHeight;

	void InitBoard();
	void DeleteLine(int pY);
};

