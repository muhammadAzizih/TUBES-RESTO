#include <stdio.h>
#include "pesanMakanan.h"
#include "booking.h"
#include "pembayaran.h"
#include "riwayat.h"
#include "batalpesanan.h"

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
        printf("2. batalpesanan\n");
        printf("3. Booking Meja\n");
        printf("4. Pembayaran\n");
        printf("5. Lihat Riwayat\n");
        printf("6. hapus riwayat\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            totalPesanan += pesanMakanan();
            break;

        case 2:
            batalPesanan(&totalPesanan);
            break;

        case 3:
            totalBooking = bookingMeja();
            break;

        case 4:
            pembayaran(totalPesanan, totalBooking);
            break;

        case 5:
            lihatRiwayat();
            break;
        
        case 6: 
            hapusRiwayat(&totalPesanan,&totalBooking);
            break;    

        case 7:
            printf("==================================\n");
            printf("Terima kasih sudah berkunjung!\n");
            printf("==================================\n");
            break;

        default:
            printf("Pilihan tidak valid.\n");
        }

    } while (pilih != 7);

    return 0;
}
