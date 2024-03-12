#include <iostream>
#include <map>

using namespace std;
int main() {
    // Membuat map dengan key berupa string dan value berupa int
    map<string, int> umur;

    // Menambahkan 10 pasangan key-value ke dalam map
    umur["Ali"] = 18;
    umur["Banu"] = 34;
    umur["Celine"] = 20;
    umur["Dodi"] = 24;
    umur["Edi"] = 45;
    umur["Farah"] = 25;
    umur["Gani"] = 27;
    umur["Hakan"] = 29;
    umur["Irma"] = 30;
    umur["Jaka"] = 31;

    // Menampilkan semua elemen map
    for(auto i = umur.begin(); i != umur.end(); i++) {
        
    cout << "Nama : " << i->first << ", Umur : " << i->second << endl;
    }

    return 0;
}