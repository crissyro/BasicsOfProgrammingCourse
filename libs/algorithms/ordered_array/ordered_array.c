#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ordered_array.h"

typedef struct ordered_array_set {
    int * data ;
    size_t size ;
    size_t capacity ;
} ordered_array_set ;

ordered_array_set ordered_array_set_create(size_t capacity) {
    ordered_array_set set;
    set.data = (int*)malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;
    return set;
}

ordered_array_set ordered_array_set_create_from_array(const int* a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    memcpy(set.data, a, size * sizeof(int));
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
 
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        for (size_t j = 0; j < set.size; j++) {
            if (subset.data[i] == set.data[j]) {
                return true;
            }
        }
    }

    return false;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set -> size < set -> capacity);
}

void ordered_array_set_insert(ordered_array_set* set, int value) {
    ordered_array_set_isAbleAppend(set);
    size_t i = set->size;

    while (i > 0 && set->data[i - 1] > value) {
        set->data[i] = set->data[i - 1];
        i--;
    }

    append_(set -> data, &set -> size, value);
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t index = ordered_array_set_in(set, value);
 
    if (index != set->size)
        deleteByPosSaveOrder_(set->data, &set->size, index);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            set.data[k] = set1.data[i];
            i++;
        } else if (set1.data[i] > set2.data[j]) {
            set.data[k] = set2.data[j];
            j++;
        } else {
            set.data[k] = set1.data[i];
            i++;
            j++;
        }
        k++;
    }
    while (i < set1.size) {
        set.data[k] = set1.data[i];
        i++;
        k++;
    }
    while (j < set2.size) {
        set.data[k] = set2.data[j];
        j++;
        k++;
    }

    set.size = k;

    return set;
} 

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    size_t new_capacity = set1.size < set2.size ? set1.size : set2.size;
    ordered_array_set set = ordered_array_set_create(new_capacity);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            i++;
        } else if (set1.data[i] > set2.data[j]) {
            j++;
        } else {
            set.data[k] = set1.data[i];
            i++;
            j++;
            k++;
        }
    }
    
    set.size = k;

    return set;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size);

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            set.data[k] = set1.data[i];
            i++;
            k++;
        } else if (set1.data[i] > set2.data[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < set1.size) {
        set.data[k] = set1.data[i];
        i++;
        k++;
    }

    set.size = k;

    return set;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set universum = ordered_array_set_union(set1, set2);
    ordered_array_set intersection = ordered_array_set_intersection(set1, set2);
 
    ordered_array_set symmetric = ordered_array_set_complement(intersection, universum);
 
    ordered_array_set_delete(intersection);
    ordered_array_set_delete(universum);
 
    return symmetric;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set new_set = ordered_array_set_create(universumSet.size);
 
    size_t i = 0;
    size_t j = 0;

    while (i < universumSet.size) {
        if (j < set.size && universumSet.data[i] == set.data[j]) {
            i++;
            j++;
        } else {
            new_set.data[new_set.size] = universumSet.data[i];
            new_set.size++;
            i++;
        }
    }
 
    return new_set;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");

    if (set.size != 0) {
        for (size_t i = 0; i < set.size; i++) {
            printf("%d ", set.data[i]);
        }
    }

    printf("}\n");

}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}