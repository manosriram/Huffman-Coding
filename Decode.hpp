#ifndef DEC
#define DEC
#include "HuffStruct.hpp"
#include <bitset>

void Decode(MinHeap *root) {

    file.open("out.txt", ios::in | ios::out | ios::binary);
    string dec1 = "";
    if (file.is_open()) {
        string tp;
        while (getline(file, tp)) {
            int n = tp.end() - tp.begin();
            for (int t=0;t<n;t++) {
                int x = (int)tp[t];
                if (x < 0)
                    x += 256;

                dec1 += bitset<8>(x).to_string();
            }
        }
        file.close();
    }

    MinHeap *Node = root;
    int n = dec1.end() - dec1.begin();
    string out = "";
    for (int t=0;t<n;t++) {
        if (dec1[t] == '0')
            root = root->left;
        else
            root = root->right;

        if (root->isLeaf) {
            out += root->character;
            root = Node;
        }
    }
    file.open("dec.txt",  ios::out | ios::binary);
    file << out;
    file.close();
}
#endif
