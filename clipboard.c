#include <stdio.h>
#include <string.h>
#include "clipboard.h"
#include "cursor.h"
#include "history.h"

char clipboard[MAX_KARAKTER];

void copyLine(){
    if (jumlahBaris == 0){
        printf("Dokumen kosong\n");
        return;
    }

    if (!isCursorValid()){
        printf("Cursor tidak valid\n");
        return;
    }

    int len = strlen(buffer[cursor_row]);
    if (cursor_col > len) cursor_col = len;

    strcpy(clipboard, buffer[cursor_row] + cursor_col);

    printf("Copy berhasil\n");
}

void cutLine(){
    if (jumlahBaris == 0){
        printf("Dokumen kosong\n");
        return;
    }

    if (!isCursorValid()){
        printf("Cursor tidak valid\n");
        return;
    }

    pushSnapshot();
    clearRedo();

    int len = strlen(buffer[cursor_row]);
    if (cursor_col > len) cursor_col = len;

    strcpy(clipboard, buffer[cursor_row] + cursor_col);

    buffer[cursor_row][cursor_col] = '\0';

    printf("Cut berhasil\n");
}

void pasteLine(){
    if (strlen(clipboard) == 0){
        printf("Clipboard kosong\n");
        return;
    }

    if (!isCursorValid()){
        printf("Cursor tidak valid\n");
        return;
    }

    pushSnapshot();
    clearRedo();

    char temp[MAX_KARAKTER];

    int len = strlen(buffer[cursor_row]);
    if (cursor_col > len) cursor_col = len;

    strcpy(temp, buffer[cursor_row] + cursor_col);

    buffer[cursor_row][cursor_col] = '\0';

    strcat(buffer[cursor_row], clipboard);
    strcat(buffer[cursor_row], temp);

    cursor_col += strlen(clipboard);

    printf("Paste berhasil\n");
}