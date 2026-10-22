#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* ================= PATIENT STRUCTURE ================= */

struct patient
{
    int patientid;
    char name[30];
    int age;
    char gender[10];
    char disease[30];
    char doctor[30];
    float doctorfees;
    float paid;
    float due;
    int roomno;
    int bedno;
}pat;


/* ================= STAFF STRUCTURE ================= */

struct staff
{
    int staffid;
    char name[30];
    char designation[20];
    char department[30];
     char phone[15];
    float salary;
}staff;


/* ================= MEDICINE STRUCTURE ================= */

struct medicine
{
    int medicineid;
    char medicinename[30];
    char patientname[30];
    int patientid;
    int quantity;
    float price;
}med;


/* ================= APPOINTMENT STRUCTURE ================= */

struct appointment
{
    int appointmentid;
    int patientid;
    char patientname[30];
    char doctor[30];
    char date[15];
    char time[10];
}app;


/* ================= ROOM STRUCTURE ================= */

struct room
{
    int roomno;
    int bedno;
    int patientid;
    char patientname[30];
    char disease[30];
    int available;
}room;


/* =========================================================
   PATIENT SECTION
   ========================================================= */
   struct blood
{
    int bloodid;
    int patientid;
    char patientname[30];
    char bloodgroup[10];
    char donorname[30];
    int units;
    char date[15];
}blood;

struct labreport
{
    int reportid;
    int patientid;
    char patientname[30];
    char department[20];
    char category[30];
    char testname[50];
    char result[50];
    char unit[20];
    char normallevel[50];
    char date[15];
}lab;


// ===== FUNCTION DECLARATIONS =====

// LAB menu functions
void labmenu();
void pathologymenu();
void haematologymenu();
void cbcmenu();

// CBC test functions
void haemoglobin();
void totalwbc();
void differentialwbc();
void rbccount();
void plateletcount();
void mcv();
void mch();
void mchc();
void rdw();

// Haematology test functions
void esr();
void coagulationmenu();
void pt();
void inr();
void aptt();
void bloodgroupingmenu();
void abobloodgroup();
// Rh Typing function
void rhtyping();
// Biochemistry menu functions
void biochemistrymenu();
// Blood Glucose menu and test functions
void bloodglucosemenu();
void fastingbloodsugar();
void postprandialbloodsugar();
void randombloodsugar();
// Lipid Profile menu and test functions
void lipidprofilemenu();
void totalcholesterol();
void hdl();
void ldl();
void vldl();
void triglycerides();
// Liver Function Test menu and test functions
void liverfunctionmenu();
void bilirubin();
void sgot();
void sgpt();
void alp();
void totalprotein();
void albumin();
// Kidney Function Test menu and test functions
void kidneyfunctionmenu();
void urea();
void creatinine();
void uricacid();
void electrolytes();
// Microbiology menu and sub-menu functions
void microbiologymenu();
void stoolmenu();
void culturemenu();
// Urine menu and test functions
void urinemenu();
void routineurine();
void urinecultureandsensitivity();
// Stool menu and test functions
void stoolmenu();
void routinestool();
void stooloccultblood();
// Culture menu and test functions
void culturemenu();
void bloodculture();
void urineculture();
void sputumculture();
// Histopathology menu and test functions
void histopathologymenu();
void biopsy();
void fnac();
void cytology();
// Radiology menu and sub-menu functions
void radiologymenu();
void xraymenu();
void ultrasoundmenu();
void ctscanmenu();
void mrimenu();
// X-Ray menu and test functions
void chestxray();
void xrayskull();
void xrayspine();
void xraylimb();
// Ultrasound menu and test functions
void usgabdomen();
void usgpelvis();
void usgpregnancy();
void usgkub();
// CT Scan menu and test functions
void ctbrain();
void ctchest();
void ctabdomen();
void ctspine();
// MRI menu and test functions
void mrispine();
void mribrain();
void mriknee();
void mriabdomen();
// Cardiology menu and sub-menu functions
void cardiologymenu();
void ecgmenu();
void echocardiographymenu();
void stresstestmenu();
void holtermenu();
// ECG menu and test functions
void restingecg();
void twelveleadecg();
// Echocardiography menu and test functions
void echo2d();
void dopplerecho();
void colourdoppler();
// Stress test menu and test function
void stresstestmenu();
void tmt();
// Holter menu and test functions
void holtermenu();
void holter24hour();
void holter48hour();
// LAB report display function
void displaylabreports();
// LAB report search function
void searchlabreports();
// LAB report update function
void updatelabreport();
// LAB report delete function
void deletelabreport();
void labreportssummary();  // Displays the LAB report summary
int getnextlabreportid();  // Generates the next LAB report ID
/* STAFF FUNCTION DECLARATIONS */
void staffinsert();   // Add a staff record
void staffdisplay();  // Display all staff records
void staffsearch();   // Search for a staff record
void staffupdate();   // Update a staff record
void staffdelete();   // Delete a staff record
void staffmenu();  // Displays the Staff Management menu

/* FUNCTION TO CHECK PATIENT ID */

