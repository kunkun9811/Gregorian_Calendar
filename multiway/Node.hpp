#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <array>

using namespace std;

class Node {
    public:
        bool word = false;  // Node's "word" label
        Node* children[26]; // children[0] corresponds to 'a', children[1] to 'b', etc.
        Node();             // Node constructor
};

Node::Node(void) {
    for(int i = 0; i < 26; ++i) {
        children[i] = NULL;
    }
}

#endif