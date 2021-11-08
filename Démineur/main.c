//Choix des différentes bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Creation des Constante
#define Taille_Grille_X 9
#define Taille_Grille_Y 9
#define Mines 10
//DEFINITION des fonctions
void creaTabDem(int tabGrille[Taille_Grille_X][Taille_Grille_Y], int tab_Choix[Taille_Grille_X][Taille_Grille_Y], int tabGrille2[Taille_Grille_X][Taille_Grille_Y]);
void debutDemineur(int tabGrille[Taille_Grille_X][Taille_Grille_Y], int tab_Choix[Taille_Grille_X][Taille_Grille_Y]);
void Verification(int tabGrille[Taille_Grille_X][Taille_Grille_Y], int tab_Choix[Taille_Grille_X][Taille_Grille_Y], int tabGrille2[Taille_Grille_X][Taille_Grille_Y]);
//creation du main
int  main()
{
    //CREATION DES TABLEAUX DE JEU ET DE VERIFICATION
    int tabGrille[Taille_Grille_X][Taille_Grille_Y];
    int tab_Choix[Taille_Grille_X][Taille_Grille_Y];
    int tabGrille2[Taille_Grille_X][Taille_Grille_Y];
    //APPELLE DES FONCTION
    creaTabDem(tabGrille, tab_Choix, tabGrille2);
    debutDemineur(tabGrille, tab_Choix);
    Verification(tabGrille, tab_Choix, tabGrille2);




}
//CREATION DE LA FONCTION D'INITIALISATION DES TABLEAUX
void creaTabDem(int tabGrille[Taille_Grille_X][Taille_Grille_Y], int tab_Choix[Taille_Grille_X][Taille_Grille_Y], int tabGrille2[Taille_Grille_X][Taille_Grille_Y])
{

    int i = 0;
    int j = 0;
    for (i = 0; i < Taille_Grille_X; i++)
    {
        for (j = 0; j < Taille_Grille_Y; j++)
        {
            tabGrille2[i][j] = rand() % 10;
            if (tabGrille[i][j] == 9)
            {
                tab_Choix[i][j] = "/";
                tabGrille[i][j] = -1;
                tabGrille2[i][j] = 0;
            }
            else
            {
                tab_Choix[i][j] = "/";
                tabGrille[i][j] = 0;
                tabGrille2[i][j] = 0;
            };
        };



    };
};

void debutDemineur(int tabGrille[Taille_Grille_X][Taille_Grille_Y], int tab_Choix[Taille_Grille_X][Taille_Grille_Y])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < Taille_Grille_X; i++)
    {
        tabGrille[i][j - 1] = 0;
        printf("     0   1   2   3   4   5   6   7   8   X\n");
        printf("   [---|---|---|---|---|---|---|---|---]\n");
        for (i = 0; i < Taille_Grille_X; i++)
        {
            printf(" %d | ", i);

            for (j = 0; j < Taille_Grille_Y; j++)
            {
                if (tabGrille[i][j] != -1)
                {
                    if (tabGrille[i - 1][j - 1] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i][j - 1] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i + 1][j - 1] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i - 1][j] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i + 1][j] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i - 1][j + 1] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i][j + 1] == -1) { tabGrille[i][j]++; }
                    if (tabGrille[i + 1][j + 1] == -1) { tabGrille[i][j]++; }
                };

                printf("%s | ", tab_Choix[i][j]);
            };
            printf("\n");
            printf("   [---|---|---|---|---|---|---|---|---]\n");
        };
        printf(" Y\n");
    };
};

void Verification(int tabGrille[Taille_Grille_X][Taille_Grille_Y], int tab_Choix[Taille_Grille_X][Taille_Grille_Y], int tabGrille2[Taille_Grille_X][Taille_Grille_Y])
{
    int i = 0;
    int j = 0;
    int HP = 1;
    int cordX = -1;
    int cordY = -1;

    printf("Veuillez saisir une ordonnee (Y) : ");
    while (cordX > 8 || cordX < 0)
    {
        scanf("%d", &cordX);
    };
    i--;
    printf("veuillez saisir les abscisse (X) : ");
    while (cordY > 8 | cordY < 0)
    {
        scanf("%d", &cordY);
    };
    printf("     0   1   2   3   4   5   6   7   8   X\n");
    printf("   [---|---|---|---|---|---|---|---|---]\n");
    for (i = 0; i < Taille_Grille_X; i++)
    {
        printf(" %d | ", i);
        for (j = 0; j < Taille_Grille_Y; j++)
        {
            if (tabGrille[cordX][cordY] != -1)
            {
                tab_Choix[cordX][cordY] = tabGrille[cordX][cordY];
                tabGrille2[cordX][cordY] = 1;
                if (tabGrille2[i][j] == 1)
                {

                    printf("%d | ", tab_Choix[i][j]);
                }
                else
                {
                    printf("/ | ");
                }
            }
            else
            {
                tab_Choix[cordX][cordY] = tabGrille[cordX][cordY];
                tabGrille2[cordX][cordY] = 1;
                if (tabGrille2[i][j] == 1)
                {
                    HP = 0;
                    printf("%d | ", tab_Choix[i][j]);
                }
                else
                {
                    printf("/ | ");
                }
            }
        }
        printf("\n");
        printf("   [---|---|---|---|---|---|---|---|---]\n");
    }
    printf(" Y\n");

    if (HP == 1)
    {
        Verification(tabGrille, tab_Choix, tabGrille2);
    }
    if (HP == 0)
    {
        printf("PERDU");
    }
}











