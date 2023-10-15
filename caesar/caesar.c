#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char letter, int keyy);

int main(int argc, string argv[])
{
    //if there is no argument passed when compiling code
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //convert key to integer
    int key = atoi(argv[1]);
    //if key passed is not a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //input plain text
    string plain_text = get_string("Plain text: ");
    //length of plain text
    int len = strlen(plain_text);

    for (int i = 0; i < len; i++)
    {
        //rotate plain text use rotate function
        char j = rotate(plain_text[i], key);
        plain_text[i] = j;
    }
    //print cipher text
    printf("ciphertext: %s\n", plain_text);

    return 0;
}
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        /* If each value of s is not a digit using integer ascii values*/
        if (s[i] < 48 || s[i] > 57)
        {
            return false;
        }
    }

    return true;
}
char rotate(char letter, int keyy)
{
    int n = 0 ;
    //if letter is not an alphabet
    if (!isalpha(letter))
    {
        return letter;
    }
    //if letter is lowercase use ascii values of lowercase for manipulation
    if (islower(letter))
    {
        n = letter - 97;
        n = (n + keyy) % 26;
        return (n + 97);
    }
    //if letter is uppercase use ascii values for uppercase for manipulation
    n += letter - 65;
    n = (n + keyy) % 26;
    return (n + 65);
}