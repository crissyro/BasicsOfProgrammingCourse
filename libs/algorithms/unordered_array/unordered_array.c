#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "libs/algorithms/unordered_array/unordered_array.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set set;
    set.data = (int*)malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;
    return set;
}

unordered_array_set unordered_array_set_create_from_array(const int* a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    memcpy(set.data, a, size * sizeof(int));
    set.size = size;
    return set;
}

size_t linearSearch_ (const int *a, const size_t n, int x ) {
    for (size_t i = 0; i < n; i++)
        if ( a[i] == x )
            return i ;
    return n ;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set -> data, set -> size, value);
}

size_t unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        for (size_t j = 0; j < set.size; j++) {
            if (subset.data[i] == set.data[j]) {
                return j;
            }
        }
    }

    return set.size;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    return set1.size == set2.size && memcmp(set1.data, set2.data, set1.size * sizeof(set1.data[0])) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set -> size < set -> capacity);
}

void unordered_array_set_insert(unordered_array_set* set, int value) {
    if (unordered_array_set_in(set, value) == set -> size) {
        unordered_array_set_isAbleAppend(set);
        append_(set -> data, &set -> size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set* set, int value) {
    size_t index_value = unordered_array_set_in(set, value);
 
    if (index_value < set -> size) {
        set->data[index_value] = set->data[set->size - 1];
        (set->size)--;
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);

    for (size_t i = 0; i < set1.size; i++) {
        append_(set.data, set.size, set1.data[i]);
    }
    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&set, set2.data[i]);
    }

    return set;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    size_t new_capacity = set1.size < set2.size ? set1.size : set2.size;
    unordered_array_set set = unordered_array_set_create(new_capacity);
 
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            unordered_array_set_insert(&set, set1.data[i]);
 
    return set;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size);
 
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            unordered_array_set_insert(&set, set1.data[i]);
 
    return set;
}


unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set new_arr = unordered_array_set_create(set.capacity + universumSet.capacity);
    for (int i = 0; i < universumSet.size; i++) {
        bool found = false;
        for (int j = 0; j < set.size; j++) {
            if (universumSet.data[i] == set.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unordered_array_set_insert(&new_arr, universumSet.data[i]);
        }
    }

    return new_arr;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set universum = unordered_array_set_union(set1, set2);
    unordered_array_set intersection = unordered_array_set_intersection(set1, set2);
 
    unordered_array_set symmetric = unordered_array_set_complement(intersection, universum);
 
    unordered_array_set_delete(intersection);
    unordered_array_set_delete(universum);
 
    return symmetric;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");

    if (set.size != 0) {
        for (size_t i = 0; i < set.size; i++) {
            printf("%d ", set.data[i]);
        }
    }

    printf("}\n");

}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}