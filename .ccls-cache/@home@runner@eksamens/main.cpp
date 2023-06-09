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
      {"Kāda ir C++ funkcija, lai iegūtu maksimālo vērtību?",
       {"max()", "maxval()", "maximum()", "fmax()"},
       {0, 3}},
      {

      },
      // Citi jautājumu, pagaidam neizdomāja
  };

  // Izveidojiet rezultātu mainīgos
  int pareizasAtbildes = 0;
  vector<int> nepareizasAtbildes;

  // Iziet cauri katram jautājumam
  for (int i = 0; i < jautajumi.size(); i++) {
    cout << "Jautājums " << (i + 1) << ": " << jautajumi[i].jautajums << "\n";
    cout << "Izvēlieties atbildi (ievadiet atbilžu numuru):"
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
  }
}