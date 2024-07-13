#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_NAME 50
#define MAX_COLUMN_NAME 50
#define MAX_ROWS 100
#define MAX_COLUMNS 10

// Structure pour représenter une table
typedef struct {
    char name[MAX_TABLE_NAME];
    char columns[MAX_COLUMNS][MAX_COLUMN_NAME];
    int num_columns;
    int num_rows;
    char data[MAX_ROWS][MAX_COLUMNS][50];
} Table;

// Fonction pour créer une table
void create_table(Table* table, char* name, char* columns[], int num_columns) {
    strcpy(table->name, name);
    table->num_columns = num_columns;
    for (int i = 0; i < num_columns; i++) {
        strcpy(table->columns[i], columns[i]);
    }
    table->num_rows = 0;
}

// Fonction pour insérer des données dans une table
void insert_data(Table* table, char* values[]) {
    if (table->num_rows < MAX_ROWS) {
        for (int i = 0; i < table->num_columns; i++) {
            strcpy(table->data[table->num_rows][i], values[i]);
        }
        table->num_rows++;
    } else {
        printf("Maximum number of rows reached.\n");
    }
}

int main() {
    Table my_table;
    char* columns[] = {"ID", "Name", "Age"};
    create_table(&my_table, "Users", columns, 3);

    char* row1[] = {"1", "John Doe", "30"};
    char* row2[] = {"2", "Jane Smith", "25"};
    insert_data(&my_table, row1);
    insert_data(&my_table, row2);

    return 0;
}