int avlpatientid(int pid)
{
    FILE *fp;

    fp = fopen("Patient", "r");

    if(fp == NULL)
        return 0;

    while(fread(&pat, sizeof(pat), 1, fp))
    {
        if(pat.patientid == pid)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}


/* FUNCTION TO INSERT PATIENT */

void patientinsert()
{
    FILE *fp;

    fp = fopen("Patient", "a");

    printf("\nEnter Patient ID (Numbers only) : ");
    scanf("%d", &pat.patientid);

    if(avlpatientid(pat.patientid) == 1)
    {
        printf("\nPatient ID already exists.\n");
        fclose(fp);
        return;
    }

    printf("Enter Patient Name : ");
    scanf("%s", pat.name);

    printf("Enter Age : ");
    scanf("%d", &pat.age);

    printf("Enter Gender : ");
    scanf("%s", pat.gender);

    printf("Enter Cause/Disease : ");
    scanf("%s", pat.disease);

    printf("Enter Doctor Name : ");
    scanf("%s", pat.doctor);

    printf("Enter Doctor Fees : ");
    scanf("%f", &pat.doctorfees);

    printf("Enter Payment Paid : ");
    scanf("%f", &pat.paid);

    pat.due = pat.doctorfees - pat.paid;

    printf("Enter Room Number : ");
    scanf("%d", &pat.roomno);

    printf("Enter Bed Number : ");
    scanf("%d", &pat.bedno);

    fwrite(&pat, sizeof(pat), 1, fp);

    fclose(fp);

    printf("\nPATIENT RECORD ADDED SUCCESSFULLY\n");
}


/* FUNCTION TO DISPLAY PATIENT DETAILS */

void patientdisplay()
{
    FILE *fp;

    fp = fopen("Patient", "r");

    if(fp == NULL)
    {
        printf("\nNo patient records found.\n");
        return;
    }

    printf("\n==============================================================\n");
    printf("                    PATIENT DETAILS\n");
    printf("==============================================================\n");

    while(fread(&pat, sizeof(pat), 1, fp))
    {
        printf("\nPatient ID      : %d", pat.patientid);
        printf("\nPatient Name    : %s", pat.name);
        printf("\nAge             : %d", pat.age);
        printf("\nGender          : %s", pat.gender);
        printf("\nCause/Disease   : %s", pat.disease);
        printf("\nDoctor          : %s", pat.doctor);
        printf("\nDoctor Fees     : %.2f", pat.doctorfees);
        printf("\nPayment Paid    : %.2f", pat.paid);
        printf("\nPayment Due     : %.2f", pat.due);
        printf("\nRoom Number     : %d", pat.roomno);
        printf("\nBed Number      : %d", pat.bedno);

        printf("\n--------------------------------------------------------------\n");
    }

    fclose(fp);
}


/* FUNCTION TO SEARCH PATIENT */

void patientsearch()
{
    FILE *fp;
    int id;

    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    if(avlpatientid(id) == 0)
    {
        printf("\nPatient ID %d not found.\n", id);
        return;
    }

    fp = fopen("Patient", "r");

    while(fread(&pat, sizeof(pat), 1, fp))
    {
        if(pat.patientid == id)
        {
            printf("\n================ PATIENT FOUND ================\n");

            printf("Patient ID    : %d\n", pat.patientid);
            printf("Name          : %s\n", pat.name);
            printf("Age           : %d\n", pat.age);
            printf("Gender        : %s\n", pat.gender);
            printf("Cause/Disease : %s\n", pat.disease);
            printf("Doctor        : %s\n", pat.doctor);
            printf("Doctor Fees   : %.2f\n", pat.doctorfees);
            printf("Payment Paid  : %.2f\n", pat.paid);
            printf("Payment Due   : %.2f\n", pat.due);
            printf("Room No.      : %d\n", pat.roomno);
            printf("Bed No.       : %d\n", pat.bedno);

            break;
        }
    }

    fclose(fp);
}


/* FUNCTION TO DELETE PATIENT */

void patientdelete()
{
    FILE *fpo;
    FILE *fpt;

    int id;

    printf("\nEnter Patient ID to delete : ");
    scanf("%d", &id);

    if(avlpatientid(id) == 0)
    {
        printf("\nPatient ID not found.\n");
        return;
    }

    fpo = fopen("Patient", "r");
    fpt = fopen("TempFile", "w");

    while(fread(&pat, sizeof(pat), 1, fpo))
    {
        if(pat.patientid != id)
        {
            fwrite(&pat, sizeof(pat), 1, fpt);
        }
    }

    fclose(fpo);
    fclose(fpt);

    fpo = fopen("Patient", "w");
    fpt = fopen("TempFile", "r");

    while(fread(&pat, sizeof(pat), 1, fpt))
    {
        fwrite(&pat, sizeof(pat), 1, fpo);
    }

    fclose(fpo);
    fclose(fpt);

    printf("\nPATIENT DELETED SUCCESSFULLY\n");
}


/* FUNCTION TO UPDATE PATIENT */

void patientupdate()
{
    FILE *fpo;
    FILE *fpt;

    int id, ch;

    printf("\nEnter Patient ID to update : ");
    scanf("%d", &id);

    if(avlpatientid(id) == 0)
    {
        printf("\nPatient ID not found.\n");
        return;
    }

    fpo = fopen("Patient", "r");
    fpt = fopen("TempFile", "w");

    while(fread(&pat, sizeof(pat), 1, fpo))
    {
        if(pat.patientid != id)
        {
            fwrite(&pat, sizeof(pat), 1, fpt);
        }
        else
        {
            printf("\n1. Update Name");
            printf("\n2. Update Age");
            printf("\n3. Update Gender");
            printf("\n4. Update Cause/Disease");
            printf("\n5. Update Doctor");
            printf("\n6. Update Doctor Fees");
            printf("\n7. Update Payment");
            printf("\n8. Update Room");
            printf("\n9. Update All");

            printf("\n\nEnter your choice : ");
            scanf("%d", &ch);

            switch(ch)
            {
                case 1:
                    printf("Enter Name : ");
                    scanf("%s", pat.name);
                    break;

                case 2:
                    printf("Enter Age : ");
                    scanf("%d", &pat.age);
                    break;

                case 3:
                    printf("Enter Gender : ");
                    scanf("%s", pat.gender);
                    break;

                case 4:
                    printf("Enter Cause/Disease : ");
                    scanf("%s", pat.disease);
                    break;

                case 5:
                    printf("Enter Doctor : ");
                    scanf("%s", pat.doctor);
                    break;

                case 6:
                    printf("Enter Doctor Fees : ");
                    scanf("%f", &pat.doctorfees);

                    pat.due = pat.doctorfees - pat.paid;
                    break;

                case 7:
                    printf("Enter Payment Paid : ");
                    scanf("%f", &pat.paid);

                    pat.due = pat.doctorfees - pat.paid;
                    break;

                case 8:
                    printf("Enter Room Number : ");
                    scanf("%d", &pat.roomno);

                    printf("Enter Bed Number : ");
                    scanf("%d", &pat.bedno);
                    break;

                case 9:
                    printf("Enter Name : ");
                    scanf("%s", pat.name);

                    printf("Enter Age : ");
                    scanf("%d", &pat.age);

                    printf("Enter Gender : ");
                    scanf("%s", pat.gender);

                    printf("Enter Cause/Disease : ");
                    scanf("%s", pat.disease);

                    printf("Enter Doctor : ");
                    scanf("%s", pat.doctor);

                    printf("Enter Doctor Fees : ");
                    scanf("%f", &pat.doctorfees);

                    printf("Enter Payment Paid : ");
                    scanf("%f", &pat.paid);

                    pat.due = pat.doctorfees - pat.paid;

                    printf("Enter Room Number : ");
                    scanf("%d", &pat.roomno);

                    printf("Enter Bed Number : ");
                    scanf("%d", &pat.bedno);
                    break;

                default:
                    printf("Invalid choice.\n");
                    break;
            }

            fwrite(&pat, sizeof(pat), 1, fpt);
        }
    }

    fclose(fpo);
    fclose(fpt);

    fpo = fopen("Patient", "w");
    fpt = fopen("TempFile", "r");

    while(fread(&pat, sizeof(pat), 1, fpt))
    {
        fwrite(&pat, sizeof(pat), 1, fpo);
    }

    fclose(fpo);
    fclose(fpt);

    printf("\nPATIENT RECORD UPDATED\n");
}


/* =========================================================
   PATIENT BILL
   ========================================================= */

void bill()
{
    FILE *fp;
    int id;

    printf("\nEnter Patient ID for Bill : ");
    scanf("%d", &id);

    if(avlpatientid(id) == 0)
    {
        printf("\nPatient ID not found.\n");
        return;
    }

    fp = fopen("Patient", "r");

    while(fread(&pat, sizeof(pat), 1, fp))
    {
        if(pat.patientid == id)
        {
            printf("\n========================================\n");
            printf("              PATIENT BILL\n");
            printf("========================================\n");

            printf("Patient ID       : %d\n", pat.patientid);
            printf("Patient Name     : %s\n", pat.name);
            printf("Doctor           : %s\n", pat.doctor);
            printf("Doctor Fees      : %.2f\n", pat.doctorfees);
            printf("Payment Paid     : %.2f\n", pat.paid);
            printf("Payment Due      : %.2f\n", pat.due);
            printf("Room Number      : %d\n", pat.roomno);
            printf("Bed Number       : %d\n", pat.bedno);

            printf("========================================\n");

            if(pat.due <= 0)
                printf("Payment Status   : PAID\n");
            else
                printf("Payment Status   : PAYMENT DUE\n");

            printf("========================================\n");

            break;
        }
    }

    fclose(fp);
}


/* =========================================================
   MEDICINE SECTION
   ========================================================= */

void medicineinsert()
{
    FILE *fp;

    fp = fopen("Medicine", "a");

    printf("\nEnter Medicine ID : ");
    scanf("%d", &med.medicineid);

    printf("Enter Medicine Name : ");
    scanf("%s", med.medicinename);

    printf("Enter Patient ID : ");
    scanf("%d", &med.patientid);

    printf("Enter Patient Name : ");
    scanf("%s", med.patientname);

    printf("Enter Quantity : ");
    scanf("%d", &med.quantity);

    printf("Enter Price : ");
    scanf("%f", &med.price);

    fwrite(&med, sizeof(med), 1, fp);

    fclose(fp);

    printf("\nMEDICINE RECORD ADDED\n");
}


void medicinedisplay()
{
    FILE *fp;

    fp = fopen("Medicine", "r");

    if(fp == NULL)
    {
        printf("\nNo medicine records found.\n");
        return;
    }

    printf("\n================================================\n");
    printf("                MEDICINE RECORDS\n");
    printf("================================================\n");

    while(fread(&med, sizeof(med), 1, fp))
    {
        printf("\nMedicine ID   : %d", med.medicineid);
        printf("\nMedicine Name : %s", med.medicinename);
        printf("\nPatient ID    : %d", med.patientid);
        printf("\nPatient Name  : %s", med.patientname);
        printf("\nQuantity      : %d", med.quantity);
        printf("\nPrice         : %.2f", med.price);

        printf("\n-----------------------------------------------\n");
    }

    fclose(fp);
}


/* =========================================================
   STAFF SECTION
   ========================================================= */

void staffinsert()
{
    FILE *fp;

    fp = fopen("Staff", "a");

    printf("\nEnter Staff ID : ");
    scanf("%d", &staff.staffid);

    printf("Enter Staff Name : ");
    scanf("%s", staff.name);

    printf("Enter Designation : ");
    scanf("%s", staff.designation);

    printf("Enter Department : ");
    scanf("%s", staff.department);
    
    printf("Enter Phone : ");
    scanf("%s", staff.phone);

    printf("Enter Salary : ");
    scanf("%f", &staff.salary);

    fwrite(&staff, sizeof(staff), 1, fp);

    fclose(fp);

    printf("\nSTAFF RECORD ADDED\n");
}


void staffdisplay()
{
    FILE *fp;

    fp = fopen("Staff", "r");

    if(fp == NULL)
    {
        printf("\nNo staff records found.\n");
        return;
    }

    printf("\n================================================\n");
    printf("                STAFF MANAGEMENT\n");
    printf("================================================\n");

    while(fread(&staff, sizeof(staff), 1, fp))
    {
        printf("\nStaff ID      : %d", staff.staffid);
        printf("\nName          : %s", staff.name);
        printf("\nDesignation   : %s", staff.designation);
        printf("\nDepartment    : %s", staff.department);
        printf("\nSalary        : %.2f", staff.salary);

        printf("\n-----------------------------------------------\n");
    }

    fclose(fp);
}



/* FUNCTION TO SEARCH FOR A STAFF RECORD */
void staffsearch()
{
    FILE *fp;
    int id, found = 0;

    // Open the staff file in binary read mode
    fp = fopen("Staff", "rb");

    if(fp == NULL)
    {
        printf("\nNo staff records found.\n");
        return;
    }

    // Ask for the Staff ID to search
    printf("\nEnter Staff ID to search: ");
    scanf("%d", &id);

    // Search through all saved staff records
    while(fread(&staff, sizeof(staff), 1, fp) == 1)
    {
        if(staff.staffid == id)
        {
            found = 1;

            // Display the matching staff details
            printf("\n========== STAFF DETAILS ==========");
            printf("\nStaff ID    : %d", staff.staffid);
            printf("\nName        : %s", staff.name);
            printf("\nDesignation : %s", staff.designation);
            printf("\nDepartment  : %s", staff.department);
            printf("\nSalary      : %.2f", staff.salary);
            printf("\n===================================");
            break;
        }
    }

    fclose(fp);

    // Inform the user if the ID was not found
    if(found == 0)
        printf("\nStaff record not found.\n");
}




/* FUNCTION TO UPDATE STAFF DETAILS */
void staffupdate()
{
    FILE *fp, *temp;
    int id, found = 0;

    // Open the existing Staff file
    fp = fopen("Staff", "rb");

    if(fp == NULL)
    {
        printf("\nNo staff records found.\n");
        return;
    }

    // Open a temporary file to store updated records
    temp = fopen("TempStaff", "wb");

    if(temp == NULL)
    {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }

    // Ask for the Staff ID to update
    printf("\nEnter Staff ID to update: ");
    scanf("%d", &id);

    // Read each staff record
    while(fread(&staff, sizeof(staff), 1, fp) == 1)
    {
        if(staff.staffid == id)
        {
            found = 1;

            printf("\nEnter New Staff Name: ");
            scanf(" %29[^\n]", staff.name);

            printf("Enter New Designation: ");
            scanf(" %19[^\n]", staff.designation);

            printf("Enter New Department: ");
            scanf(" %29[^\n]", staff.department);

            printf("Enter New Salary: ");
            scanf("%f", &staff.salary);
        }

        // Save the original or updated record
        fwrite(&staff, sizeof(staff), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    // Replace the original file only if a matching ID exists
    if(found == 1)
    {
        remove("Staff");
        rename("TempStaff", "Staff");

        printf("\nSTAFF RECORD UPDATED SUCCESSFULLY.\n");
    }
    else
    {
        remove("TempStaff");
        printf("\nStaff ID not found.\n");
    }
}




/* FUNCTION TO DELETE A STAFF RECORD */
void staffdelete()
{
    FILE *fp, *temp;
    int id, found = 0;

    // Open the existing Staff file
    fp = fopen("Staff", "rb");

    if(fp == NULL)
    {
        printf("\nNo staff records found.\n");
        return;
    }

    // Create a temporary file for the remaining records
    temp = fopen("TempStaff", "wb");

    if(temp == NULL)
    {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }

    // Ask for the Staff ID to delete
    printf("\nEnter Staff ID to delete: ");
    scanf("%d", &id);

    // Read each saved staff record
    while(fread(&staff, sizeof(staff), 1, fp) == 1)
    {
        if(staff.staffid == id)
        {
            found = 1;

            // Skip this record so it is not copied
            continue;
        }

        // Copy all other records to the temporary file
        if(fwrite(&staff, sizeof(staff), 1, temp) != 1)
        {
            printf("\nError writing staff record.\n");
            fclose(fp);
            fclose(temp);
            remove("TempStaff");
            return;
        }
    }

    fclose(fp);
    fclose(temp);

    // Replace the original file if the ID was found
    if(found == 1)
    {
        remove("Staff");
        rename("TempStaff", "Staff");

        printf("\nSTAFF RECORD DELETED SUCCESSFULLY.\n");
    }
    else
    {
        remove("TempStaff");
        printf("\nStaff ID not found.\n");
    }
}




/* FUNCTION TO DISPLAY STAFF MANAGEMENT MENU */
void staffmenu()
{
    int ch;

    do
    {
        // Display the Staff Management options
        printf("\n\n========== STAFF MANAGEMENT ==========");
        printf("\n1. Add Staff");
        printf("\n2. Display All Staff");
        printf("\n3. Search Staff");
        printf("\n4. Update Staff");
        printf("\n5. Delete Staff");
        printf("\n6. Back to Main Menu");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        // Call the selected staff function
        switch(ch)
        {
            case 1:
                staffinsert();
                break;

            case 2:
                staffdisplay();
                break;

            case 3:
                staffsearch();
                break;

            case 4:
                staffupdate();
                break;

            case 5:
                staffdelete();
                break;

            case 6:
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(ch != 6);  // Repeat until the user selects Back
}




/* =========================================================
   APPOINTMENT SECTION
   ========================================================= */

void appointmentinsert()
{
    FILE *fp;

    fp = fopen("Appointment", "a");

    printf("\nEnter Appointment ID : ");
    scanf("%d", &app.appointmentid);

    printf("Enter Patient ID : ");
    scanf("%d", &app.patientid);

    printf("Enter Patient Name : ");
    scanf("%s", app.patientname);

    printf("Enter Doctor Name : ");
    scanf("%s", app.doctor);

    printf("Enter Date : ");
    scanf("%s", app.date);

    printf("Enter Time : ");
    scanf("%s", app.time);

    fwrite(&app, sizeof(app), 1, fp);

    fclose(fp);

    printf("\nAPPOINTMENT ADDED\n");
}


void appointmentdisplay()
{
    FILE *fp;

    fp = fopen("Appointment", "r");

    if(fp == NULL)
    {
        printf("\nNo appointment records found.\n");
        return;
    }

    printf("\n================================================\n");
    printf("                 APPOINTMENTS\n");
    printf("================================================\n");

    while(fread(&app, sizeof(app), 1, fp))
    {
        printf("\nAppointment ID : %d", app.appointmentid);
        printf("\nPatient ID     : %d", app.patientid);
        printf("\nPatient Name   : %s", app.patientname);
        printf("\nDoctor         : %s", app.doctor);
        printf("\nDate           : %s", app.date);
        printf("\nTime           : %s", app.time);

        printf("\n-----------------------------------------------\n");
    }

    fclose(fp);
}


/* =========================================================
   ROOM SECTION
   ========================================================= */

void roominsert()
{
    FILE *fp;

    fp = fopen("Room", "a");

    printf("\nEnter Room Number : ");
    scanf("%d", &room.roomno);

    printf("Enter Bed Number : ");
    scanf("%d", &room.bedno);

    printf("Enter Patient ID : ");
    scanf("%d", &room.patientid);

    printf("Enter Patient Name : ");
    scanf("%s", room.patientname);

    printf("Enter Cause/Disease : ");
    scanf("%s", room.disease);

    room.available = 0;

    fwrite(&room, sizeof(room), 1, fp);

    fclose(fp);

    printf("\nROOM ALLOCATED TO PATIENT\n");
}


void roomdisplay()
{
    FILE *fp;
    int available = 0;
    int occupied = 0;

    fp = fopen("Room", "r");

    if(fp == NULL)
    {
        printf("\nNo room records found.\n");
        return;
    }

    printf("\n================================================\n");
    printf("                  ROOM DETAILS\n");
    printf("================================================\n");

    while(fread(&room, sizeof(room), 1, fp))
    {
        printf("\nRoom Number   : %d", room.roomno);
        printf("\nBed Number    : %d", room.bedno);

        if(room.available == 1)
        {
            printf("\nStatus        : AVAILABLE");
            available++;
        }
        else
        {
            printf("\nStatus        : OCCUPIED");
            printf("\nPatient ID    : %d", room.patientid);
            printf("\nPatient Name  : %s", room.patientname);
            printf("\nCause/Disease : %s", room.disease);

            occupied++;
        }

        printf("\n-----------------------------------------------\n");
    }

    printf("\nTotal Available Rooms/Beds : %d", available);
    printf("\nTotal Occupied Rooms/Beds  : %d\n", occupied);

    fclose(fp);
}


/* =========================================================
   REPORT SECTION
   ========================================================= */

void reports()
{
    FILE *fp;

    int patients = 0;
    int staffcount = 0;
    int medicines = 0;
    int appointments = 0;

    fp = fopen("Patient", "r");

    if(fp != NULL)
    {
        while(fread(&pat, sizeof(pat), 1, fp))
            patients++;

        fclose(fp);
    }


    fp = fopen("Staff", "r");

    if(fp != NULL)
    {
        while(fread(&staff, sizeof(staff), 1, fp))
            staffcount++;

        fclose(fp);
    }


    fp = fopen("Medicine", "r");

    if(fp != NULL)
    {
        while(fread(&med, sizeof(med), 1, fp))
            medicines++;

        fclose(fp);
    }


    fp = fopen("Appointment", "r");

    if(fp != NULL)
    {
        while(fread(&app, sizeof(app), 1, fp))
            appointments++;

        fclose(fp);
    }


    printf("\n============================================\n");
    printf("              HOSPITAL REPORT\n");
    printf("============================================\n");

    printf("\nTotal Patients       : %d", patients);
    printf("\nTotal Staff          : %d", staffcount);
    printf("\nMedicine Records     : %d", medicines);
    printf("\nAppointments         : %d", appointments);

    printf("\n============================================\n");
}


/* =========================================================
   PATIENT MANAGEMENT MENU
   ========================================================= */

void patientmenu()
{
    int c;

    do
    {
        printf("\n\n============================================");
        printf("\n             PATIENT MANAGEMENT");
        printf("\n============================================");

        printf("\n1. Add Patient");
        printf("\n2. Display Patient Details");
        printf("\n3. Search Patient");
        printf("\n4. Delete Patient");
        printf("\n5. Update Patient");
        printf("\n6. Patient Bill");
        printf("\n7. Back");

        printf("\n\nEnter your choice : ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                patientinsert();
                break;

            case 2:
                patientdisplay();
                break;

            case 3:
                patientsearch();
                break;

            case 4:
                patientdelete();
                break;

            case 5:
                patientupdate();
                break;

            case 6:
                bill();
                break;

            case 7:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    }while(c != 7);
}


/* =========================================================
   MEDICINE MENU
   ========================================================= */

void medicinemenu()
{
    int c;

    do
    {
        printf("\n\n============================================");
        printf("\n             MEDICINE MANAGEMENT");
        printf("\n============================================");

        printf("\n1. Add Medicine Record");
        printf("\n2. Display Medicine Records");
        printf("\n3. Back");

        printf("\n\nEnter your choice : ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                medicineinsert();
                break;

            case 2:
                medicinedisplay();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    }while(c != 3);
}

/* =========================================================
   APPOINTMENT MENU
   ========================================================= */

void appointmentmenu()
{
    int c;

    do
    {
        printf("\n\n============================================");
        printf("\n              APPOINTMENT MANAGEMENT");
        printf("\n============================================");

        printf("\n1. Add Appointment");
        printf("\n2. Display Appointments");
        printf("\n3. Back");

        printf("\n\nEnter your choice : ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                appointmentinsert();
                break;

            case 2:
                appointmentdisplay();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    }while(c != 3);
}


/* =========================================================
   ROOM MENU
   ========================================================= */

void roommenu()
{
    int c;

    do
    {
        printf("\n\n============================================");
        printf("\n                ROOM MANAGEMENT");
        printf("\n============================================");

        printf("\n1. Allocate Room");
        printf("\n2. Display Room Details");
        printf("\n3. Back");

        printf("\n\nEnter your choice : ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                roominsert();
                break;

            case 2:
                roomdisplay();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    }while(c != 3);
}


   void bloodinsert()
{
    FILE *fp;

    fp = fopen("BloodBank", "a");

    printf("\nEnter Blood Record ID : ");
    scanf("%d", &blood.bloodid);

    printf("Enter Patient ID : ");
    scanf("%d", &blood.patientid);

    printf("Enter Patient Name : ");
    scanf("%s", blood.patientname);

    printf("Enter Blood Group : ");
    scanf("%s", blood.bloodgroup);

    printf("Enter Donor Name : ");
    scanf("%s", blood.donorname);

    printf("Enter Units : ");
    scanf("%d", &blood.units);

    printf("Enter Date : ");
    scanf("%s", blood.date);

    fwrite(&blood, sizeof(blood), 1, fp);

    fclose(fp);

    printf("\nBLOOD BANK RECORD ADDED\n");
}

void blooddisplay()
{
    FILE *fp;

    fp = fopen("BloodBank", "r");

    if(fp == NULL)
    {
        printf("\nNo blood bank records found.\n");
        return;
    }

    printf("\n============================================");
    printf("\n              BLOOD BANK RECORDS");
    printf("\n============================================\n");

    while(fread(&blood, sizeof(blood), 1, fp))
    {
        printf("\nBlood Record ID : %d", blood.bloodid);
        printf("\nPatient ID      : %d", blood.patientid);
        printf("\nPatient Name    : %s", blood.patientname);
        printf("\nBlood Group     : %s", blood.bloodgroup);
        printf("\nDonor Name      : %s", blood.donorname);
        printf("\nUnits           : %d", blood.units);
        printf("\nDate            : %s", blood.date);

        printf("\n--------------------------------------------\n");
    }

    fclose(fp);
}

void bloodmenu()
{
    int c;

    do
    {
        printf("\n\n============================================");
        printf("\n                BLOOD BANK");
        printf("\n============================================");

        printf("\n1. Add Blood Record");
        printf("\n2. Display Blood Records");
        printf("\n3. Back");

        printf("\n\nEnter your choice : ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                bloodinsert();
                break;

            case 2:
                blooddisplay();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    }while(c != 3);
}

void labmenu()
{
    int ch;

    do
    {
        printf("\n1. PATHOLOGY");
printf("\n2. RADIOLOGY");
printf("\n3. CARDIOLOGY");
printf("\n4. DISPLAY ALL LAB REPORTS");
printf("\n5. SEARCH LAB REPORTS");
printf("\n6. UPDATE LAB REPORT");
printf("\n7. DELETE LAB REPORT");
printf("\n8. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
		   pathologymenu();
		   break;

            case 2:
               radiologymenu();
             break;

            case 3:
             cardiologymenu();
             break;

            case 4:
             displaylabreports();
              break;
              
               case 5:
    searchlabreports();
    break;

case 6:
    updatelabreport();
    break;

case 7:
    deletelabreport();
    break;

case 8:
    labreportssummary();  // Display report counts
    break;

case 9:
    break;  // Return to the previous menu

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=9);
}
void pathologymenu()
{
    int ch;

    do
    {
        printf("\n1. HAEMATOLOGY");
printf("\n2. BIOCHEMISTRY");
printf("\n3. MICROBIOLOGY");
printf("\n4. HISTOPATHOLOGY");
printf("\n5. BACK");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
			haematologymenu();
			break;

            case 2:
			biochemistrymenu();
			break;

            case 3:
    microbiologymenu();
    break;

           case 4:
    histopathologymenu();
    break;

           case 5:
            break;
    
            default:
                printf("\nInvalid choice");
        }

    }while(ch!=5);
}


void haematologymenu()
{
    int ch;

    do
    {
        printf("\n\n========== HAEMATOLOGY ==========");
        printf("\n1. CBC");
        printf("\n2. ESR");
        printf("\n3. COAGULATION");
        printf("\n4. BLOOD GROUPING");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
		   cbcmenu();
		   break;

            case 2:
			esr();
			break;

           case 3:
		   coagulationmenu();
		   break;

           case 4:
		   bloodgroupingmenu();
		   break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=5);
}
    

void cbcmenu()
{
    int ch;

    do
    {
        printf("\n\n========== CBC ==========");
        printf("\n1. Haemoglobin (Hb)");
        printf("\n2. Total WBC Count");
        printf("\n3. Differential WBC Count");
        printf("\n4. RBC Count");
        printf("\n5. Platelet Count");
        printf("\n6. MCV");
        printf("\n7. MCH");
        printf("\n8. MCHC");
        printf("\n9. RDW");
        printf("\n10. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
		   haemoglobin();
		   break;

            case 2:
			totalwbc();
			break;

            case 3:
			differentialwbc();
			break;

            case 4:
			rbccount();
			break;

            case 5:
			plateletcount();
			break;

           case 6:
		    mcv();
			 break;

            case 7:
			mch();
			break;

           case 8:
		   mchc();
		   break;

            case 9:
			rdw();
			break;

            case 10:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=10);
}

void haemoglobin()
{
    FILE *fp;

    fp = fopen("LabReport","ab");

    printf("\n\n========== HAEMOGLOBIN (Hb) ==========");

    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    lab.reportid = 1;

    printf("Enter Haemoglobin Result : ");
    scanf("%s",lab.result);

    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    printf("Enter Date : ");
    scanf("%s",lab.date);

    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"HAEMATOLOGY");
    strcpy(lab.testname,"Haemoglobin (Hb)");

    fwrite(&lab,sizeof(lab),1,fp);

    fclose(fp);

    printf("\nHaemoglobin report saved successfully.");
}


void totalwbc()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    // New report will be added without deleting old reports
    fp = fopen("LabReport","ab");

    printf("\n\n========== TOTAL WBC COUNT ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the WBC test result
    printf("Enter Total WBC Count : ");
    scanf("%s",lab.result);

    // Enter the unit of the test
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department name
    strcpy(lab.department,"PATHOLOGY");

    // Store the main category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the name of the test
    strcpy(lab.testname,"Total WBC Count");

    // Write the complete report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nTotal WBC Count report saved successfully.");
}

void differentialwbc()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== DIFFERENTIAL WBC COUNT ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the Differential WBC result
    // Multiple values can be entered together
    printf("Enter Differential WBC Result : ");
    scanf(" %[^\n]",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"Differential WBC Count");

    // Save the report in the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nDifferential WBC Count report saved successfully.");
}

void rbccount()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    // This adds the new report without deleting previous reports
    fp = fopen("LabReport","ab");

    printf("\n\n========== RBC COUNT ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the RBC Count result
    printf("Enter RBC Count : ");
    scanf("%s",lab.result);

    // Enter the unit of the test
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"RBC Count");

    // Save the report in the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nRBC Count report saved successfully.");
}


void plateletcount()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    // This keeps all previous laboratory reports
    fp = fopen("LabReport","ab");

    printf("\n\n========== PLATELET COUNT ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the Platelet Count result
    printf("Enter Platelet Count : ");
    scanf("%s",lab.result);

    // Enter the unit of the test
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"Platelet Count");

    // Save the complete report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nPlatelet Count report saved successfully.");
}


void mcv()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== MCV ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the MCV result
    printf("Enter MCV Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"MCV");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nMCV report saved successfully.");
}


void mch()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    // Previous laboratory reports will remain ?????
    fp = fopen("LabReport","ab");

    printf("\n\n========== MCH ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the MCH result
    printf("Enter MCH Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"MCH");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nMCH report saved successfully.");
}


void mchc()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== MCHC ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the MCHC result
    printf("Enter MCHC Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"MCHC");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nMCHC report saved successfully.");
}



void rdw()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== RDW ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the RDW result
    printf("Enter RDW Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"RDW");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nRDW report saved successfully.");
}


void esr()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== ESR ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the ESR result
    printf("Enter ESR Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"HAEMATOLOGY");

    // Store the test name
    strcpy(lab.testname,"Erythrocyte Sedimentation Rate");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nESR report saved successfully.");
}


void coagulationmenu()
{
    int ch;

    do
    {
        printf("\n\n========== COAGULATION ==========");
        printf("\n1. PT");
        printf("\n2. INR");
        printf("\n3. APTT");
        printf("\n4. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
			pt();
			break;

            case 2:
			inr();
			break;

            case 3:
			aptt();
			break;

            case 4:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=4);
}


void pt()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== PT (PROTHROMBIN TIME) ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the PT result
    printf("Enter PT Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"COAGULATION");

    // Store the test name
    strcpy(lab.testname,"PT");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nPT report saved successfully.");
}


void inr()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== INR (INTERNATIONAL NORMALIZED RATIO) ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the INR result
    printf("Enter INR Result : ");
    scanf("%s",lab.result);

    // INR does not normally require a physical unit,
    // but we keep this field so the same report structure is used
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"COAGULATION");

    // Store the test name
    strcpy(lab.testname,"INR");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nINR report saved successfully.");
}


void aptt()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== APTT (ACTIVATED PARTIAL THROMBOPLASTIN TIME) ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the APTT result
    printf("Enter APTT Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"COAGULATION");

    // Store the test name
    strcpy(lab.testname,"APTT");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nAPTT report saved successfully.");
}


void bloodgroupingmenu()
{
    int ch;

    do
    {
        printf("\n\n========== BLOOD GROUPING ==========");
        printf("\n1. ABO Blood Group");
        printf("\n2. Rh Typing");
        printf("\n3. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
		   abobloodgroup();
		   break;

           case 2:
		   rhtyping();
		   break;

            case 3:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=3);
}


void abobloodgroup()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== ABO BLOOD GROUP ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the patient's ABO blood group
    // Example: A, B, AB or O
    printf("Enter ABO Blood Group : ");
    scanf("%s",lab.result);

    // Blood group does not require a numerical unit
    // We store it as "N/A"
    strcpy(lab.unit,"N/A");

    // Enter the normal/reference information
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date of the test
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store the department
    strcpy(lab.department,"PATHOLOGY");

    // Store the category
    strcpy(lab.category,"BLOOD GROUPING");

    // Store the test name
    strcpy(lab.testname,"ABO Blood Group");

    // Save the report into the binary file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nABO Blood Group report saved successfully.");
}


// Function to enter and save Rh Typing report
void rhtyping()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== RH TYPING ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter Rh Typing result
    printf("Enter Rh Type (+/-) : ");
    scanf("%s",lab.result);

    // Rh Typing does not require a unit
    strcpy(lab.unit,"N/A");

    // Enter normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"BLOOD GROUPING");
    strcpy(lab.testname,"Rh Typing");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nRh Typing report saved successfully.");
}


// Function to display the Biochemistry menu
void biochemistrymenu()
{
    int ch;

    do
    {
        printf("\n\n========== BIOCHEMISTRY ==========");
        printf("\n1. BLOOD GLUCOSE");
        printf("\n2. LIPID PROFILE");
        printf("\n3. LIVER FUNCTION TEST");
        printf("\n4. KIDNEY FUNCTION TEST");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                bloodglucosemenu();
                break;

            case 2:
    lipidprofilemenu();
    break;

            case 3:
    liverfunctionmenu();
    break;
	
	     case 4:
    kidneyfunctionmenu();
    break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=5);
}


// Function to display the Blood Glucose menu
void bloodglucosemenu()
{
    int ch;

    do
    {
        printf("\n\n========== BLOOD GLUCOSE ==========");
        printf("\n1. Fasting Blood Sugar");
        printf("\n2. Post-Prandial Blood Sugar");
        printf("\n3. Random Blood Sugar");
        printf("\n4. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                fastingbloodsugar();
                break;

            case 2:
                postprandialbloodsugar();
                break;

            case 3:
                randombloodsugar();
                break;

            case 4:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=4);
}


// Function to enter and save Fasting Blood Sugar report
void fastingbloodsugar()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== FASTING BLOOD SUGAR ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Fasting Blood Sugar Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"BLOOD GLUCOSE");
    strcpy(lab.testname,"Fasting Blood Sugar");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nFasting Blood Sugar report saved successfully.");
}


// Function to enter and save Post-Prandial Blood Sugar report
void postprandialbloodsugar()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== POST-PRANDIAL BLOOD SUGAR ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Post-Prandial Blood Sugar Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"BLOOD GLUCOSE");
    strcpy(lab.testname,"Post-Prandial Blood Sugar");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nPost-Prandial Blood Sugar report saved successfully.");
}


