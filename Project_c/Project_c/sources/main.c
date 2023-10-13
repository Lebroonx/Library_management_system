#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/functions.h"

void menu();
void add_book();
void search_book();
void delete_book();
void list_book();
void exit_app();

int j;


int main()
{
    printf("Bienvenu !\n");
    do
    {
        menu();
        scanf("%d", &j);

        switch (j)
        {
        case 1:
            add_book();
            await_input();
            break;

        case 2:
            search_book();
            await_input();
            break;

        case 3:
            search_author();
            await_input();
            break;

        case 4:
            modify_book();
            await_input();
            break;

        case 5:
            delete_book();
            await_input();
            break;

        case 6:
            list_book();
            await_input();
            break;

        case 7:
            exit_app();
            exit(0);

        default:
            printf("Veuillez selectionner une valeur correcte");
            exit(0);

        }

    } while (j != 7);

    return 0;
}
