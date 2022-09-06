//Nash Steed _ ucq8hz _ Apr 17 2022 _ "huffnode.cpp"
#include "huffnode.h"
#include <iostream>
#include <string>
using namespace std;

HuffNode::HuffNode(){
	c = '?';
	f=0;
	right = NULL;
	left = NULL;
}
HuffNode::HuffNode(string c1){
	c=c1;
	f=1;
	right=NULL;
	left=NULL;
}
HuffNode::HuffNode(string c1, int freq){
	c=c1;
	f=freq;
	right=NULL;
	left=NULL;
}