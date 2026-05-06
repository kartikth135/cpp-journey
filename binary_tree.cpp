#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(int val) { root = insert(root, val); }
    bool search(int val) { return search(root, val); }
    void inorder()   { cout << "Inorder:   "; inorder(root);   cout << "\n"; }
    void preorder()  { cout << "Preorder:  "; preorder(root);  cout << "\n"; }
    void postorder() { cout << "Postorder: "; postorder(root); cout << "\n"; }
};

int main() {
    BST tree;

    vector<int> vals = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals) tree.insert(v);

    tree.inorder();
    tree.preorder();
    tree.postorder();

    cout << "\nSearch 40: " << (tree.search(40) ? "Found" : "Not found") << "\n";
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not found") << "\n";

    return 0;
}