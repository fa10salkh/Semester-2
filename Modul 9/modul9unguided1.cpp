#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int jumlah_simpul;
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlah_simpul;

    map<string, map<string, int>> busur;
    vector<string> simpul(jumlah_simpul);
    for(int i = 0; i < jumlah_simpul; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    cout << "Silahkan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlah_simpul; i++)
    {
        for (int j = 0; j < jumlah_simpul; ++j)
        {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            int bobot_Faisal_Khoiruddin_2311102046;
            cin >> bobot_Faisal_Khoiruddin_2311102046;
            busur[simpul[i]][simpul[j]] = bobot_Faisal_Khoiruddin_2311102046;
        }
    }

    cout << endl << setw(15) << " ";
    for (int i = 0; i < jumlah_simpul; ++i)
    {
        cout << setw(10) << simpul[i];
    }
    cout << endl;
    for(int i = 0; i < jumlah_simpul; ++i)
    {
        cout << setw(15) << simpul[i];
        for (int j = 0; j < jumlah_simpul; ++j)
        {
            cout << setw(9) << busur[simpul[i]][simpul[j]];
        }
        cout << endl;
    }
    return 0;
}