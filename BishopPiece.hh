#ifndef __BISHOPPIECE_H__
#define __BISHOPPIECE_H__
#include <iostream>
#include "ChessPiece.hh"

/**
 * Student implementation of a Bishop chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class BishopPiece : public ChessPiece
    {
        public:
         BishopPiece(ChessBoard &board, Color color, int row, int column)
            : ChessPiece(board, color, row, column) {}

        void setPosition(int row, int column)override;
         
        bool canMoveToLocation(int toRow, int toColumn)override; 
        Type getType() override{  
            return Type::Bishop; 
        }
            const char *toString() override {
                if(color == White){
        return "♗"; 
                }
                else{ 
                    return "♝";
                }
            }
    };
    }

#endif
