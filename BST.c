#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insertRecursive(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insertRecursive(root->left, key);
    else
        root->right = insertRecursive(root->right, key);
    return root;
}

struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

struct Node* insertIterative(struct Node* root, int key) {
    struct Node* newnode = newNode(key);
    if (root == NULL) return newnode;

    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (key < parent->key)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

struct Node* searchIterative(struct Node* root, int key) {
    struct Node* current = root;
    while (current != NULL) {
        if (key == current->key) return current;
        else if (key < current->key) current = current->left;
        else current = current->right;
    }
    return NULL;
}

int main() {
    int n = 50000;   // Number of nodes to insert
    int searchKey = n - 10; // Key to search near end
    struct Node* rootRec = NULL;
    struct Node* rootItr = NULL;

    clock_t start, end;
    double time_rec, time_itr;

    // ===== Recursive BST Test =====
    start = clock();
    for (int i = 0; i < n; i++) {
        rootRec = insertRecursive(rootRec, i);
    }
    searchRecursive(rootRec, searchKey);
    end = clock();
    time_rec = ((double)(end - start)) / CLOCKS_PER_SEC;

    // ===== Iterative BST Test =====
    start = clock();
    for (int i = 0; i < n; i++) {
        rootItr = insertIterative(rootItr, i);
    }
    searchIterative(rootItr, searchKey);
    end = clock();
    time_itr = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Performance Comparison (n = %d)\n", n);
    printf("Recursive BST Time: %f seconds\n", time_rec);
    printf("Iterative BST Time: %f seconds\n", time_itr);

    return 0;
}