#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATIENT 100
#define MAX_STRING_LENGTH 100

void view_EHR_patient() {
    struct EHRpatient {
        char id[MAX_STRING_LENGTH];
        char fullname[MAX_STRING_LENGTH];
        char age[MAX_STRING_LENGTH];
        char gender[MAX_STRING_LENGTH];
        char contact_number[MAX_STRING_LENGTH];
        char address[MAX_STRING_LENGTH];
        char medicalhistory[MAX_STRING_LENGTH];
        char allergies[MAX_STRING_LENGTH];
        char medication[MAX_STRING_LENGTH];
        char past_procedure[MAX_STRING_LENGTH];
        char diagnosis_report[MAX_STRING_LENGTH];
    };

    struct EHRpatient patients[MAX_PATIENT];

    FILE *file = fopen("EHRpatient.txt", "r");
    if (file == NULL) {
        printf("Error opening file for loading! Starting with an empty list.\n");
    }

    char line[1024];
    int patientCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (patientCount >= MAX_PATIENT) {
            printf("Reached maximum number of patients during loading.\n");
            break;
        }

        char *id = strtok(line, "|");
        char *fullname = strtok(NULL, "|");
        char *age = strtok(NULL, "|");
        char *gender = strtok(NULL, "|");
        char *contact_number = strtok(NULL, "|");
        char *address = strtok(NULL, "|");
        char *medicalhistory = strtok(NULL, "|");
        char *allergies = strtok(NULL, "|");
        char *medication = strtok(NULL, "|");
        char *past_procedure = strtok(NULL, "|");
        char *diagnosis_report = strtok(NULL, "|");

        if (id != NULL && fullname != NULL && age != NULL && gender != NULL &&
            contact_number != NULL && address != NULL && medicalhistory != NULL &&
            allergies != NULL && medication != NULL && past_procedure != NULL &&
            diagnosis_report != NULL) {

            struct EHRpatient patient;
            strcpy(patient.id, id);
            strcpy(patient.fullname, fullname);
            strcpy(patient.age, age);
            strcpy(patient.gender, gender);
            strcpy(patient.contact_number, contact_number);
            strcpy(patient.address, address);
            strcpy(patient.medicalhistory, medicalhistory);
            strcpy(patient.allergies, allergies);
            strcpy(patient.medication, medication);
            strcpy(patient.past_procedure, past_procedure);
            strcpy(patient.diagnosis_report, diagnosis_report);

            patients[patientCount++] = patient;
        }
    }

    fclose(file);
    printf("\n");
    printf("| Patient ID | Full Name       | Age | Gender | Contact Number | Address           | Medical History         | Allergies      | Medications     | Past Procedures | Diagnosis Report  |\n");
    printf("|------------|-----------------|-----|--------|----------------|-------------------|-------------------------|----------------|-----------------|-----------------|-------------------|\n");

    for (int i = 0; i < patientCount; i++) {
        printf("| %-10s | %-15s | %-3s | %-6s | %-14s | %-17s | %-23s | %-14s | %-15s | %-15s | %-17s\n",
               patients[i].id, patients[i].fullname, patients[i].age,
               patients[i].gender, patients[i].contact_number, patients[i].address,
               patients[i].medicalhistory, patients[i].allergies, patients[i].medication,
               patients[i].past_procedure, patients[i].diagnosis_report);
    }
    
    printf("\n");
}

void search_EHR_patient() {
    getchar(); // Clear the newline left by the previous input
    char search_name[MAX_STRING_LENGTH];
    printf("Enter the patient's full name to search: ");
    fgets(search_name, MAX_STRING_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // Remove the newline character

    FILE *file = fopen("EHRpatient.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Search Results for '%s':\n", search_name);
    printf("\n");
    printf("| Patient ID | Full Name       | Age | Gender | Contact Number | Address           | Medical History         | Allergies      | Medications     | Past Procedures | Diagnosis Report  |\n");
    printf("|------------|-----------------|-----|--------|----------------|-------------------|-------------------------|----------------|-----------------|-----------------|-------------------|\n");

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *id = strtok(line, "|");
        char *fullname = strtok(NULL, "|");
        char *age = strtok(NULL, "|");
        char *gender = strtok(NULL, "|");
        char *contact_number = strtok(NULL, "|");
        char *address = strtok(NULL, "|");
        char *medicalhistory = strtok(NULL, "|");
        char *allergies = strtok(NULL, "|");
        char *medication = strtok(NULL, "|");
        char *past_procedure = strtok(NULL, "|");
        char *diagnosis_report = strtok(NULL, "|");

        if (fullname != NULL && strstr(fullname, search_name) != NULL) {
            printf("| %-10s | %-15s | %-3s | %-6s | %-14s | %-17s | %-23s | %-14s | %-15s | %-15s | %-17s\n",
                   id, fullname, age, gender, contact_number, address, medicalhistory,
                   allergies, medication, past_procedure, diagnosis_report);
            found = 1;
        }
    }

    if (!found) {
        printf("No patients found with '%s' in their name, please try again.\n", search_name);
    }

    fclose(file);
}

