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
                  if(toRow > board.getNumRows() || toColumn > board.getNumCols() || toColumn < 0 || toRow > 0){
        return 0; 
      }
            if(((row == toRow) || (column == toColumn)) &!((row == toRow && column == toColumn))){
                return 1;
            }
            return 0; 
        }
        Type getType() { 
            return Rook;
        }
    }
