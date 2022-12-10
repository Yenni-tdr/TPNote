#include "../include/functions.h"

int main(int argc, char* argv[]){
    Logement x;
    Logement data[ROWS];
    Logement data2[ROWS];
    int k, l = {0};
    init(data);

    printf("Veuillez entrez les caracteristiques de votre logement\n");
    printf("Nombre de personnes :\n");
    scanf("%f", &x.acc);
    if(x.acc <= 0){
        printf("Le logement doit au moins pouvoir accueillir une personne\n");
        while(x.acc <= 0){
            scanf("%f", &x.acc);
        }
    }
    printf("Nombre de chambres :\n");
    scanf("%f", &x.bedrooms);
    if(x.bedrooms <= 0){
        printf("Le logement doit avoir une chambre\n");
        while(x.bedrooms <= 0){
            scanf("%f", &x.bedrooms);
        }
    }
    printf("Nombre de lits :\n");
    scanf("%f", &x.beds);
    if(x.beds <= 0){
        printf("Le logement doit au moins avoir un lit\n");
        while(x.beds<= 0){
            scanf("%f", &x.beds);
        }
    }
    printf("Nombre de salle de bains :\n");
    scanf("%f", &x.bathrooms);
    if(x.beds <= 0){
        printf("Le logement doit au moins avoir une salle de bain\n");
        while(x.bathrooms<= 0){
            scanf("%f", &x.bathrooms);
        }
    }

    dist(x, data, data2);
    system("clear");
    printf("Selon quel critère voulez vous comparez votre logement ?\n");
    printf("0. Nombre de personnes\n");
    printf("1. Nombre de chambres\n");
    printf("2. Nombre de lits\n");
    printf("3. Nombre de salle de bains\n");
    scanf("%d", &l);
    if(l<0 || l>3){
        printf("Veuillez selectionner un critere valable\n");
        while(l<0 || l>3){
            scanf("%d", &l);
        }
    }
    randomize(data2, l);
    sort(data2, l);
    affichage(data2, l);

    printf("A combien de logements souhaitez-vous comparer le votre pour obtenir une prediction du prix?\n");
    scanf("%d", &k);
    if(k <= 0){
        printf("Vous devez comparer à au moins un logement\n");
        while(k <= 0){
            scanf("%d", &k);
        }
    }
    if(k > 7917){
        printf("Le nombre maximal de logements presents dans la base de donnees est 7917\n");
        while(k > 7917){
            scanf("%d", &k);
        }
    }
    price(data2, k);

    return 0;
}