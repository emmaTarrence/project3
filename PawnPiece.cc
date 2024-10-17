#include "ChessPiece.hh"
#include "ChessBoard.hh"
#include "Chess.h"
#include "PawnPiece.hh"
#include <iostream>

namespace Student{
        void PawnPiece::setPosition(int row, int column) { 
        this->row = row; 
        this->column = column;
        }
        bool PawnPiece::canMoveToLocation(int toRow, int toColumn) { 
                  if(toRow > board.getNumRows() || toColumn > board.getNumCols()){
        return 0; 
      }
             if((row == toRow) && (column == toColumn)){ 
                return 0;
            } 
            if((color == Black) && (row == toRow) && (column > toColumn)){
                if((row == 1) &&((toColumn == (column + 1)) || ((toColumn + 2) == column))){
                    return 1; 
                }
                else if((column + 1) == toColumn){
                    return 1;
                }
            }
            if((color == White) && (row == toRow) && (column > toColumn)){
                // need to figure oout what n should be, need to add this back in but idk now rn 
                if((row == board.getNumRows()) &&((toColumn == (column - 1)) || (toColumn == (column - 2)))){ 
                    return 1; 
                }
                else if((column - 1) == toColumn) { 
                    return 1; 
                }
            }
            return 0;
        }
    }
