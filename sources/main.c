#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct book{
        int id;
        char name[30];
        char author[20];
    } bk[20]={0};

    int j;
    char searchid[50];
    
    do
    {
        printf("1. Ajouter un livre\n2. Rechercher un livre\n3. Supprimer un livre\n4. Afficher tous les livres\n5. Sortir\n\nQue voulez vous faire : ");
        scanf("%d", &j);

        switch(j)
        {
            case 1:
                for(int i=1; i<20; i++){
                    if (bk[i].id==0){
                        bk[i].id = i;
                        printf("Entrer le nom du livre: ");
                        scanf("%s", bk[i].name);
                        printf("Entrer le nom de l'auteur: ");
                        scanf("%s", bk[i].author);
                        i=20;
                        printf("Le livre a été ajouté.\n\n");
                    }
                }
            break;
        
            case 2:
                printf("Entrer le nom du livre: ");
                scanf("%s", &searchid);
                for(int i=1; i<20; i++){
                    if (strcmp(searchid, bk[i].name) == 0) {
                        printf("\n\tInformations du livre\nID du livre: %d\nNom du livre: %s\nAuteur: %s\n\n", bk[i].id, bk[i].name, bk[i].author);
                    }
                }
                

            break;
        
            case 3:
                printf("Entrer le nom du livre: ");
                scanf("%s", &searchid);
                for(int i=1; i<20; i++){
                    if (strcmp(searchid, bk[i].name) == 0){
                        for(i=i; i<20; i++){
                            bk[i]=bk[i+1];
                        }
                    }
                }
                
            break;
        
            case 4:
                printf("\nListe des livres\n\nID\tNom\t\tAuteur\n");
                for (int i = 1; i < 20; i++) {
                    if(bk[i].id != 0){
                    printf("%d\t%s\t\t%s\n", bk[i].id, bk[i].name, bk[i].author);
                    }
                }
            break;

            case 5:
                printf("\n\t\tAu revoir");
                exit(0);
            break;
        
        }
        
    }while(j!=5);

    return 0;
}


