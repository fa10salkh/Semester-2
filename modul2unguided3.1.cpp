#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n); 
    cout << "Masukkan elemen array (pisah dengan spasi): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pilihan;
    cout << "Pilih operasi :\n";
    cout << "1. Nilai Maksimum\n";
    cout << "2. Nilai Minimum\n";
    cout << "3. Nilai Rata-rata\n";
    cout << "\nMasukkan pilihan Anda: ";
    cin >> pilihan;

    switch(pilihan) {
        case 1: {
            
            int max_val = *max_element(arr.begin(), arr.end());
            cout << "Nilai Maksimum: " << max_val << "\n";
            break;
        }
        case 2: {
            
            int min_val = *min_element(arr.begin(), arr.end());
            cout << "Nilai Minimum: " << min_val << "\n";
            break;
        }
        case 3: {
            
            double avg_val = accumulate(arr.begin(), arr.end(), 0.0) / n;
            cout << "Nilai Rata-rata: " << avg_val << "\n";
            break;
        }
        default: {
            cout << "Pilihan tidak valid.\n";
            break;
        }
    }

    return 0;
}