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
        void setPosition(int row, int column);
        bool canMoveToLocation(int toRow, int toColumn); 
        Type getType() {  
            return Type::Pawn; 
        }
                    const char *toString() override {
        return "♙"; 
            }
    };
}

#endif
