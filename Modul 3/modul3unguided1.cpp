#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int usia;
    Node* next;
};

Node* head;
Node* tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return head == NULL;
}

// Tambah Node di depan
void insertDepan(string nama, int usia) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di belakang
void insertBelakang(string nama, int usia) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->usia = usia;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah Node di list
int hitungList() {
    Node* hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Node di posisi tengah
void insertTengah(string nama, int usia, int posisi) {
    if (posisi < 1 || posisi > hitungList() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node* baru = new Node();
        baru->nama = nama;
        baru->usia = usia;
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Node di belakang
void hapusBelakang() {
    if (!isEmpty()) {
        if (head != tail) {
            Node* hapus = tail;
            Node* bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di posisi tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node* hapus;
        Node* bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah data Node di depan
void ubahDepan(string nama, int usia) {
    if (!isEmpty()) {
        head->nama = nama;
        head->usia = usia;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di posisi tengah
void ubahTengah(string nama, int usia, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node* bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->nama = nama;
            bantu->usia = usia;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di belakang
void ubahBelakang(string nama, int usia) {
    if (!isEmpty()) {
        tail->nama = nama;
        tail->usia = usia;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus semua Node di list
void clearList() {
    Node* bantu = head;
    while (bantu != NULL) {
        Node* hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void tampil() {
    if (!isEmpty()) {
        Node* bantu = head;
        cout << "--------------------------------\n";
        cout << "| No | Nama              | Usia |\n";
        cout << "--------------------------------\n";
        int no = 1;
        while (bantu != NULL) {
            cout << "| " << left << setw(2) << no << " | " << left << setw(17) << bantu->nama << " | " << left << setw(3) << bantu->usia << " |\n";
            bantu = bantu->next;
            no++;
        }
        cout << "--------------------------------\n";
    } else {
        cout << "List masih kosong!" << endl;
    }
}
int main() {
    init();
    int pilihan;
    do {
        cout << "========== | Menu | ==========\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data Urutan Tertentu\n";
        cout << "5. Hapus Data Urutan Tertentu\n";
        cout << "6. Hapus Seluruh Data\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Exit\n";
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: {
                string nama;
                int usia;
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan usia : ";
                cin >> usia;
                int posisi;
                cout << "Tambah data di  1 depan atau 2 belakang? ";
                cin >> posisi;
                if (posisi == 1) {
                    insertDepan(nama, usia);
                } else if (posisi == 2) {
                    insertBelakang(nama, usia);
                } else {
                    cout << "Pilihan tidak valid. Data akan ditambahkan di depan.\n";
                    insertDepan(nama, usia);
                }
                break;
            }
            case 2: {
                if (!isEmpty()) {
                    int posisi;
                    cout << "Masukkan posisi data yang ingin dihapus : ";
                    cin >> posisi;
                    hapusTengah(posisi);
                    cout << "Data berhasil dihapus.\n";
                } else {
                    cout << "List masih kosong!\n";
                }
                break;
            }
            case 3: {
                if (!isEmpty()) {
                    int posisi;
                    string nama;
                    int usia;
                    cout << "Masukkan posisi data yang ingin diperbarui : ";
                    cin >> posisi;
                    cout << "Masukkan nama baru : ";
                    cin >> nama;
                    cout << "Masukkan usia baru : ";
                    cin >> usia;
                    ubahTengah(nama, usia, posisi);
                    cout << "Data berhasil diupdate.\n";
                } else {
                    cout << "List masih kosong!\n";
                }
                break;
            }
            case 4: {
                int posisi;
                string nama;
                int usia;
                cout << "Masukkan posisi data yang ingin ditambahkan : ";
                cin >> posisi;
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan usia : ";
                cin >> usia;
                insertTengah(nama, usia, posisi);
                cout << "Data berhasil ditambahkan.\n";
                break;
            }
            case 5: {
                if (!isEmpty()) {
                    int posisi;
                    cout << "Masukkan posisi data yang ingin dihapus : ";
                    cin >> posisi;
                    hapusTengah(posisi);
                    cout << "Data berhasil dihapus.\n";
                } else {
                    cout << "List masih kosong!\n";
                }
                break;
            }
            case 6: {
                if (!isEmpty()) {clearList();
                    cout << "Seluruh data berhasil dihapus.\n";
                } else {
                    cout << "List masih kosong!\n";
                }
                break;
            }
            case 7: {
                cout << "Data dalam list: \n";
                tampil();
                break;
            }
            case 8:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (pilihan != 8);
    return 0;
}
