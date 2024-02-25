
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

char *Str_copy(char *pcSrc, const char *src)
{
    assert(pcSrc != NULL && src != NULL);
    while (*src != '\0') {
            *pcSrc = *src;
            src++;
            pcSrc++;
        }
    *pcSrc = '\0';
    return pcSrc;
}

char *Str_concat(char *pcSrc, const char *subSrc)
{
    assert(pcSrc != NULL && subSrc != NULL);
    char *pcSrcEnd = pcSrc;
    //to find the end of pcSrc
    while (*pcSrcEnd != '\0') {
        pcSrcEnd++;
    }

    while (*subSrc != '\0') {
        *pcSrcEnd = *subSrc;
        pcSrcEnd++;
        subSrc++;
    }

    *pcSrcEnd = '\0';
    return pcSrc;
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

    return *pcSrc - *subSrc;
}

//char *Str_search(const char pcSrc[], const char subSrc[])
//{
//
//    assert(pcSrc != NULL && subSrc != NULL);
//    size_t uLength = Str_getLength(pcSrc);
//    size_t sLength = Str_getLength(subSrc);
//    char *res;
//    if (sLength == 0) {
//        return (char *)pcSrc;
//    }
//    size_t j = 0;
//
//    for (size_t i = 0; i < uLength; i++) {
//        if (pcSrc[i] != subSrc[j]) {
//            continue;
//        }
//        res = (char *)&pcSrc[i];
//        while (j < sLength) {
//            if (subSrc[j] == '\0') return res;
//        }
//    }
//    return NULL;
//}
//


char *Str_search(const char *pcSrc, const char *subSrc)
{
    assert(pcSrc != NULL && subSrc != NULL);

    size_t sLength = Str_getLength(subSrc);
    if (sLength == 0) {
        return (char *)pcSrc;
    }

    while (*pcSrc != '\0') {
        const char *pcTempo = pcSrc; // to keep track ofstart of the match
        const char *subTempo = subSrc;
        
        while (*subTempo == *pcTempo && *subTempo != '\0') {
            pcTempo++;
            subTempo++;
        }
        
        // when the entire substring matching
        if (*subTempo == '\0') {
            return (char *)pcSrc;
        }
    
        pcSrc++;
    }
    return NULL;
}

