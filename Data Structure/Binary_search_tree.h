//
// Created by gauss on 04/07/2026.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_IMPLEMENTATION_BINARY_SEARCH_TREE_H
#define INTRODUCTION_TO_ALGORITHMS_IMPLEMENTATION_BINARY_SEARCH_TREE_H

typedef struct node
{
    struct node *left, *right;
    int key;
    unsigned char value; // 1 byte
} node_t;

typedef struct tree
{
    struct node *root;
} tree_t;

node_t *node_t create_node(int key, unsigned char value);
node_t *search_node(tree_t *tree, int key);
node_t tree_minimum(node_t *x);
node_t tree_maximum(node_t *x);

tree_t *create_tree();

void insert_node(tree_t *tree, node_t *x);
void delete_node(tree_t *tree, node_t *x);
void inorder_tree_walk(node_t *root);


#endif //INTRODUCTION_TO_ALGORITHMS_IMPLEMENTATION_BINARY_SEARCH_TREE_H