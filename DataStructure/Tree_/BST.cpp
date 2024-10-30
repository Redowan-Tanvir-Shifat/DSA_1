#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int x){
        data = x;
        left = right = nullptr;
    }
};

class BST{
    node *root;
public:
    BST() {
        root = nullptr;
    }

    void Insert(int x) {
        node *newnode = new node(x);
        //tree is empty
        if(root == nullptr){
            root = newnode;
            return;
        }
        node *current = root, *parent = root;
        while (current != nullptr) {
            parent = current;
            if(x < current->data) current = current->left;
            else current = current->right;
        }
        if(parent->data > x ) {
            parent->left = newnode;
        }
        else {
            parent->right = newnode;
        }
    }

    void inorder() {
        cout << "inorder:";
        inorder(root);
        cout << endl;
    }
    void inorder(node *treeNode) {
        if(treeNode == nullptr)
            return;
        inorder(treeNode->left);
        cout << treeNode->data << " , ";
        inorder(treeNode->right);
    }

    void preorder() {
        cout << "preorder:";
        preorder(root);
        cout << endl;
    }
    void preorder(node *treeNode) {
        if(treeNode == nullptr) return;
        //root, left, right
        cout << treeNode->data << " , ";  //root
        preorder(treeNode->left);  //left subtree
        preorder(treeNode->right);  //right subtree
    }

    void postorder() {
        cout << "postorder:";
        postorder(root);
        cout << endl;
    }
    void postorder(node *treeNode) {
        if(treeNode == nullptr) return;
        //root, left, right
        postorder(treeNode->left);  //left subtree
        postorder(treeNode->right);  //right subtree
        cout << treeNode->data << " , ";  //root
    }

    node * Search(int key) {
        node * current = root;
        while(current != nullptr){
            if(current->data == key)
                return current;
            else if(key < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return current;
    }

    int findMin() {
        //tree is empty
        if(root == nullptr) return INT_MAX;
        node * current = root;

        while(current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    int findMax() {
        //tree is empty
        if(root == nullptr) return INT_MIN;
        node * current = root;

        while(current->right != nullptr){
            current = current->right;
        }
        return current->data;
    }

    int geTHeight() {
        return Height(root);
    }
    int Height(node *treeNode) {
        //if the node is null
        if(treeNode == nullptr) return -1;
        //if leaf node -> height =0
        if(treeNode->left == nullptr && treeNode->right == nullptr)
            return 0;

        int h1 = Height(treeNode->left);
        int h2 = Height(treeNode->right);

        return max(h1, h2) + 1;
    }
};


int main() {
    BST bst;
    bst.Insert(28);
    cout<<"height:"<<bst.geTHeight()<<endl;
    node * s = bst.Search(28);
    if(s != nullptr) cout<<"28 is in the tree"<<endl;
    else cout<<"28 is not in the tree"<<endl;
    node * s1 = bst.Search(32);
    if(s1 != nullptr) cout<<"32 is in the tree"<<endl;
    else cout<<"32 is not in the tree"<<endl;
    bst.Insert(14);
    bst.Insert(32);
    bst.Insert(8);
    bst.Insert(12);
    bst.Insert(46);
    bst.Insert(11);
    bst.Insert(56);
    bst.inorder();
    cout<<"height:"<<bst.geTHeight()<<endl;
}
