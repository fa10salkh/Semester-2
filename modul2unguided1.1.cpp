#include <iostream>
using namespace std;

int main() {
    cout << "\n|| Program Menentukan Nomor Genap dan Nomor Ganjil ||\n" << endl;
    int n;
    cout << "Masukkan panjang array : ";
    cin >> n;
    int arr[n];
    int genap[n], ganjil[n];
    int nmr_genap = 0, nmr_ganjil = 0;

    cout << "Masukkan " << n << " angka\n";
    for (int i = 0; i < n; i++) {
        cout << "Array ke- " << i << ": ";
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            genap[nmr_genap] = arr[i];
            nmr_genap++;
        } else {
            ganjil[nmr_ganjil] = arr[i];
            nmr_ganjil++;
        }
    }

    cout << "\nData Array   : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNomor Genap  : ";
    for (int i = 0; i < nmr_genap; i++) {
        cout << genap[i] << " ";
    }

    cout << "\nNomor Ganjil : ";
    for (int i = 0; i < nmr_ganjil; i++) {
        cout << ganjil[i] << " ";
    }

    return 0;
}