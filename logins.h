#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "role_menu.h"

void staff_login(){
    char username[20], password[20];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen("staff_login.txt", "r");
    char line[100];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char user_stored[20];
        char pass_stored[20];

        strcpy(user_stored, token);
        token = strtok(NULL, "|");
        strcpy(pass_stored, token);

        if (strcmp(user_stored, username) == 0){
            found = 1;
            if (strcmp(pass_stored, password) == 0){
                printf("\nLogin Successful!\n\n");
                
                if (strstr(username, "DOC") != NULL){
                    doctor_main(username);
                } else if (strstr(username, "NUR") != NULL){
                    nurse_main(username);
                } else if (strstr(username, "ADM") != NULL){
                    admin_main(username);
                }
            } else {
                printf("Incorrect Password!\n\n");
            }
        }
    }
    fclose(file);

    if (!found) {
        printf("Username Does Not Exist!\n\n");
    }
}

void patient_login(){
    char username[20], password[20];
    int found = 0;
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    FILE *file = fopen("patient_login.txt", "r");
    char line[100];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char user_stored[20];
        char pass_stored[20];

        strcpy(user_stored, token);
        token = strtok(NULL, "|");
        strcpy(pass_stored, token);

        if (strcmp(user_stored, username) == 0){
            found = 1;
            if (strcmp(pass_stored, password) == 0){
                printf("\nLogin Successful!\n\n");
                patient_main(username);
            } else {
                printf("Incorrect Password!\n\n");
            }
        
        }
    }
    fclose(file);

    if (!found) {
        printf("Username Does Not Exist!\n\n");
    }
}

