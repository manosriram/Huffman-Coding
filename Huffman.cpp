#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    fstream newFile;
    map<char, int> mp;
    int total = 0;
    newFile.open("in.txt", ios::in);

    if (newFile.is_open()) {
        string tp;
        while (getline(newFile, tp)) {
            int n = tp.end() - tp.begin();
            for (int t=0;t<n;t++) {
                ++mp[tp[t]];
                ++total;
            }
        }
        newFile.close();
    }

    cout << "Total Letters: " << total << endl;

    for (auto t=mp.begin();t!=mp.end();t++) {
        cout << "Character: " << t->first << "\tOccurences: " << t->second << "\tFrequency: " << (double)t->second/total * 100 << endl;
    }
}
