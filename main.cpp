#include <iostream>

using namespace std;

struct node {
    int data;
    node * left;
    node * right;
};

node * root;

bool add(int data, node **pNode) {
    if (*pNode == nullptr) {
        node *t = new node;
        t->data = data;
        t->left = nullptr;
        t->right = nullptr;
        *pNode = t;
        return true;
    } else {
        int d = (*pNode)->data;
        if (d==data) return false;
        if (d<data) {
            return add(data, &((*pNode)->right));
        } else {
            return add(data, &((*pNode)->left));
        }
    }
}

void printTreeLeftToRight(node *pNode) {
    if (pNode != nullptr) {
        printTreeLeftToRight(pNode->left);
        cout << pNode->data << endl;
        printTreeLeftToRight(pNode->right);
    }
}

void printTreeRightToLeft(node *pNode) {
    if (pNode != nullptr) {
        printTreeRightToLeft(pNode->right);
        cout << pNode->data << endl;
        printTreeRightToLeft(pNode->left);
    }
}

void printFromUpToDown(node *pNode) {
    if (pNode != nullptr) {
        cout << pNode->data << " ";
        printFromUpToDown(pNode->left);
        printFromUpToDown(pNode->right);
    }
}

int main() {
    root = nullptr;

    add(7, &root);
    add(4, &root);
    add(10, &root);
    add(2, &root);
    add(3, &root);
    add(17, &root);
    add(8, &root);
    add(5, &root);
    add(2, &root);

//    printTreeLeftToRight(root);
//    printTreeRightToLeft(root);
    printFromUpToDown(root);

    return 0;
}