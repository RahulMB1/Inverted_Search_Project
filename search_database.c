#include "main.h"

int search_database(mainnode **HT)
{
    char word_input[50];

    printf("Enter a word: ");
    scanf("%s", word_input);

    int index = tolower(word_input[0]) % 97;
    mainnode *main = HT[index];

    if (main == NULL)
    {
        printf("Word %s not found\n", word_input);
        return DATA_NOT_FOUND;
    }

    while (main)
    {
        if (!strcmp(main -> word, word_input))
        {
            subnode *sub = main -> subnode;
            printf("Word %s is present in:\n", word_input);
            while (sub)
            {
                printf("In %s for %d times\n", sub -> filename, sub -> wordcount);
                sub = sub -> subnode;
            }
            return SUCCESS; 
        }
        main = main -> mainnode; 
    }

    printf("Word %s not found.\n", word_input);
    return DATA_NOT_FOUND;
}