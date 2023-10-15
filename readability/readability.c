#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string text);
int count_letters(string text);
int count_sentence(string text);
int main(void)
{
    //get text from user
    string texts = get_string("Input text: ");
    //the amount of words
    int word = count_words(texts);
    //the amount of letters
    int letter = count_letters(texts);
    //the amount of sentences
    int sentence = count_sentence(texts);
    //the amount of words in float
    float words = count_words(texts);
    //the amount of letters in float
    float letters = count_letters(texts);
    //the amount of sentences in float
    float sentences = count_sentence(texts);
    //calculate the average number of letters per 100 words in the text
    float L = (letters / words) * 100;
    //calculate the average number of sentences per 100 words in the text
    float S = (sentences / words) * 100;
    //calculate index
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    // round up to the nearest decimal to give grade
    int grade = round(index);
    //printf("Number of words: %i\nNumber of letters: %i\nNumber of sentences: %i\n", word, letter, sentence);
    //printf("%f", L);
    if (grade < 1)
    {
        //if grade less than 1
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        //if grade greater than 16
        printf("Grade 16+\n");
    }
    else
    {
        //if grade between 1 & 16
        printf("Grade %i\n", grade);
    }


}
int count_words(string text)
{
    int n = 0;
    int j = strlen(text);
    for (int i = 0; i < j; i++)
    {
        //if the character has space or . or ? or ! or , count as a character
        if (text[i] == ' ' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ',')
        {
            n += 1;
        }
        // if character is space and has a punctuation mark before it reduce counter by 1
        if ((text[i] == ' ' && text[i - 1] == '.') ||
            (text[i] == ' ' && text[i - 1] == '?') ||
            (text[i] == ' ' && text[i - 1] == '!') ||
            (text[i] == ' ' && text[i - 1] == ','))
        {
            n -= 1;
        }
    }
    return n;
}
int count_letters(string text)
{
    //initialize counter n
    int n = 0;
    //length of text
    int j = strlen(text);
    for (int i = 0; i < j; i++)
    {
        char c = text[i];
        //for each character, if it is a alphabet, add 1 to counter
        if (isalpha(c))
        {
            n += 1;
        }
    }
    return n;
}
int count_sentence(string text)
{
    //initialize counter n
    int n = 0;
    //length of text
    int j = strlen(text);
    for (int i = 0; i < j; i++)
    {
        //if each character is . or ? or !, they should be regarded as sentence so add one to counter n
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            n += 1;
        }
    }
    return n;
}