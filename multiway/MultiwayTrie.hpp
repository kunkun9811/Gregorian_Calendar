#ifndef MULTIWAYTRIE_HPP
#define MULTIWAYTRIE_HPP

#include <iostream>

#include "Node.hpp"

using namespace std;

class MultiwayTrie {
    public:
        Node* root = new Node();  // root node of Multiway Trie
        bool find(string word);   // "find" function of MultiwayTrie class
        void insert(string word); // "insert" function of MultiwayTrie class
        void remove(string word); // "remove" function of MultiwayTrie class
};


/* Return true if MultiwayTrie contains word, otherwise return false */
bool MultiwayTrie::find(string word) {
    /* YOUR CODE HERE */
    if(word.size() == 0){
        cout << "N/A" << endl;
        return false;
    }
    
    Node* prevNode = NULL;
    Node* currNode = root;
    int j = 0;                              // Keep track of the position of the string we are on 
    while(j < word.size()){
        if( (currNode->children)[ int(word.at(j)) - 97 ] == NULL ){
            return false;
        }
        prevNode = currNode;
        currNode = (currNode->children)[ int(word.at(j)) - 97 ];
        j++;
    }
    if((prevNode->word) == true){
        return true;
    }
    else {
        return false;
    }
}

/* Insert word into MultiwayTrie (return nothing) */
void MultiwayTrie::insert(string word) {
    if(word.size() == 0){
        cout << "N/A" << endl;
        return;
    }
    
    /* YOUR CODE HERE */
    Node* prevNode = NULL;
    Node* currNode = root;
    int j = 0;                              // Keep track of the position of the string we are on 
    while(j < word.size()){
        if( (currNode->children)[ int(word.at(j)) - 97] == NULL ){
            (currNode->children)[ int(word.at(j)) - 97] = new Node();
        }
        prevNode = currNode;
        currNode = (currNode->children)[ int(word.at(j)) - 97 ];
        j++;
    }
    
    prevNode->word = true;
    return;
}

/* Remove word from MultiwayTrie (return nothing) */
void MultiwayTrie::remove(string word) {
    /* YOUR CODE HERE */
    Node* prevNode = NULL;
    Node* currNode = root;
    int j = 0;                              // Keep track of the position of the string we are on 
    while(j < word.size()){
        if( (currNode->children)[ int(word.at(j)) - 97 ] == NULL ){
            return;
        }
        prevNode = currNode;
        currNode = (currNode->children)[ int(word.at(j)) - 97 ];
        j++;
    }
    prevNode->word = false;
}

#endif