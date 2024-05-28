#include <iostream>
#include <iomanip>

using namespace std;

class Node 
{
public:
    string nama;
    string nim;
    Node* next;

    Node (string nama, string nim)
    {
        this->nama = nama;
        this->nim = nim;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int capacity;

public:
    Queue (int capacity){
        this->capacity = capacity;
        front = nullptr;
        rear = nullptr;
    }

void enqueue (string nama, string nim) {
    if (isFull()){
        cout << "Antrian penuh. Tidak dapat menambahkan lebih banyak elemen." << endl;
        return;
    }
    Node* newNode = new Node (nama, nim);
    if (isEmpty()){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
  }

void dequeue(){
    if (isEmpty()){
        cout << "Antrian kosong. Tidak dapat menghapus elemen." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    string namaYangDihapus = temp->nama;
    delete temp;
    cout << "Data di depan yaitu (" << namaYangDihapus << ") telah dihapus." << endl;
}
    string peek(){
        if (isEmpty()){
            cout << "Antrian kosong. Tidak dapat melihat elemen." << endl;
            return"";
        }
        return front->nama + " (" + front->nim + ") ";
    }

    bool isEmpty(){
        return front == nullptr;
    }

    bool isFull(){
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return  count == capacity;
    }

    int size(){
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void viewQueue (){
        cout << "Data antrian" << endl;
        cout << setfill('=') << setw(57) << "=" << setfill (' ') << endl;
        cout << "| " << setw(2) << left << "NO" << " | " << setw(15) << left << "Nama" << " | " << setw(30) << left << "NIM" << " |" << endl;
        cout << setfill ('=') << setw(57) << "=" << setfill (' ') << endl;
        Node* current = front;
        int no = 1;
        while (current != nullptr) {
            cout << "| " << setw(2) << left << no << " | " << setw(15) << left << current->nama << " | " << setw(30) << left << current->nim << " |" << endl;
            current = current->next;
            no++;
        }
        cout << setfill('=') << setw(57) << "=" << setfill(' ') << endl;
    }
};

int main() {
    Queue queue (5);
    int pilihan;
    string nama, nim;

    do {
        cout << "\nMenu Operasi Antrian:\n";
        cout << setfill ('=') << setw (39) << "=" << setfill (' ') << endl;
        cout << "| " << setw (2) << left << "1" << " | " << "Tambahkan data" << "                 |\n";
        cout << "| " << setw (2) << left << "2" << " | " << "Hapus data" << "                     |\n";
        cout << "| " << setw (2) << left << "3" << " | " << "Melihat data antrian di depan" << "  |\n";
        cout << "| " << setw (2) << left << "4" << " | " << "Jumlah elemen antrian" << "          |\n";
        cout << "| " << setw (2) << left << "5" << " | " << "Melihat seluruh antrian" << "        |\n";
        cout << "| " << setw (2) << left << "6" << " | " << "Keluar" << "                         |\n";
        cout << setfill ('=') << setw (39) << "=" << setfill (' ') << endl;
        cout << "Pilih menu dari 1 sampai 6: ";
        cin >> pilihan;
        cout << "\n";

        switch (pilihan){
            case 1:
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan NIM  : ";
                cin >> nim;
                queue.enqueue(nama, nim);
                break;
            case 2:
                queue.dequeue();
                cout << "Data di depan telah dihapus." << endl;
                break;
            case 3:
                cout << "Data di depan: " << queue.peek() << endl;
                break;
            case 4:
                cout << "Jumlah data dalam antrian : " << queue.size() << endl;
                break;
            case 5:
                queue.viewQueue();
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    } while (pilihan != 6);

    return 0;
}