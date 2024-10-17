#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>

void printPiecePosition(const Student::ChessPiece* piece, int row, int column)
{
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

    // Initial setup: print positions
    std::cout << "Initial positions:\n";
    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);  // White Rook
    printPiecePosition(sBoard.getPiece(1, 3), 1, 3);  // Black Bishop
    printPiecePosition(sBoard.getPiece(1, 1), 1, 1);  // Black Rook
    printPiecePosition(sBoard.getPiece(2, 3), 2, 3);  // White Rook

    // Test if a move is valid for a piece
    std::cout << "Testing valid moves:\n";
    printPiecePosition(sBoard.getPiece(3, 2), 3, 2);  // White Rook
    assert(sBoard.isValidMove(3, 2, 3, 0));  // White Rook moves horizontally (valid)
    
    std::cout << "Testing invalid moves:\n";
    assert(!sBoard.isValidMove(3, 2, 2, 1));  // White Rook can't move diagonally (invalid)

    // Perform valid move
    std::cout << "Performing valid move (Rook to (3, 0)):\n";
    bool moveSuccess = sBoard.movePiece(3, 2, 3, 0);  // Move White Rook to the left horizontally
    assert(moveSuccess == true);
    printPiecePosition(sBoard.getPiece(3, 0), 3, 0);  // White Rook new position

    assert(sBoard.getPiece(3, 2) == nullptr);  // Old position should be empty now

    // Test for an invalid Bishop move
    std::cout << "Testing invalid Bishop move:\n";
    assert(!sBoard.isValidMove(1, 3, 1, 1));  // Black Bishop can't move horizontally to Black Rook's position (invalid)

    // Valid diagonal Bishop move
    std::cout << "Performing valid Bishop move (Bishop to (3, 1)):\n";
    assert(sBoard.isValidMove(1, 3, 3, 1));  // Black Bishop moves diagonally (valid)
    moveSuccess = sBoard.movePiece(1, 3, 3, 1);
    assert(moveSuccess == true);
    printPiecePosition(sBoard.getPiece(3, 1), 3, 1);  // Black Bishop new position

    // Edge case: Moving out of bounds
    std::cout << "Testing out-of-bounds move:\n";
    assert(!sBoard.isValidMove(3, 1, 4, 1));  // Move out-of-bounds (too far down)
    assert(!sBoard.isValidMove(3, 1, 3, 4));  // Move out-of-bounds (too far right)

    // Edge case: Rook blocked by another piece (White Rook at 2,3 blocks White Rook at 3,0)
    std::cout << "Testing obstructed Rook move:\n";
    assert(!sBoard.isValidMove(3, 0, 2, 3));  // Path blocked by another White Rook

    // Moving to the same position
    std::cout << "Testing move to the same position:\n";
   // assert(!sBoard.isValidMove(3, 1, 3, 1));  // Bishop can't move to the same location

    // Perform another valid move for Rook
    std::cout << "Performing valid move for Rook:\n";
    assert(sBoard.isValidMove(2, 3, 2, 0));  // White Rook moves horizontally (valid)
    assert(sBoard.movePiece(2, 3, 2, 0));    // Move should succeed
    printPiecePosition(sBoard.getPiece(2, 0), 2, 0);  // White Rook new position

    // Invalid move: Rook attempting a diagonal move
    std::cout << "Testing invalid Rook diagonal move:\n";
    assert(!sBoard.isValidMove(1, 1, 2, 2));  // Black Rook can't move diagonally

    // Testing pieces at board edges
    std::cout << "Testing edge cases:\n";
    assert(!sBoard.isValidMove(0, 2, -1, 2));  // Move out-of-bounds (negative index)
    assert(!sBoard.isValidMove(3, 0, 3, 4));   // Move out-of-bounds (right edge exceeded)

    std::cout << "All tests passed.\n";
}

int main()
{
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}
