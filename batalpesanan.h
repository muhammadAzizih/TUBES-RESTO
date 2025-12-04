#include <stdio.h>

void batalPesanan(int *totalPesanan)
{
    if (*totalPesanan <= 0)
    {
        printf("\nTidak ada pesanan untuk dibatalkan!\n");
        return;
    }

    printf("\n=== BATAL PESANAN ===\n");
    printf("Pesanan dengan total Rp %d berhasil dibatalkan!\n", *totalPesanan);

    // Simpan ke riwayat
    FILE *file = fopen("riwayat.txt", "a");
    fprintf(file, "Pesanan dibatalkan (total Rp %d)\n", *totalPesanan);
    fclose(file);

    // Reset total pesanan
    *totalPesanan = 0;
}
