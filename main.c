//
//  main.c
//  StringModule
//
//  Created by Sofia Makovetska on 21.02.2024.
//

#include <stdio.h>
#include "str.h"

int main(int argc, const char * argv[]) {
//    const char *myString = "Hello, world!";
    const char myString[] = "hello, world!";
    char secondStr[] = "hallo!";
    const char thirdStr[] = "anyoeng";
    size_t length = Str_getLength(myString);
    printf("The length of the string is: %zu\n", length);
    
    size_t copy = Str_copy(myString, secondStr);
    printf("The copy of the string is: %zu\n", copy);
    
    size_t concat = Str_concat(secondStr, myString);
    printf("The concat of the string is: %zu\n", concat);
    
    size_t compare = Str_compare(myString, thirdStr);
    printf("The compare of the string is: %zu\n", compare);
    
    size_t search = Str_search(myString, thirdStr);
    printf("The search of the string is: %zu\n", search);
    return 0;
}
