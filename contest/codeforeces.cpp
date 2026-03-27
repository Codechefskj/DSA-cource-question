#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
vector<TrieNode*> temp = vector<TrieNode*>(26, nullptr);
bool flag = false ;
};

class Trie{
    TrieNode* root ; 
    public : 
    Trie(){
        root = new TrieNode;
    }

    void insert(string word){
       TrieNode* node = root ; 
       for(int i = 0 ; i< word.size(); i++){
        if(node->temp[word[i]-'a']){
         node = node->temp[word[i]-'a'];
        }
        else{
            node->temp[word[i]-'a'] = new TrieNode;
            node = node->temp[word[i]-'a'];
        }
       }
       node->flag= true ; 
    }

    bool search(string word){
        TrieNode* node = root ; 
        for(int i = 0 ; i< word.size(); i++){
           if(node->temp[word[i]-'a'] != nullptr){
             node = node->temp[word[i]-'a'];
           }
           else{
            return false ;
           }
        }
        return node->flag;
    }

    void remove(string word){
    TrieNode* node = root;
    for(int i = 0; i < word.size(); i++){
        if(node->temp[word[i] - 'a'] != nullptr){
            node = node->temp[word[i] - 'a'];
        }
    }
    node->flag = false;
}

};


int main() {
Trie h ; 
h.insert("apple");
h.insert("hell");
h.insert("car");
h.insert("cars");
cout << h.search("carsss")<<endl;
cout << h.search("car")<<endl;
cout << h.search("apple")<<endl;
}