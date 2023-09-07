// CPP implementation

#include <conio.h>
#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  Node(int nodeData) {
    key = nodeData;
    left = NULL;
    right = NULL;
  }
};

void InsertToTree(Node *root, int key) {
  Node *nodeToAdd = new Node(key);
  Node *currentNode = root;
  Node *previousNode = NULL;

  while (currentNode != NULL) {
    previousNode = currentNode;
    if (nodeToAdd->key < currentNode->key)
      currentNode = currentNode->left;
    else
      currentNode = currentNode->right;
  }
  if (previousNode->key > nodeToAdd->key) {
    previousNode->left = nodeToAdd;
    cout << nodeToAdd->key << ", was added to the left of " << previousNode->key
         << endl;
  } else {
    previousNode->right = nodeToAdd;
    cout << nodeToAdd->key << ", was added to the right of" << previousNode->key 
         << endl;
  }
}

void Search(Node *root, int key) {
  Node *currentNode = root;
  cout << "Search order: ";
  bool keyFound = true;
  while (currentNode->key != key) {
    cout << currentNode->key << " -> ";
    if (key < currentNode->key)
      currentNode = currentNode->left;
    else
      currentNode = currentNode->right;
    if (currentNode == NULL) {
      keyFound = false;
      cout << "\nNumber does not exist on tree." << endl;
      break;
    }
  }
  if (currentNode != NULL)
    cout << currentNode->key;
  if (keyFound)
    cout << "\nNumber exists on tree." << endl;
}

int main() {
  int valueArray[] = {2, 3,  4,  6,  7,
                      9, 13, 17, 18, 20}; // BST MEMBERS OTHER THAN ROOT
  Node *root = new Node(15);              // ROOT VALUE
  cout << "Root and members taken from code." << endl;
  cout << "Root = " << root->key << endl;
  cout << "Members = 2, 3, 4, 6, 7, 9, 13, 17, 18, 20" << endl;
  int arraySize = sizeof(valueArray) / sizeof(valueArray[0]);
  for (int i = 0; i < arraySize; i++) {
    InsertToTree(root, valueArray[i]);
  }
  cout << "Member to search: ";
  int key;
  cin >> key;
  Search(root, key);
  return 0;
}
