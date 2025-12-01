#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H

#include <stdio.h>

void pembayaran(int totalPesanan, int totalBooking)
{
    int pilih, uang;

    printf("\n=== MENU PEMBAYARAN ===\n");
    printf("1. Pembayaran Pesanan\n");
    printf("2. Pembayaran Booking\n");
    printf("Pilih: ");
    scanf("%d", &pilih);

    // ============================================
    // 1. PEMBAYARAN PESANAN
    // ============================================
    if (pilih == 1)
    {
        if (totalPesanan <= 0)
        {
            printf("Belum ada pesanan! Tidak bisa melakukan pembayaran.\n");
            return;
        }

        printf("\nTotal bayar pesanan: Rp %d\n", totalPesanan);
        printf("Metode Pembayaran:\n");
        printf("1. Cash\n");
        printf("2. BRI\n");
        printf("3. Mandiri\n");
        printf("4. BNI\n");
        printf("Pilih metode: ");

        int m;
        scanf("%d", &m);

        // ===== CASH =====
        if (m == 1)
        {
            printf("Masukkan uang cash: Rp ");
            scanf("%d", &uang);

            while (uang < totalPesanan)
            {
                printf("Uang kurang, masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            printf("Kembalian: Rp %d\n", uang - totalPesanan);
            printf("Pembayaran pesanan BERHASIL!\n");
        }
        // ===== TRANSFER =====
        else if (m >= 2 && m <= 4)
        {
            if (m == 2)
                printf("No Rek BRI     : 1234-5678-1111\n");
            if (m == 3)
                printf("No Rek Mandiri : 3245-6575-4325\n");
            if (m == 4)
                printf("No Rek BNI     : 9876-5432-1098\n");

            printf("Masukkan jumlah transfer: Rp ");
            scanf("%d", &uang);

            while (uang < totalPesanan)
            {
                printf("Transfer kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            if (uang > totalPesanan)
                printf("Kembalian otomatis dikirim: Rp %d\n", uang - totalPesanan);

            printf("Pembayaran pesanan BERHASIL!\n");
        }
        else
        {
            printf("Metode tidak valid!\n");
            return;
        }

        // SIMPAN RIWAYAT PESANAN
        FILE *file = fopen("riwayat_pesanan.txt", "a");
        fprintf(file, "Pembayaran Pesanan = Rp %d\n", totalPesanan);
        fclose(file);

        printf("Riwayat pembayaran pesanan tersimpan.\n");
    }

    // ============================================
    // 2. PEMBAYARAN BOOKING (TANPA PANJAR)
    // ============================================
    else if (pilih == 2)
    {
        if (totalBooking <= 0)
        {
            printf("Belum ada booking! Tidak bisa membayar.\n");
            return;
        }

        printf("\n=== PEMBAYARAN BOOKING ===\n");
        printf("Total Booking yang harus dibayar: Rp %d\n\n", totalBooking);

        printf("Metode Pembayaran:\n");
        printf("1. Cash\n");
        printf("2. BRI\n");
        printf("3. Mandiri\n");
        printf("4. BNI\n");
        printf("Pilih metode: ");

        int mb;
        scanf("%d", &mb);

        // CASH
        if (mb == 1)
        {
            printf("Masukkan uang cash: Rp ");
            scanf("%d", &uang);

            while (uang < totalBooking)
            {
                printf("Uang kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            printf("Kembalian: Rp %d\n", uang - totalBooking);
            printf("Pembayaran booking BERHASIL!\n");
        }
        // TRANSFER
        else if (mb >= 2 && mb <= 4)
        {
            if (mb == 2)
                printf("No Rek BRI     : 1234-5678-1111\n");
            if (mb == 3)
                printf("No Rek Mandiri : 3245-6575-4325\n");
            if (mb == 4)
                printf("No Rek BNI     : 9876-5432-1098\n");

            printf("Masukkan jumlah transfer: Rp ");
            scanf("%d", &uang);

            while (uang < totalBooking)
            {
                printf("Transfer kurang! Masukkan lagi: Rp ");
                scanf("%d", &uang);
            }

            if (uang > totalBooking)
                printf("Kembalian otomatis dikirim: Rp %d\n", uang - totalBooking);

            printf("Pembayaran booking BERHASIL!\n");
        }
        else
        {
            printf("Metode tidak valid!\n");
            return;
        }

        // SIMPAN RIWAYAT BOOKING
        FILE *file = fopen("riwayat_booking.txt", "a");
        fprintf(file, "Pembayaran Booking = Rp %d\n", totalBooking);
        fclose(file);

        printf("Riwayat pembayaran booking tersimpan.\n");
    }

    // ============================================
    else
    {
        printf("Pilihan tidak valid!\n");
    }
}

#endif
