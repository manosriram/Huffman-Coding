#ifndef DEC
#define DEC
#include <sstream>
#include "HuffStruct.hpp"
#include <bitset>

int rest(int b) {
    int sz = 8;
    while (b) {
        b >>= 1;
        sz--;
    }
    return sz;
}
int rs;
void Decode(MinHeap *root) {
    map<int, bool> check;
    file.open("out.txt", ios::in | ios::out | ios::binary);
    string dec1 = "";
    int no = 0;
    vector<string> vs;
    if (file.is_open()) {
        string tp;
        while (getline(file, tp)) {
            int n = tp.end() - tp.begin();
            no += n;
            if (n == 0) {
                check[vs.size() - 1] = true;
            }

            for (int t=0;t<n;t++) {
                int x = (int)tp[t];
                if (x < 0)
                    x += 256;
                
                dec1 += bitset<8>(x).to_string();
                vs.push_back(dec1);
                dec1 = "";
            }
        }
        file.close();
    }

    file.open("dec.txt",  ios::out | ios::binary);
    MinHeap *Node = root;
    int n = dec1.end() - dec1.begin();
    string out = "";
    cout << vs.size() << endl;
    cout << no << endl;
    for (int t=0;t<vs.size();t++) {
        if (check[t]) {
            file << '\n' << '\n';
        }
        for (int l = 0;l < vs[t].length();l++) {
            if (vs[t][l] == '0')
                root = root->left;
            else
                root = root->right;

            if (root->isLeaf) {
                file << root->character;
                root = Node;
            }
        }
    }
    file.close();
    return;

    cout << n << " " << no << endl;
    for (int t=0;t<n;t++) {
        if (check[t])
            file << endl;
        if (dec1[t] == '0')
            root = root->left;
        else
            root = root->right;

        if (root->isLeaf) {
            file << root->character;
            root = Node;
        }
    }
    file.close();
}
#endif
