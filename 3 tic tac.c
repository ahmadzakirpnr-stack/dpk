#include <stdio.h>
#include <stdlib.h>

char papan[9];

void resetPapan(void) {
    for (int i = 0; i < 9; i++) {
        papan[i] = '1' + i;
    }
}

void tampilkanPapan(void) {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", papan[0], papan[1], papan[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", papan[3], papan[4], papan[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", papan[6], papan[7], papan[8]);
    printf("     |     |     \n\n");
}

/* Mengembalikan 1 jika pemain dengan simbol tsb menang */
int cekMenang(char s) {
    int pola[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},   /* baris   */
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},   /* kolom   */
        {0, 4, 8}, {2, 4, 6}               /* diagonal */
    };
    for (int i = 0; i < 8; i++) {
        if (papan[pola[i][0]] == s &&
            papan[pola[i][1]] == s &&
            papan[pola[i][2]] == s) {
            return 1;
        }
    }
    return 0;
}

int papanPenuh(void) {
    for (int i = 0; i < 9; i++) {
        if (papan[i] != 'X' && papan[i] != 'O') return 0;
    }
    return 1;
}

int bacaPilihan(char pemain) {
    int pilihan;
    char buf[64];

    while (1) {
        printf("Giliran Pemain %c, pilih kotak (1-9): ", pemain);
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("\nInput berakhir. Keluar dari permainan.\n");
            exit(0);
        }
        if (sscanf(buf, "%d", &pilihan) != 1) {
            printf("Input tidak valid. Masukkan angka 1-9.\n");
            continue;
        }
        if (pilihan < 1 || pilihan > 9) {
            printf("Angka harus antara 1 sampai 9.\n");
            continue;
        }
        if (papan[pilihan - 1] == 'X' || papan[pilihan - 1] == 'O') {
            printf("Kotak sudah terisi. Pilih kotak lain.\n");
            continue;
        }
        return pilihan - 1;
    }
}

int main(void) {
    char ulang = 'y';

    printf("=== PERMAINAN TIC TAC TOE ===\n");
    printf("Pemain 1 = X, Pemain 2 = O\n");

    while (ulang == 'y' || ulang == 'Y') {
        char pemain = 'X';
        int selesai = 0;
        char buf[64];

        resetPapan();

        while (!selesai) {
            tampilkanPapan();
            int idx = bacaPilihan(pemain);
            papan[idx] = pemain;

            if (cekMenang(pemain)) {
                tampilkanPapan();
                printf("Selamat! Pemain %c menang!\n", pemain);
                selesai = 1;
            } else if (papanPenuh()) {
                tampilkanPapan();
                printf("Permainan seri!\n");
                selesai = 1;
            } else {
                pemain = (pemain == 'X') ? 'O' : 'X';
            }
        }

        printf("\nMain lagi? (y/n): ");
        if (fgets(buf, sizeof(buf), stdin) == NULL) break;
        ulang = buf[0];
    }

    printf("Terima kasih sudah bermain!\n");
    return 0;
}