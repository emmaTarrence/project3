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
    
      if(toRow > board.getNumRows() || toColumn > board.getNumCols()){
        return 0; 
      }
            if(row == toRow && column == toColumn){ 
                  return 0;
            } 
            if((abs(toRow-row)) == (abs(toColumn-column))){ 
                            int stepRow = (toRow > row) ? 1 : -1;
            int stepColumn = (toColumn > column) ? 1 : -1;

            int currentRow = row + stepRow;
            int currentColumn = column + stepColumn;
            while(currentRow != toRow || currentColumn != toColumn){
                ChessPiece* pieceInPath = board.getPiece(currentRow, currentColumn);
                if(pieceInPath != nullptr){
               //     if(pieceInPath->color == color) { 
                        return 0;
                    }
                
                    currentRow += stepRow;
                    currentColumn+= stepColumn;
                }
                    if((board.getPiece(toRow, toColumn) != nullptr)){
                        if(board.getPiece(toRow, toColumn)->color == color) { 
                            return 0; 
                        }
                     
                    }
                       return 1;
                       
            }
            
            return 0;
        }
}
