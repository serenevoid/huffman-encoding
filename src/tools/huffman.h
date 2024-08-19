#ifndef _HUFFMAN_ENCODING_
#define _HUFFMAN_ENCODING_

#include "binarytree.h"

Node* createBinaryTree(int* count);
int* getTable(Node* rootNode, int* codes);

#endif