// Function to enter and save Random Blood Sugar report
void randombloodsugar()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== RANDOM BLOOD SUGAR ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Random Blood Sugar Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"BLOOD GLUCOSE");
    strcpy(lab.testname,"Random Blood Sugar");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nRandom Blood Sugar report saved successfully.");
}


// Function to display the Lipid Profile menu
void lipidprofilemenu()
{
    int ch;

    do
    {
        printf("\n\n========== LIPID PROFILE ==========");
        printf("\n1. Total Cholesterol");
        printf("\n2. HDL");
        printf("\n3. LDL");
        printf("\n4. VLDL");
        printf("\n5. Triglycerides");
        printf("\n6. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                totalcholesterol();
                break;

            case 2:
                hdl();
                break;

            case 3:
                ldl();
                break;

            case 4:
                vldl();
                break;

            case 5:
                triglycerides();
                break;

            case 6:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=6);
}


// Function to enter and save Total Cholesterol report
void totalcholesterol()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== TOTAL CHOLESTEROL ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Total Cholesterol Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIPID PROFILE");
    strcpy(lab.testname,"Total Cholesterol");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nTotal Cholesterol report saved successfully.");
}


// Function to enter and save HDL report
void hdl()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== HDL ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter HDL Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIPID PROFILE");
    strcpy(lab.testname,"HDL");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nHDL report saved successfully.");
}


