//Nash Steed _ ucq8hz _ Apr 17 2022 _ "huffmanenc.cpp"
#include <iostream>
#include "heap.h"
#include "huffnode.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib> 
using namespace std;
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    Heap h;
    char g;
    string s;
    unordered_map<char,int> map;
    while (file.get(g)) {
    	if(g<0x20 || g>0x7e){
    		continue;
    	}
    	s+=g;
    	if(map.find(g)!=map.end()){
    		map[g]=map[g]+1;
    	}
    	else{
    		map[g]=1;
    	}
    }
    unordered_map<char,int>::iterator iter;
    for(iter=map.begin();iter!=map.end();iter++){
    	//cout << iter->first << endl;
    	HuffNode* node = new HuffNode(iter->first,iter->second);
    	h.insert(node);
    }
    int uniqueSymbols = h.heap_size;
    
    while(h.heap_size!=1){
    	HuffNode* a = h.deleteMin();
    	int af = a->f;
    	HuffNode* b = h.deleteMin();
    	int bf = b->f;
    	HuffNode* parent = new HuffNode();
    	parent->f=af+bf;
    	parent->left=a;
    	parent->right=b;
    	h.insert(parent);
    }
    //print the Huffman codes
    h.printHuffman(h.heap[1],"");
    cout<< "----------------------------------------" << endl;
    //print the encoded message
    for(int i=0;i<s.length();i++){
    	char c2 = s.at(i);
    	h.printEncodedMessage(h.heap[1],"",c2);
    }
    cout << endl;
    cout<< "----------------------------------------" << endl;
    //print the total
    cout << "There are a total of " << s.length() << " symbols that are encoded."<< endl;
    //print the number of unique symbols
    cout << "There are " << uniqueSymbols << " distinct symbols used."<< endl;
    //print the original number of bits
    cout << "There were "<< s.length()*8 << " bits in the original file."<< endl;
    //print the new number of bits
    cout << "There were " << h.totalBitsCompressed << " bits in the compressed file."<< endl;
    double totalBits = 1.0*s.length()*8;
    double ratio = totalBits / h.totalBitsCompressed;
    cout << "This gives a compression ratio of " << fixed << setprecision(5) << ratio << "."<< endl;
    double cost = (1.0*h.totalBitsCompressed)/s.length();
    cout << "The cost of the Huffman tree is " << fixed << setprecision(5) << cost << " bits per character."<< endl;
    return 0;
}
	
