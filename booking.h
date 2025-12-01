#include <stdio.h>
#include <string.h>

int pesanMakanan();

int bookingMeja()
{
    char nama[50], tanggal[20], ruangan[20];
    int orang, meja, jam;
    int totalMakanan = 0;

    printf("\n--- BOOKING MEJA ---\n");
    printf("Nama: ");
    scanf(" %s", nama);

    printf("Tanggal (dd/mm/yyyy): ");
    scanf(" %s", tanggal);

    printf("Jam (0-23): ");
    scanf(" %d", &jam);

    printf("Jumlah orang: ");
    scanf(" %d", &orang);

    printf("Ruangan (indoor/outdoor): ");
    scanf(" %s", ruangan);

    while (1)
    {
        if (strcmp(ruangan, "indoor") == 0)
        {
            printf("Nomor meja (1-10): ");
            scanf("%d", &meja);

            if (meja >= 1 && meja <= 10)
            {
                printf("Meja %d di ruangan indoor berhasil dipesan.\n", meja);
                break;
            }
            else
            {
                printf("Error: meja indoor harus 1-10!\n");
            }
        }
        else if (strcmp(ruangan, "outdoor") == 0)
        {
            printf("Nomor meja (11-15): ");
            scanf("%d", &meja);

            if (meja >= 11 && meja <= 15)
            {
                printf("Meja %d di ruangan outdoor berhasil dipesan.\n", meja);
                break;
            }
            else
            {
                printf("Error: meja outdoor harus 11-15!\n");
            }
        }
        else
        {
            printf("Error: Ruangan tidak valid. Harus 'indoor' atau 'outdoor'.\n");
            printf("Input ruangan ulang: ");
            scanf(" %s", ruangan);
        }
    }

    char pilih;
    printf("\nApakah ingin sekalian pesan makanan? (y/n): ");
    scanf(" %c", &pilih);

    if (pilih == 'y' || pilih == 'Y')
        totalMakanan = pesanMakanan();

    // Simpan ke file
    FILE *file = fopen("booking.txt", "a");
    if (file == NULL)
    {
        printf("File tidak bisa dibuka!\n");
        return 0;
    }

    fprintf(file,
            "Booking: %s | %s | %d org | Meja %d | Ruangan: %s | Total Makanan: Rp %d\n",
            nama, tanggal, orang, meja, ruangan, totalMakanan);

    fclose(file);

    printf("\nBooking disimpan dengan total makanan Rp %d\n", totalMakanan);

    printf("\n--- KEBIJAKAN BOOKING ---\n");
    printf("Mohon diperhatikan bahwa meja hanya akan ditahan selama 20 menit");
    printf("dari waktu reservasi. Jika terjadi keterlambatan atau tidak hadir,");
    printf("restoran berhak membatalkan booking Anda karena kemungkinan");
    printf("akan ada reservasi berikutnya yang menggunakan meja tersebut.\n");

    return totalMakanan;
}