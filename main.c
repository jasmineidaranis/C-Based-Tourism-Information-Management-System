#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main() {
    loadData();
    int choice;

    while (1) {
        printf("\n--- Tourism Management System ---\n");
        printf("1. Add Tourist\n");
        printf("2. Display Tourists\n");
        printf("3. Search Tourist\n");
        printf("4. Update Tourist\n");
        printf("5. Delete Tourist\n");
        printf("6. Sort by ID\n");
        printf("7. Sort by Name\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTourist(); break;
            case 2: displayTourists(); break;
            case 3: searchTourist(); break;
            case 4: updateTourist(); break;
            case 5: deleteTourist(); break;
            case 6: sortByID(); break;
            case 7: sortByName(); break;
            case 8:
                saveData();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
