#include <iostream>
#include <string>

using namespace std;

// Membuat class dengan nama 'Mahasiswa'
class Data_diri {
public: // Mengatur akses ke public
    string namalengkap; // Membuat atribut 'nama'
    string jeniskelamin; // Membuat atribut 'jurusan'
    string tempattanggalLahir;// Membuat atribut 'angkatan'
    string alamatlengkap;
    string telp;
    string agama;
    string tinggibadan;
    string warnakulit;
    string kewarganegaraan;
    string suku;
    
    

    // Membuat metode untuk menampilkan detail mahasiswa
    void tampilkanDetail() {
        cout << "Nama lengkap           : " << namalengkap << "\n";
        cout << "Jenis kelamin          : " << jeniskelamin << "\n";
        cout << "Tempat & Tanggal Lahir : " << tempattanggalLahir << "\n";
        cout << "Alamat lengkap         : " << alamatlengkap << "\n";
        cout << "No. Telp               : " << telp << "\n";
        cout << "Agama                  : " << agama << "\n";
        cout << "Tinggi badan           : " << tinggibadan << "\n";
        cout << "Warna kulit            : " << warnakulit << "\n";
        cout << "Kewarganegaraan        : " << kewarganegaraan << "\n";
        cout << "Suku                   : " << suku << "\n";
    }
};

int main() {
    // Membuat objek dari class 'Mahasiswa'
    Data_diri org1;
    org1.namalengkap = "Andi Budiman";
    org1.jeniskelamin = "Laki - Laki";
    org1.tempattanggalLahir = "Semarang, 2 Januari 2000";
    org1.alamatlengkap = "Jl. Jend. Soedirman No.2 Karang Jambu, Kab. Semarang, Jawa Tengah";
    org1.telp = "081132932746";
    org1.agama = "Islam";
    org1.tinggibadan = "170";
    org1.warnakulit = "Sawo matang";
    org1.kewarganegaraan = "Indonesia";
    org1.suku = "Jawa";
                

    // Menampilkan detail mahasiswa menggunakan metode 'tampilkanDetail'
    org1.tampilkanDetail();

    return 0;
}