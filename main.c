#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.c"

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

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}