#ifndef str_h
#define str_h
#include <stdio.h>

size_t Str_getLength(const char pcSrc[]);
char *Str_copy(char pcSrc[], const char src[]);
char *Str_concat(char pcSrc[], const char subSrc[]);
size_t Str_compare(const char pcSrc[], const char subSrc[]);
char *Str_search(const char pcSrc[], const char subSrc[]);
#endif /* str_h */