// Function to enter and save LDL report
void ldl()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== LDL ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter LDL Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIPID PROFILE");
    strcpy(lab.testname,"LDL");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nLDL report saved successfully.");
}


// Function to enter and save VLDL report
void vldl()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== VLDL ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter VLDL Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIPID PROFILE");
    strcpy(lab.testname,"VLDL");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nVLDL report saved successfully.");
}


// Function to enter and save Triglycerides report
void triglycerides()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== TRIGLYCERIDES ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Triglycerides Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIPID PROFILE");
    strcpy(lab.testname,"Triglycerides");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nTriglycerides report saved successfully.");
}


// Function to display the Liver Function Test menu
void liverfunctionmenu()
{
    int ch;

    do
    {
        printf("\n\n========== LIVER FUNCTION TEST ==========");
        printf("\n1. Bilirubin");
        printf("\n2. SGOT / AST");
        printf("\n3. SGPT / ALT");
        printf("\n4. ALP");
        printf("\n5. Total Protein");
        printf("\n6. Albumin");
        printf("\n7. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                bilirubin();
                break;

            case 2:
                sgot();
                break;

            case 3:
                sgpt();
                break;

            case 4:
                alp();
                break;

            case 5:
                totalprotein();
                break;

            case 6:
                albumin();
                break;

            case 7:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=7);
}


// Function to enter and save Bilirubin report
void bilirubin()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== BILIRUBIN ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Bilirubin Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIVER FUNCTION TEST");
    strcpy(lab.testname,"Bilirubin");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nBilirubin report saved successfully.");
}


