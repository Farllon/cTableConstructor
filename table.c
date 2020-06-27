#include "table.h"

int len(char * word) {
    int i, cont = 0;

    for(i = 0; word[i] != '\0'; i++){
        cont++;
    }

    return cont;
}

Table * create_table(int rows, int columns, int max_size_word, char filename[100]) {

    FILE *f = fopen(filename, "r");

    Table * tab = (Table *) malloc(sizeof(Table));
    tab->maxWord = 0;

    table * matrix;
    matrix = (table *) malloc(rows * sizeof(line));

    int i, j;

    for(i = 0; i < rows; i++){
        matrix[i] = (line) malloc(columns * sizeof(char *));
        for(j = 0; j < columns; j++){
            matrix[i][j] = (char *) malloc(max_size_word * sizeof(char));
            fgets(matrix[i][j], max_size_word, f);
            if(len(matrix[i][j]) - 1 > tab->maxWord){
                tab->maxWord = len(matrix[i][j]) - 1;
            }
        }
    }

    fclose(f);

    tab->myTable = matrix;
    tab->columns = columns;
    tab->rows = rows;
    tab->maxWordAccepted = max_size_word;

    return tab;
}

void print_table(Table * tab) {
    int i;
    for(i = 0; i < tab->rows; i++){
        if(i == 0){
            print_breaker(tab);
            printf("\n");
        }
        print_line(tab, i);
        printf("\n");
        if(i == 0){
            print_breaker(tab);
            printf("\n");
        }
    } 
    print_breaker(tab);
}

void print_line(Table * tab, int lin) {
    int i, j, cont;
    int mid = 0;
    int max = tab->maxWord + 2;
    char * word = (char *) malloc(sizeof(char));

    for(i = 0; i < tab->columns; i++){
        printf("|");
        cont = 0;
        mid = (max - (len(tab->myTable[lin][i]) - 1))/2;
        cont += mid * 2;
        printf("%*s", mid, "");

        word = tab->myTable[lin][i];
        
        for(j = 0; j < len(word) - 1; j++){
            printf("%c", word[j]);
            cont++;
        }

        printf("%*s", mid, "");
        if(cont < max) {
            printf("%*s", max - cont, "");
        }
    }
    printf("|");
}

void print_breaker(Table * tab) {
    int i;
    printf("+");
    for(i = 0; i < (tab->maxWord + 2) * (tab->columns) + (tab->columns + 1) - 2; i++){
        printf("-");
    }
    printf("+");
}