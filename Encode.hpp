#ifndef ENC
#define ENC
#include <iostream>
#include "HuffStruct.hpp"
#include <map>
#include <bitset>
#include <vector>
#include "BuildTree.hpp"
fstream file;
unsigned char acc;
int bitcount;
using namespace std;
string txt;
void search(char c, MinHeap *root) {
    if (!root)
        return;

    if (root->isLeaf && c == root->character) {
        cout << "Found " << c << ", has frequency " << root->freq << endl;
        v.push_back(path);
        return;
    }

    path.push_back('0');
    search(c, root->left);
    path.pop_back();
    path.push_back('1');
    search(c, root->right);
    path.pop_back();
}

unsigned char ch;
int bitC = 0;
void writeBit(int bit) {
    ch = (ch << 1) | bit;
    if (++bitC == 8) {
        int sz = 8; 
        file << ch;
        ch = 0;
        bitC = 0;
    }
}
MinHeap *Encode(map<char, pair<int, string> > mp,
        priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q, MinHeap *root) {
    file.open("out.txt", ios::out | ios::binary);
    for (auto t = mp.begin(); t!=mp.end();++t) {
        search(t->first, root);
        t->second.second = v[0];
        v.clear();
    }

    for (int t=0;t<txt.length();t++) {
        int n = mp[txt[t]].second.end() - mp[txt[t]].second.begin();
        for (int t1=0;t1<mp[txt[t]].second.length();t1++) {
            char temp = mp[txt[t]].second[t1];

            if (temp == '1')
                writeBit(1);
            else
                writeBit(0);
        }
    }
    file.close();
    cout << endl;
    return root;
}
#endif
