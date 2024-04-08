#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;      // указатель на элементы вектора
    size_t size;    // размер вектора
    size_t capacity;// вместимость вектора
} vector;

void check_Memory_(vector *v) {
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}


vector createVector(size_t n) {
    vector vec;
    vec.data = (int *)malloc(n * sizeof(int));
    vec.size = 0;
    vec.capacity = n;

    check_Memory_(&vec);

    return vec;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->capacity = 0;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
        v->data = (int*)realloc(v->data, sizeof(int)*v->size);
    } else if (newCapacity > v->capacity) {
        v->capacity = newCapacity;
        v->data = (int*)realloc(v->data, sizeof(int)*v->capacity);
        check_Memory_(&v);
    }
}


void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    if (!isFull(v)) {
        v->data = (int*)realloc(v->data, sizeof(int)*v->size);
        v->capacity = v->size;
    }
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0; 
    v->capacity = 0;
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
        fprintf(stderr, "Vector is empty");
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
    return v->data + v->size - 1;
}

int* front(vector *v) {
    return v->data;
}
