#ifndef TABLE_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define TABLE_H
typedef char*** table;
typedef char** line;

typedef struct tab {
    int rows;
    int columns;
    int maxWord;
    int maxWordAccepted;
    table * myTable;
} Table;

int len(char * word);
Table * create_table(int rows, int columns, int max_size_word, char filename[100]);
void print_table(Table * tab);
void print_line(Table * tab, int lin);
void print_breaker(Table * tab);

#endif