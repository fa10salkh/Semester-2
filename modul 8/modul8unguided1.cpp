#include <iostream>
#include <vector>
#include <string>

using namespace std;

string data;
char cari;

void selection_sort() 
{
    int i, j, min;
    char temp;
    for (i = 0; i < data.length(); i++)
    {
        min = i;
        for (j = i + 1; j < data.length(); j++)
        {
            if (data[j] < data[min]) 
            {
                  min = j;
            }
    }
    temp = data[i];
    data[i] = data[min];
    data[min] = temp;
    }
}

void binarysearch(){
    vector<int> foundIndices;
    for(int i = 0; i < data.length(); i++){
        if(data[i] == cari){
            foundIndices.push_back(i);
        }
    }
    if(!foundIndices.empty()){
        cout << "\nHuruf ditemukan pada indeks ke- ";
        for(int i = 0; i < foundIndices.size(); i++){
            cout << foundIndices[i]-1 << ", ";
        }
        cout << "\b\b";
    }
    else {
        cout << "\n Data tidak ditemukan\n ";
    }
}
int main(){
    cout << "\t Binary Search Mencari Huruf dari Kalimat " << endl;
    cout << "\n Masukkan kalimat : ";
    getline(cin, data);
    cout << "\n Masukkan huruf yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Kalimat diurutkan : ";
    selection_sort();
    cout << data << endl;
    binarysearch();
    return 0;
}

