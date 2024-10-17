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
    
    //        std::cout <<"row:"<< row<< "to row: "<< toRow<< std::endl;
      //      std::cout <<"column:"<< column<< "to column: "<< toColumn<< std::endl;
      if(toRow > board.getNumRows() || toColumn > board.getNumCols()){
        return 0; 
      }
            if(row == toRow && column == toColumn){ 
             //   std::cout << "didnt move if" <<std::endl;
                return 0;
            } 
            if((abs(row-toRow)) == (abs(column - toColumn))){ 
                return 1;
            }
            return 0;
        }
    }
