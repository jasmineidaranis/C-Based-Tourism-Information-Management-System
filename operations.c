#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

#define FILE_NAME "tourists.dat"

struct Tourist *tourists = NULL;
int touristCount = 0;

/* -------- Load Data -------- */
void loadData() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) return;

    fread(&touristCount, sizeof(int), 1, file);
    tourists = malloc(touristCount * sizeof(struct Tourist));
    fread(tourists, sizeof(struct Tourist), touristCount, file);

    fclose(file);
}

/* -------- Save Data -------- */
void saveData() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) return;

    fwrite(&touristCount, sizeof(int), 1, file);
    fwrite(tourists, sizeof(struct Tourist), touristCount, file);

    fclose(file);
}

/* -------- Add Tourist -------- */
void addTourist() {
    tourists = realloc(tourists, (touristCount + 1) * sizeof(struct Tourist));

    struct Tourist t;
    printf("Enter Tourist ID: ");
    scanf("%d", &t.id);

    for (int i = 0; i < touristCount; i++) {
        if (tourists[i].id == t.id) {
            printf("ID already exists.\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf("%s", t.name);
    printf("Enter Destination: ");
    scanf("%s", t.destination);
    printf("Enter Days: ");
    scanf("%d", &t.days);

    tourists[touristCount++] = t;
    saveData();

    printf("Tourist added successfully!\n");
}

/* -------- Display Tourists -------- */
void displayTourists() {
    if (touristCount == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n+------+----------------+----------------+------+\n");
    printf("| ID   | Name           | Destination    | Days |\n");
    printf("+------+----------------+----------------+------+\n");

    for (int i = 0; i < touristCount; i++) {
        printf("| %-4d | %-14s | %-14s | %-4d |\n",
               tourists[i].id, tourists[i].name,
               tourists[i].destination, tourists[i].days);
    }

    printf("+------+----------------+----------------+------+\n");
}

/* -------- Search Tourist -------- */
void searchTourist() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < touristCount; i++) {
        if (tourists[i].id == id) {
            printf("\nTourist Found:\n");
            printf("ID: %d\nName: %s\nDestination: %s\nDays: %d\n",
                   tourists[i].id, tourists[i].name,
                   tourists[i].destination, tourists[i].days);
            return;
        }
    }
    printf("Tourist not found.\n");
}

/* -------- Update -------- */
void updateTourist() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < touristCount; i++) {
        if (tourists[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", tourists[i].name);
            printf("Enter new Destination: ");
            scanf("%s", tourists[i].destination);
            printf("Enter new Days: ");
            scanf("%d", &tourists[i].days);

            saveData();
            printf("Record updated!\n");
            return;
        }
    }
    printf("ID not found.\n");
}

/* -------- Delete -------- */
void deleteTourist() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < touristCount; i++) {
        if (tourists[i].id == id) {

            for (int j = i; j < touristCount - 1; j++)
                tourists[j] = tourists[j + 1];

            touristCount--;
            tourists = realloc(tourists, touristCount * sizeof(struct Tourist));

            saveData();
            printf("Record deleted.\n");
            return;
        }
    }
    printf("ID not found.\n");
}

/* -------- Sort by ID -------- */
void sortByID() {
    for (int i = 0; i < touristCount - 1; i++) {
        for (int j = 0; j < touristCount - i - 1; j++) {
            if (tourists[j].id > tourists[j + 1].id) {
                struct Tourist temp = tourists[j];
                tourists[j] = tourists[j + 1];
                tourists[j + 1] = temp;
            }
        }
    }
    saveData();
    printf("Sorted by ID.\n");
}

/* -------- Sort by Name -------- */
void sortByName() {
    for (int i = 0; i < touristCount - 1; i++) {
        for (int j = 0; j < touristCount - i - 1; j++) {
            if (strcmp(tourists[j].name, tourists[j + 1].name) > 0) {
                struct Tourist temp = tourists[j];
                tourists[j] = tourists[j + 1];
                tourists[j + 1] = temp;
            }
        }
    }
    saveData();
    printf("Sorted by Name.\n");
}
