#ifndef INC_STRING_PROCESSING_H
#define INC_STRING_PROCESSING_H

#include <stdio.h>

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

// Удаляет из строки все пробельные символы
void removeNonLetters(char *s) ;

// Преобразовывает строку, оставляя только один символ
// в каждой последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s) ;

// Функция getWord вернёт значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word) ;




#endif