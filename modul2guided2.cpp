#include <iostream>
using namespace std;
int main(){
    int maks, a, i=1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a]; 
    cout << "Masukkan " << a << " angka\n";
    for (i=0; i < a; i++){ // i=0, i yang memulai
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }    
    maks = array[0];
    for (i = 0; i < a; i++){
        if (array[i] > maks){
            maks = array[i]; //maks = array yang dimasukkan tadi
            lokasi = i; // lokasi di i
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}