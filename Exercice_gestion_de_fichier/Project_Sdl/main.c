#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaration.h"



int main() {
   
    tInfos* myInfos;
    myInfos = malloc(sizeof(tInfos));

    //compte(); // appel exercice 1
    repertoire(myInfos); //appel exercice 2
    recherchePers(myInfos);//appel exercice 3
    free(myInfos);
   
   
    
}