int loadPatients() {
    struct EHRpatient {
        char id[MAX_STRING_LENGTH];
        char fullname[MAX_STRING_LENGTH];
        char age[MAX_STRING_LENGTH];
        char gender[MAX_STRING_LENGTH];
        char contact_number[MAX_STRING_LENGTH];
        char address[MAX_STRING_LENGTH];
        char medicalhistory[MAX_STRING_LENGTH];
        char allergies[MAX_STRING_LENGTH];
        char medication[MAX_STRING_LENGTH];
        char past_procedure[MAX_STRING_LENGTH];
        char diagnosis_report[MAX_STRING_LENGTH];
    };

    struct EHRpatient patients[MAX_PATIENT];

    FILE *file = fopen("EHRpatient.txt", "r");
    if (file == NULL) {
        printf("Error opening file for loading! Starting with an empty list.\n");
    }

    char line[1024];
    int patientCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (patientCount >= MAX_PATIENT) {
            printf("Reached maximum number of patients during loading.\n");
            break;
        }

        char *id = strtok(line, "|");
        char *fullname = strtok(NULL, "|");
        char *age = strtok(NULL, "|");
        char *gender = strtok(NULL, "|");
        char *contact_number = strtok(NULL, "|");
        char *address = strtok(NULL, "|");
        char *medicalhistory = strtok(NULL, "|");
        char *allergies = strtok(NULL, "|");
        char *medication = strtok(NULL, "|");
        char *past_procedure = strtok(NULL, "|");
        char *diagnosis_report = strtok(NULL, "|");

        if (id != NULL && fullname != NULL && age != NULL && gender != NULL &&
            contact_number != NULL && address != NULL && medicalhistory != NULL &&
            allergies != NULL && medication != NULL && past_procedure != NULL &&
            diagnosis_report != NULL) {

            struct EHRpatient patient;
            strcpy(patient.id, id);
            strcpy(patient.fullname, fullname);
            strcpy(patient.age, age);
            strcpy(patient.gender, gender);
            strcpy(patient.contact_number, contact_number);
            strcpy(patient.address, address);
            strcpy(patient.medicalhistory, medicalhistory);
            strcpy(patient.allergies, allergies);
            strcpy(patient.medication, medication);
            strcpy(patient.past_procedure, past_procedure);
            strcpy(patient.diagnosis_report, diagnosis_report);

            patients[patientCount++] = patient;
        }
    }

    fclose(file);

    return patientCount;
}

