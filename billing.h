#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int load_BILLS() {
    struct billing {
    char bill_id[100];
    char patient_id[100];
    char billing_date[100];
    float amount;
    char insurance_info[100];
    char measure_outcomes[100];  // Added new column for measure outcomes
    };

    struct billing bills[100];

    FILE *file = fopen("billing_records.txt", "r");
    if (file == NULL) {
        printf("Records undetected within the database\n");
    }

    char line[1024];
    int billCount = 0; // Ensure billCount is reset before loading

    while (fgets(line, sizeof(line), file) != NULL) {
        struct billing newBill;
        char *bill_id = strtok(line, "|");
        char *patient_id = strtok(NULL, "|");
        char *billing_date = strtok(NULL, "|");
        float amount = atof(strtok(NULL, "|"));
        char *insurance_info = strtok(NULL, "|");
        char *measure_outcomes = strtok(NULL, "|");  // Load measure outcomes

        strcpy(newBill.bill_id, bill_id);
        strcpy(newBill.patient_id, patient_id);
        strcpy(newBill.billing_date, billing_date);
        newBill.amount = amount;
        strcpy(newBill.insurance_info, insurance_info);
        if (measure_outcomes != NULL) {
            measure_outcomes[strcspn(measure_outcomes, "\n")] = '\0';
            strcpy(newBill.measure_outcomes, measure_outcomes);
        } else {
            strcpy(newBill.measure_outcomes, "");
        }

        bills[billCount++] = newBill;
    }

    fclose(file);
    printf("\nBilling records loaded successfully.\n");

    return billCount;
}

void add_BILLS() {
    struct billing {
    char bill_id[100];
    char patient_id[100];
    char billing_date[100];
    float amount;
    char insurance_info[100];
    char measure_outcomes[100];  // Added new column for measure outcomes
    };

    struct billing bills[100];
    struct billing newBill;

    int billCount = load_BILLS();

    getchar();
    printf("Enter Bill ID: ");
    fgets(newBill.bill_id, sizeof(newBill.bill_id), stdin);
    newBill.bill_id[strcspn(newBill.bill_id, "\n")] = '\0';

    printf("Enter Patient ID: ");
    fgets(newBill.patient_id, sizeof(newBill.patient_id), stdin);
    newBill.patient_id[strcspn(newBill.patient_id, "\n")] = '\0';

    printf("Enter Billing Date (DD/MM/YYYY): ");
    fgets(newBill.billing_date, sizeof(newBill.billing_date), stdin);
    newBill.billing_date[strcspn(newBill.billing_date, "\n")] = '\0';

    printf("Enter Amount: ");
    scanf("%f", &newBill.amount);

    getchar();
    printf("Enter Insurance Information: ");
    fgets(newBill.insurance_info, sizeof(newBill.insurance_info), stdin);
    newBill.insurance_info[strcspn(newBill.insurance_info, "\n")] = '\0';

    
    printf("Enter Measure Outcomes: ");  // Prompt for measure outcomes
    fgets(newBill.measure_outcomes, sizeof(newBill.measure_outcomes), stdin);
    newBill.measure_outcomes[strcspn(newBill.measure_outcomes, "\n")] = '\0';

    bills[billCount++] = newBill;

    FILE *file = fopen("billing_records.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < billCount; i++) {
        fprintf(file, "%s|%s|%s|%.2f|%s|%s\n",
                bills[i].bill_id, bills[i].patient_id, bills[i].billing_date,
                bills[i].amount, bills[i].insurance_info, bills[i].measure_outcomes);  // Save measure outcomes
    }

    fclose(file);
    printf("Billing records saved successfully.\n");

    printf("Billing record added successfully.\n");
}

