#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Polynomial {
    int pow;
    int k;
} Polynomial;

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }

    return file;
}

void generatePolynomial(char *filename, int nPolynomial, int nMember) {
    srand(time(NULL));
    FILE *file = openFile(filename, "wb");

    for (int i = 0; i < nPolynomial; i++) {
        for (int j = 0; j < nMember; j++) {
            Polynomial p;
            p.pow = j;
            p.k = (rand() % 2 == 0 ? 1 : -1) * (rand() % 9 + 1);
            fwrite(&p, sizeof(Polynomial), 1, file);
        }
    }

    fclose(file);
}

void removePolynomialsWithRoot(char *filename, int x, int nPolynomial, int nMember) {
    FILE *file = openFile(filename, "rb+");

    for (int i = 0; i < nPolynomial; i++) {
        int res = 0;
        int x_pow = 0;

        for (int j = 0; j < nMember; j++) {
            Polynomial p;
            fread(&p, sizeof(Polynomial), 1, file);
            res += p.k * pow(x, x_pow);
            x_pow += 1;
        }

        if (res == 0) {
            fseek(file, i * nMember * sizeof(Polynomial), SEEK_SET);
            for (int j = 0; j < nMember; j++) {
                Polynomial zero = {0, 0};
                fwrite(&zero, sizeof(Polynomial), 1, file);
            }
        }
    }
    
    fclose(file);
}

void printPolynomial(char *filename, int x, int nPolynomial, int nMember) {
    FILE *file = openFile(filename, "rb");
    
    for (int i = 0; i < nPolynomial; ++i) {
        int allZero = 1;
        int sum = 0;
        int x_pow = 0;

        for (int j = 0; j < nMember; ++j) {
            Polynomial p;
            fread(&p, sizeof(Polynomial), 1, file);
            sum += p.k * pow(x, x_pow);
            x_pow += 1;

            if (p.k != 0 || p.pow != 0) {
                allZero = 0;
                fseek(file, -sizeof(Polynomial), SEEK_CUR);
                break;
            }
        }

        if (!allZero && sum != 0) {
            for (int j = 0; j < nMember; ++j) {
                Polynomial p;
                fread(&p, sizeof(Polynomial), 1, file);
                printf("(%dx^%d)", p.k, p.pow);

                if (j != nMember - 1) {
                    printf(" + ");
                }
            }

            printf(" = 0\n");
        }
    }
    
    fclose(file);
}

int main() {
    char *filename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    int nPolynomial = 3;
    int nMember = 4;
    int x = 2;

    generatePolynomial(filename, nPolynomial, nMember);

    printf("Polynomials before deletion:\n");
    printPolynomial(filename, x, nPolynomial, nMember);

    removePolynomialsWithRoot(filename, x, nPolynomial, nMember);

    printf("Polynomials after deletion:\n");
    printPolynomial(filename, x, nPolynomial, nMember);

    return 0;
}