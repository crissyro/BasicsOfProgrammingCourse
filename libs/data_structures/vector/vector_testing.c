#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.c"
#include "libs/data_structures/vector/vectorVoid.c"

void exampleVectorVoid() {
    vectorVoid vec;

    vec.data = NULL;
    vec.size = 0;
    vec.capacity = 0;
    vec.baseTypeSize = sizeof(int);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    
    pushBack(&v, 5);
    
    assert(v.size == 1);
    assert(v.data[0] == 5);
    
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(10);

    pushBack(&v, 14);
    
    assert(v.size == 11);
    assert(v.data[v.size - 1] == 14);
    
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);

    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        v.data[i] = i;
    }

    assert(*atVector(&v, 2) == 2);
    
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);

    for (int i = 0; i < 5; ++i) {
        v.data[i] = i;
    }

    assert(*atVector(&v, 4) == 4);
    
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(5);

    pushBack(&v, 14);

    assert(*back(&v) == 14);
    
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    
    pushBack(&v, 14);

    assert(*front(&v) == 14);
    
    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}

// int main() {
//     size_t n;
//     scanf("%zd", &n);

//     vectorVoid v = createVectorV(0, sizeof(int));

//     for (int i = 0; i < n; i++) {
//         int x;
//         scanf("%d", &x);

//         pushBackV(&v, &x);
//     }

//     for (int i = 0; i < n; i++) {
//         int x;
//         getVectorValueV(&v, i, &x);

//         printf("%d ", x);
//     }
    
//     return 0;
// }

// int main() {
//     size_t n;
//     scanf("%zd", &n);

//     vectorVoid v = createVectorV(0, sizeof(float));

//     for (int i = 0; i < n; i++) {
//         float x;
//         scanf("%f", &x);

//         pushBackV(&v, &x);
//     }

//     for (int i = 0; i < n; i++) {
//         float x;
//         getVectorValueV(&v, i, &x);

//         printf("%f ", x);
//     }

//     return 0;
// }