
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
    for (int fromRow = 0; fromRow < 4; ++fromRow) {
        for (int fromCol = 0; fromCol < 4; ++fromCol) {
            for (int toRow = 0; toRow < 4; ++toRow) {
                for (int toCol = 0; toCol < 4; ++toCol) {
                    // Only check moves from positions that have a piece
                    if (sBoard.getPiece(fromRow, fromCol) != nullptr) {
                        bool validMove = sBoard.isValidMove(fromRow, fromCol, toRow, toCol);
                        
                        // Output the result of the move check
                        std::cout << "Move from (" << fromRow << ", " << fromCol << ") "
                                  << "to (" << toRow << ", " << toCol << "): "
                                  << (validMove ? "Valid" : "Invalid") << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "All tests passed." << std::endl;

    return;
}

int main()
{
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}