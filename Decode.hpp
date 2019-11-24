#ifndef DEC
#define DEC
#include <sstream>
#include "HuffStruct.hpp"
#include <bitset>

void Decode(MinHeap *root) {
    //fstream fin("dec.txt", fstream::in | fstream::out | fstream::binary);
    //file.open("out.txt", ios::in | ios::out | ios::binary);
    MinHeap *Node = root;
    string str, decoded;
    file.open("out.txt", ios::out | ios::in | ios::binary);
    
    while(getline(file, str)) {
        for (auto t : str) {
           int x = (int)t;
            
            if (x < 0)
               x += 256;

            decoded += bitset<8>(x).to_string(); 
        }
    };
    file.close();

    file.open("dec.txt", ios::out | ios::in | ios::binary);
    int n = decoded.length() - needed;
    for (int t=0;t<n;t++) {
        char temp = decoded[t];

        if (temp == '0')
            root = root->left;
        else
            root = root->right;

        if (root->isLeaf) {
            file << root->character;
            root = Node;
        }
    }
    cout << endl;
    file.close();

    return;
}
#endif
