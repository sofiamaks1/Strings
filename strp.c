
#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

size_t Str_copy(const char *pcSrc, char *src)
{
    assert(pcSrc != NULL && src != NULL);
    while (*pcSrc != '\0') {
            *src = *pcSrc;
            src++;
            pcSrc++;
        }
    *src = '\0';
    return Str_getLength(src);
}

size_t Str_concat(char *pcSrc, const char *subSrc)
{
    assert(pcSrc != NULL && subSrc != NULL);
    size_t uLength = Str_getLength(pcSrc);
    char *pcSrcEnd = pcSrc + uLength;
    
    while (*subSrc != '\0') {
        *pcSrcEnd = *subSrc;
        pcSrcEnd++;
        subSrc++;
        }
    
    *pcSrcEnd = '\0';
    return Str_getLength(pcSrc);
}

size_t Str_compare(const char *pcSrc, const char *subSrc)
{
    assert(pcSrc != NULL && subSrc != NULL);
    while(*pcSrc != '\0' && *subSrc != '\0') {
        if (*pcSrc != *subSrc) {
            return *pcSrc - *subSrc;
        }
        pcSrc++;
        subSrc++;
    }

    return (size_t)*pcSrc - (size_t)*subSrc;
}

size_t Str_search(const char *pcSrc, const char *subSrc)
{
    assert(pcSrc != NULL && subSrc != NULL);
    size_t uLength = Str_getLength(pcSrc);
    size_t sLength = Str_getLength(subSrc);
    assert(uLength >= sLength);
    size_t found = SIZE_MAX;
    
    while (*subSrc != '\0') {
        if (*pcSrc == *subSrc) {
            found = *pcSrc;
        }
        pcSrc++;
        subSrc++;
    }
    return found;
}

