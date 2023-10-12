#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct book {
    int id;
    char name[30];
    char author[20];
}
bk[100] = { 0 };
char searchname[50];

void await_input()
{
    printf("\nEntrer une touche pour continuer\n");
    getch();
}

void menu()
{
    printf("Library management system\n\n1. Ajouter un livre\n2. Rechercher un livre\n3. Supprimer un livre\n4. Afficher tous les livres\n5. Sortir\n\nQue voulez vous faire : ");
}

void add_book()
{
    for (int i = 1; i < 100; i++)
    {
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

void search_book()
{
    printf("\nEntrer le nom du livre: ");
    scanf("%s", &searchname);
    for (int i = 1; i < 20; i++)
    {
        if (strcmp(searchname, bk[i].name) == 0)
        {
            printf("\nInformations du livre\n\nID du livre: %d\nNom du livre: %s\nAuteur: %s\n", bk[i].id, bk[i].name, bk[i].author);
        }
    }
}

void delete_book()
{
    printf("\nEntrer le nom du livre: ");
    scanf("%s", &searchname);
    for (int i = 1; i < 100; i++)
    {
        if (strcmp(searchname, bk[i].name) == 0)
        {
            bk[i].id = 0;
        }
    }
}

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
    printf("\n\t\tAu revoir");
    exit(0);
}
