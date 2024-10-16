#include "ChessPiece.hh"
#include "ChessBoard.hh"
#include "Chess.h"
#include <iostream>

namespace Student{

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column)
    : board(board), color(color), row(row), column(column) {
   }

Color Student::ChessPiece::getColor() {
    return color;
}

/*const char* toString() {
    return nullptr;   
}*/

int ChessPiece::getRow() {
    return row;
}
int ChessPiece::getColumn() {
    return column;
}
void ChessPiece::setPosition(int row, int column) {
    this->row = row;
    this->column = column;
}

}