#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Find LCA
Node* findLCA(Node* root, int a, int b) {
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node* leftLCA = findLCA(root->left, a, b);
    Node* rightLCA = findLCA(root->right, a, b);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Find distance from root to target node
int findDistance(Node* root, int target, int dist) {
    if (root == NULL)
        return -1;

    if (root->data == target)
        return dist;

    int left = findDistance(root->left, target, dist + 1);
    if (left != -1)
        return left;

    return findDistance(root->right, target, dist + 1);
}

// Distance between two nodes
int distanceBetweenNodes(Node* root, int a, int b) {
    Node* lca = findLCA(root, a, b);

    int d1 = findDistance(lca, a, 0);
    int d2 = findDistance(lca, b, 0);

    return d1 + d2;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << distanceBetweenNodes(root, 4, 5);

    return 0;
}