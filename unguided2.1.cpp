#include <stdio.h>

// Membuat struct dengan nama 'Mahasiswa'
struct BiodataMhs {
    const char *nim;
    const char *namalngkp; // Membuat atribut 'nama'
    const char *namapgln;
    const char *TTL;
    int umur;
    const char *ank_ke;
    const char *jnsklmn;
    const char *agama;
    const char* tlp;
    const char *kwrgn;
    const char *hobi;
    const char *alamat; // Membuat atribut 'jurusan'
    const char *angkatan; // Membuat atribut 'angkatan'
};

int main() {
    // Membuat objek dari struct 'Mahasiswa'
    struct BiodataMhs Mhs1;
    Mhs1.nim = "2190230073";
    Mhs1.namalngkp = "Toni Wijaya";
    Mhs1.namapgln = "Toni";
    Mhs1.TTL = "Surakarta, 2 Agustus 2001";
    Mhs1.umur = 23;
    Mhs1.ank_ke = "2 dari dua bersaudara";
    Mhs1.jnsklmn = "Laki-Laki";
    Mhs1.agama = "Islam";
    Mhs1.tlp = "081913128091";
    Mhs1.kwrgn = "Indonesia";
    Mhs1.hobi = "Menggambar";
    Mhs1.alamat = "Jl. Yosodipuro No.2 Kec. Banjarsari, Kota Surakarta, Jawa Tengah";
    Mhs1.angkatan = "2021";
   
    

    // Menampilkan detail mahasiswa
   printf("--------Biodata Mahasiswa------\n");
   printf("\nNIM                   : %s\n", Mhs1.nim);
   printf("Nama lengkap            : %s\n", Mhs1.namalngkp);
   printf("Nama panggilan          : %s\n", Mhs1.namapgln);
   printf("Tempat & Tanggal Lahir  : %s\n", Mhs1.TTL);
   printf("Umur                    : %d\n", Mhs1.umur);
   printf("Anak ke-                : %s\n", Mhs1.ank_ke);
   printf("Jenis kelamin           : %s\n", Mhs1.jnsklmn);
   printf("Agama                   : %s\n", Mhs1.agama);
   printf("No. Telepon             : %s\n", Mhs1.tlp);
   printf("Kewarganegaraan         : %s\n", Mhs1.kwrgn);
   printf("Hobi                    : %s\n", Mhs1.hobi);
   printf("Alamat                  : %s\n", Mhs1.alamat);
   printf("Angkatan                : %s\n", Mhs1.angkatan);
   
   
   // Mencetak alamat memori dari name dan address
   printf("\nAlamat memori dari biodata Mahasiswa 1:\n");
   printf("NIM                     : %p\n", Mhs1.nim);
   printf("Nama lengkap            : %p\n", Mhs1.namalngkp);
   printf("Nama panggilan          : %p\n", Mhs1.namapgln);
   printf("Tempat & Tanggal Lahir  : %p\n", Mhs1.TTL);
   printf("Anak ke-                : %p\n", Mhs1.ank_ke);
   printf("Jenis kelamin           : %p\n", Mhs1.jnsklmn);
   printf("Agama                   : %p\n", Mhs1.agama);
   printf("No. Telepon             : %p\n", Mhs1.tlp);
   printf("Kewarganegaraan         : %p\n", Mhs1.kwrgn);
   printf("Hobi                    : %p\n", Mhs1.hobi);
   printf("Alamat                  : %p\n", Mhs1.alamat);
   printf("Angkatan                : %p\n", Mhs1.angkatan);
  
    return 0;
}