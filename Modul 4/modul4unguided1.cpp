#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head;
Node *tail;

void init() {
    head = NULL;
    tail = NULL;
}

bool isEmpty() {
    return head == NULL;
}

void insertDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }

}

void insertBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }

}

int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertTengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->nama = nama;
        baru->nim = nim;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;

    }
}

void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        string namaHapus = hapus->nama;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
        cout << "\nData (" << namaHapus << ") berhasil dihapus." << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusBelakangNIM(string nim) {
    if (!isEmpty()) {
        Node *hapus = tail;
        string namaHapus = hapus->nama;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
        cout << "\nData (" << namaHapus << ") berhasil dihapus." << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void hapusTengahNIM(string nim) {
    if (!isEmpty()) {
        Node *bantu = head;
        Node *sebelum = NULL;
        while (bantu != NULL && bantu->nim != nim) {
            sebelum = bantu;
            bantu = bantu->next;
        }
        if (bantu == NULL) {
            cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
        } else {
            if (sebelum != NULL) {
                sebelum->next = bantu->next;
            } else {
                head = bantu->next;
            }
            string namaHapus = bantu->nama;
            delete bantu;
            cout << "\nData (" << namaHapus << ") berhasil dihapus." << endl;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}
void ubahDepan(string nama, string nim) {
    if (!isEmpty()) {
        string namaLama = head->nama;
        head->nama = nama;
        head->nim = nim;
        cout << "\nData (" << namaLama << ") telah diganti dengan data (" << nama << ")." << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(string nama, string nim, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            string namaLama = bantu->nama;
            bantu->nama = nama;
            bantu->nim = nim;
            cout << "\nData (" << namaLama << ") telah diganti dengan data (" << nama << ")." << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(string nama, string nim) {
    if (!isEmpty()) {
        string namaLama = tail->nama;
        tail->nama = nama;
        tail->nim = nim;
        cout << "\nData (" << namaLama << ") telah diganti dengan data (" << nama << ")." << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void clearList() {
    Node *bantu = head;
    Node *hapus;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampil() {
    if (!isEmpty()) {
        Node* bantu = head;
        cout << "------------------------------------------------\n";
        cout << "| No | Nama              | NIM                 |\n";
        cout << "------------------------------------------------\n";
        int no = 1;
        while (bantu != NULL) {
            cout << "| " << left << setw(2) << no << " | " << left << setw(17) << bantu->nama << " | " << left << setw(19) << bantu->nim << " |\n";
            bantu = bantu->next;
            no++;
        }
        cout << "------------------------------------------------\n";
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    int pilihan;
    string nama, nim, namaHapus;
    int posisi;
    do {
        cout << "===========================================" << endl;
        cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
        cout << "===========================================" << endl;
        cout << "| No. | Pilihan Menu                      |" << endl;
        cout << "===========================================" << endl;
        cout << "| 1.  | Tambah Depan                      |" << endl;
        cout << "| 2.  | Tambah Belakang                   |" << endl;
        cout << "| 3.  | Tambah Tengah                     |" << endl;
        cout << "| 4.  | Ubah Depan                        |" << endl;
        cout << "| 5.  | Ubah Belakang                     |" << endl;
        cout << "| 6.  | Ubah Tengah                       |" << endl;
        cout << "| 7.  | Hapus Depan                       |" << endl;
        cout << "| 8.  | Hapus Belakang                    |" << endl;
        cout << "| 9.  | Hapus Tengah                      |" << endl;
        cout << "| 10. | Hapus List                        |" << endl;
        cout << "| 11. | TAMPILKAN                         |" << endl;
        cout << "| 0.  | KELUAR                            |" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                insertDepan(nama, nim);
                cout << "---------------------------------\n";
                cout << "| Nama              | NIM       |\n";
                cout << "---------------------------------\n";
                cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                cout << "---------------------------------\n";
                cout << "\nData telah ditambahkan.\n" << endl;
                cout << "=================================\n" << endl;
                break;
            case 2:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                insertBelakang(nama, nim);
                cout << "---------------------------------\n";
                cout << "| Nama              | NIM       |\n";
                cout << "---------------------------------\n";
                cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                cout << "---------------------------------\n";
                cout << "\nData telah ditambahkan." << endl;
                cout << "=================================\n" << endl;
                break;

            case 3:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                cout << "------------------------------------------\n";
                cout << "| Nama              | NIM       | Posisi |\n";
                cout << "------------------------------------------\n";
                cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " | " << setw(6) << left << posisi << " |\n";
                cout << "------------------------------------------\n";
                cout << "==========================================\n" << endl;
                break;
             case 4:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                ubahDepan(nama, nim);
                cout << "---------------------------------\n";
                cout << "| Nama              | NIM       |\n";
                cout << "---------------------------------\n";
                cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                cout << "---------------------------------\n";
                cout << "=================================\n" << endl;
                break;
            case 5:
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                ubahBelakang(nama, nim);
                cout << "---------------------------------\n";
                cout << "| Nama              | NIM       |\n";
                cout << "---------------------------------\n";
                cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                cout << "---------------------------------\n";
                cout << "=================================\n" << endl;
                break;
            case 6:
                 cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                cout << "------------------------------------------\n";
                cout << "| Nama              | NIM       | Posisi |\n";
                cout << "------------------------------------------\n";
                cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " | " << setw(6) << left << posisi << " |\n";
                cout << "------------------------------------------\n";
                cout << "==========================================\n" << endl;
                break;

            case 7:
                if (!isEmpty()) {
                    nama = head->nama; // Simpan nama sebelum node dihapus
                    nim = head->nim; // Simpan nim sebelum node dihapus
                    hapusDepan();
                    cout << "---------------------------------\n";
                    cout << "| Nama              | NIM       |\n";
                    cout << "---------------------------------\n";
                    cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                    cout << "---------------------------------\n";
                } else {
                    cout << "List masih kosong!" << endl;
                }
                break;
            case 8:
                    cout << "Masukkan NIM: ";
                    cin >> nim;
                    if (!isEmpty()) {
                        Node *bantu = head;
                        while (bantu != NULL && bantu->nim != nim) {
                            bantu = bantu->next;
                        }
                        if (bantu == NULL) {
                            cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
                        } else {
                            nama = bantu->nama; // Simpan nama sebelum node dihapus
                            hapusBelakangNIM(nim);
                            cout << "---------------------------------\n";
                            cout << "| Nama              | NIM       |\n";
                            cout << "---------------------------------\n";
                            cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                            cout << "---------------------------------\n";
                        }
                    } else {
                        cout << "List masih kosong!" << endl;
                    }
                    break;
            case 9:
                cout << "Masukkan NIM: ";
                cin >> nim;
                if (!isEmpty()) {
                    Node *bantu = head;
                    while (bantu != NULL && bantu->nim != nim) {
                        bantu = bantu->next;
                    }
                    if (bantu == NULL) {
                        cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
                    } else {
                        nama = bantu->nama; // Simpan nama sebelum node dihapus
                        hapusTengahNIM(nim);
                        cout << "---------------------------------\n";
                        cout << "| Nama              | NIM       |\n";
                        cout << "---------------------------------\n";
                        cout << "| " << setw(17) << left << nama << " | " << setw(10) << left << nim << " |\n";
                        cout << "---------------------------------\n";
                        cout << "Data berhasil dihapus." << endl;
                    }
                } else {
                    cout << "List masih kosong!" << endl;
                }
                break;
            case 10:
                clearList();
                break;
            case 11:
                tampil();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
    return 0;
}