// Function to enter and save SGOT / AST report
void sgot()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    printf("\n\n========== SGOT / AST ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter SGOT / AST Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIVER FUNCTION TEST");
    strcpy(lab.testname,"SGOT / AST");

    // Save the report into the LabReport file
    fwrite(&lab,sizeof(lab),1,fp);

    // Close the file
    fclose(fp);

    printf("\nSGOT / AST report saved successfully.");
}


// Function to enter and save SGPT / ALT report
void sgpt()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== SGPT / ALT ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter SGPT / ALT Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIVER FUNCTION TEST");
    strcpy(lab.testname,"SGPT / ALT");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nSGPT / ALT report saved successfully.");
    }
    else
    {
        printf("\nError saving SGPT / ALT report.");
    }

    // Close the file
    fclose(fp);
}


// Function to enter and save ALP report
void alp()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== ALP ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter ALP Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIVER FUNCTION TEST");
    strcpy(lab.testname,"ALP");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nALP report saved successfully.");
    }
    else
    {
        printf("\nError saving ALP report.");
    }

    // Close the file
    fclose(fp);
}


// Function to enter and save Total Protein report
void totalprotein()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== TOTAL PROTEIN ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Total Protein Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIVER FUNCTION TEST");
    strcpy(lab.testname,"Total Protein");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nTotal Protein report saved successfully.");
    }
    else
    {
        printf("\nError saving Total Protein report.");
    }

    // Close the file
    fclose(fp);
}


// Function to enter and save Albumin report
void albumin()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== ALBUMIN ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Albumin Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"LIVER FUNCTION TEST");
    strcpy(lab.testname,"Albumin");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nAlbumin report saved successfully.");
    }
    else
    {
        printf("\nError saving Albumin report.");
    }

    // Close the file
    fclose(fp);
}


// Function to display the Kidney Function Test menu
void kidneyfunctionmenu()
{
    int ch;

    do
    {
        printf("\n\n========== KIDNEY FUNCTION TEST ==========");
        printf("\n1. Urea");
        printf("\n2. Creatinine");
        printf("\n3. Uric Acid");
        printf("\n4. Electrolytes");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                urea();
                break;

            case 2:
                creatinine();
                break;

            case 3:
                uricacid();
                break;

            case 4:
                electrolytes();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=5);
}


// Function to enter and save Urea report
void urea()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== UREA ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Urea Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"KIDNEY FUNCTION TEST");
    strcpy(lab.testname,"Urea");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nUrea report saved successfully.");
    }
    else
    {
        printf("\nError saving Urea report.");
    }

    // Close the file
    fclose(fp);
}


// Function to enter and save Creatinine report
void creatinine()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CREATININE ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Creatinine Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"KIDNEY FUNCTION TEST");
    strcpy(lab.testname,"Creatinine");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nCreatinine report saved successfully.");
    }
    else
    {
        printf("\nError saving Creatinine report.");
    }

    // Close the file
    fclose(fp);
}


// Function to enter and save Uric Acid report
void uricacid()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== URIC ACID ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Uric Acid Result : ");
    scanf("%s",lab.result);

    // Enter the unit
    printf("Enter the Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"KIDNEY FUNCTION TEST");
    strcpy(lab.testname,"Uric Acid");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nUric Acid report saved successfully.");
    }
    else
    {
        printf("\nError saving Uric Acid report.");
    }

    // Close the file
    fclose(fp);
}


// Function to enter and save Electrolytes report
void electrolytes()
{
    FILE *fp;

    // Open the LabReport file in append-binary mode
    fp = fopen("LabReport","ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== ELECTROLYTES ==========");

    // Enter the patient's ID
    printf("\nEnter Patient ID : ");
    scanf("%d",&lab.patientid);

    // Enter the patient's name
    printf("Enter Patient Name : ");
    scanf(" %[^\n]",lab.patientname);

    // Enter the test result
    printf("Enter Electrolytes Result : ");
    scanf(" %[^\n]",lab.result);

    // Enter the unit
    printf("Enter Unit : ");
    scanf("%s",lab.unit);

    // Enter the normal/reference level
    printf("Enter Normal Level : ");
    scanf(" %[^\n]",lab.normallevel);

    // Enter the date
    printf("Enter Date : ");
    scanf("%s",lab.date);

    // Store department, category and test name
    strcpy(lab.department,"PATHOLOGY");
    strcpy(lab.category,"KIDNEY FUNCTION TEST");
    strcpy(lab.testname,"Electrolytes");

    // Save the report into the LabReport file
    if(fwrite(&lab,sizeof(lab),1,fp) == 1)
    {
        printf("\nElectrolytes report saved successfully.");
    }
    else
    {
        printf("\nError saving Electrolytes report.");
    }

    // Close the file
    fclose(fp);
}


// Function to display the Microbiology menu
void microbiologymenu()
{
    int ch;

    do
    {
        printf("\n\n========== MICROBIOLOGY ==========");
        printf("\n1. URINE");
        printf("\n2. STOOL");
        printf("\n3. CULTURE");
        printf("\n4. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                urinemenu();
                break;

            case 2:
                stoolmenu();
                break;

            case 3:
                culturemenu();
                break;

            case 4:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=4);
}


// ===== URINE MENU =====
void urinemenu()
{
    int ch;

    do
    {
        printf("\n\n========== URINE ==========");
        printf("\n1. Routine Examination");
        printf("\n2. Culture & Sensitivity");
        printf("\n3. BACK");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                routineurine();
                break;

            case 2:
                urinecultureandsensitivity();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(ch!=3);
}


// ===== ROUTINE URINE EXAMINATION =====
void routineurine()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== ROUTINE URINE EXAMINATION ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter urine examination details
    printf("\nEnter Colour : ");
    scanf(" %[^\n]", lab.result);

    printf("Enter Unit : ");
    scanf(" %[^\n]", lab.unit);

    printf("Enter Normal Level / Reference : ");
    scanf(" %[^\n]", lab.normallevel);

    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the LAB report category and test name
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "URINE");
    strcpy(lab.testname, "Routine Examination");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nRoutine Urine Examination report saved successfully.");
    }
    else
    {
        printf("\nError saving Routine Urine Examination report.");
    }

    // Close the file
    fclose(fp);
}

// ===== URINE CULTURE AND SENSITIVITY =====
void urinecultureandsensitivity()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== URINE CULTURE & SENSITIVITY ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter culture and sensitivity findings
    printf("\nEnter Organism Identified : ");
    scanf(" %[^\n]", lab.result);

    printf("Enter Antibiotic Sensitivity Details : ");
    scanf(" %[^\n]", lab.normallevel);

    // Store N/A because these findings do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "URINE");
    strcpy(lab.testname, "Culture & Sensitivity");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nUrine Culture & Sensitivity report saved successfully.");
    }
    else
    {
        printf("\nError saving Urine Culture & Sensitivity report.");
    }

    // Close the file
    fclose(fp);
}



