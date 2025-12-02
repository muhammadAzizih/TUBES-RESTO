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

    while (1)
    {
        printf("Tanggal (dd/mm/yyyy): ");
        scanf(" %s", tanggal);

        int d, m, y;
        if (sscanf(tanggal, "%d/%d/%d", &d, &m, &y) == 3)
        {
            if (d >= 1 && d <= 31 && m >= 1 && m <= 12 && y == 2025)
            {
                break;
            }
        }
        printf("Error: Format tanggal salah! Contoh: 21/02/2025\n");
    }

    while (1)
    {
        printf("Jam (7-23): ");
        scanf("%d", &jam);

        if (jam >= 7 && jam <= 23)
            break;

        printf("Error: Jam harus antara 7 sampai 23!\n");
    }

    while (1)
    {
        printf("Jumlah orang (1-15): ");
        scanf("%d", &orang);

        if (orang >= 1 && orang <= 15)
            break;

        printf("Error: Jumlah orang harus 1-15!\n");
    }

    // ------------------ INPUT RUANGAN ------------------
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

    // ------------------ MASUK PESAN MAKANAN ------------------
    printf("\n--- Silakan Tulis Pesanan Anda ---\n");
    totalMakanan = pesanMakanan();

    // ------------------ SIMPAN BOOKING ------------------
    FILE *file = fopen("booking.txt", "a");
    if (file == NULL)
    {
        printf("File tidak bisa dibuka!\n");
        return 0;
    }

    fprintf(file,
            "Booking: %s | %s | %d org | Jam %d | Meja %d | Ruangan: %s | Total Makanan: Rp %d\n",
            nama, tanggal, orang, jam, meja, ruangan, totalMakanan);

    fclose(file);

    printf("\nBooking disimpan dengan total makanan Rp %d\n", totalMakanan);
    printf("Silakan lakukan pembayaran di halaman Pembayaran.\n");

    // ------------------ KEBIJAKAN ------------------
    printf("\n--- KEBIJAKAN BOOKING ---\n");
    printf("Meja hanya ditahan selama 20 menit dari waktu reservasi.\n");
    printf("Jika terlambat atau tidak hadir, booking dapat dibatalkan.\n");

    return totalMakanan;
}
