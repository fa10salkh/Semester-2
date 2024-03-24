#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "\n                      |==| Program Array |==|\n        " << endl;
    int x, y, z;
    cout << "Masukkan ukuran dimensi x: ";
    cin >> x;
    cout << "Masukkan ukuran dimensi y: ";
    cin >> y;
    cout << "Masukkan ukuran dimensi z: ";
    cin >> z;
    cout << endl;
    int arr[x][y][z]; // Membuat array tiga dimensi

    // Input elemen
    cout << "                          | Input Array |  \n   " << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }
    


    // Output Array
    cout << " \n                        | Data Array |   \n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    cout << endl;
 // Tampilan array
 for (int x = 0; x < 2; x++){ 
     
    for (int y = 0; y < 3; y++){
        cout << "|";
        for (int z = 0; z < 3; z++)
        {
            cout << setw(3) << arr[x][y][z] << " ";
        }cout << "|";
      cout << endl;
      }
    cout << endl;
}


    return 0;
}