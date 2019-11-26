#ifndef DEC
#define DEC
#include <sstream>
#include "HuffStruct.hpp"
#include <bitset>

void Decode(MinHeap *root) {
    MinHeap *Node = root;
    string str;
    fstream file;
    file.open("compressed.txt", ios::in | ios::binary );
    vector<string> decoded;

    while(getline(file, str)) {
        for (auto t : str) {
            int x = (int)t;

            if (x < 0)
                x += 256;

            decoded.push_back(bitset<8>(x).to_string());
        }
    };

    file.close();
    int sz = decoded.size() - 1;
    decoded[sz] = decoded[sz].substr(0, sz - needed + 1);

    file.open("decoded.txt", ios::in | ios::out | ios::trunc);
    int n = decoded.size() - 1;
    bool next = false;
    int currentChars = 0, line = 0;

    for (int t=0;t<n;t++) {
        string g = decoded[t];
        int tempN = g.end() - g.begin();

        for (int j=0;j<tempN;j++) {
            char tempCh = decoded[t][j];
            if (currentChars == mm[line]) {
                file << endl;
                currentChars = 0;
                ++line;
            }

            if (tempCh == '0')
                root = root->left;

            else
                root = root->right;

            if (root->isLeaf) {
                ++currentChars;
                file << root->character;
                root = Node;
            }
        }
    }
    file.close();
    return;
}
#endif
