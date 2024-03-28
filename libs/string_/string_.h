#ifndef INC_STRING__H
#define INC_STRING__H

#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

// Возвращает количество символов в строке 
size_t strlen1(char *s) ;

// Возвращает количество символов в строке 
size_t strlen2(char *s) ;

// Возвращает количество символов в строке 
size_t strlen_(const char *begin) ;

// Возвращает указатель на первый элемент с кодом ch, 
// расположенным на ленте памяти между адресами begin и end не включая end.
// Если символ не найден, возвращается значение end.
char* find(char *begin, char *end, int ch) ;

// Возвращает указатель на первый символ, отличный от пробельных, 
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа.
char* findNonSpace(char *begin) ;

// Возвращает указатель на первый пробельный символ, 
// расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ
char* findSpace(char *begin) ;

// Возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символ
// строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки). 
// Если символ не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend) ;

// Возвращает указатель на первый пробельный символ справа, 
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend. 
// Если символ не найден, возвращается адрес rend.
char* findSpaceReverse(char *rbegin, const char *rend) ;

// Проверяет строки на равенство
int strcmp_(const char *lhs, const char *rhs) ;

// Записывает по адресу beginDestination фрагмент памяти, 
// начиная с адреса beginSource до endSource.
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char* copy(const char *beginSource, const char *endSource, char *beginDestination) ;

// Записывает по адресу beginDestination фрагмент памяти, 
// начиная с адреса beginSource до endSource.
// Возвращает указатель на последний фрагмент памяти в destination, на '/0'.
char* copy2(const char *beginSource, const char *endSource, char *beginDestination) ;

// Записывает по адресу beginDestination элементы из фрагмента памяти 
// начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f. 
// Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) ;

// Записывает по адресу beginDestination элементы из фрагмента памяти 
// начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f. 
// Функция возвращает значение beginDestination по окончанию работы.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) ;

// Если символ c совпадает с каким-либо символом из delim, 
// функция возвращает 1, указывая на то, что символ c является разделителем. 
// В противном случае возвращается 0.
int is_delim(char c, char *delim) ;

// Функция используется для извлечения следующей подстроки
// из строки inputString, используя набор разделителей delimiters.
char *strtok_(char *inputString, char *delimiters) ;

// Функция реализует сравнение двух строк до определенной длины n.
int strncmp_( const char * s1, const char * s2, size_t n ) ;

// Функция реализует поиск подстроки subStr в строке mainStr
char* strstr_(const char * mainStr, const char * subStr) ;

// Функция вернёт значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word) ;

// Функция начинает считывание с переданного указателя s и 
// перемещается по строке до тех пор, пока не достигнет символа завершающего нуля. 
// Возвращает указатель на предыдущий символ, который является последним символом строки перед '\0'.
char* getEndOfString(char* s) ;

// Функция для считывания слова с конца строки
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) ;

// Выполняет операцию сортировки символов в строке, 
// перемещая цифры в начало строки
void digitToStart(WordDescriptor word) ;

// Функция для тестирования
void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) ;

#endif