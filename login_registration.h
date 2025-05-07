#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void patient_registration(){
    struct registration{
        char name[100], address[100], contact[15], dob[20], gender[10], id[20], password[50];
    };
    struct registration patientreg;

    printf("-------------------- Patient Registration --------------------\n");
    getchar();
    printf("Enter username (PAT000): ");
    fgets(patientreg.id, sizeof(patientreg.id), stdin);
    patientreg.id[strcspn(patientreg.id, "\n")] = '\0';
    if (strstr(patientreg.id, "PAT") == NULL){
        printf("\nInvalid username! Please use the valid username format (PAT000)\n");
        return;
    }
    printf("Enter password: ");
    fgets(patientreg.password, sizeof(patientreg.password), stdin);
    patientreg.password[strcspn(patientreg.password, "\n")] = '\0';
    printf("Enter Patient Name: ");
    fgets(patientreg.name, sizeof(patientreg.name), stdin);
    patientreg.name[strcspn(patientreg.name, "\n")] = '\0';

    FILE *file = fopen("patient_login.txt", "a");

    fprintf(file, "%s|%s|%s\n", 
    patientreg.id, patientreg.password, patientreg.name);
    fclose(file);
    printf("----------------Patient Registered Successfully!--------------\n\n");

}

void staff_registration(){
    struct registration{
        char name[100], address[100], contact[15], dob[20], gender[10], id[20], password[50];
    };
    struct registration staffreg;

    printf("-------------------- Staff Registration --------------------\n");
    getchar();
    printf("Enter username (DOC/NUR/ADM000) EX:DOC123 : ");
    fgets(staffreg.id, sizeof(staffreg.id), stdin);
    staffreg.id[strcspn(staffreg.id, "\n")] = '\0';
    if (strstr(staffreg.id, "DOC") == NULL && strstr(staffreg.id, "NUR") == NULL && strstr(staffreg.id, "ADM") == NULL){
        printf("\nInvalid username! Please use the valid username format\n");
        printf("Doctor: DOC000\nNurse: NUR000\nAdmin: ADM000\n");
        return;
    }
    printf("Enter password: ");
    fgets(staffreg.password, sizeof(staffreg.password), stdin);
    staffreg.password[strcspn(staffreg.password, "\n")] = '\0';
    printf("Enter Staff Name: ");
    fgets(staffreg.name, sizeof(staffreg.name), stdin);
    staffreg.name[strcspn(staffreg.name, "\n")] = '\0';
    printf("Enter Staff Address: ");
    fgets(staffreg.address, sizeof(staffreg.address), stdin);
    staffreg.address[strcspn(staffreg.address, "\n")] = '\0';
    printf("Enter Staff Contact Number: ");
    fgets(staffreg.contact, sizeof(staffreg.contact), stdin);
    staffreg.contact[strcspn(staffreg.contact, "\n")] = '\0';
    printf("Enter Staff Date of Birth (DD/MM/YYYY): ");
    fgets(staffreg.dob, sizeof(staffreg.dob), stdin);
    staffreg.dob[strcspn(staffreg.dob, "\n")] = '\0';
    printf("Enter Staff Gender (M/F): ");
    fgets(staffreg.gender, sizeof(staffreg.gender), stdin);
    staffreg.gender[strcspn(staffreg.gender, "\n")] = '\0';

    FILE *file = fopen("staff_login.txt", "a");

    fprintf(file, "%s|%s|%s|%s|%s|%s|%s\n",
    staffreg.id, staffreg.password, staffreg.name, staffreg.dob, staffreg.gender, staffreg.address, staffreg.contact);
    fclose(file);

    if (strstr(staffreg.id, "DOC") != NULL){
        printf("----------------Doctor Registered Successfully!--------------\n\n");
    } else if (strstr(staffreg.id, "NUR") != NULL){
        printf("----------------Nurse Registered Successfully!--------------\n\n");
    } else if (strstr(staffreg.id, "ADM") != NULL){
        printf("----------------Admin Registered Successfully!--------------\n\n");
    }
}


