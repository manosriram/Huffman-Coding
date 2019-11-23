#ifndef ENC
#define ENC
#include <iostream>
#include "HuffStruct.hpp"
#include <map>
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

int reverseByte(int num) {
    unsigned int rev = 0;
    while (num) {
        rev <<= 1;
        if (num & 1)
            rev ^= 1;

        num >>= 1;
    }
    return rev;
}

void writeByte(int byte) {
    //byte = reverseByte(byte);
    int n = sizeof(int);
    while (byte) {
        file << (byte & 1);
        byte >>= 1;
        n--;
    }
    while (n > 0) {
        file << 0;
        n--;
    }
    return;
}


void writeBit(int bit) {
    ch = (ch << 1) | bit;
    //cout << "Ch: " << (int)ch << endl;
    if (++bitC == 8) {
        int sz = 8; 
        while (ch) {
            file << (ch & 1);
            ch >>= 1;
            sz--;
        }
        while (sz--) {
            file << 0;
        }
        bitC = 0;
        ch = 0;
    }
}
MinHeap *Encode(map<char, pair<int, string> > mp,
        priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q, MinHeap *root) {
    file.open("out.txt", ios::out);
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
            // cout << temp;
        }
    }
    file.close();
    return root;
}
#endif
