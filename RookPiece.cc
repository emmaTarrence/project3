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
            int stepRow = (toRow > row) ? 1 : (toRow < row) ? -1 : 0;
            int stepColumn = (toColumn > column) ? 1 : (toColumn < column) ? -1 : 0;

            int currentRow = row + stepRow;
            int currentColumn = column + stepColumn;
            if(((column == toColumn) || (row == toRow))){
                while(currentRow != toRow || currentColumn != toColumn) {
                    ChessPiece* pieceInPath = board.getPiece(currentRow, currentColumn);
                    if(pieceInPath != nullptr) { 
                     //   if(pieceInPath->color == color) { 
                            return 0;
                        }
                    
                    currentRow += stepRow;
                    currentColumn += stepColumn;
            }

                  if((board.getPiece(toRow, toColumn) != nullptr)){
                        if(board.getPiece(toRow, toColumn)->color == color) { 
                            return 0;
                        }
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
