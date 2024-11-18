#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Macro Definition*/
#ifndef MAIN_H
#define MAIN_H
#define FAILURE 0
#define SUCCESS 1
#define DATA_NOT_FOUND 2

/* Structure definitions*/
typedef struct Slist_node
{
    char filename[20];
    struct Slist_node *link;
}Slist;

/* Subnode structure*/
typedef struct sub_node
{
    int wordcount;
    char *filename;
    struct sub_node *subnode;
} subnode;

/* Main node structure*/
typedef struct main_node
{
    int filecount;
    char *word;
    subnode *subnode;
    struct main_node *mainnode;
} mainnode;

/* LinkedList Function prototypes below*/
int read_and_validate(int argc, char *argv[], Slist **filename_head);
int insert_at_last(Slist **filename_head, char *filename);

/* Database Function prototypes*/
int create_database(mainnode **HT, Slist *filename_head);
void display_database(mainnode **HT);
int search_database(mainnode **HT);
int save_database(mainnode **HT);
int read_validate_update(char *file_name);
int update_database(mainnode **HT, char *file_name);
#endif