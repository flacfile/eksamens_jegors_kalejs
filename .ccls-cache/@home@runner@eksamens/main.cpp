#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Question {
  string jautajums;
  vector<string> atbildes;
  vector<int> pareizasatbildes;
};

int main() {
  // Izveidojiet jautājumu sarakstu
  vector<Question> jautajumi = {
      {"Kāda ir C++ matemātiska funkcija, lai iegūtu maksimālo vērtību?",
       {"max()", "maxval()", "maximum()", "fmax()"},
       {0, 3}},
      {"Kādas no C++ matemātiskiem funkcijam, iespējams lietot bez <cmath> bibliotēkas?",
       {"cos()", "max()", "min()", "sin()"},
       {1, 2}},
      {"Kādas no C++ matemātiskiem funkcijam, noapaļo skaitļi?",
       {"round()", "ceil()", "min()", "floor()"},
       {0, 1, 3}},

};

  // Izveidojiet rezultātu mainīgos
  int pareizasAtbildes = 0;
  vector<int> nepareizasAtbildes;

  // Iziet cauri katram jautājumam
  for (int i = 0; i < jautajumi.size(); i++) {
    cout << "Jautājums " << (i + 1) << ": " << jautajumi[i].jautajums << "\n";
    cout << "Izvēlieties atbildi (ievadiet atbilžu numuru pa vienu skaitli):"
         << "\n";

    // Izvada atbilžu variantus
    for (int j = 0; j < jautajumi[i].atbildes.size(); j++) {
      cout << j + 1 << ". " << jautajumi[i].atbildes[j] << "\n";
    }
    
     // Iegūst lietotāja atbildi
        vector<int> lietotajaAtbildes;
        int lietotajaAtbilde;
        while (cin >> lietotajaAtbilde) {
            if (lietotajaAtbilde < 1 || lietotajaAtbilde > jautajumi[i].atbildes.size()) {
                cout << "Nederīga atbilde. Lūdzu, ievadiet atbilžu numuru: ";
            } else {
                lietotajaAtbildes.push_back(lietotajaAtbilde - 1);
                if (lietotajaAtbildes.size() == jautajumi[i].pareizasatbildes.size()) {
                    break;
            }
          }
        }

  // Pārbauda vai atbildes ir pareizas
        bool vaiPareizi = true;
        for (int atb : lietotajaAtbildes) {
            if (find(jautajumi[i].pareizasatbildes.begin(), jautajumi[i].pareizasatbildes.end(), atb) == jautajumi[i].pareizasatbildes.end()) {
                vaiPareizi = false;
                break;
            }
        }
// Palielina pareizo atbilžu skaitu un saglabā nepareizo jautājumu indeksu
        if (vaiPareizi) {
            pareizasAtbildes++;
        } else {
            nepareizasAtbildes.push_back(i);
        }

        cout << "\n";
    }

// Izvada rezultātus
     cout << "Pareizi atbildēti jautājumi: " << pareizasAtbildes << "/" << jautajumi.size() <<  "\n";
     cout << "Nepareizi atbildētie jautājumi:" <<  "\n";
    for (int index : nepareizasAtbildes) {
         cout << "- Jautājums " << (index + 1) << ": " << jautajumi[index].jautajums <<  "\n";
    }

    return 0;
}
    
  

