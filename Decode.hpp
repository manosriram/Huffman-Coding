#ifndef DEC
#define DEC
#include <sstream>
#include "HuffStruct.hpp"
#include <bitset>

void Decode(MinHeap *root) {
    MinHeap *Node = root;
    string str;
    fstream file;
    file.open("out.txt", ios::in | ios::binary );
    vector<string> decoded;
    while(getline(file, str)) {
        if (str.empty()) {
            decoded.push_back("");
            continue;
        }
        for (auto t : str) {
            int x = (int)t;

            if (x < 0)
                x += 256;

            decoded.push_back(bitset<8>(x).to_string());
        }
    };
    file.close();

    file.open("dec.txt", ios::in | ios::out | ios::trunc);
    int n = decoded.size();
    bool next = false;

    for (int t=0;t<n;t++) {
        string g = decoded[t];
        int tempN = g.end() - g.begin();
        if (tempN == 0) {
            next = true;
            continue;
        }
        for (int j=0;j<tempN;j++) {
            char tempCh = decoded[t][j];
            if (tempCh == '0')
                root = root->left;

            else
                root = root->right;

            if (root->isLeaf) {
                file << root->character;
                root = Node;
            }
        }
        if (next) {
            file << endl;
            next = false;
        }
    }
    file.close();
    return;
}
#endif
