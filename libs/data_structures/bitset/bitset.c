#include <stdio.h>
#include <stdint.h>
#include "bitset.h"

typedef struct bitset {
    uint32_t values ;
    uint32_t maxValue ;
} bitset ;

bitset bitset_create(unsigned setMaxValue) {
    assert (setMaxValue < 32);
    return (bitset) {0, setMaxValue};
}
bool bitset_in(bitset set, unsigned value) {
    return set.values & (1 << value);
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (subset.values & set.values) == subset.values && subset.maxValue <= set.maxValue;
}

void bitset_insert(bitset* set, unsigned int value) {
    if (value <= set->maxValue) {
        set->values |= (1 << value);
    }
}

void bitset_deleteElement(bitset* set, unsigned int value) {
    if (value <= set->maxValue) {
        set->values &= ~(1 << value);
    }
}

bitset bitset_union(bitset set1, bitset set2) {
    bitset set3 = {set1.values | set2.values , set1.maxValue | set2.maxValue};
    return set3;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    bitset set3 = {set1.values & ~set2.values , set1.maxValue & ~set2.maxValue};
    return set3;
}


bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    bitset set3 = {set1.values ^ set2.values , set1.maxValue ^ set2.maxValue};
    return set3;
}

bitset bitset_complement(bitset set) {
    bitset result;
    result.values = ~(set.values);
    result.maxValue = set.maxValue;
    return result;
}

void bitset_print(bitset set) {
    printf("{ ");
    for (int i = 0; i <= set.maxValue; i++) {
        if (set.values & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}
