#include "libs/algorithms/unordered_array/unordered_array.c"
#include "libs/algorithms/array/array.c"

// Определи маршрут (1056A)
#include <stdio.h>
 
int main() {
    int count_stops;
    scanf("%d", &count_stops);
 
    int array[101] = {0};
 
    for (int i = 0; i < count_stops; i++) {
        int count_tram_routes;
        scanf("%d", &count_tram_routes);
 
        for (int j = 0; j < count_tram_routes; j++) {
            int number_route;
            scanf("%d", &number_route);
 
            array[number_route]++;
        }
    }
 
    for (int i = 1; i <= 100; i++) {
        if (array[i] == count_stops) {
            printf("%d ", i);
        }
 
    }
 
    return 0;
}

// Пропущенная серия (440A)
#include <stdio.h>

int main() {
    int number_series;
    scanf("%d", &number_series);

    int a[number_series-1], sum = 0, total_amount = 0;
     
    for (int i = 0; i < number_series-1; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for (int i = 1; i <= number_series; i++) {
        total_amount += i;
    }

    int number_last_series = total_amount-sum;

    printf("%d", number_last_series);
    
    return 0;
}

// Перестановка букв (1093B)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
void swap(char *a, char *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int main() {
    int requests;
    scanf("%lld", &requests);
 
    for (int i = 0; i < requests; i++) {
        char string[1000];
        scanf("%s", string);
 
        bool flag = false;
        int count_elements = strlen(string);
 
        for (int j = 1; j < count_elements; j++) {
            if (string[j] != string[0]) {
                swap(&string[j], &string[count_elements - 1]);
                flag = true;
                break;
            }
        }
 
        if (!flag) {
            printf("-1\n");
        } else {
            printf("%s\n", string);
        }
    }
 
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
void swap(char *a, char *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int main() {
    int requests;
    scanf("%lld", &requests);
 
    for (int i = 0; i < requests; i++) {
        char string[1000];
        scanf("%s", string);
 
        bool flag = false;
        int count_elements = strlen(string);
 
        for (int j = 1; j < count_elements; j++) {
            if (string[j] != string[0]) {
                swap(&string[j], &string[count_elements - 1]);
                flag = true;
                break;
            }
        }
 
        if (!flag) {
            printf("-1\n");
        } else {
            printf("%s\n", string);
        }
    }
 
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
void swap(char *a, char *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int main() {
    int requests;
    scanf("%lld", &requests);
 
    for (int i = 0; i < requests; i++) {
        char string[1000];
        scanf("%s", string);
 
        bool flag = false;
        int count_elements = strlen(string);
 
        for (int j = 1; j < count_elements; j++) {
            if (string[j] != string[0]) {
                swap(&string[j], &string[count_elements - 1]);
                flag = true;
                break;
            }
        }
 
        if (!flag) {
            printf("-1\n");
        } else {
            printf("%s\n", string);
        }
    }
 
    return 0;
}

// Тихий класс (1166A)
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 21
#define ALPHABET_SIZE 26

int main() {
    int n;
    scanf("%d", &n);

    int count[ALPHABET_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);
        count[name[0] - 'a']++;
    }

    int min_pairs = 0;
    int division1, division2;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        division1 = count[i] / 2;
        division2 = (count[i] + 1) / 2;
        min_pairs += (division1 * (division1 - 1) / 2) + (division2 * (division2 - 1) / 2);
    }

    printf("%d\n", min_pairs);

    return 0;
}

// Щедрый Кефа (841A)
#include <stdio.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
 
int main() {
    int number_balls, number_friends;
    scanf("%d %d", &number_balls, &number_friends);

    int count[ALPHABET_SIZE] = {0};

    char balls[number_balls];
    scanf("%s", balls);

    for (int i = 0; i < number_balls; i++) {
        count[balls[i] - 'a']++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (count[i] > number_friends){
            printf("NO\n");
			return 0;
        }
    }

    printf("YES\n");

    return 0;
}

// Перекраска собачек (1025A)
#include <stdio.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
 
int main() {
    int number_puppies;
    scanf("%d", &number_puppies);

    char colors[number_puppies];
    scanf("%s", colors);
 
    int count[ALPHABET_SIZE] = {0};

    for (int i = 0; i < number_puppies; i++) {
        count[colors[i] - 'a']++;
    }
 
    bool flag = false;
    int check = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (count[i] > 1) {
            flag = true;
        }
        
        if (count[i] == 0) {
            check++;
        }
    }
 
    if (flag || check == 25) {
        printf("YES");
    } else {
        printf("NO");
    }
 
    return 0;
}



// Ступени (1011A)
#include <stdio.h>
 
#define ALPHABET_SIZE 26
 
int main() {
    int number_available_steps, number_required_steps;
    scanf("%d %d", &number_available_steps, &number_required_steps);
 
    char string[number_available_steps];
    scanf("%s", string);
 
    int count[ALPHABET_SIZE] = {0};
 
    for (int i = 0; i < number_available_steps; i++) {
        count[string[i] - 'a']++;
    }
 
    int min_weight = 0;
 
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count[i] > 0 && number_required_steps > 0) {
            i++;
            min_weight += i;
            number_required_steps--;
        }
    }
 
    if (number_required_steps == 0) {
        printf("%d\n", min_weight);
    } else {
        printf("%d\n", -1);
    }
 
    return 0;
}

// Башни (37A)
#include <stdio.h>

#define MAX_NUMBER_BLOCKS 1001
 
int main() {
    int number_blocks;
    scanf("%d", &number_blocks);
 
    int lengths_blocks[MAX_NUMBER_BLOCKS] = {0};
 
    int max_height = 0, number_towers = 0;

    for (int i = 0; i < number_blocks; i++) {
        int length;
        scanf("%d", &length);

        lengths_blocks[length]++;

        if (lengths_blocks[length] > max_height) {
            max_height = lengths_blocks[length];
        }

        if (lengths_blocks[length] == 1) {
            number_towers++;
        }
    }
 
    printf("%d %d", max_height, number_towers);
 
    return 0;
}

// Бейджик (1020B)
#include <stdio.h>
 
#define MAX_NUMBER_STUDENTS 1001
 
int main() {
    int number_students;
    scanf("%d", &number_students);
 
    int array[number_students];
 
    for (int i = 1; i <= number_students; i++) {
        scanf("%d", &array[i]);
    }
 
    int holes_in_badges[MAX_NUMBER_STUDENTS] = {0};
 
    for (int i = 1; i <= number_students; i++) {
        int j = i;
        while (holes_in_badges[j] != i) {
            holes_in_badges[j] = i;
            j = array[j];
        }
 
        printf("%d ", j);
    }
 
    return 0;
}

// Разнообразие - это хорошо (672B)
#include <stdio.h>
 
int main() {
    int length_string;
    scanf("%d", &length_string);

    char string[length_string + 1];
    scanf("%s", string);

    int count = 0;

    for(int i = 0; i < length_string; i++){
        for(int j = i + 1; j < length_string; j++){
            if (string[i] == string[j]) {
                count++;
                break;
            }
        }
    }

    if (length_string > 26){
        printf("-1");
        return 0;
    }

    printf("%d", count);
    
    return 0;
}

// Игра: Банковские карты (777B)
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_COUNT 1001
 
int comp(const void *p1, const void *p2) {
    return *((char *) p1) - *((char *) p2);
}
 
int main() {
    int number_digits_in_cards;
    scanf("%d\n", &number_digits_in_cards);

    char sherlock_card[MAX_COUNT];
    char moriarty_card[MAX_COUNT];

    scanf("%s\n %s", sherlock_card, moriarty_card);
 
    qsort(sherlock_card, number_digits_in_cards, sizeof(char), comp);
    qsort(moriarty_card, number_digits_in_cards, sizeof(char), comp);
 
    int number_clicks = 0;
    int j = 0;

    for (int i = 0; i < number_digits_in_cards; i++) {
        while (j < number_digits_in_cards && sherlock_card[i] > moriarty_card[j]) {
            j++;
        }
        
        if (j >= number_digits_in_cards) {
            number_clicks++;
        }

        j++;
    }
 
    printf("%d\n", number_clicks);
 
    number_clicks = 0;

    for (int i = 0, j = 0; i < number_digits_in_cards; i++) {
        while (j < number_digits_in_cards && sherlock_card[i] >= moriarty_card[j]) {
            j++;
        }

        if (j < number_digits_in_cards) {
            number_clicks++;
        }

        j++;
    }
 
    printf("%d\n", number_clicks);
 
    return 0;
}

// Противоположности притягиваются (131B)
#include <stdio.h>
 
int main(){
    int number_clients;
    scanf("%d", &number_clients);

    long long array[25] = {0};
    int count = 0;
    long long sum = 0;   

    for (int i=0; i < number_clients; i++){
        int client_parameter;
        scanf("%d", &client_parameter);

        if (client_parameter == 0) {
            sum += count;
            count++;
        } else {
            array[client_parameter+10]++;
        }
    }

    for (int i=0; i < 10; i++){		
        sum = sum + array[i] * array[20-i];
    }

    printf("%lld", sum);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
 
// #define ALPHABET_SIZE 26
 
// typedef struct unordered_array_set {
//     int *data;
//     size_t size;
//     size_t capacity;
// } unordered_array_set;
 
// unordered_array_set unordered_array_set_create(size_t capacity) {
//     unordered_array_set set;
//     set.data = (int*)calloc(capacity * sizeof(int));
//     set.size = 0;
//     set.capacity = capacity;
//     return set;
// }
 
// int main() {
//     int number_puppies;
//     scanf("%d", &number_puppies);
 
//     char colors[number_puppies + 1]; 
//     scanf("%s", colors);
 
//     unordered_array_set count = unordered_array_set_create(ALPHABET_SIZE);
 
//     for (int i = 0; i < number_puppies; i++) {
//         count.data[colors[i] - 'a']++;
//         count.size++;
//     }
 
//     bool duplicate_color = false;
//     int missing_color_count = 0;
 
//     for (int i = 0; i < ALPHABET_SIZE; i++){
//         if (count.data[i] > 1) {
//             duplicate_color = true;
//         }
        
//         if (count.data[i] == 0) {
//             missing_color_count++;
//         }
//     }
 
//     if (duplicate_color || missing_color_count == 25) {
//         printf("YES");
//     } else {
//         printf("NO");
//     }
    
//     unordered_array_set_delete(count);
 
//     return 0;
// }
 
// int main() {
//     int number_clients;
//     scanf("%d", &number_clients);
 
//     unordered_array_set array_set = unordered_array_set_create(25);
 
//     int count = 0;
//     long long sum = 0;
 
//     for (int i = 0; i < number_clients; i++) {
//         int client_parameter;
//         scanf("%d", &client_parameter);
 
//         if (client_parameter == 0) {
//             sum += count;
//             count++;
//         } else {
//             array_set.data[client_parameter + 10]++;
//         }
//     }
 
//     for (int i = 0; i < 10; i++) {
//         sum = sum + array_set.data[i] * array_set.data[20 - i];
//     }
 
//     printf("%lld", sum);
 
//     unordered_array_set_delete(array_set);
 
//     return 0;
// }


// #define MAX_VALUE_OF_PARAMETR 25
 
// int main() {
//     int number_clients;
//     scanf("%d", &number_clients);
 
//     unordered_array_set array_set = unordered_array_set_create(MAX_VALUE_OF_PARAMETR);
 
//     int count = 0;
//     long long sum = 0;
 
//     for (int i = 0; i < number_clients; i++) {
//         int client_parameter;
//         scanf("%d", &client_parameter);
 
//         if (client_parameter == 0) {
//             sum += count;
//             count++;
//         } else {
//             int positive_index = client_parameter + 10;
//             array_set.data[positive_index]++;
//         }
//     }
    
//     int max_positive_number = 10;

//     for (int i = 0; i < max_positive_number; i++) {
//         sum = sum + array_set.data[i] * array_set.data[20 - i];
//     }
 
//     printf("%lld", sum);
 
//     unordered_array_set_delete(array_set);
 
//     return 0;
// }

// int main() {
//     int t;
//     scanf("%d", &t);
 
//     for (int t_sets = 0; t_sets < t; t_sets++) {
//         unordered_array_set amount = unordered_array_set_create(26);
//         for (int i = 0; i < 26; i++) {
//             amount.data[i] = 0;
//             amount.size++;
//         }
 
//         char str[1000];
//         scanf("%s", str);
 
//         size_t size_str = strlen(str);
//         for (size_t i = 0; i < size_str; i++) {
//             size_t char_index = str[i] - 97;
//             amount.data[char_index]++;
//         }
 
//         bool is_palindrome = true;
//         for (size_t i = 0; i < 26; i++) {
//             if (amount.data[i] != 0 && amount.data[i] != size_str)
//                 is_palindrome = false;
//         }
 
//         if (is_palindrome)
//             printf("-1\n");
//         else {
//             for (int i = 0; i < 26; i++)
//                 for (int j = 0; j < amount.data[i]; j++)
//                     printf("%c", 'a' + i);
//             printf("\n");
//         }
//     }
 
//     return 0;
// }