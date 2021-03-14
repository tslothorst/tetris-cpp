#pragma once
#include "board.h"
#include "pieces.h"
#include <time.h>
#include "IO.h"

constexpr int WaitTime = 700;

class game
{
public:
	game(board* pBoard, pieces* pPieces, IO* pIO, int pScreenHeight);

	void DrawScene();
	void CreateNewPiece();

	// Position of the piece that is falling down
	int mPosX;
	int	mPosY;

	int mPiece;				// Type of piece
	int mRotation;			// Orientation of piece

private:
	int mScreenHeight;

	// Position of the next piece
	int mNextPosX;
	int mNextPosY;

	int mNextPiece;			// Type of piece
	int mNextRotation;		// Orientation of piece

	board* mBoard;
	pieces* mPieces;
	IO* mIO;

	int GetRand(int pA, int pB);
	void InitGame();
	void DrawPiece(int pX, int pY, int pPiece, int pRotation);
	void DrawBoard();
};

