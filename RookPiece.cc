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
                     if(toRow > board.getNumRows() || toColumn > board.getNumCols() || toColumn < 0 || toRow < 0){
        return 0; 
      }
            if(((column == toColumn) || (row == toRow))){
                  if((board.getPiece(toRow, toColumn) != nullptr)){
                        if(board.getPiece(toRow, toColumn)->color == color) { 
                            return 0;
                        }
                        return 1;
                  }
    //            printf("in row");
                return 1;
                        
            }
            
            return 0; 
            }
        
        Type getType() { 
            return Rook;
        }
    }