// ===== STOOL MENU =====
void stoolmenu()
{
    int ch;

    do
    {
        printf("\n\n========== STOOL ==========");
        printf("\n1. Routine Examination");
        printf("\n2. Occult Blood");
        printf("\n3. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                routinestool();
                break;

            case 2:
                stooloccultblood();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 3);
}


// ===== STOOL ROUTINE EXAMINATION =====
void routinestool()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== STOOL ROUTINE EXAMINATION ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter stool examination findings
    printf("\nEnter Colour / Appearance : ");
    scanf(" %[^\n]", lab.result);

    printf("Enter Unit : ");
    scanf(" %[^\n]", lab.unit);

    printf("Enter Normal Level / Reference : ");
    scanf(" %[^\n]", lab.normallevel);

    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "STOOL");
    strcpy(lab.testname, "Routine Examination");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nStool Routine Examination report saved successfully.");
    }
    else
    {
        printf("\nError saving Stool Routine Examination report.");
    }

    // Close the file
    fclose(fp);
}


// ===== STOOL OCCULT BLOOD TEST =====
void stooloccultblood()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== STOOL OCCULT BLOOD ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the test result, such as Positive or Negative
    printf("\nEnter Occult Blood Result : ");
    scanf(" %[^\n]", lab.result);

    // This test does not use a numeric measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the laboratory reference information
    printf("Enter Normal Level / Reference : ");
    scanf(" %[^\n]", lab.normallevel);

    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "STOOL");
    strcpy(lab.testname, "Occult Blood");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nStool Occult Blood report saved successfully.");
    }
    else
    {
        printf("\nError saving Stool Occult Blood report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CULTURE MENU =====
void culturemenu()
{
    int ch;

    do
    {
        printf("\n\n========== CULTURE ==========");
        printf("\n1. Blood Culture");
        printf("\n2. Urine Culture");
        printf("\n3. Sputum Culture");
        printf("\n4. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                bloodculture();
                break;

            case 2:
                urineculture();
                break;

            case 3:
                sputumculture();
                break;

            case 4:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 4);
}



// ===== BLOOD CULTURE =====
void bloodculture()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== BLOOD CULTURE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the culture findings
    printf("\nEnter Organism Identified (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    printf("Enter Culture Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Culture findings do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "CULTURE");
    strcpy(lab.testname, "Blood Culture");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nBlood Culture report saved successfully.");
    }
    else
    {
        printf("\nError saving Blood Culture report.");
    }

    // Close the file
    fclose(fp);
}


// ===== URINE CULTURE =====
void urineculture()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== URINE CULTURE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the culture result
    printf("\nEnter Organism Identified (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter additional culture findings
    printf("Enter Culture Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Culture findings do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "CULTURE");
    strcpy(lab.testname, "Urine Culture");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nUrine Culture report saved successfully.");
    }
    else
    {
        printf("\nError saving Urine Culture report.");
    }

    // Close the file
    fclose(fp);
}


// ===== SPUTUM CULTURE =====
void sputumculture()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== SPUTUM CULTURE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the organism identified or the pending status
    printf("\nEnter Organism Identified (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter additional culture findings
    printf("Enter Culture Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Culture findings do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "CULTURE");
    strcpy(lab.testname, "Sputum Culture");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nSputum Culture report saved successfully.");
    }
    else
    {
        printf("\nError saving Sputum Culture report.");
    }

    // Close the file
    fclose(fp);
}


// ===== HISTOPATHOLOGY MENU =====
void histopathologymenu()
{
    int ch;

    do
    {
        printf("\n\n========== HISTOPATHOLOGY ==========");
        printf("\n1. BIOPSY");
        printf("\n2. FNAC");
        printf("\n3. CYTOLOGY");
        printf("\n4. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                biopsy();
                break;

            case 2:
                fnac();
                break;

            case 3:
                cytology();
                break;

            case 4:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 4);
}          


// ===== BIOPSY =====
void biopsy()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== BIOPSY ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter biopsy findings or pending status
    printf("\nEnter Biopsy Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter additional remarks or the diagnostic impression
    printf("Enter Report Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // This report does not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "HISTOPATHOLOGY");
    strcpy(lab.testname, "Biopsy");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nBiopsy report saved successfully.");
    }
    else
    {
        printf("\nError saving Biopsy report.");
    }

    // Close the file
    fclose(fp);
}


// ===== FNAC =====
void fnac()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== FNAC ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter FNAC findings or pending status
    printf("\nEnter FNAC Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the diagnostic impression or additional remarks
    printf("Enter Report Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // FNAC findings do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "HISTOPATHOLOGY");
    strcpy(lab.testname, "FNAC");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nFNAC report saved successfully.");
    }
    else
    {
        printf("\nError saving FNAC report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CYTOLOGY =====
void cytology()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CYTOLOGY ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter cytology findings or pending status
    printf("\nEnter Cytology Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the diagnostic impression or additional remarks
    printf("Enter Report Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Cytology findings do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the test classification
    strcpy(lab.department, "PATHOLOGY");
    strcpy(lab.category, "HISTOPATHOLOGY");
    strcpy(lab.testname, "Cytology");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nCytology report saved successfully.");
    }
    else
    {
        printf("\nError saving Cytology report.");
    }

    // Close the file
    fclose(fp);
}

// ===== RADIOLOGY MENU =====
void radiologymenu()
{
    int ch;

    do
    {
        printf("\n\n========== RADIOLOGY ==========");
        printf("\n1. X-RAY");
        printf("\n2. ULTRASOUND");
        printf("\n3. CT SCAN");
        printf("\n4. MRI");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                xraymenu();
                break;

            case 2:
                ultrasoundmenu();
                break;

            case 3:
                ctscanmenu();
                break;

            case 4:
                mrimenu();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);
}


// ===== X-RAY MENU =====
void xraymenu()
{
    int ch;

    do
    {
        printf("\n\n========== X-RAY ==========");
        printf("\n1. Chest X-Ray");
        printf("\n2. X-Ray Skull");
        printf("\n3. X-Ray Spine");
        printf("\n4. X-Ray Limb");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                chestxray();
                break;

            case 2:
                xrayskull();
                break;

            case 3:
                xrayspine();
                break;

            case 4:
                xraylimb();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);
}


// ===== CHEST X-RAY =====
void chestxray()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CHEST X-RAY ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the radiology findings
    printf("\nEnter X-Ray Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or additional remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "X-RAY");
    strcpy(lab.testname, "Chest X-Ray");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nChest X-Ray report saved successfully.");
    }
    else
    {
        printf("\nError saving Chest X-Ray report.");
    }

    // Close the file
    fclose(fp);
}


// ===== X-RAY SKULL =====
void xrayskull()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== X-RAY SKULL ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the radiology findings
    printf("\nEnter X-Ray Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "X-RAY");
    strcpy(lab.testname, "X-Ray Skull");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nX-Ray Skull report saved successfully.");
    }
    else
    {
        printf("\nError saving X-Ray Skull report.");
    }

    // Close the file
    fclose(fp);
}


// ===== X-RAY SPINE =====
void xrayspine()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== X-RAY SPINE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the radiology findings
    printf("\nEnter X-Ray Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "X-RAY");
    strcpy(lab.testname, "X-Ray Spine");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nX-Ray Spine report saved successfully.");
    }
    else
    {
        printf("\nError saving X-Ray Spine report.");
    }

    // Close the file
    fclose(fp);
}


// ===== X-RAY LIMB =====
void xraylimb()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== X-RAY LIMB ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter the radiology findings
    printf("\nEnter X-Ray Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "X-RAY");
    strcpy(lab.testname, "X-Ray Limb");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nX-Ray Limb report saved successfully.");
    }
    else
    {
        printf("\nError saving X-Ray Limb report.");
    }

    // Close the file
    fclose(fp);
}


// ===== ULTRASOUND MENU =====
void ultrasoundmenu()
{
    int ch;

    do
    {
        printf("\n\n========== ULTRASOUND ==========");
        printf("\n1. USG Abdomen");
        printf("\n2. USG Pelvis");
        printf("\n3. USG Pregnancy");
        printf("\n4. USG KUB");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                usgabdomen();
                break;

            case 2:
                usgpelvis();
                break;

            case 3:
                usgpregnancy();
                break;

            case 4:
                usgkub();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);
}


// ===== USG ABDOMEN =====
void usgabdomen()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== USG ABDOMEN ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter ultrasound findings
    printf("\nEnter USG Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "ULTRASOUND");
    strcpy(lab.testname, "USG Abdomen");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nUSG Abdomen report saved successfully.");
    }
    else
    {
        printf("\nError saving USG Abdomen report.");
    }

    // Close the file
    fclose(fp);
}


// ===== USG PELVIS =====
void usgpelvis()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== USG PELVIS ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter ultrasound findings
    printf("\nEnter USG Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "ULTRASOUND");
    strcpy(lab.testname, "USG Pelvis");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nUSG Pelvis report saved successfully.");
    }
    else
    {
        printf("\nError saving USG Pelvis report.");
    }

    // Close the file
    fclose(fp);
}


// ===== USG PREGNANCY =====
void usgpregnancy()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== USG PREGNANCY ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter ultrasound findings or Pending
    printf("\nEnter USG Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "ULTRASOUND");
    strcpy(lab.testname, "USG Pregnancy");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nUSG Pregnancy report saved successfully.");
    }
    else
    {
        printf("\nError saving USG Pregnancy report.");
    }

    // Close the file
    fclose(fp);
}


