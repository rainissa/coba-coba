#ifndef CLIPBOARD_H
    #define CLIPBOARD_H

    #define MAX_BARIS 100
    #define MAX_KARAKTER 256
    #define MAX_CLIPBOARD_BARIS 20

/* dokumen utama */
    extern char dokumen[MAX_BARIS][MAX_KARAKTER];
    extern int jumlahBaris;

/* clipboard multi baris */
    extern char clipboard[MAX_CLIPBOARD_BARIS][MAX_KARAKTER];
    extern int jumlahClipboard;

/* cursor */
    extern int cursor;

/* fungsi cursor */
    void setCursor(int posisi);

/* input teks */
    void inputText(char teks[]);

/* operasi clipboard */
    void copyBlock(int start, int end);
    void cutBlock(int start, int end);
    void pasteBlock();

#endif