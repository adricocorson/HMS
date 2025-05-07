#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int manage_availability(char doctorID[20]){

    char doctorName[100];
    char date[20];
    int startTime, endTime;

    FILE *login = fopen("staff_login.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), login) != NULL) {
        char *id = strtok(line, "|");
        char *password = strtok(NULL, "|");
        char *name = strtok(NULL, "|");

        if (strcmp(id, doctorID) == 0) {
            strcpy(doctorName, name);
        }
    }

    getchar();
    printf("Enter Date DD/MM/YYYY: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    if (strlen(date) != 10 || date[2] != '/' || date[5] != '/'){
        printf("Invalid date format\n");
        return 0;
    }
    printf("Enter Start Time (Hour only) (0-24): ");
    scanf("%d", &startTime);
    if (startTime < 0 || startTime > 24){
        printf("Invalid time\n");
        return 0;
    }
    printf("Enter End Time (Hour only) (0-24): ");
    scanf("%d", &endTime);
    if (endTime < 0 || endTime > 24 || endTime <= startTime){
        printf("Invalid time\n");
        return 0;
    }

    FILE *file = fopen("appointment.txt", "a");

    for (startTime; startTime < endTime; startTime++){
        fprintf(file, "%s|%s|%s|%d|Available|Na|Na|\n", doctorID, doctorName, date, startTime);
    }

    fclose(file);

    printf("Availability set for: %s\n", date);

}

void view_drSchedule(){

    getchar();
    char searchDR[100];
    printf("Enter the Doctor's ID or Name to search: ");
    fgets(searchDR, sizeof(searchDR), stdin);
    searchDR[strcspn(searchDR, "\n")] = '\0';

    FILE *file = fopen("appointment.txt", "r");
    char line[200];
    int found = 0;

    printf("Search results for '%s':\n", searchDR);
    printf("______________________________________________________________________________________________________________________\n");
    printf("| Doctor ID |      Doctor Name       |    Date    |      Time     |   Status   | Patient ID |         Patient        |\n");
    printf("|-----------|------------------------|------------|---------------|------------|------------|------------------------|\n");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        int time;
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        time = atoi(token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if (strstr(doctorID, searchDR) != NULL || strstr(doctorName, searchDR) != NULL){
            printf("| %-9s | %-22s | %-10s | %02d:00 - %02d:00 | %-10s | %-10s | %-22s |\n",
                doctorID, doctorName, date, time, time+1, status, patientID, patient);
            found = 1;
        }
    }
    if (found == 0){
        printf("No results found\n");
    }
    fclose(file);
    printf("|___________|________________________|____________|_______________|____________|____________|________________________|\n");
    printf("\n");

}

void view_appointment_byDate(){
    
        char searchDate[20];
        printf("Enter Date DD/MM/YYYY: ");
        scanf("%s", searchDate);
        if (strlen(searchDate) != 10 || searchDate[2] != '/' || searchDate[5] != '/'){
            printf("Invalid date format\n");
            return;
        }
    
        FILE *file = fopen("appointment.txt", "r");
        char line[200];
        int found = 0;
    
        printf("Appointments on %s:\n", searchDate);
        printf("______________________________________________________________________________________________________________________\n");
        printf("| Doctor ID |      Doctor Name       |    Date    |      Time     |   Status   | Patient ID |         Patient        |\n");
        printf("|-----------|------------------------|------------|---------------|------------|------------|------------------------|\n");
    
        while(fgets(line, sizeof(line), file) != NULL){
            line[strcspn(line, "\n")] = '\0';
    
            char *token = strtok(line, "|");
            char doctorID[10];
            char doctorName[23];
            char date[20];
            int time;
            char status[10];
            char patientID[10];
            char patient[23];
    
            strcpy(doctorID, token);
            token = strtok(NULL, "|");
            strcpy(doctorName, token);
            token = strtok(NULL, "|");
            strcpy(date, token);
            token = strtok(NULL, "|");
            time = atoi(token);
            token = strtok(NULL, "|");
            strcpy(status, token);
            token = strtok(NULL, "|");
            strcpy(patientID, token);
            token = strtok(NULL, "|");
            strcpy(patient, token);
    
            if (strstr(date, searchDate) != NULL){
                printf("| %-9s | %-22s | %-10s | %02d:00 - %02d:00 | %-10s | %-10s | %-22s |\n",
                    doctorID, doctorName, date, time, time+1, status, patientID, patient);
                found = 1;
            }
        }
        if (found == 0){
            printf("No results found\n");
        }
        fclose(file);
        printf("|___________|________________________|____________|_______________|____________|____________|________________________|\n");
        printf("\n");
    
    
}

