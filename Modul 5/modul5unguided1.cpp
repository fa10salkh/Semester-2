#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

const int TABLE_SIZE = 11;

class Mahasiswa 
{
public:
    string NIM;
    string nama;
    int nilai;
    Mahasiswa (string NIM, string nama, int nilai)
    {
            this->NIM = NIM;
            this->nama = nama;
            this->nilai = nilai;
    }
};

class HashMap
{
private:
    vector<Mahasiswa*> tabel[TABLE_SIZE];
public:
    int hashFunc (string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
void tambahData(string NIM, string nama, int nilai)
{
    int hash_val = hashFunc(NIM);
    for (auto node : tabel[hash_val])
    {
        if (node->NIM == NIM)
        {
            node->nama = nama;
            node->nilai = nilai;
            return;
        }
    }
    tabel[hash_val].push_back(new Mahasiswa(NIM, nama, nilai));
}
void hapusData (string NIM)
{
    int hash_val = hashFunc(NIM);
    bool found = false;
    for (auto it = tabel[hash_val].begin(); it != tabel[hash_val].end(); it++)
    {
        if ((*it)->NIM == NIM)
        {
            tabel [hash_val].erase(it);
            found = true;
            break;
        }
    }
    if (! found)
    {
        cout << "Data tidak ditemukan.\n";
    }
}
    Mahasiswa* cariBerdasarkanNIM(string NIM)
    {
        int hash_val = hashFunc(NIM);
        for (auto node : tabel[hash_val])
            {
                if (node->NIM == NIM)
                {
                    return node;
                }
            }
            return nullptr;
    }
void cariBerdasarkanNilai (int nilai)
{
    bool found = false;
    if (nilai < 80 || nilai > 90)
    {
        cout << "Nilai di luar rentang yang ditentukan (80-90).\n";
        return;
    }
    cout << "Mahasiswa dengan nilai: " << nilai << "\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        for (auto node : tabel[i])
        {
            if (node != nullptr && node->nilai == nilai)
            {
                cout << "NIM: " << node->NIM << ", Nama: " << node->nama << endl;
                found = true;
            }
        }
    }
    if (!found)
    {
        cout << "Data tidak ditemukan.\n";
    }
  }
void print ()
{
    cout << "==================================================\n";
    cout << "| " << left << setw(10) << "NIM" << " | " << left << setw(25) << "Nama" << " | " << left << setw(5) << "Nilai" << " |\n";
    cout << "==================================================\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        for (auto node : tabel[i])
        {
            if (node != nullptr)
            {
                cout << "| " << left << setw(10) << node->NIM << " | " << left << setw(25) << node->nama << " | " << left << setw(5) << node->nilai << " |\n";
            }
        }
        
    }
    cout << "==================================================\n\n";
  }
};

int main()
{
    HashMap dataMahasiswa;
    int pilihan;
    string NIM;
    string nama;
    int nilai;
    Mahasiswa* mhs;

    while (true)
    {
        cout << "=========================================\n";
        cout << "|           Program Hash Table          |\n";
        cout << "=========================================\n";
        cout << "| NO |            Menu                  |\n";
        cout << "=========================================\n";
        cout << "| 1  | Tambah data                      |\n"; 
        cout << "| 2  | Hapus data                       |\n"; 
        cout << "| 3  | Cari berdasarkan NIM             |\n"; 
        cout << "| 4  | Cari berdasarkan nilai           |\n";
        cout << "| 5  | Print semua data                 |\n";
        cout << "| 6  | Keluar                           |\n"; 
        cout << "=========================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Masukkan NIM  : ";
                cin >> NIM;
                cout << "Masukkan nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan nilai: ";
                cin >> nilai;
                dataMahasiswa.tambahData(NIM, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM  : ";
                cin >> NIM;
                dataMahasiswa.hapusData(NIM);
                break;
            case 3:
                cout << "Masukkan NIM  : ";
                cin >> NIM;
                mhs = dataMahasiswa.cariBerdasarkanNIM(NIM);
                if (mhs == nullptr)
                {
                    cout << "Data tidak ditemukan\n";
                }
                else
                {
                    cout << "Nama : " << mhs->nama << ", Nilai: " << mhs->nilai << endl;
                }
                break;
            case 4:
                cout << "Masukkan nilai : ";
                cin >> nilai;
                dataMahasiswa.cariBerdasarkanNilai(nilai);
                break;
            case 5:
                dataMahasiswa.print();
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silahkan masukkan angka antara 1 sampai 6.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}