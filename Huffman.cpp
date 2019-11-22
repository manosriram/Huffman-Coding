#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <map>
#include <functional>
#include "HuffStruct.hpp"
using namespace std;
int total;
string path = "";
vector<string> v;
#include "Encode.hpp"
#include "Decode.hpp"

int main() {

    priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q;
    map<char, pair<int, string> > mp;
    fstream newFile;
    newFile.open("in.txt", ios::in | ios::out);

    if (newFile.is_open()) {
        string tp;
        while (getline(newFile, tp)) {
            int n = tp.end() - tp.begin();
            txt += tp;
            for (int t=0;t<n;t++) {
                ++mp[tp[t]].first;
                ++total;
            }
        }
    }
    cout << "Total Letters: " << total << endl;

    auto pr = Encode(mp, q);
    string decoded = Decode(pr.first, pr.second);
    cout << decoded << endl;
}
