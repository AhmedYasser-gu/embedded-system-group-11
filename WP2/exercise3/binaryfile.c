// (C) Ahmed Yasser, Axel Broberg, Niklas H�glund , group: 11 (2022)
// Work package 2
// Exercise 3
// Submission code: 

// Include section
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

// -----typedefs -------
typedef struct  {
    char firstname[20];
    char famname[20];
    char pers_number[20]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person�s record.

void write_new_file(PERSON* inrecord); // Creates a file and// writes the first record

void write_new_file(PERSON* inrecord) {
    errno_t err;
    PERSON ppost;
    FILE* fptr;

    // Open for read  
    err = fopen_s(&fptr, "C:\database.bin", "wb");
    if (err == 0)
    {
        printf("The file is created\n");
    }
    else
    {
        printf("The file is not created\n");
    }

    strncpy_s(ppost.firstname, MAX, "Matt\n", 5);
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);

    strncpy_s(ppost.famname, MAX, "Murdock\n", 8);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);

    strncpy_s(ppost.pers_number, MAX, "200010016475\n", 13);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    fclose(fptr);
}

void printfile(); // Prints out all persons in the file

void printfile() {
    FILE* fptr;	// file which we will create
    errno_t err;
    PERSON* ppost = NULL;
    char* buf[15];


    err = fopen_s(&fptr, "database.bin", "rb");
    if (err == 0) {
        while (!feof(fptr)) {
            fread(&buf, sizeof(char), 10, fptr);
            printf("\n %.*s", sizeof(&buf)+2, &buf);

        }
    }
    else {
        printf("\n Can not open file");
        exit(1);
    }
    
    fclose(fptr);

}


void search_by_firstname(char* name); // Prints out the person if // in list
void search_by_firstname(char* name);

void append_file(PERSON* inrecord); // appends a new person to the file

void append_file(PERSON* inrecord) {
    errno_t err;
    PERSON ppost;
    FILE* fptr;

    char firstname[20];
    char famname[20];
    char pernum[20];

    printf("Add new person to database.\nFirst name: ");
    scanf_s("\n%s", &firstname, 20);

    printf("\nFamily name: ");
    scanf_s("\n%s", &famname, 20);

    printf("\nPersonal number: ");
    scanf_s("\n%s", &pernum, 20);


    // Open for read  
    err = fopen_s(&fptr, "C:\database.bin", "ab");
    if (err == 0)
    {
        printf("New user has been added\n");
    }
    else
    {
        printf("\nThe file is not created\n");
    }

    strncpy_s(ppost.firstname, MAX, firstname, 20);
    fwrite(&ppost.firstname, sizeof(ppost.firstname), 1, fptr);

    strncpy_s(ppost.famname, MAX, famname, 20);
    fwrite(&ppost.famname, sizeof(ppost.famname), 1, fptr);

    strncpy_s(ppost.pers_number, MAX, pernum, 20);
    fwrite(&ppost.pers_number, sizeof(ppost.pers_number), 1, fptr);

    fclose(fptr);
}


int main(void) {
    // Initilizations
    int choice;
    //Main program menu 
    while (1) {
        printf("\nWelcome to your database, Choose an option from below : \n \n");
        printf("1. Create a new and delete the old file.\n");
        printf("2. Add a new person to the file.\n");
        printf("3. Search for a person in the file.\n");
        printf("4. Print out all in the file.\n");
        printf("5. Exit the program.\n \n");

        // reads user input to execute the requested task
        scanf_s("%d", &choice);

        // if statement according to the user's input, so it will display whats requested
        if (choice == 1) {

            write_new_file(NULL);

        }
        else if (choice == 2) {
            append_file(NULL);

        }
        else if (choice == 3) {


        }
        else if (choice == 4) {
            printfile();
        }
        else if (choice == 5) {
            exit(0);
        }
        else {
            break;
        }
    }
    return(0);
}