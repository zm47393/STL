#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

class Druzyna {
public:
    string nazwa;
    int wygrane;
    int remisy;
    int przegrane;
    int bramki;
    int stracone_bramki;

    Druzyna(string n, int w, int r, int p, int b, int s): 
        nazwa(n), wygrane(w),remisy(r),przegrane(p),bramki(b),stracone_bramki(s) {}

    int counter() const{
        return remisy + wygrane * 3;
    }

    friend ostream& operator<<(ostream& os, const Druzyna& d) {
        os << d.nazwa << " - " << d.wygrane <<"\033[32m"<< "W \t" << "\033[0m" << d.remisy << "R \t" << d.przegrane << "\033[31m" << "P \t" << "\033[0m" << d.bramki <<"\033[32m"<< "B\t" << "\033[0m" << d.stracone_bramki<< "\033[31m"<<"S \n"<< "\033[0m";
        return os;
    }

    bool operator<(const Druzyna& a) const {
        if (counter() != a.counter()) return counter() > a.counter();
        if (wygrane != a.wygrane) return wygrane > a.wygrane;
        if (przegrane != a.przegrane) return przegrane < a.przegrane;
        if (bramki != a.bramki) return bramki > a.bramki;
        return stracone_bramki < a.stracone_bramki;
    }

};



int main()
{
    vector<Druzyna> liga = {
        Druzyna("TEAM1",9, 3, 1, 7, 10),
        Druzyna("TEAM2",6, 2, 7, 1, 4),
        Druzyna("TEAM3",8, 2, 10, 6, 4),
        Druzyna("TEAM4",7, 2, 10, 9, 7),
        Druzyna("TEAM5",1, 4, 7, 6, 10),
        Druzyna("TEAM6",2, 9, 1, 10, 8),
        Druzyna("TEAM7",3, 7, 9, 6, 10),
        Druzyna("TEAM8",5, 10, 3, 9, 1),
        Druzyna("TEAM9",9, 10, 5, 8, 2),
        Druzyna("TEAM10",7, 8, 6, 1, 4),
    };
    sort(liga.begin(), liga.end());
    for (auto Druzyna : liga) {
        cout << Druzyna;
    }
}

