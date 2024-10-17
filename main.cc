#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>

// Helper function to print the position of a piece
void printPiecePosition(const Student::ChessPiece* piece, int row, int column) {
    if (piece != nullptr) {
        std::cout << "Piece " << piece << " is at (" << row << ", " << column << ")" << std::endl;
    } else {
        std::cout << "No piece at (" << row << ", " << column << ")" << std::endl;
    }
}

void test_part1_4x4_1()
{
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);
    
    std::cout << sBoard.displayBoard().str() << std::endl;

    Student::ChessPiece* piece1 = sBoard.getPiece(3, 2);
    assert(piece1 != nullptr);
    assert(piece1->getType() == Type::Rook);
    assert(piece1->getColor() == White);

    Student::ChessPiece* piece2 = sBoard.getPiece(1, 3);
    assert(piece2 != nullptr);
    assert(piece2->getType() == Type::Bishop);
    assert(piece2->getColor() == Black);

    // Print piece position before the move
    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);
    assert(sBoard.isValidMove(3, 2, 3, 0));  // White Rook can move horizontally
    // Print piece position after the move (position shouldn't have changed)
    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);

    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);
    assert(!sBoard.isValidMove(3, 2, 2, 1));  // Invalid move for the White Rook
    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);

    // Test if the move is correctly performed
    bool moveSuccess = sBoard.movePiece(3, 2, 3, 0);  // Move White Rook
    assert(moveSuccess == true);
    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);  // Old position is now empty
    printPiecePosition(sBoard.getPiece(3, 0), 3, 0);  // New position has the Rook

    // Invalid Bishop move
    printPiecePosition(sBoard.getPiece(1, 3), 1, 3);
    assert(!sBoard.isValidMove(1, 3, 3, 3));  // Black Bishop can't move like a Rook
    printPiecePosition(sBoard.getPiece(1, 3), 1, 3);
    
    // Move the Bishop diagonally
    assert(sBoard.isValidMove(1, 3, 3, 1));  // Black Bishop can move diagonally
    moveSuccess = sBoard.movePiece(1, 3, 3, 1);  // Perform the move
    assert(moveSuccess == true);
    printPiecePosition(sBoard.getPiece(1, 3), 1, 3);  // Old position should be empty
    printPiecePosition(sBoard.getPiece(3, 1), 3, 1);  // New position has the Bishop

    // Ensure the board reflects the moves
    std::cout << sBoard.displayBoard().str() << std::endl;

    std::cout << "All tests passed." << std::endl;
}

int main()
{
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}