void view_BILLS() {
    struct billing {
    char bill_id[100];
    char patient_id[100];
    char billing_date[100];
    float amount;
    char insurance_info[100];
    char measure_outcomes[100];  // Added new column for measure outcomes
    };

    struct billing bills[100];

    FILE *file = fopen("billing_records.txt", "r");
    if (file == NULL) {
        printf("Records undetected within the database\n");
    }

    char line[1024];
    int billCount = 0; // Ensure billCount is reset before loading

    while (fgets(line, sizeof(line), file) != NULL) {
        struct billing newBill;
        char *bill_id = strtok(line, "|");
        char *patient_id = strtok(NULL, "|");
        char *billing_date = strtok(NULL, "|");
        float amount = atof(strtok(NULL, "|"));
        char *insurance_info = strtok(NULL, "|");
        char *measure_outcomes = strtok(NULL, "|");  // Load measure outcomes

        strcpy(newBill.bill_id, bill_id);
        strcpy(newBill.patient_id, patient_id);
        strcpy(newBill.billing_date, billing_date);
        newBill.amount = amount;
        strcpy(newBill.insurance_info, insurance_info);
        if (measure_outcomes != NULL) {
            measure_outcomes[strcspn(measure_outcomes, "\n")] = '\0';
            strcpy(newBill.measure_outcomes, measure_outcomes);
        } else {
            strcpy(newBill.measure_outcomes, "");
        }

        bills[billCount++] = newBill;
    }

    fclose(file);
    printf("\nBilling records loaded successfully.\n");

    if (billCount == 0) {
        printf("No billing records found.\n");
        return;
    }

    printf("\n");
    printf("| Bill ID    | Patient ID | Billing Date     | Amount | Insurance Info | Measure Outcomes |\n");
    printf("|------------|------------|------------------|--------|----------------|------------------|\n");

    for (int i = 0; i < billCount; i++) {
        printf("| %-10s | %-10s | %-16s | %-6.2f | %-14s | %-16s |\n",
               bills[i].bill_id, bills[i].patient_id, bills[i].billing_date,
               bills[i].amount, bills[i].insurance_info, bills[i].measure_outcomes);
    }
    printf("\n");
}

void search_BILLS() {
    getchar(); // Clear the newline left by the previous input
    char search_id[100];
    printf("Enter the bill ID to search: ");
    fgets(search_id, sizeof(search_id), stdin);
    search_id[strcspn(search_id, "\n")] = '\0'; // Remove the newline character

    FILE *file = fopen("billing_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Search Results for '%s':\n", search_id);
    printf("\n");
    printf("| Bill ID    | Patient ID | Billing Date     | Amount | Insurance Info | Measure Outcomes |\n");
    printf("|------------|------------|------------------|--------|----------------|------------------|\n");

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *bill_id = strtok(line, "|");
        char *patient_id = strtok(NULL, "|");
        char *billing_date = strtok(NULL, "|");
        char *amount = strtok(NULL, "|");
        char *insurance_info = strtok(NULL, "|");
        char *measure_outcomes = strtok(NULL, "|");

        if (measure_outcomes != NULL) {
            measure_outcomes[strcspn(measure_outcomes, "\n")] = '\0';
        }

        if (bill_id != NULL && strstr(bill_id, search_id) != NULL) {
            printf("| %-10s | %-10s | %-16s | %-6s | %-14s | %-16s |\n",
                   bill_id, patient_id, billing_date, amount, insurance_info, measure_outcomes);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No bills found with ID %s, please try again.\n\n", search_id);
    }

    printf("\n");
    fclose(file);
}


