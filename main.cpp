#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Question {
    string jautajums;
    vector<string> atbildes;
    vector<int> pareizasatbildes;
};

int main() {
    // Izveidojiet jautājumu sarakstu
    vector<Question> jautajumi = {
        {
           "Kāda ir C++ funkcija, lai iegūtu maksimālo vērtību?",
            {"max()", "maxval()", "maximum()", "fmax()"},
            {0, 3}
        },
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
        cout << "Izvēlieties atbildi (ievadiet atbilžu numuru):" << "\n";
}
}