#ifndef DEC
#define DEC
#include "HuffStruct.hpp"
bool taken = false;

string Decode(MinHeap *root) {

    file.open("out.txt", ios::in | ios::out); 
    
    if (file.is_open()) {
        string tp;
        while (getline(file, tp)) {
            for (int t=0;t<tp.length();t++)
                cout << (unsigned char)tp[t] << " ";
        }
    } 
    
    
    return "1213";
}
#endif
