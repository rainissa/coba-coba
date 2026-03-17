#include <stdio.h>
#include <string.h>
#include "clipboard.h"

/* mengatur cursor */
void setCursor(int posisi)
{
    if (posisi >= 0 && posisi < jumlahBaris)
    {
        cursor = posisi;
        printf("Cursor di baris %d\n", cursor);
    }
    else
    {
        printf("Posisi cursor tidak valid\n");
    }
}

/* input teks dengan auto pindah baris */
void inputText(char teks[])
{
    int i = 0;

    while (teks[i] != '\0')
    {
        int panjang = strlen(dokumen[cursor]);

        if (panjang >= MAX_KARAKTER - 1)
        {
            if (jumlahBaris >= MAX_BARIS - 1)
            {
                printf("Dokumen penuh\n");
                return;
            }

            cursor++;
            jumlahBaris++;
            dokumen[cursor][0] = '\0';
        }

        int pos = strlen(dokumen[cursor]);

        dokumen[cursor][pos] = teks[i];
        dokumen[cursor][pos + 1] = '\0';

        i++;
    }
}

/* COPY BLOK BARIS */
void copyBlock(int start, int end)
{
    if (start < 0 || end >= jumlahBaris || start > end)
    {
        printf("Range tidak valid\n");
        return;
    }

    jumlahClipboard = 0;

    for (int i = start; i <= end; i++)
    {
        if (jumlahClipboard >= MAX_CLIPBOARD_BARIS)
        {
            printf("Clipboard penuh\n");
            break;
        }

        strcpy(clipboard[jumlahClipboard], dokumen[i]);
        jumlahClipboard++;
    }

    printf("Blok baris berhasil dicopy\n");
}

/* CUT BLOK BARIS */
void cutBlock(int start, int end)
{
    if (start < 0 || end >= jumlahBaris || start > end)
    {
        printf("Range tidak valid\n");
        return;
    }

    copyBlock(start, end);

    int jumlahHapus = end - start + 1;

    for (int i = start; i < jumlahBaris - jumlahHapus; i++)
    {
        strcpy(dokumen[i], dokumen[i + jumlahHapus]);
    }

    jumlahBaris -= jumlahHapus;

    printf("Blok baris dipotong\n");
}

/* PASTE BLOK */
void pasteBlock()
{
    if (jumlahClipboard == 0)
    {
        printf("Clipboard kosong\n");
        return;
    }

    if (jumlahBaris + jumlahClipboard >= MAX_BARIS)
    {
        printf("Dokumen penuh\n");
        return;
    }

    for (int i = jumlahBaris - 1; i > cursor; i--)
    {
        strcpy(dokumen[i + jumlahClipboard], dokumen[i]);
    }

    for (int i = 0; i < jumlahClipboard; i++)
    {
        strcpy(dokumen[cursor + 1 + i], clipboard[i]);
    }

    jumlahBaris += jumlahClipboard;

    printf("Clipboard berhasil ditempel\n");
}