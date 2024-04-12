#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.c"

void gameOfLife(matrix *board) {
    matrix next_state = getMemMatrix(board->nRows, board->nCols);

    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    for (int i = 0; i < board->nRows; i++) {
        for (int j = 0; j < board->nCols; j++) {
            int live_neighbors = 0;

            for (int k = 0; k < 8; k++) {
                int ni = i + directions[k][0];
                int nj = j + directions[k][1];

                if (ni >= 0 && ni < board->nRows && nj >= 0 && nj < board->nCols &&
                    board->values[ni][nj] == 1) {
                    live_neighbors++;
                }
            }

            if (board->values[i][j] == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    next_state.values[i][j] = 0;
                } else {
                    next_state.values[i][j] = 1;
                }
            } else {
                if (live_neighbors == 3) {
                    next_state.values[i][j] = 1;
                } else {
                    next_state.values[i][j] = 0;
                }
            }
        }
    }

    freeMemMatrix(board);

    *board = next_state;
}

void test_gameOfLife() {
    matrix board = createMatrixFromArray(
        (int[]){
            0, 1, 0,
            0, 0, 1,
            1, 1, 1,
            0, 0, 0
        }, 
        4, 3
    );

    gameOfLife(&board);

    matrix expected_result = createMatrixFromArray(
        (int[]) {
            0, 0, 0,
            1, 0, 1,
            0, 1, 1,
            0, 1, 0
        },
        4, 3
    );

    assert(areTwoMatricesEqual(&board, &expected_result) == true);

    freeMemMatrix(&board);
    freeMemMatrix(&expected_result);
}

int main() {
    test_gameOfLife() ;
    
    return 0;
}