// ===== USG KUB =====
void usgkub()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== USG KUB ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter ultrasound findings or Pending
    printf("\nEnter USG Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Radiology reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "ULTRASOUND");
    strcpy(lab.testname, "USG KUB");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nUSG KUB report saved successfully.");
    }
    else
    {
        printf("\nError saving USG KUB report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CT SCAN MENU =====
void ctscanmenu()
{
    int ch;

    do
    {
        printf("\n\n========== CT SCAN ==========");
        printf("\n1. CT Brain");
        printf("\n2. CT Chest");
        printf("\n3. CT Abdomen");
        printf("\n4. CT Spine");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                ctbrain();
                break;

            case 2:
                ctchest();
                break;

            case 3:
                ctabdomen();
                break;

            case 4:
                ctspine();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);
}


// ===== CT BRAIN =====
void ctbrain()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CT BRAIN ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter CT findings or Pending
    printf("\nEnter CT Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // CT reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "CT SCAN");
    strcpy(lab.testname, "CT Brain");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nCT Brain report saved successfully.");
    }
    else
    {
        printf("\nError saving CT Brain report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CT CHEST =====
void ctchest()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CT CHEST ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter CT findings or Pending
    printf("\nEnter CT Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // CT reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "CT SCAN");
    strcpy(lab.testname, "CT Chest");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nCT Chest report saved successfully.");
    }
    else
    {
        printf("\nError saving CT Chest report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CT ABDOMEN =====
void ctabdomen()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CT ABDOMEN ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter CT findings or Pending
    printf("\nEnter CT Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // CT reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "CT SCAN");
    strcpy(lab.testname, "CT Abdomen");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nCT Abdomen report saved successfully.");
    }
    else
    {
        printf("\nError saving CT Abdomen report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CT SPINE =====
void ctspine()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== CT SPINE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter CT findings or Pending
    printf("\nEnter CT Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // CT reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "CT SCAN");
    strcpy(lab.testname, "CT Spine");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nCT Spine report saved successfully.");
    }
    else
    {
        printf("\nError saving CT Spine report.");
    }

    // Close the file
    fclose(fp);
}


// ===== MRI MENU =====
void mrimenu()
{
    int ch;

    do
    {
        printf("\n\n========== MRI ==========");
        printf("\n1. MRI Brain");
        printf("\n2. MRI Spine");
        printf("\n3. MRI Knee");
        printf("\n4. MRI Abdomen");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                mribrain();
                break;

            case 2:
                mrispine();
                break;

            case 3:
                mriknee();
                break;

            case 4:
                mriabdomen();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);
}


// ===== MRI BRAIN =====
void mribrain()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== MRI BRAIN ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter MRI findings or Pending
    printf("\nEnter MRI Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // MRI reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "MRI");
    strcpy(lab.testname, "MRI Brain");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nMRI Brain report saved successfully.");
    }
    else
    {
        printf("\nError saving MRI Brain report.");
    }

    // Close the file
    fclose(fp);
}


// ===== MRI SPINE =====
void mrispine()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== MRI SPINE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter MRI findings or Pending
    printf("\nEnter MRI Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // MRI reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "MRI");
    strcpy(lab.testname, "MRI Spine");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nMRI Spine report saved successfully.");
    }
    else
    {
        printf("\nError saving MRI Spine report.");
    }

    // Close the file
    fclose(fp);
}


// ===== MRI KNEE =====
void mriknee()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== MRI KNEE ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter MRI findings or Pending
    printf("\nEnter MRI Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // MRI reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "MRI");
    strcpy(lab.testname, "MRI Knee");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nMRI Knee report saved successfully.");
    }
    else
    {
        printf("\nError saving MRI Knee report.");
    }

    // Close the file
    fclose(fp);
}



// ===== MRI ABDOMEN =====
void mriabdomen()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== MRI ABDOMEN ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter MRI findings or Pending
    printf("\nEnter MRI Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the radiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // MRI reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%s", lab.date);

    // Store the report classification
    strcpy(lab.department, "RADIOLOGY");
    strcpy(lab.category, "MRI");
    strcpy(lab.testname, "MRI Abdomen");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nMRI Abdomen report saved successfully.");
    }
    else
    {
        printf("\nError saving MRI Abdomen report.");
    }

    // Close the file
    fclose(fp);
}


// ===== CARDIOLOGY MENU =====
void cardiologymenu()
{
    int ch;

    do
    {
        printf("\n\n========== CARDIOLOGY ==========");
        printf("\n1. ECG");
        printf("\n2. ECHOCARDIOGRAPHY");
        printf("\n3. STRESS TEST");
        printf("\n4. HOLTER");
        printf("\n5. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                ecgmenu();
                break;

            case 2:
                echocardiographymenu();
                break;

            case 3:
                stresstestmenu();
                break;

            case 4:
                holtermenu();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 5);
}


// ===== ECG MENU =====
void ecgmenu()
{
    int ch;

    do
    {
        printf("\n\n========== ECG ==========");
        printf("\n1. Resting ECG");
        printf("\n2. 12-Lead ECG");
        printf("\n3. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                restingecg();
                break;

            case 2:
                twelveleadecg();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 3);
}


// ===== RESTING ECG =====
void restingecg()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== RESTING ECG ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter ECG findings or Pending
    printf("\nEnter ECG Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // ECG reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "ECG");
    strcpy(lab.testname, "Resting ECG");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nResting ECG report saved successfully.");
    }
    else
    {
        printf("\nError saving Resting ECG report.");
    }

    // Close the file
    fclose(fp);
}


// ===== 12-LEAD ECG =====
void twelveleadecg()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== 12-LEAD ECG ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter ECG findings or Pending
    printf("\nEnter ECG Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // ECG reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "ECG");
    strcpy(lab.testname, "12-Lead ECG");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\n12-Lead ECG report saved successfully.");
    }
    else
    {
        printf("\nError saving 12-Lead ECG report.");
    }

    // Close the file
    fclose(fp);
}


// ===== ECHOCARDIOGRAPHY MENU =====
void echocardiographymenu()
{
    int ch;

    do
    {
        printf("\n\n========== ECHOCARDIOGRAPHY ==========");
        printf("\n1. 2D Echo");
        printf("\n2. Doppler Echo");
        printf("\n3. Colour Doppler");
        printf("\n4. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                echo2d();
                break;

            case 2:
                dopplerecho();
                break;

            case 3:
                colourdoppler();
                break;

            case 4:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 4);
}


// ===== 2D ECHO =====
void echo2d()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== 2D ECHO ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter echocardiography findings
    printf("\nEnter Echo Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Echo reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "ECHOCARDIOGRAPHY");
    strcpy(lab.testname, "2D Echo");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\n2D Echo report saved successfully.");
    }
    else
    {
        printf("\nError saving 2D Echo report.");
    }

    // Close the file
    fclose(fp);
}


// ===== DOPPLER ECHO =====
void dopplerecho()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== DOPPLER ECHO ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter Doppler Echo findings
    printf("\nEnter Doppler Echo Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Echo reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "ECHOCARDIOGRAPHY");
    strcpy(lab.testname, "Doppler Echo");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nDoppler Echo report saved successfully.");
    }
    else
    {
        printf("\nError saving Doppler Echo report.");
    }

    // Close the file
    fclose(fp);
}


// ===== COLOUR DOPPLER =====
void colourdoppler()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== COLOUR DOPPLER ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter Colour Doppler findings
    printf("\nEnter Colour Doppler Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // This report does not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "ECHOCARDIOGRAPHY");
    strcpy(lab.testname, "Colour Doppler");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nColour Doppler report saved successfully.");
    }
    else
    {
        printf("\nError saving Colour Doppler report.");
    }

    // Close the file
    fclose(fp);
}


// ===== STRESS TEST MENU =====
void stresstestmenu()
{
    int ch;

    do
    {
        printf("\n\n========== STRESS TEST ==========");
        printf("\n1. TMT (Treadmill Test)");
        printf("\n2. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                tmt();
                break;

            case 2:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 2);
}


// ===== TMT (TREADMILL TEST) =====
void tmt()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== TMT (TREADMILL TEST) ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter TMT findings or Pending
    printf("\nEnter TMT Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // TMT reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date (DD-MM-YYYY) : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "STRESS TEST");
    strcpy(lab.testname, "TMT");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\nTMT report saved successfully.");
    }
    else
    {
        printf("\nError saving TMT report.");
    }

    // Close the file
    fclose(fp);
}


// ===== HOLTER MENU =====
void holtermenu()
{
    int ch;

    do
    {
        printf("\n\n========== HOLTER ==========");
        printf("\n1. 24-Hour Holter");
        printf("\n2. 48-Hour Holter");
        printf("\n3. BACK");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                holter24hour();
                break;

            case 2:
                holter48hour();
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(ch != 3);
}


// ===== 24-HOUR HOLTER =====
void holter24hour()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== 24-HOUR HOLTER ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter Holter monitoring findings or Pending
    printf("\nEnter Holter Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or additional remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Holter reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date (DD-MM-YYYY) : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "HOLTER");
    strcpy(lab.testname, "24-Hour Holter");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\n24-Hour Holter report saved successfully.");
    }
    else
    {
        printf("\nError saving 24-Hour Holter report.");
    }

    // Close the file
    fclose(fp);
}


// ===== 48-HOUR HOLTER =====
void holter48hour()
{
    FILE *fp;

    // Open the LAB report file in append-binary mode
    fp = fopen("LabReport", "ab");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nUnable to open LabReport file.");
        return;
    }

    printf("\n\n========== 48-HOUR HOLTER ==========");

    // Enter patient information
    printf("\nEnter Patient ID : ");
    scanf("%d", &lab.patientid);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", lab.patientname);

    // Enter Holter monitoring findings or Pending
    printf("\nEnter Holter Findings (or Pending) : ");
    scanf(" %[^\n]", lab.result);

    // Enter the cardiologist's impression or remarks
    printf("Enter Report Impression / Remarks : ");
    scanf(" %[^\n]", lab.normallevel);

    // Holter reports do not use a single measurement unit
    strcpy(lab.unit, "N/A");

    // Enter the report date
    printf("Enter Date (DD-MM-YYYY) : ");
    scanf("%14s", lab.date);

    // Store the report classification
    strcpy(lab.department, "CARDIOLOGY");
    strcpy(lab.category, "HOLTER");
    strcpy(lab.testname, "48-Hour Holter");

    // Save the report to the binary file
    if(fwrite(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\n48-Hour Holter report saved successfully.");
    }
    else
    {
        printf("\nError saving 48-Hour Holter report.");
    }

    // Close the file
    fclose(fp);
}


