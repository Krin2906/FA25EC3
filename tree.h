//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    Node(const string &nodeID, const U &value)
        : id(nodeID), data(value) {}
};

template <typename T>
class Tree {
public:
    // Basic constructor starting with no root.
    Tree() : rootNode(nullptr) {

    }

    //creates the root node. (should probably warn if it already exists).
    void createRoot(const string &rootID, const T &value) {
        if (rootNode != nullptr) {
            // maybe throw an exception instead here?
            return;
        }

        Node<T>* tempRoot = new Node<T>(rootID, value);

        // Storing the newly created node
        rootNode = tempRoot;
        nodesList.push_back(tempRoot);  // I might have to check for duplicates

    }


    void addNode(const string &parentID, const string &childID, const T &value);

    // Looking up a node by ID
    Node<T>* findNode(const string &searchID) {

        for (auto* currentNode : nodesList) {
            if (currentNode->id == searchID) {
                return currentNode;  // Found it!
            }
        }
        return nullptr; // If it's not there, shrug.
    }

    bool nodeExists(const string &nodeID) {
        return findNode(nodeID) != nullptr;
    }

    // Dump everything. Still need to implement properly.
    // Possibility of  making this const?
    void printAll();

    void playGame();

    ~Tree();

private:
    Node<T>* rootNode;
    vector<Node<T>*> nodesList;  // Keeping track of all nodes for now

    // Maybe add some utility functions later

};

#endif //FA25EC3_TREE_H
