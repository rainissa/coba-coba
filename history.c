#include <stdio.h>
#include <string.h>
#include "history.h"
#include "cursor.h"
#include "text-edit.h"

// Variabel buffer global dari text-edit.c
extern char buffer[MAX_ROW][MAX_COL];
extern int jumlahBaris;

Action undoStack[STACK_SIZE];
int undoTop = -1;

Action redoStack[STACK_SIZE];
int redoTop = -1;

void pushUndo(int row, char *teks, ActionType tipe) {
    if (undoTop < STACK_SIZE - 1) {
        undoTop++;
        undoStack[undoTop].row = row;
        undoStack[undoTop].tipe = tipe;
        // Salin teks dari Array 2D ke memori Stack
        strcpy(undoStack[undoTop].dataLama, teks);
    }
}

void clearRedo() {
    redoTop = -1;
}

void undo() {
    if (undoTop >= 0) {
        Action last = undoStack[undoTop];
        undoTop--;

        // Simpan kondisi sekarang ke Redo sebelum dikembalikan
        // Implementasi Redo

        switch(last.tipe) {
            case EDIT:
                // Timpa baris di Array 2D dengan data lama dari Stack
                strcpy(buffer[last.row], last.dataLama);
                break;
            
            case TAMBAH:
                // Kebalikan tambah adalah hapus baris terakhir
                jumlahBaris--;
                break;

            case HAPUS:
                // Kebalikan hapus adalah menggeser baris ke bawah (Insert)
                for (int i = jumlahBaris; i > last.row; i--) {
                    strcpy(buffer[i], buffer[i-1]);
                }
                strcpy(buffer[last.row], last.dataLama);
                jumlahBaris++;
                break;
        }

        // Pindahkan kursor ke lokasi kejadian agar user tahu apa yang berubah
        cursor = last.row;
        printf("Undo berhasil.\n");
    } else {
        printf("Tidak ada yang bisa di-undo.\n");
    }
}

void redo() {
    
}