void add_EHR_patient() {
    struct EHRpatient {
    char id[MAX_STRING_LENGTH];
    char fullname[MAX_STRING_LENGTH];
    char age[MAX_STRING_LENGTH];
    char gender[MAX_STRING_LENGTH];
    char contact_number[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char medicalhistory[MAX_STRING_LENGTH];
    char allergies[MAX_STRING_LENGTH];
    char medication[MAX_STRING_LENGTH];
    char past_procedure[MAX_STRING_LENGTH];
    char diagnosis_report[MAX_STRING_LENGTH];
    };

    struct EHRpatient patients[MAX_PATIENT];

    int patientCount = loadPatients();

    if (patientCount >= MAX_PATIENT) {
        printf("Maximum number of patients reached.\n");
        return;
    }

    struct EHRpatient newPatient;
    getchar(); // Clear the newline left by the previous input

    printf("Enter patient ID: \n");
    fgets(newPatient.id, MAX_STRING_LENGTH, stdin);
    newPatient.id[strcspn(newPatient.id, "\n")] = '\0';

    // Load patient's full name from login file based on ID
    FILE *login = fopen("patient_login.txt", "r");

    char line[200];
    while (fgets(line, sizeof(line), login) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char id[20];
        char password[50];
        char name[100];

        strcpy(id, token);
        token = strtok(NULL, "|");
        strcpy(password, token);
        token = strtok(NULL, "|");
        strcpy(name, token);

        if (strcmp(id, newPatient.id) == 0) {
            strcpy(newPatient.fullname, name);
            break;
        }
    }
    fclose(login);

    printf("Enter your age: \n");
    fgets(newPatient.age, MAX_STRING_LENGTH, stdin);
    newPatient.age[strcspn(newPatient.age, "\n")] = '\0';

    printf("Enter your gender (Male/female): \n");
    fgets(newPatient.gender, MAX_STRING_LENGTH, stdin);
    newPatient.gender[strcspn(newPatient.gender, "\n")] = '\0';

    printf("Enter your contact number: \n");
    fgets(newPatient.contact_number, MAX_STRING_LENGTH, stdin);
    newPatient.contact_number[strcspn(newPatient.contact_number, "\n")] = '\0';

    printf("Enter your address: \n");
    fgets(newPatient.address, MAX_STRING_LENGTH, stdin);
    newPatient.address[strcspn(newPatient.address, "\n")] = '\0';

    printf("Enter Medical History: \n");
    fgets(newPatient.medicalhistory, MAX_STRING_LENGTH, stdin);
    newPatient.medicalhistory[strcspn(newPatient.medicalhistory, "\n")] = '\0';

    printf("Enter your allergies: \n");
    fgets(newPatient.allergies, MAX_STRING_LENGTH, stdin);
    newPatient.allergies[strcspn(newPatient.allergies, "\n")] = '\0';

    printf("Enter your medication: \n");
    fgets(newPatient.medication, MAX_STRING_LENGTH, stdin);
    newPatient.medication[strcspn(newPatient.medication, "\n")] = '\0';

    printf("Enter past procedures: \n");
    fgets(newPatient.past_procedure, MAX_STRING_LENGTH, stdin);
    newPatient.past_procedure[strcspn(newPatient.past_procedure, "\n")] = '\0';

    printf("Enter diagnostic report: \n");
    fgets(newPatient.diagnosis_report, MAX_STRING_LENGTH, stdin);
    newPatient.diagnosis_report[strcspn(newPatient.diagnosis_report, "\n")] = '\0';

    patients[patientCount] = newPatient;
    patientCount++;

    FILE *file = fopen("EHRpatient.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
            newPatient.id, newPatient.fullname, newPatient.age,
            newPatient.gender, newPatient.contact_number, newPatient.address,
            newPatient.medicalhistory, newPatient.allergies, newPatient.medication,
            newPatient.past_procedure, newPatient.diagnosis_report);

    fclose(file);
    printf("Patient records saved to file.\n");

    printf("Patient added successfully.\n");
}

void modify_EHR_patient() {
    view_EHR_patient();  // Assuming there's a function to view current EHR patients

    FILE *file = fopen("EHRpatient.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        perror("Error opening file");
        return;
    }

    char patientID[11];
    char fullname[50], new_fullname[50];
    char age[4], new_age[4];
    char gender[10], new_gender[10];
    char contact_number[15], new_contact_number[15];
    char address[100], new_address[100];
    char medicalhistory[200], new_medicalhistory[200];
    char allergies[100], new_allergies[100];
    char medication[100], new_medication[100];
    char past_procedure[100], new_past_procedure[100];
    char diagnosis_report[200], new_diagnosis_report[200];
    char update_id[11], buffer[200];
    char line[1024];

    getchar();
    printf("Enter the Patient ID to modify: ");
    fgets(update_id, sizeof(update_id), stdin);
    update_id[strcspn(update_id, "\n")] = '\0';

    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
               patientID, fullname, age, gender, contact_number, address, medicalhistory, allergies, medication, past_procedure, diagnosis_report);

        if (strcmp(patientID, update_id) == 0) {
            found = 1;
            printf("\nPatient Information:\n");
            printf(" ID: %s\n", patientID);
            printf(" Full Name: %s\n", fullname);
            printf(" Age: %s\n", age);
            printf(" Gender: %s\n", gender);
            printf(" Contact Number: %s\n", contact_number);
            printf(" Address: %s\n", address);
            printf(" Medical History: %s\n", medicalhistory);
            printf(" Allergies: %s\n", allergies);
            printf(" Medications: %s\n", medication);
            printf(" Past Procedures: %s\n", past_procedure);
            printf(" Diagnosis Report: %s\n", diagnosis_report);

            strncpy(new_fullname, fullname, sizeof(new_fullname));
            strncpy(new_age, age, sizeof(new_age));
            strncpy(new_gender, gender, sizeof(new_gender));
            strncpy(new_contact_number, contact_number, sizeof(new_contact_number));
            strncpy(new_address, address, sizeof(new_address));
            strncpy(new_medicalhistory, medicalhistory, sizeof(new_medicalhistory));
            strncpy(new_allergies, allergies, sizeof(new_allergies));
            strncpy(new_medication, medication, sizeof(new_medication));
            strncpy(new_past_procedure, past_procedure, sizeof(new_past_procedure));
            strncpy(new_diagnosis_report, diagnosis_report, sizeof(new_diagnosis_report));

            int choice;
            do {
                printf("\nWhat would you like to modify?\n");
                printf("1. Full Name\n");
                printf("2. Age\n");
                printf("3. Gender\n");
                printf("4. Contact Number\n");
                printf("5. Address\n");
                printf("6. Medical History\n");
                printf("7. Allergies\n");
                printf("8. Medications\n");
                printf("9. Past Procedures\n");
                printf("10. Diagnosis Report\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                // Clear input buffer (including the newline)
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}

                if (choice >= 1 && choice <= 10) {
                    printf("Enter new value: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    switch (choice) {
                        case 1: strncpy(new_fullname, buffer, sizeof(new_fullname)); break;
                        case 2: strncpy(new_age, buffer, sizeof(new_age)); break;
                        case 3: strncpy(new_gender, buffer, sizeof(new_gender)); break;
                        case 4: strncpy(new_contact_number, buffer, sizeof(new_contact_number)); break;
                        case 5: strncpy(new_address, buffer, sizeof(new_address)); break;
                        case 6: strncpy(new_medicalhistory, buffer, sizeof(new_medicalhistory)); break;
                        case 7: strncpy(new_allergies, buffer, sizeof(new_allergies)); break;
                        case 8: strncpy(new_medication, buffer, sizeof(new_medication)); break;
                        case 9: strncpy(new_past_procedure, buffer, sizeof(new_past_procedure)); break;
                        case 10: strncpy(new_diagnosis_report, buffer, sizeof(new_diagnosis_report)); break;
                        default: break;
                    }
                } else if (choice != 0) {
                    printf("Invalid choice.\n");
                }
            } while (choice != 0);

            fprintf(temp, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
                    patientID, new_fullname, new_age, new_gender, new_contact_number, new_address,
                    new_medicalhistory, new_allergies, new_medication, new_past_procedure, new_diagnosis_report);
        } else {
            fprintf(temp, "%s\n", line);
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("EHRpatient.txt");
        rename("temp.txt", "EHRpatient.txt");
        printf("Patient '%s' updated in EHR.\n", update_id);
    } else {
        remove("temp.txt");
        printf("Patient not found.\n");
    }
}


