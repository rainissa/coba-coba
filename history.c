#include <stdio.h>
#include "cursor.h"
#include "history.h"
#include "text-edit.h"

// Variabel buffer global dari text-edit.c
extern char buffer[MAX_ROW][MAX_COL];
extern int jumlahBaris;

Action undoStack[STACK_SIZE];
int undoTop = -1;

Action redoStack[STACK_SIZE];
int redoTop = -1;

void pushUndo(int row, int karakter, char c){

    if(undoTop < STACK_SIZE-1){

        undoTop++;
        undoStack[undoTop].row = row;
        undoStack[undoTop].karakter = karakter;
        undoStack[undoTop].prev_char = c;

    }
}

void undo(){

    if(undoTop >= 0){

        Action last = undoStack[undoTop];
        undoTop--;

        buffer[last.row][last.karakter] = last.prev_char;

        cursor_row = last.row;
        cursor_karakter = last.karakter;

    }
    else{
        printf("Undo stack kosong\n");
    }
}

void redo() {
    
}