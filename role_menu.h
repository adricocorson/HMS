#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login_registration.h"
#include "ehr.h"
#include "dr_appointment.h"
#include "inventory.h"
#include "billing.h"
#include "reports.h"

int patient_main (char ID[20]){
    int choice;
    int i = 0;
    while (i<1){
        printf("\nPatient Menu\n");
        printf("1. View Doctors Available on a date\n");
        printf("2. View a Doctor's Availability\n");
        printf("3. Create Appointment\n");
        printf("4. View Appointment Made\n");
        printf("5. Reschedule Appointment\n");
        printf("6. Cancel Appointment\n");
        printf("7. View EHR\n");
        printf("8. View Billings\n");
        printf("9. Search Specific Bill\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            view_appointment_byDate();
        } else if (choice == 2){
            view_drSchedule();
        } else if (choice == 3){
            create_appointment(ID);
        } else if (choice == 4){
            view_patientAppointment(ID);
        } else if (choice == 5){
            reschedule_appointment(ID);
        } else if (choice == 6){
            cancel_appointment(ID);
        } else if (choice == 7){
            search_ownEHR(ID);
        } else if (choice == 8){
            view_ownBILLS(ID);
        } else if (choice == 9){
            search_ownBILLS(ID);
        } else if (choice == 0){
            i = 1;
        } else {
            printf("Invalid choice\n");
        }
    }
}

int admin_main(char ID[20]){
    int i=0;
    while(i<1){
        int choice;
        printf("\nHospital Administrator Menu\n");
        printf("1. Patient Registration\n");
        printf("2. Staff Registration\n");
        printf("3. Appointment Trends\n");
        printf("4. View Item in Inventory\n");
        printf("5. Search Item in Inventory\n");
        printf("6. Add Patient Electronic Health Record\n");
        printf("7. View Patient Electronic Health Record\n");
        printf("8. Search Patient Electronic Health Record\n");
        printf("9. Modify Patient Electronic Health Record\n");
        printf("10. Add Bills and Payments\n");
        printf("11. View Bills and Payments\n");
        printf("12. Search Bills and Payments\n");
        printf("13. Modify Bills and Payments\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            patient_registration();
        } else if (choice == 2){
            staff_registration();
        } else if (choice == 3){
            appointment_trend();
        } else if (choice == 4){
            view_inventory();
        } else if (choice == 5){
            search_inventory();
        } else if (choice == 6){
            add_EHR_patient();
        } else if (choice == 7){
            view_EHR_patient();
        } else if (choice == 8){
            search_EHR_patient();
        } else if (choice == 9){
            modify_EHR_patient();
        } else if (choice == 10){
            add_BILLS();
        } else if (choice == 11){
            view_BILLS();
        } else if (choice == 12){
            search_BILLS();
        } else if (choice == 13){
            modify_BILLS();
        } else if (choice == 0){
            i++;
        } else {
            printf("Invalid choice\n");
        }


    }    
}

int nurse_main(char ID[20]){
    int i = 0;
    while(i < 1){
        int choice;
        printf("\nStaff Nurse Menu\n");
        printf("1. View Doctor Schedule\n");
        printf("2. View Doctor(s) Available on a Date\n");
        printf("3. View Hospital Inventory\n");
        printf("4. Search Hospital Inventory\n");
        printf("5. Add New Item to Inventory\n");
        printf("6. Update Current Inventory\n");
        printf("7. Remove Item in Inventory\n");
        printf("8. Generate Report Based on Insurance\n");
        printf("9. Generate Report Based on Patient\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            view_drSchedule();
        } else if (choice == 2){
            view_appointment_byDate();
        } else if (choice == 3){
            view_inventory();
        } else if (choice == 4){
            search_inventory();
        } else if (choice == 5){
            add_item();
        } else if (choice == 6){
            update_item();
        } else if (choice == 7){
            remove_item();
        } else if (choice == 8){
            generate_REPORT_unit();
        } else if (choice == 9){
            generate_REPORT_patient();
        } else if (choice == 0){
            i = 1;
        } else {
            printf("Invalid choice\n");
        }

    }
}

int doctor_main(char ID[20]){
    int choice;
    int i = 0;
    while (i<1) {
        printf("\nDoctor Menu\n");
        printf("1. Doctor Scheduler\n");
        printf("2. View EHR\n");
        printf("3. View Specific Patient's EHR\n");
        printf("4. Generate Report on a Patient\n");
        printf("5. Generate Report on a Condition\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            manage_availability(ID);
        }  else if (choice == 2) {
            view_EHR_patient();
        } else if (choice == 3) {
            search_EHR_patient();
        } else if (choice == 4) {
            generate_REPORT_patient();
        } else if (choice == 5) {
            generate_REPORT_condition();
        } else if (choice == 0) {
            i = 1;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
}

