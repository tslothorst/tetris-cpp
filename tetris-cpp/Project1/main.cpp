#define SDL_MAIN_HANDLED
#include "main.h"
#include "Game.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	// Class for drawing stuff, it uses SDL for the rendering. 
	IO mIO;	
	int mScreenHeight = mIO.GetScreenHeight();

	// Pieces
	pieces mPieces;

	// Board
	board mBoard(&mPieces, mScreenHeight);

	// Game
	game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

	// Get the actual clock milliseconds (SDL)
	unsigned long mTime1 = SDL_GetTicks();

	// ----- Main Loop -----

	while (!mIO.IsKeyDown(SDLK_ESCAPE))
	{
		// ----- Draw -----

		mIO.ClearScreen(); 		// Clear screen
		mGame.DrawScene();		// Draw stuff
		mIO.UpdateScreen();		// Put the graphic context in the screen

		// ----- Input -----

		int mKey = mIO.Pollkey();

		switch (mKey)
		{
			case (SDLK_RIGHT):
			{
				if (mBoard.IsPossibleMove(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX++;
				break;
			}

			case (SDLK_LEFT):
			{
				if (mBoard.IsPossibleMove(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX--;
				break;
			}

			case (SDLK_DOWN):
			{
				if (mBoard.IsPossibleMove(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
					mGame.mPosY++;
				break;
			}

			case (SDLK_x):
			{
				// Check collision from up to down
				while (mBoard.IsPossibleMove(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { mGame.mPosY++; }

				mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

				mBoard.DeletePossibleLines();

				if (mBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}

				mGame.CreateNewPiece();

				break;
			}

			case (SDLK_z):
			{
				if (mBoard.IsPossibleMove(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
					mGame.mRotation = (mGame.mRotation + 1) % 4;

				break;
			}
		}

		// ----- Vertical movement -----

		unsigned long mTime2 = SDL_GetTicks();

		if ((mTime2 - mTime1) > WaitTime)
		{
			if (mBoard.IsPossibleMove(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
			{
				mGame.mPosY++;
			}
			else
			{
				mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

				mBoard.DeletePossibleLines();

				if (mBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}

				mGame.CreateNewPiece();
			}

			mTime1 = SDL_GetTicks();
		}
	}

	return 0;
}