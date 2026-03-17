#include "cursor.h"
#include "text-edit.h"

// Inisialisasi: kursor mulai dari baris paling atas (indeks 0)
int cursor = 0;

int isCursorValid() {
    return (cursor >= 0 && cursor < jumlahBaris);
}

// Navigasi ke baris sebelumnya. Mencegah cursor menjadi negatif (di bawah 0).

void moveUp() {
    if (cursor > 0) {
        cursor--;
    }
}

// Navigasi ke baris berikutnya. Membatasi kursor agar tidak melewati jumlah baris yang ada di Array 2D.

void moveDown() {
    // jumlahBaris adalah total baris yang sudah terisi di buffer
    if (cursor < jumlahBaris - 1) {
        cursor++;
    }
}