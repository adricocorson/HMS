#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calculate_analytics(float amounts[], int count) {
    float sum = 0;
    float min = amounts[0];
    float max = amounts[0];

    for (int i = 0; i < count; i++) {
        sum += amounts[i];
        if (amounts[i] < min) {
            min = amounts[i];
        }
        if (amounts[i] > max) {  // Corrected the comparison to find the max value
            max = amounts[i];
        }
    }

    float average = sum / count;  // Corrected syntax error
    printf("\n");
    printf("-------Statistics amount-------\n");
    printf("Average Amount: %.2f\n", average);
    printf("Minimum Amount: %.2f\n", min);
    printf("Maximum Amount: %.2f\n", max);
    printf("\n");
}

void generate_REPORT_patient() {
    char condition[100];
    getchar();
    printf("Enter the Patient ID to generate report for: ");
    fgets(condition, sizeof(condition), stdin);
    condition[strcspn(condition, "\n")] = '\0';

    float amounts[100];
    int count = 0;

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

    printf("\nDoctor Report for Condition: %s\n", condition);
    printf("| Bill ID    | Patient ID | Billing Date | Amount | Insurance Info |\n");
    printf("|------------|------------|--------------|--------|----------------|\n");

    for (int i = 0; i < billCount; i++) {
        char patient_id [100];
        strcpy(patient_id,bills[i].patient_id);

        if (strcmp(bills[i].patient_id, condition) == 0) {
            printf("| %-10s | %-10s | %-12s | %-6.2f | %-14s |\n",
                   bills[i].bill_id, bills[i].patient_id, bills[i].billing_date,
                   bills[i].amount, bills[i].insurance_info);
            amounts[count++] = bills[i].amount;
        }
    }

    if (count > 0) {
        calculate_analytics(amounts, count);
    } else {
        printf("No records found for condition: %s\n", condition);
    }
}

void generate_REPORT_unit() {
    char unit[100];
    getchar();
    printf("Enter the unit to generate report for: ");
    fgets(unit, sizeof(unit), stdin);
    unit[strcspn(unit, "\n")] = '\0';

    float amounts[100];
    int count = 0;

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

    printf("\nNurse Report for Unit: %s\n", unit);
    printf("| Bill ID    | Patient ID | Billing Date | Amount | Insurance Info |\n");
    printf("|------------|------------|--------------|--------|----------------|\n");

    for (int i = 0; i < billCount; i++) {
        if (strcmp(bills[i].insurance_info, unit) == 0) {
            printf("| %-10s | %-10s | %-12s | %-6.2f | %-14s |\n",
                   bills[i].bill_id, bills[i].patient_id, bills[i].billing_date,
                   bills[i].amount, bills[i].insurance_info);
            amounts[count++] = bills[i].amount;
        }
    }

    if (count > 0) {
        calculate_analytics(amounts, count);
    } else {
        printf("No records found for unit: %s\n", unit);
    }
}

void generate_REPORT_condition(){
    char condition[100];
    getchar();
    printf("Enter the condition to generate report for: ");
    fgets(condition, sizeof(condition), stdin);
    condition[strcspn(condition, "\n")] = '\0';

    float amounts[100];
    int count = 0;

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

    printf("\nDoctor Report for Condition: %s\n", condition);
    printf("| Bill ID    | Patient ID | Billing Date | Amount | Insurance Info |\n");
    printf("|------------|------------|--------------|--------|----------------|\n");

    for (int i = 0; i < billCount; i++) {
        if (strcmp(bills[i].measure_outcomes, condition) == 0) {
            printf("| %-10s | %-10s | %-12s | %-6.2f | %-14s |\n",
                   bills[i].bill_id, bills[i].patient_id, bills[i].billing_date,
                   bills[i].amount, bills[i].insurance_info);
            amounts[count++] = bills[i].amount;
        }
    }

    if (count > 0) {
        calculate_analytics(amounts, count);
    } else {
        printf("No records found for condition: %s\n", condition);
    }
}