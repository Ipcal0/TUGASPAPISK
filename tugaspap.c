#include <stdio.h>
#include <stdlib.h>

// Fungsi-fungsi perhitungan (sama seperti sebelumnya)
float hitung_skor_dtps(int NDTPS) {
    if (NDTPS >= 6) {
        return 4.0;
    } else if (NDTPS >= 3 && NDTPS < 6) {
        return (2.0 * NDTPS) / 3.0;
    } else {
        return 0.0;
    }
}

float hitung_skor_jabatan(int NDGB, int NDLK, int NDTPS) {
    float PGBLK = ((float)(NDGB + NDLK) / NDTPS) * 100;
    if (PGBLK >= 70) {
        return 4.0;
    } else {
        return 2.0 + ((20.0 * PGBLK) / 7.0);
    }
}

float hitung_skor_kurikulum(int A, int B, int C) {
    return (float)(A + (2 * B) + (2 * C)) / 5.0;
}

float hitung_skor_penjaminan_mutu(int aspek_terpenuhi) {
    if (aspek_terpenuhi == 5) return 4.0;
    else if (aspek_terpenuhi == 4) return 3.0;
    else if (aspek_terpenuhi == 3) return 2.0;
    else if (aspek_terpenuhi == 2) return 1.0;
    else return 0.0;
}

float hitung_skor_tracer(int aspek_terpenuhi) {
    if (aspek_terpenuhi == 5) return 4.0;
    else if (aspek_terpenuhi == 4) return 3.0;
    else if (aspek_terpenuhi == 3) return 2.0;
    else if (aspek_terpenuhi == 2) return 1.0;
    else return 0.0;
}

float hitung_skor_bidang_kerja(float PBS, int NL, int NJ) {
    float Prmin;
    if (NL >= 300) {
        Prmin = 30.0;
    } else {
        Prmin = 50.0 - ((NL / 300.0) * 20.0);
    }
    
    float PJ = ((float)NJ / NL) * 100;
    float skor;
    
    if (PBS >= 60) {
        skor = 4.0;
    } else {
        skor = (20.0 * PBS) / 3.0;
    }
    
    if (PJ >= Prmin) {
        return skor;
    } else {
        return (PJ / Prmin) * skor;
    }
}

float hitung_skor_kepuasan(float *sangat_baik, float *baik, float *cukup, float *kurang, 
                          int jumlah_aspek, int NL, int NJ) {
    float total_TKi = 0;
    for (int i = 0; i < jumlah_aspek; i++) {
        float TKi = (4 * sangat_baik[i]) + (3 * baik[i]) + (2 * cukup[i]) + kurang[i];
        total_TKi += TKi;
    }
    
    float skor = total_TKi / (7.0 * jumlah_aspek);
    
    float Prmin;
    if (NL >= 300) {
        Prmin = 30.0;
    } else {
        Prmin = 50.0 - ((NL / 300.0) * 20.0);
    }
    
    float PJ = ((float)NJ / NL) * 100;
    
    if (PJ >= Prmin) {
        return skor;
    } else {
        return (PJ / Prmin) * skor;
    }
}

