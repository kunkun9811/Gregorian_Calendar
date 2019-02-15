#include <iostream>

#include "MultiwayTrie.hpp"
#include "Node.hpp"

using namespace std;

int main() {
    MultiwayTrie number1;
    MultiwayTrie number2;

    number1.insert("hello");
    number1.insert("jasmine");
    number1.insert("timothy");
    number1.insert("");
    
    // for(int i = 0; i < 26; i++){
    //     // cout << (((number1.root->children)['h' - 97])->children)[i] << endl;
    //     cout << (number1.root->children)[i] << endl;
    // }
    
    cout << number1.find("hello") << endl;
    cout << number1.find("jasmine") << endl;
    cout << number1.find("timothy") << endl;
    cout << number1.find("timo") << endl;
    cout << number1.find("jasmin") << endl;
    cout << number1.find("hihiheakjdsf") << endl;
    
    cout << number1.find("") << endl;

    return 0;
}








































    // string word = "hello";
    // int j = 0;
    // Node* currNode = number1.root;

    // while(j < word.size()){
    //     cout << j + 1 << word.at(j)<< endl;
    //     if( (currNode->children)[ int(word.at(j)) - 97] == NULL ){
    //         (currNode->children)[ int(word.at(j)) - 97] = new Node();
    //     }
        
    //     currNode = (currNode->children)[ int(word.at(j)) - 97 ];
    //     j++;
    // }
    
    // if( (number1.root->children)[ int('h') - 97] == NULL ){
    //     cout << "it is null" << endl;
    // }
    
    // cout << endl << endl << (number1.root->children)[ int('h') - 97] << endl;
    // cout << (number1.root->children)[int('h') - 97] << endl << endl << endl;
    
    // for(int i = 0; i < 26; i++){
    //     cout << (((number1.root->children)['h' - 97])->children)[i] << endl;
    // }