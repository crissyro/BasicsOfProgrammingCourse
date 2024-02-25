add_library(data_structures
        bitset/bitset.c
        vector/vector.c
        vector/vectorVoid.c
        matrix/matrix.c
        multidimensional_array/multidimensional_array.c
)

target_link_libraries(data_structures algorithms)