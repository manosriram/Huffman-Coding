#ifndef ENC
#define ENC
#include <iostream>
#include "HuffStruct.hpp"
#include <map>
#include <bitset>
#include <vector>
#include "BuildTree.hpp"
using namespace std;
fstream file;
string txt;

void search(char c, MinHeap *root) {
    if (!root)
        return;

    if (root->isLeaf && c == root->character) {
        v.push_back(path);
        table[root->character] = path;
        return;
    }

    path.push_back('0');
    search(c, root->left);
    path.pop_back();
    path.push_back('1');
    search(c, root->right);
    path.pop_back();
}

unsigned char ch = 0;
int bitC = 0;
void writeBit(int bit) {
    ch = (ch << 1) | bit;
    if (++bitC == 8) {
        file << ch;
        ch = 0;
        bitC = 0;
    }
    return;
}

int calculatePadding(map<char, pair<int, string> > mp) {
    int bits = 0;
    for (int t=0;t<store.size();t++) {
        for (int j=0;j<store[t].length();j++) {
            bits += mp[store[t][j]].second.length();
        }
    }
    return bits;
}

MinHeap *Encode(map<char, pair<int, string> > mp,
        priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q, MinHeap *root) {

    file.open("compressed.txt", ios::in | ios::out | ios::trunc);

    for (auto t = mp.begin(); t!=mp.end();++t) {
        search(t->first, root);
        t->second.second = v[0];
        v.clear();
    }

    int eightBitLength = calculatePadding(mp);
    needed = ((eightBitLength + 8) - (eightBitLength % 8)) - eightBitLength;
    
    for (int t=0;t<store.size();t++) {
        if (store[t].empty()) {
            file << endl;
            continue;
        }
        for (int j=0;j<store[t].length();j++) {
            ++mm[t];
            char temp = store[t][j];
            for (int k=0;k<mp[temp].second.length();k++) {
                char chr = mp[temp].second[k];

                if (chr == '1')
                    writeBit(1);
                else
                    writeBit(0);
            }
        }
    }
    ch <<= needed;
    file << ch;
    file.close();

    file.open("table.txt", ios::out | ios::trunc);
    for (auto t = table.begin(); t != table.end();t++) {
        file << t->first << " " << t->second << endl;
    }
    file.close();
    return root;
}
#endif
