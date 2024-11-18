/*
    Name: Rahul Basetti
    Date: 13/11/2024
*/
#include "main.h"

int main(int argc, char *argv[])
{
    Slist *filename_head = NULL;  
    if (!read_and_validate(argc, argv, &filename_head))  // Read and validate command-line arguments
    {
        return 0;  // Exit if validation fails
    }

    printf("Read and Validation Completed\n");
    int flag = 0;

    mainnode *HT[27] = {NULL};  // Initialize hash table

    int option = 0;
    do
    {
        // Display menu and get user input
        printf("\n1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n6. Exit\nEnter Choice: ");
        scanf("%d", &option);
        printf("\n");
        
        switch (option)
        {
        case 1:
            if (create_database(HT, filename_head) == 1)
            {
                printf("Creation of Database successful\n");
                flag = 1;
            }
            else
            {
                printf("Creation of database failed\n");
            }
            break;
        
        case 2:
            display_database(HT);
            break;

        case 3:
            if (search_database(HT) == 1)  // Search the database
            {
                printf("Search Completed Successfully\n");
            }
            else if (search_database(HT) == 2)  // Search failed
            {
                printf("Search Failed\n");
            }
            break;

        case 4:
            save_database(HT);
            break; 
        
        case 5:
            if (!flag)
            {
                char file_name[50];  
                printf("Enter the name of File: ");
                scanf("%s", file_name);  
                if (read_validate_update(file_name) == 1)  // Validate the file
                {
                    update_database(HT, file_name);  // Update the database
                }
            }
            else
            {
                printf("ERROR: Cannot update after creation\n");
            }
            break;
        
        case 6:
            break;  // Exit the program

        default:
            printf("Invalid Option\n");  // Invalid menu option
            break;
        }
    }
    while (option != 6);  // Repeat until option 6 is chosen
}
