#ifndef BLD
#define BLD
#include "HuffStruct.hpp"
using namespace std;

MinHeap *BuildTree(map<char, pair<int, string> > mp,
        priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q) {

    for (auto t=mp.begin();t!=mp.end();t++) {
        MinHeap *hp = new MinHeap();
        hp->freq = (double)t->second.first/total * 100;
        hp->character = t->first;
        hp->isLeaf = true;
        q.push(make_pair(hp->freq, hp));
    }

    while (q.size() > 1) {
        MinHeap *hp = new MinHeap();

        MinHeap *tp1 = new MinHeap();
        tp1 = q.top().second;
        q.pop();

        MinHeap *tp2 = new MinHeap();
        tp2 = q.top().second;
        q.pop();

        hp->freq = tp1->freq + tp2->freq;
        hp->left = tp1;
        hp->right = tp2;
        hp->isLeaf = false;
        hp->character = '\n';

        q.push(make_pair(hp->freq, hp));
    }
    MinHeap *root = q.top().second;
    q.pop();

    return root;
}
#endif
