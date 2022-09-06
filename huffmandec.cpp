//Nash Steed _ ucq8hz _ Apr 19 2022 _ "huffmandec.cpp"
#include <iostream>
#include "heap.h"
#include "huffnode.h"
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib> 
using namespace std;
HuffNode* root1 = new HuffNode();
void makeTree(HuffNode* root, string code, string character){
	if(code.length()==1){
		HuffNode* node = new HuffNode(character, 1);
		if(code.at(0)=='0'){
			if(root->left==NULL)
			{root->left=node;}
		}
		else{
			if(root->right==NULL)
			{root->right=node;}
		}
	}
	else if(code.length()>1){
		if(code.at(0)=='0'){

			if(root->left==NULL){
				HuffNode* node = new HuffNode();
				root->left=node;
				makeTree(node, code.substr(1), character);
			}
		}
		else{
			if(root->right==NULL){
				HuffNode* node = new HuffNode();
				root->right=node;
				makeTree(node, code.substr(1), character);
			}
		}
	}
}
void TraverseTree(HuffNode* root, string code){
if(root!=NULL){
	if(root->c!="?"){
		//cout << root->c;
		//cout << endl;
		if(code.length()>1){
			TraverseTree(root1,code);
		}
	}
	if(code.length()>1){
		if(code.at(0)=='0'){
			TraverseTree(root->left, code.substr(1));
		}
		else if(code.at(0)=='1'){
			TraverseTree(root->right, code.substr(1));
		}
	}
}
}

// main(): we want to use parameters
int main (int argc, char** argv) {
	unordered_map<string,string> map;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        //do something with character code

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        map[prefix]=character;
    }
    
    unordered_map<string,string>::iterator iter;
    for(iter=map.begin();iter!=map.end();iter++){
    	makeTree(root1,iter->first,iter->second);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string

    //cout << "All the bits: " << allbits << endl;
    TraverseTree(root1, allbits);
    // close the file before exiting
    file.close();

    string s;
    for(int i=0;i<allbits.length();i++){
    	s+=allbits.at(i);
    	if(map.count(s)>0){
    		cout << map[s];
    		s="";
    	}
    }

    cout << endl;
    return 0;
}