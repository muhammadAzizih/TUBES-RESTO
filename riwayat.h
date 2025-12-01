#ifndef RIWAYAT_H
#define RIWAYAT_H

#include <stdio.h>
#include <string.h>

void lihatRiwayat() {
    char line[200];
    int lineCount = 0;

    printf("\n");
    printf("================================================================\n");
    printf("           RIWAYAT TRANSAKSI RESTORAN 9Nine                     \n");
    printf("================================================================\n");

    // ========== RIWAYAT PESANAN ==========
    printf("\n-----------------------------------------------------------------\n");
    printf("                  RIWAYAT PESANAN MAKANAN                        \n");
    printf("-----------------------------------------------------------------\n");
    
    FILE *p = fopen("pesanan.txt", "r");
    
    if (!p) {
        printf("   [!] Belum ada riwayat pesanan makanan.\n");
    } else {
        lineCount = 0;
        
        while (fgets(line, sizeof(line), p)) {
            lineCount++;
            printf("   %d. %s", lineCount, line);
        }
        fclose(p);
        
        if (lineCount == 0) {
            printf("   [!] File kosong - belum ada pesanan.\n");
        }
    }

    // ========== RIWAYAT BOOKING ==========
    printf("\n-----------------------------------------------------------------\n");
    printf("                    RIWAYAT BOOKING MEJA                         \n");
    printf("-----------------------------------------------------------------\n");
    
    FILE *b = fopen("booking.txt", "r");
    
    if (!b) {
        printf("   [!] Belum ada riwayat booking meja.\n");
    } else {
        lineCount = 0;
        
        while (fgets(line, sizeof(line), b)) {
            lineCount++;
            line[strcspn(line, "\n")] = 0;
            printf("   %d. %s\n", lineCount, line);
        }
        fclose(b);
        
        if (lineCount == 0) {
            printf("   [!] File kosong - belum ada booking.\n");
        }
    }

    // ========== RIWAYAT PEMBAYARAN & PEMBATALAN ==========
    printf("\n-----------------------------------------------------------------\n");
    printf("            RIWAYAT PEMBAYARAN & PEMBATALAN                      \n");
    printf("-----------------------------------------------------------------\n");
    
    FILE *r = fopen("riwayat.txt", "r");
    
    if (!r) {
        printf("   [!] Belum ada riwayat pembayaran atau pembatalan.\n");
    } else {
        lineCount = 0;
        
        while (fgets(line, sizeof(line), r)) {
            lineCount++;
            line[strcspn(line, "\n")] = 0;
            
            // Tambahkan indicator berdasarkan jenis transaksi
            if (strstr(line, "Pembayaran")) {
                printf("   %d. [LUNAS] %s\n", lineCount, line);
            } else if (strstr(line, "dibatalkan")) {
                printf("   %d. [BATAL] %s\n", lineCount, line);
            } else {
                printf("   %d. %s\n", lineCount, line);
            }
        }
        fclose(r);
        
        if (lineCount == 0) {
            printf("   [!] File kosong - belum ada transaksi.\n");
        }
    }

    printf("\n================================================================\n");
    printf("              Terima kasih atas kunjungan Anda!                  \n");
    printf("================================================================\n\n");
}

// ========== FUNGSI HAPUS RIWAYAT ==========
void hapusRiwayat(int *totalPesanan, int *totalBooking, int *panjar) {
    char konfirmasi;
    
    printf("\n");
    printf("================================================================\n");
    printf("                    HAPUS SEMUA RIWAYAT                          \n");
    printf("================================================================\n");
    printf("\n   PERINGATAN: Semua data riwayat akan dihapus permanen!\n");
    printf("   - Riwayat pesanan makanan\n");
    printf("   - Riwayat booking meja\n");
    printf("   - Riwayat pembayaran dan pembatalan\n");
    printf("\n================================================================\n");
    
    printf("\nApakah Anda yakin ingin menghapus SEMUA riwayat? (y/n): ");
    scanf(" %c", &konfirmasi);
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        // Hapus semua file riwayat
        int hapusPesanan = remove("pesanan.txt");
        int hapusBooking = remove("booking.txt");
        int hapusRiwayat = remove("riwayat.txt");
        
        // Reset semua variabel ke 0
        *totalPesanan = 0;
        *totalBooking = 0;
        *panjar = 0;
        
        printf("\n================================================================\n");
        
        // Cek hasil penghapusan
        if (hapusPesanan == 0) {
            printf("   [OK] Riwayat pesanan berhasil dihapus\n");
        } else {
            printf("   [!] Riwayat pesanan tidak ditemukan atau sudah kosong\n");
        }
        
        if (hapusBooking == 0) {
            printf("   [OK] Riwayat booking berhasil dihapus\n");
        } else {
            printf("   [!] Riwayat booking tidak ditemukan atau sudah kosong\n");
        }
        
        if (hapusRiwayat == 0) {
            printf("   [OK] Riwayat transaksi berhasil dihapus\n");
        } else {
            printf("   [!] Riwayat transaksi tidak ditemukan atau sudah kosong\n");
        }
        
        printf("\n   Semua data telah direset!\n");
        printf("================================================================\n\n");
        
    } else {
        printf("\n================================================================\n");
        printf("   Penghapusan riwayat dibatalkan.\n");
        printf("================================================================\n\n");
    }
}

#endif
