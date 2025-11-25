#ifndef OPERATIONS_H
#define OPERATIONS_H

struct Tourist {
    int id;
    char name[50];
    char destination[50];
    int days;
};

extern struct Tourist *tourists;
extern int touristCount;

void loadData();
void saveData();

void addTourist();
void displayTourists();
void searchTourist();
void updateTourist();
void deleteTourist();

void sortByID();
void sortByName();

#endif
