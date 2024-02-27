#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *Str_copy(char pcSrc[], const char src[])
{
    assert(pcSrc != NULL && src != NULL);
    size_t uLength = Str_getLength(src);

    for (size_t i = 0; i < uLength; i++) {
        pcSrc[i] = src[i];
    }
    pcSrc[uLength] = '\0';

    return pcSrc;
}

char *Str_concat(char pcSrc[], const char subSrc[])
{
    assert(pcSrc != NULL && subSrc != NULL);
    size_t uLength = Str_getLength(pcSrc);
    size_t sLength = Str_getLength(subSrc);

    size_t totalLength = uLength + sLength;


    for (size_t i = 0; i < sLength; i++) {
        pcSrc[uLength + i] = subSrc[i];
    }
    pcSrc[totalLength] = '\0';
    return pcSrc;
}

size_t Str_compare(const char pcSrc[], const char subSrc[])
{
    assert(pcSrc != NULL && subSrc != NULL);
    size_t i = 0;

    while (pcSrc[i] != '\0' && subSrc[i] != '\0') {
        if (pcSrc[i] != subSrc[i]) {
            size_t res =  pcSrc[i] - subSrc[i];
            return (size_t) res;
        }
        i++;
    }
    size_t res =  pcSrc[i] - subSrc[i];
    return (size_t) res;
}


char *Str_search(const char pcSrc[], const char subSrc[])
{
    
    assert(pcSrc != NULL && subSrc != NULL);
    char *res;
    if (subSrc[0] == '\0') {
        return (char *)pcSrc;
    }
    for (size_t i = 0; pcSrc[i] != '\0'; i++) {
        size_t j = 0;
        if (pcSrc[i] != subSrc[j]) {
            continue;
        }
        res = (char *)&pcSrc[i];
        if (subSrc[j] == '\0') return res;
    }
    return NULL;
}
