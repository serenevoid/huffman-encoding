#ifndef _BINARY_TREE_
#define _BINARY_TREE_

typedef struct Node {
  char value;
  int count;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(char value, int count);

#endif
