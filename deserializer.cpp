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

bool query(trie* head, string &s){ //Iteratively search the trie for the string s
    trie* cur = head;
	for(auto &b:s){
		if(!cur->bit[b]){ //if the wanted character is not found at any point found variable is turned to false
            return false;
        }
		cur = cur->bit[b];
	}

    return cur->pre=="+";
}


trie* deserialize(string data) { //takes the string object and deserializes it with the help of a stack
        if (data.size() == 0)
            return nullptr;
        trie *root = new trie();
        trie *p = root;
        stack<trie *> st;
        int dataSize = data.size();
        for (int i = 0; i < dataSize; i++) {
            if(data[i] == '+') continue;
            if(data[i] == '<'){ //if a new node begins, it is pushed to the top of the stack
                    st.push(p);      
            }        
            else if(data[i] == '>'){ //implies all the children of the top of the stack are done with
                    st.pop();
            }         
            else{ //as soon as a character is found, it is assigned its frequency and made a children of the node on top of the stack
                    p = new trie();
                    st.top()->bit[data[i]] = p;
                    if(data[i-1] == '+'){
                        p->pre = "+";
                    }
            }
        }

        return root;
    } 

int  main(int argc, char **argv){ // the main function takes two arguments from the command line.

    string serialized_input = argv[1]; //  1 -> the file containing serialized string
    string queries = argv[2]; // 2 -> the file containing the queries of words to be found
    fstream file;
    trie* head = new trie();
    file.open(serialized_input,ios::in); //serialized string opened and deserialized
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            head = deserialize(line);
        }
        file.close();
    }
    file.open(queries,ios::in); //answer to each query printed on the console
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            bool val = query(head,line);
            cout<<line<<": ";
            if(!val) cout<<"No\n"; else cout<<"Yes\n";
        }
        file.close();
    }
    return 0;
}