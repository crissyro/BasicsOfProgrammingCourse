#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float bestResult;
} Athlete;

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }

    return file;
}

float randomFloat(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

void generateTestData(const char* filename, int numAthletes) {
    FILE *file = openFile(filename, "wb");

    srand(time(NULL));

    for (int i = 0; i < numAthletes; i++) {
        Athlete athlete;
        sprintf(athlete.name, "Athlete %d", i + 1);
        athlete.bestResult = randomFloat(8.0, 13.0);
        fwrite(&athlete, sizeof(Athlete), 1, file);
    }

    fclose(file);
}

void readAthletes(const char* filename, Athlete** athletes, int* numAthletes) {
    FILE *file = openFile(filename, "rb");

    *athletes = (Athlete*)malloc((*numAthletes) * sizeof(Athlete));
    if (*athletes == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    fread(*athletes, sizeof(Athlete), *numAthletes, file);

    fclose(file);
}

int compareAthletes(const void* a, const void* b) {
    Athlete* athleteA = (Athlete*)a;
    Athlete* athleteB = (Athlete*)b;
    if (athleteA->bestResult < athleteB->bestResult) return 1;
    if (athleteA->bestResult > athleteB->bestResult) return -1;
    return 0;
}

void getTopOfBestAthletes(const char* filename, const char* outputFilename, int* numAthletes, int* numBestAthletes) {
    Athlete* athletes = NULL;
    readAthletes(filename, &athletes, numAthletes);

    qsort(athletes, *numAthletes, sizeof(Athlete), compareAthletes);

    printf("Top %d athletes:\n", *numBestAthletes);
    
    for (int i = 0; i < *numBestAthletes && i < *numAthletes; i++) {
        printf("%s - Best Result: %.2f\n", athletes[i].name, athletes[i].bestResult);
    }

    FILE *outFile = openFile(outputFilename, "wb");
  
    fwrite(athletes, sizeof(Athlete), *numBestAthletes, outFile);
    fclose(outFile);

    free(athletes);
}

int main() {
    const char* filename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";

    int numAthletes = 20;
    int numBestAthletes = 5;

    generateTestData(filename, numAthletes);
    getTopOfBestAthletes(filename, outputFilename, &numAthletes, &numBestAthletes);

    return 0;
}