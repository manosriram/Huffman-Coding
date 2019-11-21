#ifndef DEC
#define DEC
#include "HuffStruct.hpp"
bool taken = false; 
void Decode(string enc, MinHeap *root, int ind) {

    if (!root)
        return;

    if (!taken) {
        Node = root;
        taken = true;
    }

    if (root->isLeaf) {
        decoded.push_back(root->character);
        cout << decoded << endl;
        root = Node;
        return; 
    }

    if (enc[ind] == '0') {
        ++ind;
        Decode(enc, root->left, ind);
    } else if (enc[ind] == '1') {
        ++ind;
        Decode(enc, root->right, ind);
    }
    --ind;
}

#endif
