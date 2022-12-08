#include "libs.h"

typedef struct Process Process;
struct Process{
    char name[3];
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

File* initialiserfile(){
    File *file = malloc(sizeof(*file));

    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    file->first = NULL;

    return file;
}

void ajout_activite(Ordonnanceur o){
    Process* p = malloc(sizeof(*p));
    char nom[3];
    int ex_time, priority = {0};

    printf("Saisir nom du processus a ajouter :\n");
    scanf("%s", nom);
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
    
    strcpy(p->name, nom);
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

void affichage(Ordonnanceur o){
    if(o.file == NULL){
        exit(EXIT_FAILURE);
    }

    if(o.file->first != NULL){
        Process* current = o.file->first;
        while(current != NULL){
            printf(" %s ->", current->name);
            current = current->next;
        }
    }
    printf(" NULL\n");  
}

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

void step(Ordonnanceur o){
    if(o.file == NULL){
        exit(EXIT_FAILURE);
    }
 
    int n = o.file->first->ex_time;
    system("clear");
    printf("Execution du processus : %s\n", o.file->first->name);
    fflush(stdout);
    for(int i = 0; i<n; i++){
        putchar('.');
        fflush(stdout);
        sleep(1);
    }
    defiler(o);
}

void run(Ordonnanceur o){
    do{
        step(o);
    }while(o.file->first != NULL);
    system("clear");
    printf("La file est vide\nExecution terminee\n");
}