//Nash Steed _ ucq8hz _ Apr 17 2022 _ "heap.h"
#ifndef HEAP_H
#define HEAP_H
#include "huffnode.h"
#include <vector>
#include <unordered_map>
using namespace std;
class Heap {
public:
    Heap();         // Constructor
    //Heap(vector<HuffNode*> vec);
    ~Heap();
    void insert(HuffNode* h);
    HuffNode* deleteMin();
    HuffNode* findMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    void print2();
    void remove(int pos);
    vector<HuffNode*> heap;
	unsigned int heap_size;
	void percolateUp(int hole);
    void percolateDown(int hole);
    void printHuffman(HuffNode* node, string code);
    void printEncodedMessage(HuffNode* node, string code, char c1);
    int returnLengthOfPrefix(HuffNode* node, string code, char c1);
    int totalBitsCompressed;
private:
 	
};

#endif