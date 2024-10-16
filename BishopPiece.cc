#include "ChessPiece.hh"
#include "ChessBoard.hh"
#include "Chess.h"
#include "BishopPiece.hh"
#include <iostream>

namespace Student{
        void BishopPiece::setPosition(int row, int column) { 
        this->row = row; 
        this->column = column;
        }
        bool BishopPiece::canMoveToLocation(int toRow, int toColumn) { 
            if((row == toRow) && (column == toColumn)){ 
                return 0;
            } 
            if((abs(row-toRow)) == (abs(column - toColumn))){ 
                return 1;
            }
            return 0;
        }
    }
