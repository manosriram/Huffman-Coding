#ifndef HUFF_SCT
#define HUFF_SCT
#include <iostream>
using namespace std;

struct MinHeap {
    double freq;
    char character;
    MinHeap *left, *right;
    bool isLeaf;
};
#endif
