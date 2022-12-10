#include "libs.h"

typedef struct Process Process;
struct Process{
    int num;
    int ex_time;
    int priority;
    Process* next;
};

typedef struct{
    Process* first;
}File;

typedef struct{
    File* file;
}Ordonnanceur;

//Initialisation de la file
File* initialiserfile(){
    File *file = malloc(sizeof(*file));

    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    file->first = NULL;

    return file;
}

//Procédure qui ajoute un processus à notre ordonnanceur
void ajout_activite(Ordonnanceur o){
    Process* p = malloc(sizeof(*p));
    int num;
    int ex_time, priority = {0};

    printf("Saisir numero du processus a ajouter :\n");
    scanf("%d", &num);
    printf("Saisir temps d'execution du processus :\n");
    scanf("%d", &ex_time);
    if(ex_time <= 0){
        printf("Le temps d'execution doit etre superieur a 1\n");
        while(ex_time <= 0){
            scanf("%d", &ex_time);
        }
    }
    printf("Saisir la priorite du processus :\n");
    scanf("%d", &priority);
    if(priority < 0 || priority > 5){
        printf("La priorite doit etre comprise entre 0 et 5\n");
        while(priority < 0 || priority > 5){
            scanf("%d", &priority);
        }
    }
    
    p->num = num;
    p->ex_time = ex_time;
    p->priority = priority;
    p->next = NULL;

    if (o.file == NULL || p == NULL){
        exit(EXIT_FAILURE);
    }

    if(o.file->first != NULL){
        Process* current = o.file->first;
        if(p->priority <= current->priority){
            p->next = current;
            o.file->first = p;
        }else{
            while(current->next != NULL){
                current = current->next;
            }
            current->next = p;
        }
    }else{
        o.file->first = p;
    }
}

//Procédure d'affichage de notre ordonnanceur (à utiliser lorsque l'on souhaite effectuer des vérifications)
void affichage(Ordonnanceur o){
    if(o.file == NULL){
        exit(EXIT_FAILURE);
    }

    if(o.file->first != NULL){
        Process* current = o.file->first;
        while(current != NULL){
            printf(" p%d ->", current->num);
            current = current->next;
        }
    }
    printf(" NULL\n");  
}

//Procédure permettant de défiler un élément de notre file (un processus)
void defiler(Ordonnanceur o){
    if (o.file == NULL){
        exit(EXIT_FAILURE);
    }

    if (o.file->first != NULL){
        Process* current = o.file->first;

        o.file->first = current->next;   
        free(current);
    }
}

//Procédure qui permet d'effectuer un tour d'ordonnancement
void step(Ordonnanceur o){
    if(o.file == NULL){
        exit(EXIT_FAILURE);
    }
 
    int n = o.file->first->ex_time;
    system("clear");
    printf("Execution du processus : p%d\n", o.file->first->num);
    fflush(stdout);
    for(int i = 0; i<n; i++){
        putchar('.');
        fflush(stdout);
        sleep(1);
    }
    defiler(o);
}

//Procédure qui itère step jusqu'à que notre file de processus soit vide
void run(Ordonnanceur o){
    do{
        step(o);
    }while(o.file->first != NULL);
    system("clear");
    printf("La file est vide\nExecution terminee\n");
}