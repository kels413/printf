#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Test printf
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    /*  unsigned int ui;
    void *addr; */

    /* Tests for char and string */

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);

    _printf("%s\n", "%");
    printf("%s\n", "%");

    _printf("%s\n", "Testing percent before null terminator %");
    printf("%s\n", "Testing percent before null terminator %");

    len = _printf("Escape characters:[\\n\\t]\n");
    len2 = printf("Escape characters:[\\n\\t]\n");
    _printf("Len from escape:[%d]\n", len);
    printf("Len from escape:[%d]\n", len2);

    len = _printf("ASCII value of 'A' is: [%c]\n", 65);
    len2 = printf("ASCII value of 'A' is: [%c]\n", 65);
    _printf("Len from _printf:[%d]\n", len);
    printf("Len from printf:[%d]\n", len2);

    len = _printf("Printing lower-case letter using ASCII value: [%c]\n", 97);
    len2 = printf("Printing lower-case letter using ASCII value: [%c]\n", 97);
    _printf("Len from lowercase:[%d]\n", len);
    printf("Len from lowercase:[%d]\n", len2);

    len = _printf("Multiline strings:\n[%s]\n", "This string is\non multiple lines.");
    len2 = printf("Multiline strings:\n[%s]\n", "This string is\non multiple lines.");
    _printf("Len from multiln:[%d]\n", len);
    printf("Len from printf:[%d]\n", len2);

    len = _printf("% %");
    _printf("\n");
    len2 = printf("% %");
    printf("\n");
    _printf("len from 2%% and midspace: %d\n", len);
    printf("len from 2%% and midspace: %d\n", len2);

    len = _printf("% ");
    _printf("\n");
    len2 = printf("% ");
    printf("\n");
    _printf("len from 1%% and space: %d\n", len);
    printf("len from 1%% and space: %d\n", len2);

    len = _printf("%\0");
    _printf("\n");
    len2 = printf("%\0");
    printf("\n");
    _printf("len from %% and null terminator: %d\n", len);
    printf("len from %% and null terminator: %d\n", len2);

    len = _printf("%c\n", NULL);
    len2 = printf("%c\n", NULL);
    _printf("len from null char:%d\n", len);
    printf("len from null char:%d\n", len2);

    len = _printf("NULL");
    _printf("\n");
    len2 = printf("NULL");
    printf("\n");
    _printf("len from NULL string: %d\n", len);
    printf("len from NULL string: %d\n", len2);

    len = _printf(NULL);
    _printf("\n");
    len2 = printf(NULL);
    printf("\n");
    _printf("len from outright null: %d\n", len);
    printf("len from outright null: %d\n\n", len2);

    /* Tests for digits (%i and %d) */

    _printf("TESTS FOR DIGITS\n\n");

    len = _printf("%d\n", 0);
    len2 = printf("%d\n", 0);
    _printf("len from zero:%d\n", len);
    printf("len from zero:%d\n", len2);

    len = _printf("%d\n", NULL);
    len2 = printf("%d\n", NULL);
    _printf("len from null digit:%d\n", len);
    printf("len from null digit:%d\n", len2);

    len = _printf("%d\n", INT_MIN);
    len2 = printf("%d\n", INT_MIN);
    _printf("len from int min:%d\n", len);
    printf("len from int min:%d\n", len2);

    len = _printf("%d\n", INT_MAX);
    len2 = printf("%d\n", INT_MAX);
    _printf("len from int max:%d\n", len);
    printf("len from int max:%d\n", len2);

    len = _printf("%c\n", "m");
    len2 = printf("%c\n", "m");
    _printf("len from m string:%d\n", len);
    printf("len from m string:%d\n", len2);

    _printf("%s\n", NULL);
    printf("%s\n", NULL);

    return (0);
}
