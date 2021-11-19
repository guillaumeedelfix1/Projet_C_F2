#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaration.h"

//exercice 1 
//creation d'une fonction pour compter le nombre de ligne 
/*void compte()
{

	//declaration du pointeur de fichier 
	FILE* pFile;
	//ouverture du fichier cible
	pFile = fopen("DocExo.txt", "w");
	fputs("Et quia Mesopotamiae tractus omnes crebro inquietari sueti praetenturis et stationibus servabantur agrariis, laevorsum flexo itinere Osdroenae subsederat extimas partes, novum parumque aliquando temptatum commentum adgressus. quod si impetrasset, fulminis modo cuncta vastarat. erat autem quod cogitabat huius modi.", pFile);
	fclose(pFile);
	pFile = fopen("DocExo.txt", "r");

	if (pFile == NULL) {
		perror("Erreur ouverture/ecriture fichier\n");
		system("pause");
		exit(1);
	}

	char c;//stock le contenu du fichier 
	int i,n_Lignes;//i permet de la taille des ligne vue au'il ne faut pas alller a plus de 80 et n_lignes a afficher le numero de ligne 
	n_Lignes = 1;//initialisation  de n_lignes
	i = 0;//initialisation  de n_lignes
	printf("%d : ",n_Lignes);
	do 
	{
		c = fgetc(pFile);//met dans la var c le contenu du fichier un charactere apres l'autre  
		i++;//augmente a chaque charactere 
		if ( i == 80 || c == "\n" ) //on verifie si on a nos 80 char et si il y a un retour a la ligne
		{
			n_Lignes++;//incremete lors du cvhqngement de ligne 
			printf("\n %d : ", n_Lignes);//affiche le numero de ligne 
			i = 0;//rebout de i pour pouvoir compter la ligne suivante
		}
		(printf("%c", c));//affiche le contenu de c 
	} while (!feof(pFile));//verifie si on est pas a la fin du fichier 

	fclose(pFile);//ferme le pfile

}*/


//exercice 2  
void repertoire(tInfos* myInfos)
{
	FILE* pFile = NULL;
	//Ecriture
	pFile = fopen("repertoire.txt", "a");
	if (pFile == NULL) {
		perror("Erreur ouverture/ecriture fichier\n");
		system("pause");
		exit(1);
	}
	//chaque bloque permet de demander a l'utilisateur de saisir la donnee voulue et l'integre dans 
	//le bon parametre de la structure donc dans le nom 
	printf("Veuillez saisir votre nom : ");
	//place la donne saisis dans le parametre nom
	scanf("%s", myInfos->c_Nom);
	//ecris dans le fichier une mise en page 
	fputs("Le nom est : ", pFile);
	//ecris le contenu du parametre
	fputs(myInfos->c_Nom,pFile);
	//retour chariot pour la forme 
	fputs("\n",pFile);
	
	//similaire a la zone d'avant mais pour la zone prenom
	printf("Veuillez saisir votre prenom : ");
	scanf("%s",myInfos->c_Prenom);
	fputs("Le prenom est : ", pFile);
	fputs(myInfos->c_Prenom, pFile);
	fputs("\n", pFile);

	//similaire a la zone d'avant mais pour la zone age
	printf("Veuillez saisir votre age : ");
	scanf("%d",&myInfos->n_Age);
	fputs("l'age est : ", pFile);
	//fputs(&myInfos->n_Age, pFile);
	fprintf(pFile,"%d",myInfos->n_Age);
	fputs("\n", pFile);

	//similaire a la zone d'avant mais pour la zone numero de telephone 
	printf("Veuillez saisir votre numero de telephone : ");
	scanf("%s",myInfos->c_Num);
	fputs("Le est numero de telephone est : ", pFile);
	fputs(myInfos->c_Num, pFile);
	fputs("\n", pFile);

	fclose(pFile);//ferme le le pfile	

	


}

//exercice 3
void recherchePers(tInfos* myInfos)
{
	FILE* pFile = NULL;
	//variable pour stocker nom rechercher
	char nom[20];
	//ouverture du fichier 
	pFile = fopen("repertoire.txt", "r");
	//verif  si fichier bien ouvert 
	if (pFile == NULL) {
		perror("Erreur ouverture/ecriture fichier\n");
		system("pause");
		exit(1);
	}
	//demande de saisis a l'utilisateur 
	printf("Veuillez saisir le nom de la personne dont vous voulez les informations : ");
	scanf("%s",nom);

	//tentative rater permet de raficher le contacte qui viens d'etre saisis impossible d'afficher ceux saisis ulterieurment
	/*if (strcmp(myInfos->c_Nom, nom) == 0)
	{
		printf("%s\n", myInfos->c_Nom);
		printf("%s\n", myInfos->c_Prenom);
		printf("%d\n", myInfos->n_Age);
		printf("%s\n", myInfos->c_Num);
	}*/

	fclose(pFile);//ferme le le pfile
	
}



