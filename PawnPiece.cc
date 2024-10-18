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
            int stepRow = (toRow > row) ? 1 : (toRow < row) ? -1 : 0;
            int stepColumn = (toColumn > column) ? 1 : (toColumn < column) ? -1 : 0;

            int currentRow = row + stepRow;
            int currentColumn = column + stepColumn;
       while(currentRow != toRow || currentColumn != toColumn){
                ChessPiece* pieceInPath = board.getPiece(currentRow, currentColumn);
                if(pieceInPath != nullptr){
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
        
      //A black piece can move in increasing row number (downwards in the figure).
               if((color == Black) && ((row == toRow) && (column > toColumn))){
                if(((column + 2) == toColumn) || ((toColumn == (column + 1))&&(column== 0))) {
                    return 1;                     
                }
                if((toColumn == (column + 1))){
                    return 1;
                }
            }
//A white piece can move in decreasing row number (upwards in the figure).
 if((color == White) && (row == toRow) && (column > toColumn)){
                if((row == board.getNumRows()) &&((toColumn == (column - 1)) || (toColumn == (column - 2)))){ 
                    return 1; 
                    }
                }
                else if((column - 1) == toColumn) { 
                    return 1; 
                }
            
//A black piece on row 1 can move 1 or 2 steps along the same column.
//A white piece on row n-2 can move 1 or 2 steps along the same column.
//In all other cases, a pawn can only move 1 step forward along the same column.
//A pawn can consume another piece by moving to a diagonally adjacent square with a higher row
//number for a black piece, or a lower row number for a white piece.

           
            return 0;
        }
}
    