int search_ownEHR(char search[100]) {

    FILE *file = fopen("EHRpatient.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    printf("Search Results for '%s':\n", search);
    printf("\n");
    printf("| Patient ID | Full Name       | Age | Gender | Contact Number | Address           | Medical History         | Allergies      | Medications     | Past Procedures | Diagnosis Report  |\n");
    printf("|------------|-----------------|-----|--------|----------------|-------------------|-------------------------|----------------|-----------------|-----------------|-------------------|\n");

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *id = strtok(line, "|");
        char *fullname = strtok(NULL, "|");
        char *age = strtok(NULL, "|");
        char *gender = strtok(NULL, "|");
        char *contact_number = strtok(NULL, "|");
        char *address = strtok(NULL, "|");
        char *medicalhistory = strtok(NULL, "|");
        char *allergies = strtok(NULL, "|");
        char *medication = strtok(NULL, "|");
        char *past_procedure = strtok(NULL, "|");
        char *diagnosis_report = strtok(NULL, "|");

        if (strstr(id, search) != NULL) {
            printf("| %-10s | %-15s | %-3s | %-6s | %-14s | %-17s | %-23s | %-14s | %-15s | %-15s | %-17s\n",
                   id, fullname, age, gender, contact_number, address, medicalhistory,
                   allergies, medication, past_procedure, diagnosis_report);
            found = 1;
        }
    }

    if (!found) {
        printf("No EHR data for patient.\n");
    }

    fclose(file);
}