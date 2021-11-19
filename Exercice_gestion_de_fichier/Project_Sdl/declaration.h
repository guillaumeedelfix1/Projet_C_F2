//exercice 1

//declaration extern void compte(); 

typedef struct tInfos {

	char c_Nom[20];
	char c_Prenom[15];
	int n_Age;
	char c_Num[11];
   

}tInfos;

//declaration exercice 2
extern void repertoire(tInfos* myInfos);

//declaration exercice 3
extern void recherchePers(tInfos* myInfos);

