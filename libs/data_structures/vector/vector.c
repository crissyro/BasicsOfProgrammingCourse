#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    } else if (newCapacity > v->capacity) {
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size == v->capacity) {
        size_t newCapacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        reserve(v, newCapacity);
    }

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] does not exist", index);
        exit(1);
    }

    return &(v->data[index]);
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    return &(v->data[v->size - 1]);
}

int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    } 

    return &(v->data[0]);
}