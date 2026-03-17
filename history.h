#ifndef UNDO_H
#define UNDO_H

#define STACK_SIZE 100

typedef struct{
    int row;
    int karakter;
    char prev_char;
} Action;

void pushUndo(int row, int karakter, char c);
void undo();

#endif