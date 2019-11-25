#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#include <queue>
#include <map>
#include <functional>
#include "unordered_map"
#include "HuffStruct.hpp"
using namespace std;

int total;
string path = "";
int needed;
vector<string> v;
vector<string> store;
map<int, int> pr;

#include "Encode.hpp"
#include "Decode.hpp"
#include "BuildTree.hpp"

int main() {
    cout << fixed << showpoint;
    priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q;
    map<char, pair<int, string> > mp;
    fstream newFile;

    newFile.open("in.txt", ios::in | ios::out);
    char ch;
    int lvl = -1;
    if (newFile.is_open()) {
        string tp;
        while (getline(newFile, tp)) {
            ++lvl;
            pr[lvl] = 0;
            int n = tp.end() - tp.begin();
            for (int t=0;t<n;t++) {
                ++mp[tp[t]].first;
                ++total;
                ++pr[lvl];
            }
            store.push_back(tp);
        }
    }

    for (auto t = pr.begin(); t != pr.end(); t++)
        cout << t->first << " " << t->second << endl;

    file.close();
    auto root = BuildTree(mp, q);
    root = Encode(mp, q, root);
    Decode(root);

    FILE *fp = fopen("out.txt", "r");
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fclose(fp);

    cout << "Input File Size: " << total << " Bytes." << '\n';;
    cout << "Output File Size: " << sz << " Bytes." << '\n';
    cout << setprecision(5);
    cout << "Compression Rate: " << (long double)((long double)sz/(long double) total)*100 << " %";
}
