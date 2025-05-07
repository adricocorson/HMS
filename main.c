#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logins.h"

#define MAX_PATIENT 100
#define MAX_STRING_LENGTH 100

int main() {
    int choice, i=0;
    while (i<1){
        printf("Welcome to the Hospital Management System\n");
        printf("1. Login as Patient\n");
        printf("2. Login as Staff\n");
        printf("0. Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            patient_login();
        } else if (choice == 2) {
            staff_login();
        } else if (choice == 0) {
            printf("Exiting Application\n");
            i=1;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}
