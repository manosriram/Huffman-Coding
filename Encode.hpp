#ifndef ENC
#define ENC
#include <iostream>
#include "HuffStruct.hpp"
#include <map>
#include <vector>
#include "BuildTree.hpp"
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

string Encode(map<char, pair<int, string> > mp,
        priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q) {
    MinHeap *root = BuildTree(mp, q);
    for (auto t = mp.begin(); t!=mp.end();++t) {
        search(t->first, root);
        t->second.second = v[0];
        v.clear();
    }
    string temp;

    for (int t=0;t<txt.length();t++) {
        temp += mp[txt[t]].second;
    }
    return temp;
}
#endif
