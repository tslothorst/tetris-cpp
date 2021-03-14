#include "pieces.h"

// Pieces definition
char mPieces[7 /*Kind of piece*/][4 /*rotation*/][5 /*horizontal blocks*/][5 /*vertical blocks*/] =
{
    // Square
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },

    // I
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
      ,
    // L
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // L mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },



       {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // T
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 2, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
};

// Displacement of the piece to the position where it is first drawn in the board when it is created
int mPiecesInitialPosition[7 /*kind of piece */][4 /*r2otation*/][2 /*position*/] =
{
    /* Square */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
       },
    /* I */
      {
        {-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3}
       },
    /* L */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    /* L mirrored */
      {
        {-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3}
       },
    /* N */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    /* N mirrored */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    /* T */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
};

/// <summary>
/// Returns the type of a block (0: No block, 1: Normal block, 2: Pivot block)
/// </summary>
/// <param name="pPiece">Piece to draw</param>
/// <param name="pRotation">One of four possible rotations</param>
/// <param name="pX">Horizontal position of the block (X-axis)</param>
/// <param name="pY">Vertical position of the block (Y-axis)</param>
/// <returns>int mPieces</returns>
int pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return mPieces[pPiece][pRotation][pX][pY];
}

/// <summary>
/// Returns the horizontal position that is needed to draw it in the correct position when it is first created
/// </summary>
/// <param name="pPiece">Piece to draw</param>
/// <param name="pRotation">One of four possible rotations</param>
/// <returns>int mPiecesInitialPosition</returns>
int pieces::GetXInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][0];
}

/// <summary>
/// Returns the vertical position that is needed to draw it in the correct position when it is first created
/// </summary>
/// <param name="pPiece">Piece to draw</param>
/// <param name="pRotation">One of four possible rotations</param>
/// <returns>int mPiecesInitialPosition</returns>
int pieces::GetYInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][1];
}