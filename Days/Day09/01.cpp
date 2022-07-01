#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct BinarySearchTree{

    Node *root;

    BinarySearchTree(){
        root = NULL;
    }

    Node *insert(Node *current, int x){
        if(current == NULL){
            current = new Node(x);
            return current;
        }
        if(x > current->data) current->right = insert(current->right, x);
        else if(x < current->data) current->left = insert(current->left, x);

        return current;
    }

    bool find(Node *current, int x){
        if(current == NULL)
            return false;
        if(x > current->data) return find(current->right, x);
        else if(x < current->data) return find(current->left, x);
        return true;
    }

    Node *findMax(Node *current){
        if(current->right == NULL)
            return current;
        return findMax(current->right);
    }

    Node *findMin(Node *current){
        if(current->left == NULL)
            return current;
        return findMin(current->left);
    }

    // void remove(){
        
    // }

    // void print(){

    // }

};

int main(){
    
    BinarySearchTree BST;
    int n = 17, x;
    cout << "x = ";
    cin >> x;
    int arr[n] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 18, 21, 24, 27, 30, 31};

    for(int i = 0; i < n; i++)
        BST.root = BST.insert(BST.root, arr[i]);
    bool finded = BST.find(BST.root, x);

    cout << (finded ? "x exists\n" : "x doesn't exists\n");

    Node *mx = BST.findMax(BST.root);
    cout << "Max = " << mx->data << endl;
    cout << "Min = " << BST.findMin(BST.root)->data << endl;

}

// Step 1:
// BinarySearchTree BST;                               // root = NULL;

// Step 2:
// BST.root = BST.insert(BST.root, 1);                 // root = node; node->data = 1, node->left = NULL, node->right = NULL;

// Step 3:
// BST.root = BST.insert(BST.root, 2);                 // node->right = node1; node1->data = 2, node1->left = NULL, node1->right = NULL;

// Step 4:
// BST.root = BST.insert(BST.root, 0);                 // node->left = node2, node2->data = 0, node2->left = NULL, node2->right = NULL;

// Step 5:
// BST.root = BST.insert(BST.root, 10);                 // 