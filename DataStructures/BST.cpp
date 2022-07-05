#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node *right;

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

    Node *remove(Node *current, int x){
        if(current == NULL) return NULL;
        
        if(x > current->data) current->right = remove(current->right, x);
        else if(x < current->data) current->left = remove(current->left, x);
        else{
            if(current->left == NULL and current->right == NULL) current = NULL;
            else if(current->right == NULL) current = current->left;
            else if(current->left == NULL) current = current->right;
            else{
                Node *minRight = findMin(current->right);
                current->data = minRight->data;
                current->right = remove(current->right, minRight->data);
            }
        }
        return current;
    }

    void inOrder(Node *current){
        if(current == NULL) return;
        inOrder(current->left);
        cout << current->data << " ";
        inOrder(current->right);
    }

    void preOrder(Node *current){
        if(current == NULL) return;
        cout << current->data << " ";
        preOrder(current->left);
        preOrder(current->right);
    }

    void postOrder(Node *current){
        if(current == NULL) return;
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data << " ";
    }

    int height(Node *current){
        if(current == NULL) return 0;
        int leftH = height(current->left);
        int rightH = height(current->right);
        return max(leftH, rightH) + 1;
    }
};

int main(){
    
    BinarySearchTree BST;
    int n = 16, x;
    cout << "x = ";
    cin >> x;
    int arr[n] = {56, 30, 70, 40, 22, 11, 3, 16, 60, 95, 65, 63, 67, 17, 18, 15};

    for(int i = 0; i < n; i++)
        BST.root = BST.insert(BST.root, arr[i]);
    bool finded = BST.find(BST.root, x);

    cout << (finded ? "x exists\n" : "x doesn't exists\n");

    Node *mx = BST.findMax(BST.root);
    cout << "Max = " << mx->data << endl;
    cout << "Min = " << BST.findMin(BST.root)->data << endl;
    cout << "inOrder: ";
    BST.inOrder(BST.root);
    cout << "\npreOrder: ";
    BST.preOrder(BST.root);
    cout << "\npostOrder: ";
    BST.postOrder(BST.root);
    cout << "\nHeight of tree: " << BST.height(BST.root);
}
