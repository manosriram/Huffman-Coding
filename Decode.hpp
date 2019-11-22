#ifndef DEC
#define DEC
#include "HuffStruct.hpp"
bool taken = false;
string Decode(string enc, MinHeap *root) {
    string decoded = "";
    MinHeap *Node = root;
    for (int t=0;t<enc.length();t++) {
        if (enc[t] == '0')
            root = root->left;
        else
            root = root->right;

        if (root->isLeaf) {
            decoded.push_back(root->character);
            root = Node;
        }
    }
    return decoded;
}

#endif
