#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    int *data;      // указатель на элементы вектора
    size_t size;    // размер вектора
    size_t capacity;// вместимость вектора
} vector;

vector createVector(size_t n) {
    vector vec;
    vec.data = NULL;
    vec.size = 0;
    vec.capacity = 0;

    if (n > 0) {
        vec.data = (int *)malloc(n * sizeof(int));
        if (vec.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        vec.size = n;
        vec.capacity = n;
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->capacity = 0;
        v->size = 0;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    } else {
        int *new_data = (int *)realloc(v->data, newCapacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = new_data;
        v->capacity = newCapacity;
    }
}


void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int *)realloc(v->data, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0; 
    v->capacity = 0;
}