#include "main.h"

/* Function to save database to a file*/
int save_database(mainnode **HT)
{
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    /* Open file in write mode*/
    FILE *fptr = fopen(filename, "w");
    if (!fptr)
    {
        printf("ERROR: Opening File\n");
        return FAILURE;
    }

    /* check for .txt extension*/
    if (!strstr(filename, ".txt"))
    {
        printf("ERROR: Wrong file extension\n");
        return FAILURE;
    }

    /* Iterate through entire hashtable*/
    for (int i = 0; i < 27; i++)
    {
        mainnode *temp = HT[i];
        while (temp)
        {
            fprintf(fptr, "#%d;%s;%d;", i, temp -> word,temp -> filecount);
            subnode *temp_subnode = temp -> subnode;
            while (temp_subnode)
            {
                /* print to file*/
                fprintf(fptr, "%s;%d;", temp_subnode -> filename, temp_subnode -> wordcount);
                temp_subnode = temp_subnode -> subnode;
            }
            fprintf(fptr, "#\n");
            temp = temp -> mainnode;
        }
    }    
    fclose(fptr);
    return SUCCESS;
}