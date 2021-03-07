#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 22;
struct Node {
    int height, val;
    Node* left;
    Node* right;
};
int n;

int getHeight(Node* root) {
    if (!root)
        return 0;
    return root->height;
}

int updateHeight(Node* root) {
    if (!root)
        return 0;
    return root->height = max(updateHeight(root->left), updateHeight(root->right)) + 1;
}

Node* rotateRight(Node* root) {
    if (!root)
        return NULL;
    Node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

Node* rotateLeft(Node* root) {
    if (!root)
        return NULL;
    Node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

Node* rotateLeftRight(Node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

Node* rotateRightLeft(Node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

Node* insert(Node* root, int val) {
    if (!root) {
        root = new Node();
        root->val = val;
        root->height = 1;
        root->left = root->right = NULL;
    } else if (val < root->val) {
        root->left = insert(root->left, val);
        updateHeight(root);
        if (getHeight(root->left) - getHeight(root->right) >= 2) {
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
        }
    } else {
        root->right = insert(root->right, val);
        updateHeight(root);
        if (getHeight(root->right) - getHeight(root->left) >= 2) {
            root = val >= root->right->val ? rotateLeft(root) : rotateRightLeft(root);
        }
    }
    return root;
}

int main() {
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d\n", root->val);
    return 0;
}