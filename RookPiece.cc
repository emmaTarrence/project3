#include "ChessPiece.hh"
#include "ChessBoard.hh"
#include "Chess.h"
#include "RookPiece.hh"
#include <iostream>

namespace Student{
        void RookPiece::setPosition(int row, int column) {
        this->row = row; 
        this->column = column;
        }
        bool RookPiece::canMoveToLocation(int toRow, int toColumn) { 
            if(((row == toRow) || (column == toColumn)) &!((row == toRow && column == toColumn))){
                return 1;
            }
            return 0; 
        }
        Type getType() { 
            return Rook;
        }
    }
