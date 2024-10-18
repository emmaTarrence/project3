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
            if(toRow != row) { 
            if(abs(toRow - row) == abs(toColumn - column) && ((toRow - row) == 1)) { 
                if(board.getPiece(toRow, toColumn)){ 
                    if(board.getPiece(toRow,toColumn)->color == !color){
                    return 1;
                }
                }
            }
            }
            


        if(toRow > board.getNumRows() || toColumn > board.getNumCols()){
            return 0; 
        }
            if(board.getPiece(toRow, toColumn)){
                    return 0;
                }
                if(toRow == row + 2 ) { 
                   if(board.getPiece(toRow - 1, toColumn)) { 
                        return 0; 
                    }
                }
            
      //A black piece can move in increasing row number (downwards in the figure).
               if((color == Black) && ((row < toRow) && (column == toColumn))){
                 //  printf("in BLack");             
//A black piece on row 1 can move 1 or 2 steps along the same column.
                if((((row + 2) == toRow) || ((toRow == (row + 1))))&&(row== 0)) {
                    return 1;                     
                }
                if((toRow == (row + 1))){
                    return 1;
                }
            }
//A white piece can move in decreasing row number (upwards in the figure).
 if((color == White) && (row > toRow) && (column == toColumn)){
    
//A white piece on row n-2 can move 1 or 2 steps along the same column.
                if((row == (board.getNumRows() - 1)) && ((toRow == (row - 1)) || (toRow == (row - 2)))){ 
                    return 1; 
                    }
                
                else if((row - 1) == toRow) { 
                    return 1; 
                }
 }

            
//In all other cases, a pawn can only move 1 step forward along the same column.
//A pawn can consume another piece by moving to a diagonally adjacent square with a higher row
//number for a black piece, or a lower row number for a white piece.

           
            return 0;
        }
}
    
