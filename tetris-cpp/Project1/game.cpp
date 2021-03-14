#include "game.h"
#include <stdlib.h>

/// <summary>
/// Draw all the objects of the scene
/// </summary>
void game::DrawScene()
{
    DrawBoard();                                                        // Draw the delimitation lines and blocks stored in the board
    DrawPiece(mPosX, mPosY, mPiece, mRotation);                         // Draw the playing piece
    DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);         // Draw the next piece
}

/// <summary>
/// Create a random piece
/// </summary>
void game::CreateNewPiece()
{
    // Makes the next piece the current piece
    mPiece = mNextPiece;
    mRotation = mNextRotation;
    mPosX = (BoardWidth / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);;
    mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

    // Generate the next piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
}

/// <summary>
/// Get a random int between to integers
/// </summary>
/// <param name="pA">First number</param>
/// <param name="pB">Second number</param>
/// <returns></returns>
int game::GetRand(int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;;
}

/// <summary>
/// Initial parameters of the game
/// </summary>
void game::InitGame()
{
    // Call srand so rand will generate a new random number every time the program is run. Seed it with current system time.
    srand((unsigned int)time(NULL));

    // First piece in the game
    mPiece = GetRand(0, 6);
    mRotation = GetRand(0, 3);
    mPosX = (BoardWidth / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

    // Next piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
    mNextPosX = BoardWidth + 5;
    mNextPosY = 5;
}

/// <summary>
/// Draw piece
/// </summary>
/// <param name="pX">Horizontal position in blocks</param>
/// <param name="pY">Vertical position in blocks</param>
/// <param name="pPiece">Piece to draw</param>
/// <param name="pRotation">One of four possible rotations</param>
void game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
    color mColor; // The color of the piece

    // Obtain the position in pixel in the screen of the block we want to draw
    int mPixelsX = mBoard->GetXPosInPixels(pX);
    int mPixelsY = mBoard->GetYPosInPixels(pY);

    for (int i = 0; i < PieceBlocks; i++)
    {
        for (int j = 0; j < PieceBlocks; j++)
        {
            switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
            {
                case 1: mColor = GREEN; break;
                case 2: mColor = BLUE; break;
            }

            if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0)
            {
                mIO->DrawRectangle(mPixelsX + i * BlockSize, mPixelsY + j * BlockSize, (mPixelsX + i * BlockSize) + BlockSize - 1, (mPixelsY + j * BlockSize) + BlockSize - 1, mColor);
            }
        }
    }
}

/// <summary>
/// Draw the two lines that delimit the board
/// </summary>
void game::DrawBoard()
{
    int mX1 = BoardPosition - (BlockSize * (BoardWidth / 2)) - 1;
    int mX2 = BoardPosition + (BlockSize * (BoardWidth / 2));
    int mY = mScreenHeight - (BlockSize * BoardHeight);

    // Check that the vertical margin is not to small
    //assert (mY > MinVerticalMargin);
    
    mIO->DrawRectangle(mX1 - BoardLineWith, mY, mX1, mScreenHeight - 1, BLUE);
    mIO->DrawRectangle(mX2, mY, mX2 + BoardLineWith, mScreenHeight - 1, BLUE);

    // Check that the horizontal margin is not to small
    //assert (mX1 > MinHorizontalMargin);
    
    // Drawing the blocks that are already stored in the board
    mX1 += 1;
    for (int i = 0; i < BoardWidth; i++)
    {
        for (int j = 0; j < BoardHeight; j++)
        {
            // Check if the block is filled, if so, draw it
            if (!mBoard->IsFreeBlock(i, j))
            {
                mIO->DrawRectangle(mX1 + i * BlockSize, mY + j * BlockSize, (mX1 + i * BlockSize) + BlockSize - 1, (mY + j * BlockSize) + BlockSize - 1, RED);
            }
        }
    }
}
