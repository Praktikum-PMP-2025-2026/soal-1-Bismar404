/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 01 - Overview of C Language
 *   Hari dan Tanggal    : Rabu, 15 April 2026
 *   Nama (NIM)          : Bismar Alwi Khadavi (13224016)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menghitung jumlah cara untuk turun tangga dengan melewati tangga yang rusak dan sekali turun bisa 1 atau 2 tangga
 *                         input: N (jumlah tangga), R (jumlah tangga rusak), dan nomor tangga yang rusak
 *                         output: jumlah cara untuk turun tangga
 */


#include <stdio.h>
#include <string.h>

int N, R;
int rusak[1000];

int hitungCara(int current){
    //kalau hanya 1 tangga, hanya ada 1 caranya
    if(current == 0) {
        return 1;
    }
    //kalau tangga yang diinjak rusak atau tangga tidak valid, tidak ada cara turun
    if(current<0 || rusak[current] == 1){
        return 0;
    }
    
    int cara = 0;
    
    //prioritas coba turun 1 tangga
    if(current-1 >= 0 && rusak[current-1] == 0) {
        cara += hitungCara(current-1);
    }
    
    //kalau bisa turun 2 tangga, coba cara turun 2 tangga
    if(current-2 >= 0 && rusak[current-2] == 0) {
        cara += hitungCara(current-2);
    }
    return cara;
}

int main() {
    scanf("%d %d", &N, &R);
    for (int i = 0; i < R; i++) {
        int rusakk;
        scanf("%d", &rusakk);
        rusak[rusakk] = 1;
    }
    
    int cara = hitungCara(N);
    printf("%d\n", cara);
    return 0;
}
 
