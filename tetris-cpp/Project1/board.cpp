#include "board.h"

/// <summary>
/// Initialize the board with all positions free
/// </summary>
void board::InitBoard()
{
	for (int i = 0; i < BoardWidth; i++)
	{
		for (int j = 0; j < BoardHeight; j++) 
		{
			mBoard[i][j] = PosFree;
		}
	}
}

/// <summary>
/// Delete a line of the board by moving all above lines down
/// </summary>
/// <param name="pY">Vertical position in blocks of the line to delete</param>
void board::DeleteLine(int pY)
{
	for (int j = pY; j > 0; j--) 
	{
		for (int i = 0; i < BoardWidth; i++)
		{
			mBoard[i][j] = mBoard[i][j - 1];
		}
	}
}
/// <summary>
/// Returns the horizontal position (in pixels) of the block given like parameter
/// </summary>
/// <param name="pPos">Horizontal position of the block in the board</param>
/// <returns></returns>
int board::GetXPosInPixels(int pPos)
{
	return ((BoardPosition - (BlockSize * (BoardWidth / 2))) + (pPos * BlockSize));
}

/// <summary>
/// Returns the vertical position (in pixels) of the block given like parameter
/// </summary>
/// <param name="pPos">Horizontal position of the block in the board</param>
/// <returns></returns>
int board::GetYPosInPixels(int pPos)
{
	return ((BoardPosition - (BlockSize * (BoardWidth / 2))) + (pPos * BlockSize));
}

/// <summary>
/// Checks if a position on the board is free (true) or not (false)
/// </summary>
/// <param name="pX">Horizontal position in blocks</param>
/// <param name="pY">Vertical position in blocks</param>
/// <returns></returns>
bool board::IsFreeBlock(int pX, int pY)
{
	if (mBoard[pX][pY] == PosFree)
	{
		return true;
	}
	else 
	{ 
		return false; 
	}
}

/// <summary>
/// Check if the piece can be stored at this position without any collision. Returns true if the movement is  possible, false if it not possible
/// </summary>
/// <param name="pX">Horizontal position in blocks</param>
/// <param name="pY">Vertical position in blocks</param>
/// <param name="pPiece">Piece to draw</param>
/// <param name="pRotation">One of four possible rotations</param>
/// <returns></returns>
bool board::IsPossibleMove(int pX, int pY, int pPiece, int pRotation)
{
	// This is just to check the 5x5 blocks of a piece with the appropriate area in the board
	for (int i1 = pX, i2 = 0 ; i1 < pY + PieceBlocks; i1++, i2++)
	{
		for(int j1 = pY, j2 = 0; j1 < pY + PieceBlocks; j1++, j2++)
		{
			// Check if the piece is outside the limits of the board
			if (i1 < 0 || i1 > BoardWidth-1 || j1 > BoardHeight-1)
			{
				if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
				{
					return 0;
				}
			}
			// Check if the piece have collisioned with a block already stored in the map
			if (j1 > 0)
			{
				if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock(i1, j1)))
				{
					return false;
				}
			}
		}
	}
	// We're good, no collissions detected
	return true;
}

/// <summary>
/// Store a piece in the board by filling the blocks
/// </summary>
/// <param name="pX">Horizontal position in blocks</param>
/// <param name="pY">Vertical position in blocks</param>
/// <param name="pPiece">Piece to draw</param>
/// <param name="pRotation">One of the four possible rotations</param>
void board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
	// Store each block of the piece into the board
	for (int i1 = pX, i2 = 0; i1 < pX + PieceBlocks; i1++, i2++) 
	{
		for(int j1 = pY, j2 = 0; j1 < pY + PieceBlocks; j1++, j2++)
		{
			if (mPieces->GetBlockType(pPiece,pRotation, j2, i2) != 0)
			{
				mBoard[i1][j1] = PosFilled;
			}
		}
	}
}

/// <summary>
/// Delete all the lines that have been filled horizontally
/// </summary>
void board::DeletePossibleLines()
{
	for (int j = 0; j < BoardHeight; j++)
	{
		int i = 0;
		while (i < BoardWidth)
		{
			if (mBoard[i][j] != PosFilled )
			{
				break;				
			}
			i++;
		}
		if (i == BoardWidth)
		{
			DeleteLine(j);
		}
	}
}

/// <summary>
/// Checks if any part of a piece occupies the top row of the board. If so returns True to end the game.
/// </summary>
/// <returns>True or False</returns>
bool board::IsGameOver()
{
	for (int i = 0; i < BoardWidth; i++)
	{
		if(mBoard[i][0] == PosFilled)
		{
			return true;
		}
	}
	return false;
}