// ===== DISPLAY ALL LAB REPORTS =====
void displaylabreports()
{
    FILE *fp;

    // Open the LAB report file in read-binary mode
    fp = fopen("LabReport", "rb");

    // Check whether the file exists and opened successfully
    if(fp == NULL)
    {
        printf("\nNo LAB reports found.");
        return;
    }

    // Check whether the file contains any reports
    if(fread(&lab, sizeof(lab), 1, fp) != 1)
    {
        printf("\nNo LAB reports available.");
        fclose(fp);
        return;
    }

    // Display the first report and continue until the file ends
    rewind(fp);

    printf("\n\n========== ALL LAB REPORTS ==========");

    while(fread(&lab, sizeof(lab), 1, fp) == 1)
    {
        printf("\n\n------------------------------------");

        // Display report information
        printf("\nPatient ID       : %d", lab.patientid);
        printf("\nPatient Name     : %s", lab.patientname);
        printf("\nDepartment       : %s", lab.department);
        printf("\nCategory         : %s", lab.category);
        printf("\nTest Name        : %s", lab.testname);
        printf("\nResult / Findings: %s", lab.result);
        printf("\nUnit             : %s", lab.unit);
        printf("\nReference/Remarks: %s", lab.normallevel);
        printf("\nReport Date      : %s", lab.date);
    }

    printf("\n\n========== END OF REPORTS ==========");

    // Close the file
    fclose(fp);
}


// ===== SEARCH LAB REPORTS BY PATIENT ID =====
void searchlabreports()
{
    FILE *fp;
    int id;
    int found = 0;

    // Open the LAB report file in read-binary mode
    fp = fopen("LabReport", "rb");

    // Check whether the file opened successfully
    if(fp == NULL)
    {
        printf("\nNo LAB reports found.");
        return;
    }

    // Ask for the patient ID to search
    printf("\nEnter Patient ID to search : ");
    scanf("%d", &id);

    // Read each report from the file
    while(fread(&lab, sizeof(lab), 1, fp) == 1)
    {
        // Check whether the report belongs to the requested patient
        if(lab.patientid == id)
        {
            found = 1;

            // Display the matching report
            printf("\n\n========== LAB REPORT ==========");
            printf("\nPatient ID        : %d", lab.patientid);
            printf("\nPatient Name      : %s", lab.patientname);
            printf("\nDepartment        : %s", lab.department);
            printf("\nCategory          : %s", lab.category);
            printf("\nTest Name         : %s", lab.testname);
            printf("\nResult / Findings : %s", lab.result);
            printf("\nUnit              : %s", lab.unit);
            printf("\nReference/Remarks : %s", lab.normallevel);
            printf("\nReport Date       : %s", lab.date);
        }
    }

    // Display a message if no matching report was found
    if(found == 0)
    {
        printf("\nNo LAB reports found for Patient ID %d.", id);
    }

    // Close the file
    fclose(fp);
}


// ===== UPDATE LAB REPORT =====
void updatelabreport()
{
    FILE *fp, *temp;
    int id, found = 0;
    char test[50];

    // Open the existing LAB report file
    fp = fopen("LabReport", "rb");

    if(fp == NULL)
    {
        printf("\nNo LAB reports found.");
        return;
    }

    // Open a temporary file to store the updated records
    temp = fopen("TempLabReport", "wb");

    if(temp == NULL)
    {
        printf("\nUnable to create temporary file.");
        fclose(fp);
        return;
    }

    // Ask which report should be updated
    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    printf("Enter Test Name : ");
    scanf(" %[^\n]", test);

    // Read each report from the original file
    while(fread(&lab, sizeof(lab), 1, fp) == 1)
    {
        // Match both patient ID and test name
        if(lab.patientid == id && strcmp(lab.testname, test) == 0)
        {
            found = 1;

            printf("\n========== UPDATE LAB REPORT ==========");

            // Enter the updated report information
            printf("\nEnter Updated Patient Name : ");
            scanf(" %[^\n]", lab.patientname);

            printf("Enter Updated Result / Findings : ");
            scanf(" %[^\n]", lab.result);

            printf("Enter Updated Unit : ");
            scanf(" %[^\n]", lab.unit);

            printf("Enter Updated Reference / Remarks : ");
            scanf(" %[^\n]", lab.normallevel);

            printf("Enter Updated Date (DD-MM-YYYY) : ");
            scanf("%14s", lab.date);
        }

        // Write both updated and unchanged records to the temporary file
        if(fwrite(&lab, sizeof(lab), 1, temp) != 1)
        {
            printf("\nError writing temporary file.");
            fclose(fp);
            fclose(temp);
            return;
        }
    }

    // Close both files before replacing the original
    fclose(fp);
    fclose(temp);

    if(found == 1)
    {
        // Replace the original file with the temporary file
        if(remove("LabReport") == 0)
        {
            if(rename("TempLabReport", "LabReport") == 0)
            {
                printf("\nLAB report updated successfully.");
            }
            else
            {
                printf("\nUnable to rename temporary file.");
                printf("\nYour updated records remain in TempLabReport.");
            }
        }
        else
        {
            printf("\nUnable to replace the original report file.");
            printf("\nUpdated records remain in TempLabReport.");
        }
    }
    else
    {
        // Remove the temporary file when no matching report exists
        remove("TempLabReport");
        printf("\nMatching LAB report not found.");
    }
}


// ===== DELETE LAB REPORT =====
void deletelabreport()
{
    FILE *fp, *temp;
    int id, found = 0;
    char test[50];

    // Open the existing LAB report file
    fp = fopen("LabReport", "rb");

    if(fp == NULL)
    {
        printf("\nNo LAB reports found.");
        return;
    }

    // Ask which report should be deleted
    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    printf("Enter Test Name to Delete : ");
    scanf(" %[^\n]", test);

    // Create a temporary file for the remaining records
    temp = fopen("TempLabReport", "wb");

    if(temp == NULL)
    {
        printf("\nUnable to create temporary file.");
        fclose(fp);
        return;
    }

    // Read each report from the original file
    while(fread(&lab, sizeof(lab), 1, fp) == 1)
    {
        // Skip the matching report
        if(lab.patientid == id && strcmp(lab.testname, test) == 0)
        {
            found = 1;
            continue;
        }

        // Copy all other reports to the temporary file
        if(fwrite(&lab, sizeof(lab), 1, temp) != 1)
        {
            printf("\nError writing temporary file.");
            fclose(fp);
            fclose(temp);
            remove("TempLabReport");
            return;
        }
    }

    // Close both files before replacing the original
    fclose(fp);
    fclose(temp);

    if(found == 1)
    {
        // Replace the original file with the remaining records
        if(remove("LabReport") == 0)
        {
            if(rename("TempLabReport", "LabReport") == 0)
            {
                printf("\nLAB report deleted successfully.");
            }
            else
            {
                printf("\nUnable to rename temporary file.");
                printf("\nRemaining records are in TempLabReport.");
            }
        }
        else
        {
            printf("\nUnable to replace the original report file.");
            printf("\nRemaining records are in TempLabReport.");
        }
    }
    else
    {
        // Remove the temporary file if no matching report exists
        remove("TempLabReport");
        printf("\nMatching LAB report not found.");
    }
}



/* FUNCTION TO DISPLAY LAB REPORT SUMMARY */
void labreportssummary()
{
    FILE *fp;
    int total = 0;
    int pathology = 0;
    int radiology = 0;
    int cardiology = 0;

    fp = fopen("LabReport", "rb");

    // Check whether the LAB report file exists
    if(fp == NULL)
    {
        printf("\nNo LAB reports found.");
        return;
    }

    // Read every saved LAB report
    while(fread(&lab, sizeof(lab), 1, fp) == 1)
    {
        total++;

        // Count reports according to department
        if(strcmp(lab.department, "PATHOLOGY") == 0)
            pathology++;

        else if(strcmp(lab.department, "RADIOLOGY") == 0)
            radiology++;

        else if(strcmp(lab.department, "CARDIOLOGY") == 0)
            cardiology++;
    }

    fclose(fp);

    // Display the final summary
    printf("\n\n========== LAB REPORT SUMMARY ==========");
    printf("\nTotal LAB Reports : %d", total);
    printf("\nPathology Reports : %d", pathology);
    printf("\nRadiology Reports : %d", radiology);
    printf("\nCardiology Reports: %d", cardiology);
    printf("\n========================================");
}



/* FUNCTION TO GENERATE THE NEXT LAB REPORT ID */
int getnextlabreportid()
{
    FILE *fp;
    struct labreport temp;
    int maxid = 0;

    // Open the existing LAB report file
    fp = fopen("LabReport", "rb");

    // If no report file exists, start from ID 1
    if(fp == NULL)
        return 1;

    // Find the highest existing report ID
    while(fread(&temp, sizeof(temp), 1, fp) == 1)
    {
        if(temp.reportid > maxid)
            maxid = temp.reportid;
    }

    fclose(fp);

    // Return the next available ID
    return maxid + 1;
}





/* =========================================================
   MAIN PROGRAM
   ========================================================= */

void main()
{
    int c;

    do
    {
        printf("\n\n==================================================");
        printf("\n          HOSPITAL MANAGEMENT SYSTEM");
        printf("\n==================================================");

        printf("\n\n1.  Patient Details");
        printf("\n2.  Patient Search");
        printf("\n3.  Delete Patient");
        printf("\n4.  Update Patient");
        printf("\n5.  Patient Bill");
        printf("\n6.  Medicine Records");
        printf("\n7.  Staff Management");
        printf("\n8.  Appointment");
       printf("\n9.  Reports");
       printf("\n10. Room Details");
	   printf("\n11. Blood Bank");
	   printf("\n12. LAB");
	   printf("\n13. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                patientmenu();
                break;

            case 2:
                patientsearch();
                break;

            case 3:
                patientdelete();
                break;

            case 4:
                patientupdate();
                break;

            case 5:
                bill();
                break;

            case 6:
                medicinemenu();
                break;

            case 7:
                staffmenu();
                break;

            case 8:
                appointmentmenu();
                break;

            case 9:
                reports();
                break;

            case 10:
                roommenu();
                break;

            case 11:
			bloodmenu();
			break;
			
			case 12:
			labmenu();
			break;
			
			case 13:
			printf("\nThank you for using Hospital Management System.\n");
			exit(1);
			break;
			
            default:
                printf("\nYour choice is wrong.\n");
                printf("Please try again...\n");
        }

    }while(c != 13);
}
