#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
    string namaProduk;
    double harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

   void push_back(string namaProduk, double harga) {
    Node* newNode = new Node;
    newNode->namaProduk = namaProduk;
    newNode->harga = harga;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(string oldNamaProduk, string newNamaProduk, double newHarga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == oldNamaProduk) {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void insertAt(int position, string namaProduk, double harga) {
    Node* newNode = new Node;
    newNode->namaProduk = namaProduk;
    newNode->harga = harga;
    if (position == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < position - 1; i++) { //aslinya - 1
            if (current != nullptr) {
                current = current->next;
            }
        }
        if (current != nullptr && current->next != nullptr) {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}

    void deleteAt(int position) {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        if (position == 0) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete current;
        }
        else {
            for (int i = 0; i < position; i++) {
                if (current != nullptr) {
                    current = current->next;
                }
            }
            if (current != nullptr) {
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                delete current;
            }
        }
    }

   void display() {
    Node* current = head;
    cout << "-----------------------------------" << endl;
    cout << "| " << left << setw(19) << "Nama Produk" << "| " << setw(10) << "Harga" << " |" << endl;
    cout << "-----------------------------------" << endl;
    while (current != nullptr) {
        cout << "| " << left << setw(19) << current->namaProduk << "| " << setw(10) << current->harga << " |" << endl;
        cout << "-----------------------------------" << endl; // Tambahkan garis ini
        current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.push_back("Originote", 60000);
    list.push_back("Somethinc", 150000);
    list.push_back("Skintific", 100000);
    list.push_back("Wardah", 50000);
    list.push_back("Hanasui", 30000);
    list.display();


    cout << "\nToko Perawatan Kulit Purwokerto\n" << endl;
    while (true) {
        cout << "\n1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Perbarui data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus semua data" << endl;
        cout << "7. Tampilkan data" << endl;
        cout << "8. Keluar\n" << endl;
        int choice;
        cout << "Masukkan pilihan Anda    : ";
        cin >> choice;
        switch (choice) {
        case 1: {
            string namaProduk;
            double harga;
            cout << "Masukkan nama produk     : ";
            cin >> namaProduk;
            cout << "Masukkan harga           : ";
            cin >> harga;
            list.push_back(namaProduk, harga);
            break;
        }
        case 2: {
            list.pop();
            break;
        }
        case 3: {
            string oldNamaProduk, newNamaProduk;
            double newHarga;
            cout << "Masukkan nama produk lama: ";
            cin >> oldNamaProduk;
            cout << "Masukkan nama produk baru: ";
            cin >> newNamaProduk;
            cout << "Masukkan harga baru      : ";
            cin >> newHarga;
            bool updated = list.update(oldNamaProduk, newNamaProduk, newHarga);
            if (!updated) {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 4: {
            // Tambahkan implementasi untuk "Tambah Data Urutan Tertentu" di sini
            string namaProduk;
            double harga;
            int pos;
            cout << "Masukkan posisi          : ";
            cin >> pos;
            cout << "Masukkan nama produk     : ";
            cin >> namaProduk;
            cout << "Masukkan harga           : ";
            cin >> harga;
            list.insertAt(pos, namaProduk, harga);
            break;
        }
        case 5: {
            // Tambahkan implementasi untuk "Hapus Data Urutan Tertentu" di sini
            int pos;
            cout << "Masukkan posisi          : ";
            cin >> pos;
            list.deleteAt(pos);
            break;
        }
        case 6: {
            list.deleteAll();
            break;
        }
        case 7: {
            list.display();
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    }
    return 0;
}
