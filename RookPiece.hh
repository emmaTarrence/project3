#ifndef _ROOKPIECE_H__
#define _ROOKPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class RookPiece : public ChessPiece
    {
        public:
        RookPiece(ChessBoard &board, Color color, int row, int column)
            : ChessPiece(board, color, row, column) {}
        void setPosition(int row, int column)override;
        bool canMoveToLocation(int toRow, int toColumn)override; 
        Type getType() override{  
            return Type::Rook; 
        }
                    const char *toString() override {
        return "♖"; 
            }
    };
}


#endif
