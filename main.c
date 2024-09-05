#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nom[100];
    char numero[100];
    char mail[100];
}Contact;

Contact list[500];
int counter = 0;

Contact saisirinfo(int modifier, char nom[]){
    Contact contact;
    if(modifier == 1){
        strcpy(contact.nom, nom);
    }else{
        printf("Entrer le nom :\n-");
        scanf("%s", contact.nom);
    }
    printf("Entrer le numero :\n-");
    scanf("%s", contact.numero);
    printf("Entrer le mail :\n-");
    scanf("%s", contact.mail);
    return contact;
}

void ajouter(){
    Contact contact = saisirinfo(0, "");
    list[counter] = contact;
    printf("Contact ajoute avec success !\n");
    counter++;
}

void afficher(){
    for(int i=0; i < counter; i++){
        printf("Nom : %s | Numero : %s | Email : %s\n", list[i].nom, list[i].numero, list[i].mail);
    }
}

int find(char message[]){
    char nom[100];
    printf("%s :\n-", message);
    scanf("%s", nom);
    for(int i=0; i<counter; i++){
        if(strcpy(list[i].nom, nom)) return i; 
    }
    
    return -1;
}

void supprimer(){

    int found = find("Entrer le nom de contact a supprimer");

    if(found == -1){
        printf("le contact n'existe pas !\n");
    }else{
        for(int i=found; i<counter; i++){
            list[i] = list[i+1];
        }

        counter--;
        printf("Contact a ete supprimer avec success !\n");
    }
}

void modifier(){
    int found = find("Entrer le nom de contact a modifier");
    if(found == -1){
        printf("le contact n'existe pas !\n");
    }else{
        Contact contact = saisirinfo(1, list[found].nom);
        list[found] = contact;
    }
}


void rechercher(){
    int i = find("Entrer le nom de contact a rechercher");
    if(i == -1){
        printf("le contact n'existe pas !\n");
    }else{
        printf("Nom : %s | Numero : %s | Email : %s\n", list[i].nom, list[i].numero, list[i].mail);
    }
}

void main(){
    int choix = 0;

    do{
        printf("------------ Welcome to main menu --------------\n\n");
        printf("0- Exit\n");
        printf("1- Ajouter un contact\n");
        printf("2- Modifier un contact\n");
        printf("3- Supprimer un contact\n");
        printf("4- Afficher tous les contacts\n");
        printf("5- Rechercher un contact\n");

        printf("Enter votre choix :\n-");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                ajouter();
            break;
            case 2:
                modifier();
                break;
            case 3:
                supprimer();
            break;
            case 4:
                afficher();
            break;
            case 5:
                rechercher();
            break;
            default:
                if(choix != 0){
                    printf("choisir un valid nombre !\n");
                }
        }
        system("pause");
        system("cls");
    }while(choix != 0);
}