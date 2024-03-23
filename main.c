// #include <stdio.h>
// #include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

// void getBagOfWords(BagOfWords *bag, char *s) {
//     char *p = s;
//     bag->size = 0;

//     while (*p != '\0') {
//         while (*p == ' ') {
//             p++;
//         }

//         if (*p == '\0') {
//             break;
//         }

//         bag->words[bag->size].begin = p;

//         while (*p != ' ' && *p != '\0') {
//             p++;
//         }

//         bag->words[bag->size].end = p;
//         bag->size++;
//     }
// }

// int main() {
//     char input[] = "Hello world from C programming";
//     BagOfWords bag;
//     getBagOfWords(&bag, input);

//     for (int i = bag.size - 1; i >= 0; i--) {
//         for (char *p = bag.words[i].begin; p < bag.words[i].end; p++) {
//             printf("%c", *p);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// // void test_removeNonLetters() {
// //     char source[] = "apple banana cherry";
// //     removeNonLetters(source);
// //     ASSERT_STRING("Hi123", source);
// // }

// // void test() {
// //     test_removeNonLetters() ;
// // }

// // int main() {
// //     test();

// //     return 0;
// // }

// #include <stdio.h>
// #include <string.h>

// char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
//     size_t size = endSource - beginSource;
//     memcpy(beginDestination, beginSource, size);
    
//     return beginDestination + size;
// }

// typedef struct {
//     char word[50]; // Максимальная длина слова - 50 символов, можно изменить при необходимости
// } WordDescriptor;

// int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
//     return strcmp(w1.word, w2.word) == 0;
// }

// int checkLexicographicalOrder(char *sentence) {
//     WordDescriptor currentWord, previousWord = {"\0"};
//     char *token = strtok(sentence, " ");

//     while (token != NULL) {
//         copy(currentWord.word, currentWord.word + strlen(currentWord.word), previousWord.word);
//         copy(token, token + strlen(token), currentWord.word);
//         if (!areWordsEqual(previousWord, currentWord) && strcmp(previousWord.word, currentWord.word) > 0) {
//             return 0;
//         }
//         token = strtok(NULL, " ");
//     }

//     return 1;
// }

// void test_checkLexicographicalOrder() {
//     char s[] = "apple banana cherry";
//     int result = checkLexicographicalOrder(s);
//     if (result == 1) {
//         printf("Y\n");
//     } else {
//         printf("Слова не упорядочены лексикографически.\n");
//     }
// }

// void test() {
//     test_checkLexicographicalOrder();
// }

// int main() {
//     test();

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    int len1 = w1.end - w1.begin;
    int len2 = w2.end - w2.begin;
    
    if (len1 != len2) {
        return 0;
    }
    
    return strncmp(w1.begin, w2.begin, len1) == 0;
}

int checkLexicographicalOrder(char *sentence) {
    WordDescriptor currentWord, previousWord = {NULL, NULL};
    char *token = strtok(sentence, " ");

    while (token != NULL) {
        currentWord.begin = token;
        currentWord.end = token + strlen(token);
        
        if (previousWord.begin != NULL && (strcmp(previousWord.begin, currentWord.begin) > 0 || 
            (strcmp(previousWord.begin, currentWord.begin) == 0 && strcmp(previousWord.end, currentWord.end) > 0))) {
            return 0;
        }
        
        previousWord = currentWord;
        token = strtok(NULL, " ");
    }
 
    return 1;
}

void test_checkLexicographicalOrder() {
    char source[] = "apple banana cherry";
    int number = checkLexicographicalOrder(source);
    char result[2];

    sprintf(result, "%d", number);
    ASSERT_STRING("1", result);
}

void test() {
    test_checkLexicographicalOrder();
}

int main() {
    test();

    return 0;
}