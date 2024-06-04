#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "\t Program Sequental Search Sederhana\n" << endl;
    cout << "Masukkan jumlah angka : ";
    cin >> n;

    int data[n];
    cout << "Masukkan angka (dengan spasi): ";
    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    int cari;
    cout << "Masukkan angka yang dicari : ";
    cin >> cari;

    int jumlah = 0;

    for (int i = 0; i < n; i++){
        if(data[i] == cari){
            jumlah++;
        }
    }

    cout << "Data : {";
    for (int i = 0; i < n; i++){
        cout << data[i];
        if (i < n - 1){
            cout << ", ";
        } 
    }
    cout << "}" << endl;

    if (jumlah > 0){
        cout << "\nAngka " << cari << " ditemukan sebanyak " << jumlah << " kali" << endl;
    } else {
        cout << "\nAngka " << cari << " tidak ditemukan " << endl;
    }
    return 0;
}