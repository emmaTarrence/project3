#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include <iostream>
using Student::ChessBoard;

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}
ChessBoard::ChessBoard(int numRow, int numCol) {
    numRows = numRow;  
    numCols = numCol;  
    board.resize(numRows, std::vector<ChessPiece*>(numCols, nullptr));
}


void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int StartColumn){
   /* std::cout << "startRow: " << startRow << ", StartColumn: " << StartColumn << std::endl;
std::cout << "Type: " << ty << ", Color: " << col << std::endl;
        ChessBoard* boardPtr = dynamic_cast<ChessBoard*>(this);
        if (boardPtr) {
            std::cout << "*this is a ChessBoard instance." << std::endl;
        } else {
            std::cout << "*this is NOT a ChessBoard instance." << std::endl;
        }*/
    if(ty == Type::Pawn) { 
        board[startRow][StartColumn] = new PawnPiece(*this, col, startRow, StartColumn);
    }else if(ty == Type::Rook) { 
       // std::cout <<"in rook"<< std::endl;
        board[startRow][StartColumn] = new RookPiece(*this, col, startRow, StartColumn);
   }else if(ty == Type::Bishop){
        board[startRow][StartColumn] = new BishopPiece(*this, col, startRow, StartColumn);
    }
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    if (this->isValidMove(fromRow, fromColumn, toRow, toColumn)) {
        board[toRow][toColumn] = board[fromRow][fromColumn];
        board[fromRow][fromColumn] = nullptr;
        return true;
    }
    return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn){
    ChessPiece* piece = board[fromRow][fromColumn];
    if(piece !=nullptr) {
        return piece->canMoveToLocation(toRow, toColumn);
    }
    return false;
    }
bool ChessBoard::isPieceUnderThreat(int row, int column){ return true;}


