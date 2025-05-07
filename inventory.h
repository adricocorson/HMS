#include <stdio.h>
#include <string.h>

void view_inventory() {
    FILE *file = fopen("inventory.txt", "r");

    char line[100];
    printf("__________________________________________\n");
    printf("| InvID |      Item Name      | Quantity |\n");
    printf("|-------|---------------------|----------|\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        char *token = strtok(line, "|");

        printf("| %-5s |", token);
        token = strtok(NULL, "|");

        printf(" %-19s |", token);
        token = strtok(NULL, "|");

        printf(" %-8s |\n", token);
        
    }
    fclose(file);
    printf("|_______|_____________________|__________|\n");
    printf("\n");
}

void search_inventory() {
    getchar();
    char search_item[200];
    printf("Enter the InventoryID or Name of item to search: ");
    fgets(search_item, sizeof(search_item), stdin);
    search_item[strcspn(search_item, "\n")] = '\0';
    printf("\n");

    FILE *file = fopen("inventory.txt", "r");
    char line[200];
    int found = 0;

    printf("Search results for '%s':\n", search_item);
    printf("__________________________________________\n");
    printf("| InvID |      Item Name      | Quantity |\n");
    printf("|-------|---------------------|----------|\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char invID[6];
        char item[20];
        char quantity[8];

        // InvID
        strcpy(invID, token);
        token = strtok(NULL, "|");

        // Item Name
        strcpy(item, token);
        token = strtok(NULL, "|");

        // Quantity
        strcpy(quantity, token);

        if (strstr(item, search_item) != NULL || strstr(invID, search_item) != NULL){
            for (int i=0; i<1; i++){    // avoid infinite loop
                printf("| %-5s | %-19s | %-8s |\n", invID, item, quantity);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("| No items found called %-17s|\n", search_item);
    }
    fclose(file);
    printf("|_______|_____________________|__________|\n");
    printf("\n");
}

void add_item() {
    FILE *file = fopen("inventory.txt", "r+");
    char line[200];
    char search_invID[6], invID[6];
    char item[20];
    char quantity[8];
    
    printf("Enter InventoryID (IN000): ");
    scanf("%s", search_invID);
    search_invID[strcspn(search_invID, "\n")] = '\0';
    if (strstr(search_invID, "IN") != NULL) {
        int invID_exists = 0;
        int stopLoop = 0;
        while (fgets(line, sizeof(line), file) != NULL && stopLoop == 0) {

            char *token = strtok(line, "|");

            // InvID
            strcpy(invID, token);
            token = strtok(NULL, "|");

            // Item Name
            strcpy(item, token);
            token = strtok(NULL, "|");

            // Quantity
            strcpy(quantity, token);
            
            if (strcmp(invID, search_invID) == 0) {
                invID_exists = 1;
                stopLoop = 1;
            }
        }

        if (invID_exists == 0) {
            getchar();
            printf("Enter Item Name: ");
            fgets(item, sizeof(item), stdin);
            item[strcspn(item, "\n")] = '\0';
            printf("Enter Quantity: ");
            scanf("%s", quantity);

            fprintf(file, "%s|%s|%s\n", search_invID, item, quantity);
            fclose(file);

            printf("\nItem added to inventory\n\n");
        } else {
            printf("\nInvID already exists\n\n");
        }

    } else {
        printf("\nInvalid InvID\n\n");
    }
}

void update_item() {
    view_inventory();

    FILE *file = fopen("inventory.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char invID[6];
    char item[20];
    char quantity[8], new_quantity[8];
    char update_item[20];

    getchar();
    printf("Enter the InventoryID or Name of item to update: ");
    fgets(update_item, sizeof(update_item), stdin);
    update_item[strcspn(update_item, "\n")] = '\0';
    printf("Enter new quantity: ");
    fgets(new_quantity, sizeof(new_quantity), stdin);
    new_quantity[strcspn(new_quantity, "\n")] = '\0';

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");

        // InvID
        strcpy(invID, token);
        token = strtok(NULL, "|");

        // Item Name
        strcpy(item, token);
        token = strtok(NULL, "|");

        // Quantity
        strcpy(quantity, token);

        if (strcmp(item, update_item) != 0 && strcmp(invID, update_item) != 0){
            fprintf(temp, "%s|%s|%s\n", invID, item, quantity);         
        } else {
            fprintf(temp, "%s|%s|%s\n", invID, item, new_quantity);     
        }
    }

    fclose(file);
    fclose(temp);

    // Replace the original file with the temporary file
    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    printf("Item '%s' updated in inventory.\n", update_item);
}

void remove_item() {
    view_inventory();

    FILE *file = fopen("inventory.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char invID[6];
    char item[20];
    char quantity[8];
    char remove_item[20];

    printf("Enter InventoryID or Name of item to remove: ");
    scanf("%s", remove_item);

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");

        // InvID
        strcpy(invID, token);
        token = strtok(NULL, "|");

        // Item Name
        strcpy(item, token);
        token = strtok(NULL, "|");

        // Quantity
        strcpy(quantity, token);

        // Write to temporary file if item is not the one to be removed
        if (strcmp(item, remove_item) != 0 && strcmp(invID, remove_item) != 0){
            fprintf(temp, "%s|%s|%s\n", invID, item, quantity);
        }
    }

    fclose(file);
    fclose(temp);

    // Replace the original file with the temporary file
    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    printf("Item '%s' removed from inventory.\n", remove_item);
}