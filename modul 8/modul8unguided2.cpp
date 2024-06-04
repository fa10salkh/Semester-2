#include <iostream>
#include <string>

using namespace std;

int main (){
    string kalimat;
    cout << "\t Program Sequental Search Menghitung Jumlah Huruf Vokal\n" << endl;
    cout << "Masukkan kalimat : ";

    getline(cin, kalimat);

    char vokal[5] = {'a', 'i', 'u', 'e', 'o'};
    int jumlahVokal = 0;

    for (int i = 0; i < kalimat.length(); i++){
        char huruf = tolower(kalimat[i]);
        for (int j = 0; j < 5; j++){
            if( huruf == vokal[j]){
                jumlahVokal++;
                break;
            }
        }
    }


    cout << "Kalimat : " << kalimat << endl;
    cout << "\nJumlah huruf vokal dalam kalimat adalah : " << jumlahVokal << endl;

    return 0;
}