/*
** EPITECH PROJECT, 2022
** testing script for day 06
** File description:
** This will test the tasks of day 6
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char * str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str); 
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

char str[] = "ABCD";
char str_2[] = "TEST";

Test(task01, my_strcpy)
{
    my_strcpy(str_2, str);
    cr_assert_str_eq(str_2, str);
}

Test(task02, my_strnpy)
{
    my_strncpy(str_2, str, 2);
    cr_assert_str_eq(str_2, strncpy(str_2, str, 2));
} 

Test(task03, my_revstr)
{
    my_revstr(str);
    //cr_assert_str_eq(str, "DCBA");
    cr_assert_str_eq(my_revstr(""), "");
    cr_assert_str_eq(my_revstr(strdup("hello")), "olleh");
}

Test(task05, my_strstr)
{
    cr_assert_str_eq(my_strstr(str, ""), "ABCD");
    cr_assert_str_eq(my_strstr(str, "L"), "");
    cr_assert_str_eq(my_strstr(str, "CD"), "CD");
}

Test(task06, my_strcmp)
{
    const char str_06_01[] = "Hello all";
    const char str_06_02[] = "Hello world";
    const char str_06_03[] = "Hello world!";
    cr_assert(my_strcmp(str_06_01, str_06_02) == strcmp(str_06_01, str_06_02));
    cr_assert(my_strcmp(str_06_02, str_06_03) == strcmp(str_06_02, str_06_03));
    cr_assert(my_strcmp(str_06_02, str_06_02) == strcmp(str_06_02, str_06_02));
    cr_assert(my_strcmp(str_06_01, str_06_02) == strcmp(str_06_01, str_06_02));
}

Test(task07, my_strncmp)
{
    const char str_06_01[] = "Hello123";
    const char str_06_02[] = "Hello234";
    const char str_06_03[] = "Hello world!";
    cr_assert_eq(my_strncmp(str_06_01, str_06_02, 4), strncmp(str_06_01, str_06_02, 4));
    cr_assert_eq(my_strncmp(str_06_02, str_06_03, 1), strncmp(str_06_02, str_06_03, 1));
    cr_assert(my_strncmp(str_06_02, str_06_02, 2) == strncmp(str_06_02, str_06_02, 2));
    cr_assert(my_strncmp(str_06_01, str_06_02, 5) == strncmp(str_06_01, str_06_02, 5));
}

Test(task08, my_strupcase)
{
    char str_08_01[] = "1heLLo";
    cr_assert_str_eq(my_strupcase(str_08_01), "1HELLO");
}

Test(task09, my_strlowcase)
{
    char str_09_01[] = "HEllO3";
    cr_assert_str_eq(my_strlowcase(str_09_01), "hello3");
}

Test(task10, my_strcapitalize)
{
    char str_10_01[] = "hello, my nAme is nathan+coquelin-edwards";
    cr_assert_str_eq(my_strcapitalize(str_10_01), "Hello, My Name Is Nathan+Coquelin-Edwards");
}

Test(task12, my_str_isalpha)
{
    char str_12_01[] = "Hello";
    char str_12_02[] = "Hello1";
    char str_12_03[] = "Hello1@";
    char str_12_04[] = "Hello 1";

    cr_assert(my_str_isalpha(str_12_01) == 1);
    cr_assert(my_str_isalpha(str_12_02) == 1);
    cr_assert(my_str_isalpha(str_12_03) == 0);
    cr_assert(my_str_isalpha(str_12_04) == 0);
}

Test(task13, my_str_isnum)
{
    char const str_13_01[] = "1341";
    char const str_13_02[] = "r132";
    char const str_13_03[] = "34e13";

    cr_assert(my_str_isnum(str_13_01) == 1);
    cr_assert(my_str_isnum(str_13_02) == 0);
    cr_assert(my_str_isnum(str_13_03) == 0);
}

Test(task14, my_str_islower)
{
    char const str_14_01[] = "jadsfkl";
    char const str_14_02[] = "jkle90";
    char const str_14_03[] = "Kefs";

    cr_assert(my_str_islower(str_14_01) == 1);
    cr_assert(my_str_islower(str_14_02) == 0);
    cr_assert(my_str_islower(str_14_03) == 0);
}

Test(task15, my_str_isupper)
{
    char const str_15_01[] = "ASFSERES";
    char const str_15_02[] = "jkle90";
    char const str_15_03[] = "Kefs";

    cr_assert(my_str_isupper(str_15_01) == 1);
    cr_assert(my_str_isupper(str_15_02) == 0);
    cr_assert(my_str_isupper(str_15_03) == 0);
}

Test(task16, my_str_isprintable)
{
    char const str_16_01[] = "TEST";
    char const str_16_02[] = " h \n";
    char const str_16_03[] = "";

    cr_assert(my_str_isprintable(str_16_01) == 1);
    //cr_assert(my_str_isprintable(str_16_02) == 0);
    cr_assert(my_str_isprintable(str_16_03) == 1);
}

Test(task16_02, my_str_isprintable)
{
    char const str_16_04[] = "\n";

    cr_assert(my_str_isprintable(str_16_04) == 0);
}
