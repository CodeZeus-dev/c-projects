//
//  main.c
//  readability
//
//  Created by Constantine Akritides on 24/07/2020.
//  Copyright © 2020 Constantine Akritides. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    /*
       The algorithm uses the Coleman-Liau index to determine the reading grade of the input text
       The equation of the index is: index = 0.0588 * L - 0.296 * S - 15.8
    */
    string userText = get_string("Text: ");

    int numLetters = count_letters(userText); // number of letters in text
    int numWords = count_words(userText); // number of words in text
    int numSent = count_sentences(userText); // number of sentences
    float L = ((float)numLetters / (float)numWords) * 100.0;
    float S = ((float)numSent / (float)numWords) * 100.0;

    float clIndex = (0.0588 * L) - (0.296 * S) - 15.8;

    if (clIndex >= 16.0)
    {
        printf("Grade 16+\n");
    }
    else if (clIndex < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(clIndex));
    }

    /* printf("# of Letters: %i\n", numLetters);
    printf("# of Words: %i\n", numWords);
    printf("# of Sentences: %i\n", numSent);
    */
}

int count_letters(string text)
{
    int numLetters = 0; // number of letters in text
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            numLetters += 1;
        }
    }

    return numLetters;
}

int count_words(string text)
{
    int wordCount = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            wordCount += 1;
        }
    }

    return wordCount;
}

int count_sentences(string text)
{
    int sentenceCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentenceCount += 1;
        }
    }

    return sentenceCount;
}