void modify_BILLS() {
    view_BILLS();

    FILE *file = fopen("billing_records.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        perror("Error opening file");
        return;
    }

    char line[200];
    char bill_id[100];
    char patient_id[100], new_patient_id[100];
    char billing_date[100], new_billing_date[100];
    float amount, new_amount;
    char insurance_info[100], new_insurance_information[100];
    char measure_outcomes[100], new_measure_outcomes[100];  // Added measure outcomes
    char update_id[11], buffer[200];

    getchar();
    printf("Enter the Bill ID to modify: ");
    fgets(update_id, sizeof(update_id), stdin);
    update_id[strcspn(update_id, "\n")] = '\0';

    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        sscanf(line, "%[^|]|%[^|]|%[^|]|%f|%[^|]|%[^|]",
               bill_id, patient_id, billing_date, &amount, insurance_info, measure_outcomes);

        if (strcmp(bill_id, update_id) == 0) {
            found = 1;
            printf("\nBilling Information:\n");
            printf("  Bill ID: %s\n", bill_id);
            printf("  Patient ID: %s\n", patient_id);
            printf("  Billing Date: %s\n", billing_date);
            printf("  Amount: %.2f\n", amount);
            printf("  Insurance Information: %s\n", insurance_info);
            printf("  Measure Outcomes: %s\n", measure_outcomes);  // Display measure outcomes
          
            strcpy(new_patient_id, patient_id);
            strcpy(new_billing_date, billing_date);
            new_amount = amount;
            strcpy(new_insurance_information, insurance_info);
            strcpy(new_measure_outcomes, measure_outcomes);  // Copy measure outcomes

            int choice;
            do {
                printf("\nWhat would you like to modify?\n");
                printf("1. Patient ID\n");
                printf("2. Billing Date\n");
                printf("3. Amount\n");
                printf("4. Insurance Information\n");
                printf("5. Measure Outcomes\n");  // Added option to modify measure outcomes
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }

                if (choice >= 1 && choice <= 5) {
                    printf("Enter new value: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    switch (choice) {
                        case 1: strncpy(new_patient_id, buffer, sizeof(new_patient_id)); break;
                        case 2: strncpy(new_billing_date, buffer, sizeof(new_billing_date)); break;
                        case 3: new_amount = atof(buffer); break;
                        case 4: strncpy(new_insurance_information, buffer, sizeof(new_insurance_information)); break;
                        case 5: strncpy(new_measure_outcomes, buffer, sizeof(new_measure_outcomes)); break;  // Modify measure outcomes
                        default: break;
                    }
                } else if (choice != 0) {
                    printf("Invalid choice.\n");
                }
            } while (choice != 0);

            fprintf(temp, "%s|%s|%s|%.2f|%s|%s\n", 
                    bill_id, new_patient_id, new_billing_date, new_amount, new_insurance_information, new_measure_outcomes);
        } else {
            fprintf(temp, "%s\n", line);
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("billing_records.txt");
        rename("temp.txt", "billing_records.txt");
        printf("Bill ID '%s' updated in billing records.\n", update_id);
    } else {
        remove("temp.txt");
        printf("Bill ID not found.\n");
    }
}

int search_ownBILLS(char ID[100]) {
    getchar(); // Clear the newline left by the previous input
    char search_id[100];
    printf("Enter the bill ID to search: ");
    fgets(search_id, sizeof(search_id), stdin);
    search_id[strcspn(search_id, "\n")] = '\0'; // Remove the newline character

    FILE *file = fopen("billing_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    printf("Search Results for '%s':\n", search_id);
    printf("\n");
    printf("| Bill ID    | Patient ID | Billing Date     | Amount | Insurance Info | Measure Outcomes |\n");
    printf("|------------|------------|------------------|--------|----------------|------------------|\n");

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *bill_id = strtok(line, "|");
        char *patient_id = strtok(NULL, "|");
        char *billing_date = strtok(NULL, "|");
        char *amount = strtok(NULL, "|");
        char *insurance_info = strtok(NULL, "|");
        char *measure_outcomes = strtok(NULL, "|");

        if (measure_outcomes != NULL) {
            measure_outcomes[strcspn(measure_outcomes, "\n")] = '\0';
        }

        if (bill_id != NULL && strstr(bill_id, search_id) != NULL && strstr(patient_id, ID) != NULL){
            printf("| %-10s | %-10s | %-16s | %-6s | %-14s | %-16s |\n",
                   bill_id, patient_id, billing_date, amount, insurance_info, measure_outcomes);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No bills found with ID %s under YOUR name, please try again.\n\n", search_id);
    }

    printf("\n");
    fclose(file);
}

int view_ownBILLS(char searchID[100]) {

    FILE *file = fopen("billing_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    printf("Search Results for '%s':\n", searchID);
    printf("\n");
    printf("| Bill ID    | Patient ID | Billing Date     | Amount | Insurance Info | Measure Outcomes |\n");
    printf("|------------|------------|------------------|--------|----------------|------------------|\n");

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *bill_id = strtok(line, "|");
        char *patient_id = strtok(NULL, "|");
        char *billing_date = strtok(NULL, "|");
        char *amount = strtok(NULL, "|");
        char *insurance_info = strtok(NULL, "|");
        char *measure_outcomes = strtok(NULL, "|");

        if (measure_outcomes != NULL) {
            measure_outcomes[strcspn(measure_outcomes, "\n")] = '\0';
        }

        if (patient_id != NULL && strstr(patient_id, searchID) != NULL) {
            printf("| %-10s | %-10s | %-16s | %-6s | %-14s | %-16s |\n",
                   bill_id, patient_id, billing_date, amount, insurance_info, measure_outcomes);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No bills found with ID %s, please try again.\n\n", searchID);
    }

    printf("\n");
    fclose(file);
}