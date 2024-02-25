#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "multidimensional_array.h"
#include "libs/data_structures/matrix/matrix.c"

void swapMinMaxRows(matrix m) {
    position min_position = getMinValuePos(m);
    position max_position = getMaxValuePos(m);

    swapRows(m, min_position.rowIndex, max_position.rowIndex);
}