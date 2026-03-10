#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BARIS 100
#define MAX_KARAKTER 200

char buffer[MAX_BARIS][MAX_KARAKTER];
int jumlahBaris = 0;
int i;

void clearScreen()
{
    system("cls");   
}

void pauseScreen()
{
    printf("\nTekan ENTER untuk lanjut...");
    getchar();
}

void tampilkan()
{
    clearScreen();
    printf("\n====== TEXT EDITOR ======\n\n");

    for(i = 0; i < jumlahBaris; i++)
	{
        printf("%2d | %s\n", i+1, buffer[i]);
    }

    printf("\n---------------------------------\n");
    printf("1. Tambah baris\n");
    printf("2. Hapus baris\n");
    printf("3. Keluar\n");
    printf("---------------------------------\n");
}

void tambahBaris()
{
    if(jumlahBaris >= MAX_BARIS)
	{
        printf("Buffer penuh!\n");
        pauseScreen();
        return;
    }

    printf("Masukkan teks: ");
    getchar(); 
    fgets(buffer[jumlahBaris], MAX_KARAKTER, stdin);

    buffer[jumlahBaris][strcspn(buffer[jumlahBaris], "\n")] = 0;

    jumlahBaris = jumlahBaris + 1;
}

void hapusBaris()
{
    int hpsBariske;

    printf("Hapus baris: ");
    scanf("%d", &hpsBariske);
    getchar();

    if(hpsBariske < 1 || hpsBariske > jumlahBaris)
	{
        printf("\nBaris tidak ada!\n");
        pauseScreen();
        return;
    }

    for(i = hpsBariske-1; i < jumlahBaris-1; i++)
	{
        strcpy(buffer[i], buffer[i+1]);
    }

    jumlahBaris = jumlahBaris - 1;
}

int main()
{
    int pilih;

    do
	{
        tampilkan();

        printf("Pilih menu: ");
        scanf("%d", &pilih);
		getchar();
		
        switch(pilih)
		{
            case 1: tambahBaris(); break;
            case 2: hapusBaris(); break;
        }

    }while(pilih != 3);

    return 0;
}