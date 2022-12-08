#include "libs.h"
#define NB_CARAC 8
#define MAX_CHAR 100
#define ROWS 7917
#define COLS 3

typedef struct{
    int id;
    float acc;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;
    float min_nights;
    float max_nights;
    float nb_reviews;
    float distance[COLS];
}Logement;

   
void init(Logement data[ROWS]){
    FILE *fp;
    fp = fopen("data/airbnb_donnees_propre.csv", "r");

    if(!fp){
        fprintf(stderr, "Ouverture du fichier impossible\n");
        exit(EXIT_FAILURE);
    }else{
        char buffer[MAX_CHAR];
        char* value;
        int i, j = {0};
        while(feof(fp) != true){
            fgets(buffer, MAX_CHAR, fp);
            if (buffer[0] == ','){
                i = 0;
                continue; //On ne prends pas en compte la 1ere ligne
            }
            //printf("Row : %s", buffer);
            value = strtok(buffer, ",");
            while(value != NULL){
                //printf("Token : %s\n", value);
                if(j == 9){
                    j = 0;
                }
                switch(j){
                    case 0:
                        data[i].id = atof(value);
                    break;
                    case 1:
                        data[i].acc = atof(value);
                    break;
                    case 2:
                        data[i].bedrooms = atof(value);
                    break;
                    case 3:
                        data[i].bathrooms = atof(value);
                    break;
                    case 4:
                        data[i].beds= atof(value);
                    break;
                    case 5:
                        data[i].price = atof(value);
                    break;
                    case 6:
                        data[i].min_nights = atof(value);
                    break;
                    case 7:
                        data[i].max_nights = atof(value);
                    break;
                    case 8:
                        data[i].nb_reviews = atof(value);
                    break;
                }
                value = strtok(NULL, ",");
                j++;
            }
            i++;
        }
        fclose(fp);
    }
}

void dist(Logement x, Logement data[ROWS], Logement data2[ROWS]){
    float sum1,sum2,sum3 = {0};
    for(int k = 0; k<ROWS; k++){
        sum1 = 0;
        sum2 = 0;
        sum3 = 0;
        for (int l = 0; l<NB_CARAC+1; l++){
            switch (l){
                case 0:
                    data2[k].id = data[k].id;
                break;
                case 1 :
                    sum1 += pow((x.acc - data[k].acc), 2);
                break;
                case 2 :
                    sum2 += pow((x.bedrooms - data[k].bedrooms), 2);
                break;
                case 4:
                    sum3 += pow((x.beds - data[k].beds), 2);
                break;
                case 5 :
                    data2[k].price = data[k].price;
                break;
                default :
                break;
            }
        }
        data2[k].distance[0] = sqrt(sum1);
        data2[k].distance[1] = sqrt(sum2);
        data2[k].distance[2] = sqrt(sum3);
    }
}

void affichage(Logement data2[ROWS], int l){
    for (int i = 0; i<ROWS; i++){
        printf("%d ", data2[i].id);
        printf("%f ", data2[i].distance[l]);
        printf("%f", data2[i].price);
        printf("\n");
    }
    printf("id   distance  prix\n");
}

void randomize(Logement data2[ROWS], int l){
    srand(time(NULL));
    float tmp, tmp2, tmp3 = {0};
    for (int i = 0; i<ROWS; i++){
        int rand_row = rand()%ROWS;
            tmp = data2[i].distance[l];
            tmp2 = data2[i].id;
            tmp3 = data2[i].price;
            data2[i].distance[l] = data2[rand_row].distance[l];
            data2[i].id = data2[rand_row].id;
            data2[i].price = data2[rand_row].price;
            data2[rand_row].distance[l] = tmp;
            data2[rand_row].id = tmp2;
            data2[rand_row].price = tmp3;
    }
}

void sort(Logement data2[ROWS], int l){
    float tmp,tmp2,tmp3 = {0};
    for (int k = 1; k<ROWS; k++){
        for (int i = 0; i<ROWS-1; i++){
        
                float a = data2[i].distance[l];
                float b = data2[i+1].distance[l];
                if(a>b){
                    tmp = data2[i].distance[l];
                    tmp2 = data2[i].id;
                    tmp3 = data2[i].price;
                    data2[i].distance[l] = data2[i+1].distance[l];
                    data2[i].id = data2[i+1].id;
                    data2[i].price = data2[i+1].price;
                    data2[i+1].distance[l] = tmp;
                    data2[i+1].id = tmp2;
                    data2[i+1].price = tmp3;
                }
        }
    }
}

void price(Logement data2[ROWS], int k){
    float price = 0;
    for (int i = 0; i<k; i++){
        price += data2[i].price;
    }
    price = price/k;
    printf("Le prix estime de votre logement est de : %f €\n", price);
}