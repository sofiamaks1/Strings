//
//  stra.c
//  StringModule
//
//  Created by Sofia Makovetska on 21.02.2024.
//

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>


size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

size_t Str_copy(const char pcSrc[], char src[])
{
    assert(pcSrc != NULL && src != NULL);
    size_t uLength = Str_getLength(pcSrc);

    for (size_t i = 0; i < uLength; i++) {
        src[i] = pcSrc[i];
    }
    src[uLength] = '\0';

    return uLength;
}

size_t Str_concat(char pcSrc[], const char subSrc[])
{
    assert(pcSrc != NULL && subSrc != NULL);
    size_t uLength = Str_getLength(pcSrc);
    size_t sLength = Str_getLength(subSrc);

    size_t totalLength = uLength + sLength;


    for (size_t i = 0; i < sLength; i++) {
        pcSrc[uLength + i] = subSrc[i];
    }
    pcSrc[totalLength] = '\0';
    return totalLength;
}

size_t Str_compare(const char pcSrc[], const char subSrc[])
{
    assert(pcSrc != NULL && subSrc != NULL);
    size_t i = 0;

    while (pcSrc[i] != '\0' && subSrc[i] != '\0') {
        if (pcSrc[i] != subSrc[i]) {
            return pcSrc[i] - subSrc[i];
        }
        i++;
    }
    return pcSrc[i] - subSrc[i];
}

size_t Str_search(const char pcSrc[], const char subSrc[])
{

    assert(pcSrc != NULL && subSrc != NULL);
    size_t uLength = Str_getLength(pcSrc);
    size_t sLength = Str_getLength(subSrc);
    assert(uLength >= sLength);
    size_t found = SIZE_MAX;
    size_t j = 0;

    for (size_t i = 0; i < uLength; i++) {
        if ((pcSrc[i] == subSrc[j]) && subSrc[j] != '\0') {
            found = i;
            j++;
        }
    }
    return found;
}
