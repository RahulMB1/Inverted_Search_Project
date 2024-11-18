#include "main.h"

void display_database(mainnode **HT)
{
    mainnode *temp;
    printf("Index   Word    Filecount        FileName        WordCount\n");
    for (int i = 0; i < 27; i++)
    {
        if (HT[i] != NULL)
        {
            temp = HT[i];
            while (temp)
            {
                printf("%d\t%s\t%d\t", i, temp->word, temp->filecount);
                subnode *s = temp->subnode;
                while (s)
                {
                    printf("\t%s\t\t%d", s->filename, s->wordcount);
                    s = s->subnode;
                }
                printf("\n");
                temp = temp->mainnode;
            }
        }
    }
}
