#include <stdio.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                         // например, если вектор хранит int -
                         // то поле baseTypeSize = sizeof(int)
                         // если вектор хранит float -
                         // то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid vec;
    vec.data = NULL;
    vec.size = 0;
    vec.capacity = 0;
    vec.baseTypeSize = baseTypeSize;

    if (n > 0) {
        vec.data = malloc(n * baseTypeSize);

        if (vec.data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        vec.size = n;
        vec.capacity = n;
    }

    return vec;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->capacity = 0;
        v->size = 0;
        v->baseTypeSize = 0;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    } else if (newCapacity > v->capacity) {
        void *new_data = realloc(v->data, newCapacity * v->baseTypeSize);

        if (new_data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->data = new_data;
        v->capacity = newCapacity;
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    v->data = realloc(v->data, v->size * v->baseTypeSize);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "Index out of range");
        exit(1);
    }

    char *source = (char *)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "Index out of range");
        exit(1);
    }

    char *destination = (char *)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->size == v->capacity) {
        size_t newCapacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        reserveV(v, newCapacity);
    }
    char *destination = (char *)v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    v->size++;
}