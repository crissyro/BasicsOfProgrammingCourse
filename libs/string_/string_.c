#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
// #include <string.h>
#include "string_.h"

size_t strlen1(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}

size_t strlen2(char *s) {
    int i = 0;
    while (*s != '\0') {
        i++;
        s++;
    }

    return i;
}

size_t strlen_(const char *begin) {
    const char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }

    return begin;
}

char* findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }

    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend) {
        if (isspace(*rbegin)) {
            return rbegin;
        }

        rbegin--;
    }

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);
    
    return beginDestination + size;
}

char* copy2(const char *beginSource, const char *endSource, char *beginDestination) {
    while (beginSource < endSource) {
        *beginDestination = *beginSource;
        beginSource++;
        beginDestination++;
    }
    
    *beginDestination = '\0';
    return beginDestination;
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource <= endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }

        beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource >= rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }

        rbeginSource--;
    }
    
    return beginDestination;
}

int is_delim(char c, char *delim) {
    while(*delim != '\0') {
        if(c == *delim) {
            return 1;
        }

        delim++;
    }

    return 0;
}

char *strtok_(char *inputString, char *delimiters) {
    static char *nextToken; 
    if (!inputString) {
        inputString = nextToken;
    }

    if (!inputString) {
        return NULL;
    }

    while (1) {
        if (is_delim(*inputString, delimiters)) {
            inputString++;
            continue;
        }

        if (*inputString == '\0') {
            return NULL; 
        }

        break;
    }

    char *tokenStart = inputString;
    while (1) {
        if (*inputString == '\0') {
            nextToken = inputString;
            return tokenStart;
        }

        if (is_delim(*inputString, delimiters)) {
            *inputString = '\0';
            nextToken = inputString + 1;
            return tokenStart;
        }

        inputString++;
    }
}

int strncmp_( const char * s1, const char * s2, size_t n ) {
    while ( n && *s1 && ( *s1 == *s2 ) ) {
        ++s1;
        ++s2;
        --n;
    }

    if ( n == 0 ){
        return 0;
    } else {
        return ( *(unsigned char *)s1 - *(unsigned char *)s2 );
    }
}

char* strstr_(const char * mainStr, const char * subStr) {
    char *s1, *s2;
 
    while( *mainStr != NULL) {
        if(*mainStr == *subStr) {
            s1 = mainStr;
            s2 = subStr;
 
            while (*s1 && *s2 ) {
                if(*s1 != *s2)
                    break;
 
                s1++;
                s2++;
            }
            
            if (*s2 == NULL) {
                return mainStr;
            }
        }
 
        mainStr++;
    }
 
    return NULL;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

char* getEndOfString(char* s) {
    char* end = s;
    
    while(*end) {
        end++;
    }
        
    end--;
    
    return end;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = rbegin;
    word->begin = findSpaceReverse(rbegin, rend);

    if (word->begin == rend)
        return 0;

    word->begin = findNonSpaceReverse(word->begin, rend);
    
    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}