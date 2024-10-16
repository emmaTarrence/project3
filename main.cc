#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>


void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);
    std::cout << sBoard.displayBoard().str() << std::endl;
    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.
 Student::ChessPiece* piece1 = sBoard.getPiece(3, 2);
    assert(piece1 != nullptr);
    assert(piece1->getType() == Type::Rook);
    assert(piece1->getColor() == White);

    Student::ChessPiece* piece2 = sBoard.getPiece(1, 3);
    assert(piece2 != nullptr);
    assert(piece2->getType() == Type::Bishop);
    assert(piece2->getColor() == Black);

    // Test if a move is valid for a piece
    assert(sBoard.isValidMove(3, 2, 3, 0));  // White Rook can move horizontally
    assert(!sBoard.isValidMove(3, 2, 2, 1));  // Invalid move for the White Rook

    // Test if the move is correctly performed
    bool moveSuccess = sBoard.movePiece(3, 2, 3, 0);  // Move White Rook
    assert(moveSuccess == true);
    assert(sBoard.getPiece(3, 2) == nullptr);  // Old position is empty
    assert(sBoard.getPiece(3, 0) != nullptr);  // New position has the Rook

    // Test invalid moves for pieces
    assert(!sBoard.isValidMove(1, 3, 3, 3));  // Black Bishop can't move like a Rook
    assert(sBoard.isValidMove(1, 3, 3, 1));  // Black Bishop can move diagonally

    // Test if the board correctly handles invalid moves
    moveSuccess = sBoard.movePiece(1, 3, 3, 3);  // Invalid Bishop move
    assert(moveSuccess == false);  // Move should fail

    std::cout << "All tests passed." << std::endl;

    return;
}

int main()
{
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}
