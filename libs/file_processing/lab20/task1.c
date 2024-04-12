#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define COORDINATES 4

void generateRandomQueries(int numQueries, int queries[][COORDINATES]) {
    srand(time(NULL));

    for (int i = 0; i < numQueries; i++) {
        queries[i][0] = rand() % N;
        queries[i][1] = rand() % N;
        queries[i][2] = queries[i][0] + rand() % (N - queries[i][0]);
        queries[i][3] = queries[i][1] + rand() % (N - queries[i][1]);
    }
}

void processQuery(int matrix[N][N], int query[][COORDINATES], int numQueries) {
    for (int i = 0; i < numQueries; i++) {
        int row1 = query[i][0];
        int col1 = query[i][1];
        int row2 = query[i][2];
        int col2 = query[i][3];
        for (int j = row1; j <= row2; j++) {
            for (int k = col1; k <= col2; k++) {
                matrix[j][k] += 1;
            }
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void printQueries(int queries[][COORDINATES], int numQueries) {
    printf("Queries:\n");

    for (int i = 0; i < numQueries; i++) {
        printf("(%d, %d) -> (%d, %d)\n", queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
    }

    printf("\n");
}

int main() {
    int numQueries = 2;
    int queries[numQueries][COORDINATES];
    int matrix[N][N] = {0};

    generateRandomQueries(numQueries, queries);

    printf("The original matrix:\n");
    printMatrix(matrix);

    printQueries(queries, numQueries);

    processQuery(matrix, queries, numQueries);

    printf("The final matrix:\n");
    printMatrix(matrix);

    return 0;
}