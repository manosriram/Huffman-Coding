#ifndef DEC
#define DEC
#include "HuffStruct.hpp"
bool taken = false;

string Decode(MinHeap *root) {

    file.open("out.txt", ios::in | ios::out | ios::binary); 
    string tp; 
    while(getline(file, tp)) {
        cout << tp;
    }
    return tp;
}
#endif
