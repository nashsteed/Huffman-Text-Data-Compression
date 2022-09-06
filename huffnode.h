//Nash Steed _ ucq8hz _ Apr 17 2022 _ "huffnode.h"
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;
class HuffNode {
public:
    HuffNode();         // Constructor
    HuffNode(string c1);
    HuffNode(string c1, int freq);
    string c;      // character
    int f;      //frequency 
    HuffNode* right;     
    HuffNode* left; 
private:
    // List needs access to value, next, and previous
    friend class Heap;
};

#endif