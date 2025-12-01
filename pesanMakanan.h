#ifndef PESAN_MAKANAN_H
#define PESAN_MAKANAN_H
#include <stdlib.h>
#include <stdio.h>

int pesanMakanan()
{
    int pilih, jumlah, harga = 0, total = 0;
    char lagi;
    char jenis;           
    const char *jenisStr;

    do {
        printf("\nPilih jenis pesanan:\n");
        printf("1. Take Away\n");
        printf("2. Dine In\n");
        printf("Masukkan pilihan (1/2): ");
        if (scanf(" %c", &jenis) != 1) {
            while (getchar() != '\n'); 
            jenis = 0;
        }
    } while (jenis != '1' && jenis != '2');

    jenisStr = (jenis == '1') ? "Take Away" : "Dine In";

    FILE *fileJenis = fopen("pesanan.txt", "a");
    if (fileJenis) {
        fprintf(fileJenis, "Jenis: %s\n", jenisStr);
        fclose(fileJenis);
    }

    do
    {
        printf("\n--- PESAN MAKANAN ---\n");
        printf("1.  Nasi Goreng       - 15000\n");
        printf("2.  Ayam Geprek       - 18000\n");
        printf("3.  Ayam Gulai        - 15000\n");
        printf("4.  Mie Ayam          - 12000\n");
        printf("5.  Ayam Bakar        - 25000\n");
        printf("6.  Sate              - 20000\n");
        printf("7.  Martabak Telor    - 30000\n");
        printf("8.  Mie Goreng        - 10000\n");
        printf("\n--- PESAN SIDE DISH ---\n");
        printf("9.  Kangkung          - 15000\n");
        printf("10.  Sop Ayam         - 18000\n");
        printf("11.  Sop Sapi         - 25000\n");
        printf("12.  Tom Yam          - 20000\n");
        printf("13.  Bayam Tumis      - 20000\n");
        printf("\n--- PESAN SNACK ---\n");
        printf("14.  Empek-Empek      - 13000\n");
        printf("15.  Gorengan         - 2000\n");
        printf("16.  Kentang          - 7000\n");
        printf("17.  Nugget           - 10000\n");
        printf("\n--- PESAN MINUMAN ---\n");
        printf("18.  Kopi Blend       - 10000\n");
        printf("19.  Kopi Susu        - 10000\n");
        printf("20.  Kopi Hitam       - 5000\n");
        printf("21.  Kopi Milo        - 12000\n");
        printf("22.  Kopi Vanilla     - 25000\n");
        printf("23.  Ice Tea          - 12000\n");
        printf("24.  Ice Lemon        - 13000\n");
        printf("25.  Lemonade         - 10000\n");
        printf("26.  Teh Tarik        - 30000\n");
        printf("27. Banana Cream      - 17000\n");
        printf("\n--- PESAN JUS ---\n");
        printf("28.  Alpukat          - 10000\n");
        printf("29.  Jeruk            - 10000\n");
        printf("30.  Sirsak           - 10000\n");
        printf("31.  Markisa          - 10000\n");
        printf("32.  Mangga           - 10000\n");
        printf("33.  MIX              - 20000\n");

        printf("Pilih menu (1-33): ");
        if (scanf("%d", &pilih) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid.\n");
            continue;
        }

        if (pilih < 1 || pilih > 33) {
            printf("Pilihan tidak valid. Masukkan menu dengan angka diantara 1 dan 33.\n");
            continue;
        }

        switch (pilih)
        {
        case 1: harga = 15000; break;
        case 2: harga = 18000; break;
        case 3: harga = 15000; break;
        case 4: harga = 12000; break;
        case 5: harga = 25000; break;
        case 6: harga = 20000; break;
        case 7: harga = 30000; break;
        case 8: harga = 10000; break;
        case 9: harga = 15000; break;
        case 10: harga = 18000; break;
        case 11: harga = 25000; break;
        case 12: harga = 20000; break;
        case 13: harga = 20000; break;
        case 14: harga = 13000; break;
        case 15: harga = 2000; break;
        case 16: harga = 7000; break;
        case 17: harga = 10000; break;
        case 18: harga = 10000; break;
        case 19: harga = 10000; break;
        case 20: harga = 5000; break;
        case 21: harga = 10000; break;
        case 22: harga = 25000; break;
        case 23: harga = 12000; break;
        case 24: harga = 13000; break;
        case 25: harga = 10000; break;
        case 26: harga = 30000; break;
        case 27: harga = 17000; break;
        case 28: harga = 10000; break;
        case 29: harga = 10000; break;
        case 30: harga = 10000; break;
        case 31: harga = 10000; break;
        case 32: harga = 10000; break;
        case 33: harga = 20000; break;
        default:
            printf("Menu tidak ada!\n");
            continue;
        }

        printf("Jumlah pesanan: ");
        if (scanf("%d", &jumlah) != 1 || jumlah <= 0) {
            while (getchar() != '\n');
            printf("Jumlah tidak valid.\n");
            continue;
        }

        int subtotal = harga * jumlah;
        total += subtotal;

        printf("Subtotal: %d\n", subtotal);

        FILE *file = fopen("pesanan.txt", "a");
        if (file) {
            fprintf(file, "Menu %d x %d = %d\n", pilih, jumlah, subtotal);
            fclose(file);
        }

        printf("Ada lagi? (y/n): ");
        scanf(" %c", &lagi);

    } while (lagi == 'y' || lagi == 'Y');

    FILE *fileTot = fopen("pesanan.txt", "a");
    if (fileTot) {
        fprintf(fileTot, "Total: %d\n\n", total);
        fclose(fileTot);
    }

    system("cls");
    printf("\n=====================================\n");
    printf("Total semua pesanan: Rp %d  (%s)\n", total, jenisStr);
    printf("=====================================\n");
    
    return total;
}

#endif