void appointment_trend(){
    char searchDate[25];
    getchar();
    printf("Enter Date DD/MM/YYYY: ");
    fgets(searchDate, sizeof(searchDate), stdin);
    searchDate[strcspn(searchDate, "\n")] = '\0';

    FILE *file = fopen("appointment.txt", "r");
    char line[200];
    int found = 0;
    int appointments[24] = {0};

    while (fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        int time;
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        time = atoi(token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if (strstr(date, searchDate) != NULL && strstr(status, "Booked") != NULL){
            appointments[time] += 1;
            found = 1;
        }
    }
    int mostAppointments = 0, mostTime = 0;
    if (found == 0){
        printf("No appointments found\n");
    } else {
        printf("Appointment count for %s:\n", searchDate);
        printf("______________________________________\n");
        printf("|      Time     | No. of Appointment |\n");
        printf("|---------------|--------------------|\n");
        for (int i = 0; i < 24; i++){
            if (appointments[i] > 0){
                printf("| %02d:00 - %02d:00 | %18d |\n", i, i+1, appointments[i]);
                if(appointments[i] > mostAppointments){
                    mostAppointments = appointments[i];
                    mostTime = i;
                }
            }
        }
        printf("|_______________|____________________|\n");
    }
    fclose(file);

    printf("\n Duration with most appointments on %s: %02d:00 - %02d:00, with %d appointments\n", searchDate, mostTime, mostTime+1, mostAppointments);
}

int create_appointment(char ID[20]){
    char patientName[100];
    char searchdate[20];
    char searchtime[20];
    char searchDR[25];

    FILE *login = fopen("patient_login.txt", "r");
    char line1[200];
    while(fgets(line1, sizeof(line1), login) != NULL){
        line1[strcspn(line1, "\n")] = '\0';
        char *token = strtok(line1, "|");
        char patientID[20];
        char name[100];
        char password[20];

        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(password, token);
        token = strtok(NULL, "|");
        strcpy(name, token);

        if (strstr(patientID, ID) != NULL){
            strcpy(patientName, name);
        }
    }


    getchar();
    printf("Enter Date DD/MM/YYYY: ");
    fgets(searchdate, sizeof(searchdate), stdin);
    searchdate[strcspn(searchdate, "\n")] = '\0';
    if (strlen(searchdate) != 10 || searchdate[2] != '/' || searchdate[5] != '/'){
        printf("Invalid date format\n");
        return 0;
    }
    printf("Enter the Start Time of appointment (Hour only) (0-24): ");
    fgets(searchtime, sizeof(searchtime), stdin);
    searchtime[strcspn(searchtime, "\n")] = '\0';
    if (atoi(searchtime) < 0 || atoi(searchtime) > 24){
        printf("Invalid time\n");
        return 0;
    }
    printf("Enter Doctor ID or Name: ");
    fgets(searchDR, sizeof(searchDR), stdin);
    searchDR[strcspn(searchDR, "\n")] = '\0';

    FILE *file = fopen("appointment.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");

    char line[200];
    int found = 0;

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        char time[3];
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        strcpy(time, token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if (strstr(date, searchdate) != NULL && strstr(time, searchtime) && (strstr(doctorID, searchDR) != NULL || strstr(doctorName, searchDR) != NULL) && strstr(status, "Available") != NULL){
            fprintf(tempfile, "%s|%s|%s|%s|Booked|%s|%s|\n", doctorID, doctorName, date, time, ID, patientName);
            found = 1;
        } else {
            fprintf(tempfile, "%s|%s|%s|%s|%s|%s|%s|\n", doctorID, doctorName, date, time, status, patientID, patient);
        }
    }
    if (found == 0){
        printf("No available slot found\n");
    }
    fclose(file);
    fclose(tempfile);

    remove("appointment.txt");
    rename("temp.txt", "appointment.txt");
}

int view_patientAppointment(char search[20]){

    FILE *file = fopen("appointment.txt", "r");
    char line[200];
    int found = 0;

    printf("Appointments for Patient %s:\n", search);
    printf("______________________________________________________________________________________________________________________\n");
    printf("| Doctor ID |      Doctor Name       |    Date    |      Time     |   Status   | Patient ID |         Patient        |\n");
    printf("|-----------|------------------------|------------|---------------|------------|------------|------------------------|\n");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        int time;
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        time = atoi(token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if (strstr(patientID, search) != NULL){
            printf("| %-9s | %-22s | %-10s | %02d:00 - %02d:00 | %-10s | %-10s | %-22s |\n",
                doctorID, doctorName, date, time, time+1, status, patientID, patient);
            found = 1;
        }
    }
    if (found == 0){
        printf("|                                              No Result Found                                                       |\n");
    }
    fclose(file);
    printf("|___________|________________________|____________|_______________|____________|____________|________________________|\n");
    printf("\n");

}

int reschedule_appointment(char searchID[10]){

    char searchdate[20],searchtime[10], searchName[100];
    FILE *login = fopen("patient_login.txt", "r");
    char line1[200];
    while(fgets(line1, sizeof(line1), login) != NULL){
        line1[strcspn(line1, "\n")] = '\0';
        char *token = strtok(line1, "|");
        char ID[20];
        char name[100];
        char password[20];
        char role[20];
        char status[20];

        strcpy(ID, token);
        token = strtok(NULL, "|");
        strcpy(password, token);
        token = strtok(NULL, "|");
        strcpy(name, token);


        if (strstr(ID, searchID) != NULL){
            strcpy(searchName, name);
        }
    }
    fclose(login);

    getchar();
    printf("Enter Date (DD/MM/YYYY) of appointment to reschedule: ");
    fgets(searchdate, sizeof(searchdate), stdin);
    searchdate[strcspn(searchdate, "\n")] = '\0';

    printf("Enter Time (Hour only) (0-24) of appointment to reschedule: ");
    fgets(searchtime, sizeof(searchtime), stdin);
    searchtime[strcspn(searchtime, "\n")] = '\0';

    FILE *file = fopen("appointment.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");

    char line[200];
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        char time[3];
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        strcpy(time, token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if (strstr(patientID, searchID) != NULL && strstr(date, searchdate) != NULL && strstr(time, searchtime) != NULL){
            fprintf(tempfile, "%s|%s|%s|%s|Available|Na|Na|\n", doctorID, doctorName, date, time);
            found = 1;
        } else {
            fprintf(tempfile, "%s|%s|%s|%s|%s|%s|%s|\n", doctorID, doctorName, date, time, status, patientID, patient);
        }
    }

    if (found == 0){
    printf("No appointment found\n");
    }

    fclose(file);
    fclose(tempfile); 
    remove("appointment.txt");
    rename("temp.txt", "appointment.txt");

    found = 0;
    printf("Enter new Date DD/MM/YYYY: ");
    char newdate[20],newtime[10],newDR[25];
    fgets(newdate, sizeof(newdate), stdin);
    newdate[strcspn(newdate, "\n")] = '\0';
    printf("Enter new Time (Hour only) (0-24): ");
    fgets(newtime, sizeof(newtime), stdin);
    newtime[strcspn(newtime, "\n")] = '\0';
    printf("Enter Doctor ID or Name: ");
    fgets(newDR, sizeof(newDR), stdin);
    newDR[strcspn(newDR, "\n")] = '\0';

    file = fopen("appointment.txt", "r");
    tempfile = fopen("temp.txt", "w");

    found = 0;
    while (fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        char time[3];
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        strcpy(time, token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if (strstr(date, newdate) != NULL && strstr(time, newtime) != NULL && (strstr(doctorID, newDR) != NULL || strstr(doctorName, newDR) != NULL) && strstr(status, "Available") != NULL){
            fprintf(tempfile, "%s|%s|%s|%s|Booked|%s|%s|\n", doctorID, doctorName, newdate, newtime, searchID, searchName);
            found = 1;
        } else {
            fprintf(tempfile, "%s|%s|%s|%s|%s|%s|%s|\n", doctorID, doctorName, date, time, status, patientID, patient);
        }

    }
    if (found == 0){
    printf("No available slot found\n");
    } else {
    printf("Appointment rescheduled\n");
    }

    fclose(file);
    fclose(tempfile);

    remove("appointment.txt");
    rename("temp.txt", "appointment.txt");
}

int cancel_appointment(char searchID[10]){
    char searchdate[20], searchtime[10];
    getchar();
    printf("Enter Date (DD/MM/YYYY) of appointment to cancel: ");
    fgets(searchdate, sizeof(searchdate), stdin);
    searchdate[strcspn(searchdate, "\n")] = '\0';

    printf("Enter Time (Hour only) (0-24) of appointment to cancel: ");
    fgets(searchtime, sizeof(searchtime), stdin);
    searchtime[strcspn(searchtime, "\n")] = '\0';

    FILE *file = fopen("appointment.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");

    char line[200];
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "|");
        char doctorID[10];
        char doctorName[23];
        char date[20];
        char time[3];
        char status[10];
        char patientID[10];
        char patient[23];

        strcpy(doctorID, token);
        token = strtok(NULL, "|");
        strcpy(doctorName, token);
        token = strtok(NULL, "|");
        strcpy(date, token);
        token = strtok(NULL, "|");
        strcpy(time, token);
        token = strtok(NULL, "|");
        strcpy(status, token);
        token = strtok(NULL, "|");
        strcpy(patientID, token);
        token = strtok(NULL, "|");
        strcpy(patient, token);

        if ((strstr(patientID, searchID) != NULL) && strstr(date, searchdate) != NULL && strstr(time, searchtime) != NULL){
            fprintf(tempfile, "%s|%s|%s|%s|Available|Na|Na|\n", doctorID, doctorName, date, time);
            found = 1;
        } else {
            fprintf(tempfile, "%s|%s|%s|%s|%s|%s|%s|\n", doctorID, doctorName, date, time, status, patientID, patient);
        }
    }

    fclose(file);
    fclose(tempfile);

    if (found == 0){
        printf("No appointment found\n");
        remove("temp.txt");
    } else {
        printf("Appointment cancelled\n");
        remove("appointment.txt");
        rename("temp.txt", "appointment.txt");
    }

    return 0;
}
