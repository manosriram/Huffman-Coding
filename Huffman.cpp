#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <functional>
using namespace std;

struct MinHeap {
    double freq;
    char character;
    MinHeap *left, *right; 
    bool isLeaf;
};

void printHeap(MinHeap *heap) {
    cout << "Character: " << heap->character << " Frequency: " << heap->freq << endl;
}
string path = "";
void search(char c, MinHeap *root) {
    if (!root)
        return;

    if (root->isLeaf && c == root->character) {
         cout << "Found " << c << ", has frequency " << root->freq << endl;
        cout << path;
        return;
    }
    
    path.push_back('0'); 
    search(c, root->left);
    path.pop_back();
    path.push_back('1');
    search(c, root->right);
    path.pop_back();
}

void Traverse(MinHeap *root) {
    if (!root)
        return;

    if (root->isLeaf)
        cout << root->character << " " << root->freq << endl;

    Traverse(root->left);
    Traverse(root->right);
}

int main() {
    priority_queue<pair< double, MinHeap *>, vector<pair<double, MinHeap *> >, greater<pair< double, MinHeap *>> > q;
    fstream newFile;
    map<char, int> mp;
    int total = 0;
    newFile.open("in.txt", ios::in);

    if (newFile.is_open()) {
        string tp;
        while (getline(newFile, tp)) {
            int n = tp.end() - tp.begin();
            for (int t=0;t<n;t++) {
                ++mp[tp[t]];
                ++total;
            }
        }
        newFile.close();
    }

    cout << "Total Letters: " << total << endl;

    for (auto t=mp.begin();t!=mp.end();t++) {
        MinHeap *hp = new MinHeap();
        hp->freq = (double)t->second/total * 100;
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
        q.push(make_pair(hp->freq, hp));
    }
    MinHeap *root = q.top().second;
    q.pop();
    search('c', root);
 //   Traverse(root);
}
