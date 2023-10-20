#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// list of books as a database
struct book 
{
    int id;
    char name[50];
    char author[50];
}
bk[100] = { 0 };    
char searchdata[50];

// Waits for an input
void await_input()
{
    printf("\nEntrer une touche pour continuer\n");
    getch();
}

// Displays a menu
void menu()
{
    printf("\nLibrary management system\n\n1. Ajouter un livre\n2. Rechercher un livre\n3. Rechercher les livres d'un auteur\n4. Modifier un livre\n5. Supprimer un livre\n6. Afficher tous les livres\n7. Sortir\n\nQue voulez vous faire : ");
}

// Add a book to the list of structures 
void add_book()
{
    for (int i = 1; i < 100; i++)
    {
        // Check an empty place
        if (bk[i].id == 0)
        {
            bk[i].id = i;
            printf("\nEntrer le nom du livre: ");
            scanf("%s", bk[i].name);
            printf("\nEntrer le nom de l'auteur: ");
            scanf("%s", bk[i].author);
            i = 100;
            printf("\nLe livre a été ajouté.\n");
        }
    }
}

// Search a book with its name
void search_book()
{
    printf("\nEntrer le nom du livre: ");
    scanf("%s", &searchdata);
    printf("\n\nID\tNom\t\tAuteur\n");
    for (int i = 1; i < 20; i++)
    {
        if (stricmp(searchdata, bk[i].name) == 0)
        {
            printf("%d\t%s\t\t%s\n", bk[i].id, bk[i].name, bk[i].author);
        }
    }
}

// Search all the books with the author's name
void search_author()
{
    printf("\nEntrer le nom de l'auteur: ");
    scanf("%s", &searchdata);
    printf("\n\nID\tNom\t\tAuteur\n");
    for (int i = 1; i < 20; i++)
    {
        if (stricmp(searchdata, bk[i].author) == 0)
        {
            if (bk[i].id != 0)
            {
                printf("%d\t%s\t\t%s\n", bk[i].id, bk[i].name, bk[i].author);
            }
        }
    }
}

// Modify an existing book with its name
void modify_book()
{
    printf("\nEntrer le nom du livre: ");
    scanf("%s", &searchdata);
    printf("\n\nID\tNom\t\tAuteur\n");
    for (int i = 1; i < 100; i++)
    {
        if (stricmp(searchdata, bk[i].name) == 0)
        {
            printf("%d\t%s\t\t%s\n", bk[i].id, bk[i].name, bk[i].author);
            printf("\nEntrer le nom modifié du livre: ");
            scanf("%s", bk[i].name);
            printf("\nEntrer l'auteur modifié du livre: ");
            scanf("%s", bk[i].author);
        }
    }
}

void delete_book()
{
    printf("\nEntrer le nom du livre: ");
    scanf("%s", &searchdata);
    printf("\n\nID\tNom\t\tAuteur\n");
    for (int i = 1; i < 100; i++)
    {
        if (stricmp(searchdata, bk[i].name) == 0)
        {
            printf("%d\t%s\t\t%s\n", bk[i].id, bk[i].name, bk[i].author);
            bk[i].id = 0;
        }
    }
}

// Display all the books in the list of struct
void list_book()
{
    printf("\nListe des livres\n\nID\tNom\t\tAuteur\n");
    for (int i = 1; i < 100; i++)
    {
        if (bk[i].id != 0)
        {
            printf("%d\t%s\t\t%s\n", bk[i].id, bk[i].name, bk[i].author);
        }
    }
}

void exit_app()
{
    printf("\nAu revoir");
    exit(0);
}