int main() {
    float skor[7];  // Array untuk menyimpan semua skor
    
    printf("\nPROGRAM PERHITUNGAN AKREDITASI PROGRAM STUDI\n");
    printf("=============================================\n\n");

    // 1. Perhitungan Skor DTPS
    printf("1. Perhitungan Skor DTPS\n");
    printf("=====================\n");
    int NDTPS;
    printf("Masukkan jumlah DTPS: ");
    scanf("%d", &NDTPS);
    skor[0] = hitung_skor_dtps(NDTPS);
    printf("Skor DTPS: %.2f\n\n", skor[0]);

    // 2. Perhitungan Skor Jabatan Akademik
    printf("2. Perhitungan Skor Jabatan Akademik\n");
    printf("================================\n");
    int NDGB, NDLK;
    printf("Masukkan jumlah Guru Besar: ");
    scanf("%d", &NDGB);
    printf("Masukkan jumlah Lektor Kepala: ");
    scanf("%d", &NDLK);
    printf("Masukkan total DTPS: ");
    scanf("%d", &NDTPS);
    skor[1] = hitung_skor_jabatan(NDGB, NDLK, NDTPS);
    printf("Skor Jabatan Akademik: %.2f\n\n", skor[1]);

    // 3. Perhitungan Skor Kurikulum
    printf("3. Perhitungan Skor Kurikulum\n");
    printf("=========================\n");
    int A, B, C;
    printf("Masukkan nilai A: ");
    scanf("%d", &A);
    printf("Masukkan nilai B: ");
    scanf("%d", &B);
    printf("Masukkan nilai C: ");
    scanf("%d", &C);
    skor[2] = hitung_skor_kurikulum(A, B, C);
    printf("Skor Kurikulum: %.2f\n\n", skor[2]);

    // 4. Perhitungan Skor Penjaminan Mutu
    printf("4. Perhitungan Skor Penjaminan Mutu\n");
    printf("===============================\n");
    int aspek_mutu;
    printf("Masukkan jumlah aspek yang terpenuhi (0-5): ");
    scanf("%d", &aspek_mutu);
    skor[3] = hitung_skor_penjaminan_mutu(aspek_mutu);
    printf("Skor Penjaminan Mutu: %.2f\n\n", skor[3]);

    // 5. Perhitungan Skor Tracer Study
    printf("5. Perhitungan Skor Tracer Study\n");
    printf("===========================\n");
    int aspek_tracer;
    printf("Masukkan jumlah aspek tracer study yang terpenuhi (0-5): ");
    scanf("%d", &aspek_tracer);
    skor[4] = hitung_skor_tracer(aspek_tracer);
    printf("Skor Tracer Study: %.2f\n\n", skor[4]);

    // 6. Perhitungan Skor Kesesuaian Bidang Kerja
    printf("6. Perhitungan Skor Kesesuaian Bidang Kerja\n");
    printf("======================================\n");
    float PBS;
    int NL, NJ;
    printf("Masukkan persentase kesesuaian bidang kerja (PBS): ");
    scanf("%f", &PBS);
    printf("Masukkan jumlah lulusan (NL): ");
    scanf("%d", &NL);
    printf("Masukkan jumlah lulusan yang terlacak (NJ): ");
    scanf("%d", &NJ);
    skor[5] = hitung_skor_bidang_kerja(PBS, NL, NJ);
    printf("Skor Kesesuaian Bidang Kerja: %.2f\n\n", skor[5]);

    // 7. Perhitungan Skor Kepuasan Pengguna
    printf("7. Perhitungan Skor Kepuasan Pengguna\n");
    printf("================================\n");
    int jumlah_aspek = 7;
    float *sangat_baik = malloc(jumlah_aspek * sizeof(float));
    float *baik = malloc(jumlah_aspek * sizeof(float));
    float *cukup = malloc(jumlah_aspek * sizeof(float));
    float *kurang = malloc(jumlah_aspek * sizeof(float));
    
    for(int i = 0; i < jumlah_aspek; i++) {
        printf("\nUntuk aspek %d:\n", i+1);
        printf("Masukkan persentase Sangat Baik: ");
        scanf("%f", &sangat_baik[i]);
        printf("Masukkan persentase Baik: ");
        scanf("%f", &baik[i]);
        printf("Masukkan persentase Cukup: ");
        scanf("%f", &cukup[i]);
        printf("Masukkan persentase Kurang: ");
        scanf("%f", &kurang[i]);
    }
    
    printf("\nMasukkan jumlah lulusan (NL): ");
    scanf("%d", &NL);
    printf("Masukkan jumlah responden (NJ): ");
    scanf("%d", &NJ);
    
    skor[6] = hitung_skor_kepuasan(sangat_baik, baik, cukup, kurang, jumlah_aspek, NL, NJ);
    printf("Skor Kepuasan Pengguna: %.2f\n\n", skor[6]);

    free(sangat_baik);
    free(baik);
    free(cukup);
    free(kurang);

    // Menampilkan ringkasan semua skor
    printf("\nRINGKASAN SKOR AKREDITASI\n");
    printf("========================\n");
    printf("1. Skor DTPS: %.2f\n", skor[0]);
    printf("2. Skor Jabatan Akademik: %.2f\n", skor[1]);
    printf("3. Skor Kurikulum: %.2f\n", skor[2]);
    printf("4. Skor Penjaminan Mutu: %.2f\n", skor[3]);
    printf("5. Skor Tracer Study: %.2f\n", skor[4]);
    printf("6. Skor Kesesuaian Bidang Kerja: %.2f\n", skor[5]);
    printf("7. Skor Kepuasan Pengguna: %.2f\n", skor[6]);

    float total_skor = 0;
    for(int i = 0; i < 7; i++) {
        total_skor += skor[i];
    }
    printf("\nRata-rata Skor: %.2f\n", total_skor / 7);

    printf("\nTerima kasih telah menggunakan program ini!\n");
    return 0;
}