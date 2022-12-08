#include "../include/functions.h"

int main(int argc, char* argv[]){
    Ordonnanceur o;
    o.file = initialiserfile();
    int n = 0;

    printf("Combien de processus voulez-vous ajouter ?\n");
    scanf("%d", &n);
    if(n <= 0){
        printf("Veuillez ajouter au moins un processus\n");
        while(n <= 0){
            scanf("%d", &n);
        }
    }
    for(int i = 0; i<n; i++){
        ajout_activite(o);   
        system("clear");
    }
    run(o);
    free(o.file);

    return 0;
}