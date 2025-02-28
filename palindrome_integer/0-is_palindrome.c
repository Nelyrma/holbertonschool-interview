#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * n: list int
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 **/

 int is_palindrome(unsigned long n) {
    unsigned long original = n;
    unsigned long reversed = 0;

    while (n != 0) {
        unsigned long digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }
}