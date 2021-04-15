#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

class trie { //A trie node object
  public:
  trie() {} //NOTE - The trie is case sensitive, no word can contain commas or digits
        unordered_map<char,trie*> bit; //map to succeeding characters
        string pre = ""; //frequency of the word ending at that node
};
void insert(trie* head,string &s){ // iteratively the trie is traversed and word is inserted
	trie* cur = head;
	for(auto &b:s)
	{
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
	}
    cur->pre = "+";
}

string serialize(trie* root) { //serialized the trie recursively in a dfs manner

        if (!root) return "";

        string result;

        for (auto c : root->bit) {
            result = result + c.second->pre + c.first + serialize(c.second);
        }

        return "<" + result + ">";
    }

int  main(int argc, char **argv){ // the main function takes two arguments from the command line.
    string input = argv[1]; // 1. The dictionary file in txt format 
    string output = argv[2]; // 2. The file into which the serialized string is to be printed
    fstream file;
    file.open(input,ios::in);
    trie* head = new trie();
    if(file.is_open()){
        string word;
        while(getline(file,word)){
            insert(head,word); //inserting the word into trie
        }
        file.close();
    }
    string encoding = serialize(head); //serializing the trie
    file.open(output,ios::out);
    if(file.is_open()){
        file<<encoding; //storing the serialized trie into external file
        file.close();
    }
    return 0;
}