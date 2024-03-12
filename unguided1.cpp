#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

double penjumlahan (double a, double b)
{
    double jumlah = a + b;
    return jumlah;
}

double pengurangan (double a, double b)
{
    double kurang = a - b;
    return kurang;
}

double perkalian (double a, double b)
{
    double kali = a * b;
    return kali;
}
double pembagian (double a, double b)
{
    double bagi = a / b;
    return bagi;
}



int main()
{
    int pilihan;
    double a, b;
 cout << "|Program Kalkulator Sederhana|\n" << endl;
 cout << "1. Penjumlahan" << endl;
 cout << "2. Pengurangan" << endl;
 cout << "3. Perkalian" << endl;
 cout << "4. Pembagian\n" << endl;

 cout << "Masukkan Pilihan : ";
 cin >> pilihan;
 switch (pilihan)
 {
 case 1:
    cout << "\n== Penjumlahan ==\n" << endl;
    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;
 cout << "Hasil penjumlahan : " << a << " + " << b << " = " <<  penjumlahan (a,b);
 break;
 case 2:
 cout << "\n== Pengurangan ==\n" << endl;
 cout << "Masukkan bilangan pertama : ";
 cin >> a;
 cout << "Masukkan bilangan kedua : ";
 cin >> b;
 cout << "Hasil pengurangan : " << a << " - " << b << " = " <<  pengurangan (a,b);
 break;
 case 3:
 cout << "\n== Perkalian ==\n" << endl;
 cout << "Masukkan bilangan pertama : ";
 cin >> a;
 cout << "Masukkan bilangan kedua : ";
 cin >> b;
 cout << "Hasil perkalian : " << a << " x " << b << " = " <<  perkalian (a,b);
 break;
 case 4:
 cout << "\n== Pembagian ==\n" << endl;
 cout << "Masukkan bilangan pertama : ";
 cin >> a;
 cout << "Masukkan bilangan kedua : ";
 cin >> b;
  cout << "Hasil pembagian : " << a << " ÷ " << b << " = " <<  pembagian (a,b);
 break;
 }
}