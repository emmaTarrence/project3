#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {
        public:
         PawnPiece(ChessBoard &board, Color color, int row, int column)
            : ChessPiece(board, color, row, column) {}
        void setPosition(int row, int column)override;
        bool canMoveToLocation(int toRow, int toColumn)override; 
        Type getType() override{  
            return Type::Pawn; 
        }
                    const char *toString() override {
                        if(color == White) { 
        return "♙"; 
                        }
                        else{
                            return "♟";
                        }

            }
    };
}

#endif
