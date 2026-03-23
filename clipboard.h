#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#define MAX_ROW 100
#define MAX_KARAKTER 200
#define MAX_CLIPBOARD_ROW 20

extern char buffer[MAX_ROW][MAX_KARAKTER];
extern int jumlahBaris;

extern char clipboard[MAX_CLIPBOARD_ROW][MAX_KARAKTER];
extern int jumlahClipboard;

void copyLine();
void cutLine();
void pasteLine();

#endif