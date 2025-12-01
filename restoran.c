#include <stdio.h>
#include <stdlib.h>
#include "pesanMakanan.h"
#include "booking.h"
#include "pembayaran.h"
#include "riwayat.h"

int totalPesanan = 0;
int totalBooking = 0;

int main()
{
    int pilih;

    do
    {
        printf("=====================================\n");
        printf("WELCOME TO RESTORAN 9Nine\n");
        printf("Alamat : JL. Merdeka Simpang 3 USU\n");
        printf("=====================================\n");

        printf("1. Pesan Makanan\n");
        printf("2. Booking Meja\n");
        printf("3. Pembayaran\n");
        printf("4. Lihat Riwayat\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            totalPesanan += pesanMakanan();
            break;

        case 2:
            totalBooking = bookingMeja();
            break;

        case 3:
            pembayaran(totalPesanan, totalBooking);
            break;

        case 4:
            lihatRiwayat();
            break;

        case 5:
            printf("==================================\n");
            printf("Terima kasih sudah berkunjung!\n");
            printf("==================================\n");
            break;

        default:
            printf("Pilihan tidak valid.\n");
        }

    } while (pilih != 5);

    return 0;
}
