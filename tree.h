//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

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


    void addNode(const string &parentID, const string &childID, const T &value) {
        // First, find the parent.
        Node<T>* parentNode = findNode(parentID);
        if (parentNode == nullptr) {
            // If the parent doesn't exist, there's not a lot to do.
            cout << "Warning: Parent node '" << parentID
                 << "' not found!" << endl;  // basic warning
            return;
        }

        // Check if the child already exists.
        Node<T>* childNode = findNode(childID);

        if (childNode == nullptr) {
            // Child doesn't exist yet, so make a new one.
            childNode = new Node<T>(childID, value);
            nodesList.push_back(childNode);
        } else {
            // Child already exists; assuming story text is consistent.
            // If it's not, I could do: childNode->data = value;
            // but I'm leaving it alone for now.
        }

        // Now link parent -> child, but avoid duplicates.
        // This loop could probably be optimized but whatever.
        for (auto* existingChild : parentNode->children) {
            if (existingChild->id == childID) {
                return; // Already linked, we're good.
            }
        }

        parentNode->children.push_back(childNode);

        // Debug output - commenting out for now.
        // cout << "Added " << childID << " as child of " << parentID << endl;
    }

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
    void printAll() {
        if (nodesList.empty()) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "===== Story Tree =====" << endl;

        // Just go through nodesList in the order nodes were added.
        for (auto* currentNode : nodesList) {

            if (currentNode == nullptr) {
                continue;  // shouldn't happen, but safety check
            }

            // Example format:
            // Node 1: You stand in a forest clearing
            cout << "Node " << currentNode->id << ": " << currentNode->data << endl;

            if (currentNode->children.empty()) {

                cout << "  Child -> (none)" << endl;
            } else {
                // Print each child like:
                //   Child -> 2
                for (auto* childNode : currentNode->children) {
                    if (childNode != nullptr) {
                        cout << "  Child -> " << childNode->id << endl;
                    }
                }
            }

            cout << endl;  // spacing between nodes
        }

        cout << "======================" << endl;
    }

    void playGame() {
        // Just checking
        if (rootNode == nullptr) {
            cout << "No story loaded yet. (Root seems to be null?)" << endl;
            return;
        }

        cout << "===== Begin Adventure =====" << endl << endl;

        Node<T>* currNode = rootNode;

        // Loop until we run out of story or the player hits a dead end.
        while (currNode != nullptr) {

            // Display whatever text this node holds
            cout << currNode->data << endl;

            // If there’s nothing beyond this point, that’s the end of the line.
            if (currNode->children.size() == 0) {
                cout << "No more paths from here." << endl;
                cout << "Your journey comes to an end." << endl << endl;
                cout << "===== Adventure Complete =====" << endl;
                break;
            }

            // Let the player see their options
            cout << "Pick what to do next:" << endl;

            for (int i = 0; i < static_cast<int>(currNode->children.size()); ++i) {
                // Show the text of each possible next step
                cout << "  " << (i + 1) << ". "
                     << currNode->children[i]->data
                     << endl;
            }

            // Grab user choice
            int picked = 0;
            cout << "Selection: ";
            cin >> picked;

            // Very low-effort validation — good enough for now
            if (!cin || picked < 1 || picked > (int)currNode->children.size()) {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "That doesn't look right. Try again?" << endl;
                continue;
            }

            // Advance to the chosen branch
            currNode = currNode->children[picked - 1];

            // Personal taste: a blank line after choices makes it easier on the eyes
            cout << endl;
        }


    }

    ~Tree() {
       // I can just run through the whole thing and delete 'em all here.

        for (auto* n : nodesList) {
           if (n != nullptr) {
                delete n;
            }
        }

        nodesList.clear();

        rootNode = nullptr;


    }
private:
    Node<T>* rootNode;
    vector<Node<T>*> nodesList;  // Keeping track of all nodes for now

};

#endif //FA25EC3_TREE_H
