//
//  str.h
//  StringModule
//
//  Created by Sofia Makovetska on 21.02.2024.
//

#ifndef str_h
#define str_h
#include <stdio.h>

size_t Str_getLength(const char pcSrc[]);
size_t Str_copy(const char pcSrc[], char src[]);
size_t Str_concat(char pcSrc[], const char subSrc[]);
size_t Str_compare(const char pcSrc[], const char subSrc[]);
size_t Str_search(const char pcSrc[], const char subSrc[]);
#endif /* str_h */
