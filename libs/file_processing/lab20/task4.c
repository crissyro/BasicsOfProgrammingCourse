#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DOMAINS 100

typedef struct Domain {
    char *name;
    int count;
} Domain;

Domain getDomain(char *s) {
    Domain domain;
    
    sscanf(s, "%d %s", &domain.count, domain.name);

    return domain;
}

void getSubDomain(Domain *arrayDomains, int *sizeArrayDomains, char *name, int count) {
    for (int i = 0; i < *sizeArrayDomains; i++) {
        if (!strcmp(arrayDomains[i].name, name)) {
            arrayDomains[i].count += count;
            return;
        }
    }

    arrayDomains[*sizeArrayDomains].count = count;
    arrayDomains[*sizeArrayDomains].name = strdup(name);
    (*sizeArrayDomains)++;
}

void getAllDomain(Domain *arrayDomains, int *sizeArrayDomains, Domain domain) {
    char *domainName = domain.name;

    while (*domainName != '\0') {
        if (*domainName == '.') {
            getSubDomain(arrayDomains, sizeArrayDomains, domainName + 1, domain.count);
        }

        domainName++;
    }
    
    getSubDomain(arrayDomains, sizeArrayDomains, domain.name, domain.count);
}

void domainProcessing(char *cpdomains[], int length, Domain arrayDomains[], int *size) {
    for (int i = 0; i < length; i++) {
        Domain domain = getDomain(cpdomains[i]);
        getAllDomain(arrayDomains, size, domain);
    }
}

void printDomain(Domain arrayDomains[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %s\n", arrayDomains[i].count, arrayDomains[i].name);
        free(arrayDomains[i].name);
    }
}

int main() {
    char *cpdomains[] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Domain arrayDomains[MAX_NUM_DOMAINS];
    int length = sizeof(cpdomains) / sizeof(cpdomains[0]);
    int size = 0;

    domainProcessing(cpdomains, length, arrayDomains, &size);
    printDomain(arrayDomains, size);

    return 0;
}