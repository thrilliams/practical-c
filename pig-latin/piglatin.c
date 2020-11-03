#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *word_to_pig_latin(const char *word)
{
    char *new_word = calloc(strlen(word) + 4, sizeof(char));
    // +4 includes a +1 for the null character and a lazy +3 for either of "ay" or "way" without checking
    strcpy(new_word, word);

    // check whether first character is different than its lowercase counterpart, i.e. is uppercase
    bool titlecase = tolower(word[0]) != word[0];
    new_word[0] = tolower(new_word[0]);

    char *vowels = "aeiou";
    if (strchr(vowels, new_word[0]) == NULL)
    { // string doesn't start with a vowel
        vowels = "aeiouy";

        for (size_t i = 1; i < strlen(new_word); i++)
        {
            if (strchr(vowels, new_word[i]) != NULL)
            {
                // save leading consonants for later
                char *consonants = calloc(i, sizeof(char));
                memcpy(consonants, new_word, sizeof(char) * i);
                // trim leading consonants off of new_word
                memcpy(new_word, new_word + (sizeof(char) * i), (strlen(new_word) - i) * sizeof(char));
                // trick strcat into overwriting the rest of the word that we no longer care about
                new_word[strlen(new_word) - i] = 0;
                // put our consonants at the end of our word and add ay
                strcat(new_word, consonants);
                strcat(new_word, "ay");
                // prevent memory leak
                free(consonants);
                break;
            }
        }
    }
    else
    { // string starts with a vowel
        strcat(new_word, "way");
    }

    // replace first character with its uppercase counterpart if the word was in titlecase
    if (titlecase)
    {
        new_word[0] = toupper(new_word[0]);
    }
    return new_word;
}

void test_pig_latin()
{
    const char *cases[][2] = {
        {"exit", "exitway"},
        {"Yellow", "Ellowyay"},
        {"scram", "amscray"},
        {"blue", "ueblay"},
        {"Type", "Ypetay"},
        {"igloo", "iglooway"},
        {"Float", "Oatflay"},
        {"bandanda", "andandabay"},
        {"Apple", "Appleway"},

        // feel free to add more cases above this line,
        // but leave the { NULL, NULL } line intact.
        {NULL, NULL}};

    size_t i = 0;
    int failed_cases = 0, passed_casses = 0;
    while (1)
    {
        const char *original = cases[i][0];
        const char *expected_latin = cases[i][1];

        if (!original || !expected_latin)
        {
            break;
        }

        char *actual_latin = word_to_pig_latin(original);

        if (!actual_latin || strcmp(expected_latin, actual_latin) != 0)
        {
            printf("Test case failed: expected '%s' -> '%s', but got '%s'\n", original, expected_latin, actual_latin);

            failed_cases++;
        }
        else
        {
            passed_casses++;
        }

        free(actual_latin);

        i++;
    }

    printf("%d/%d cases passed\n", passed_casses, failed_cases + passed_casses);
}

int main(int argc, char *argv[])
{
    test_pig_latin();

    return 0;
}