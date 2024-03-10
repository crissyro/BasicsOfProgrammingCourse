#include <stdio.h>
#include <ctype.h>
#include "srting_.h"

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
    while (*begin != ' ' && *begin != '\0') {
        begin++;
    }

    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && isspace(*rbegin)) {
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