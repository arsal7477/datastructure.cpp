#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int height;

    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};


    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(node* root) {
        if (root == nullptr)
            return 0;
        return root->height;
    }

    int getbalance(node* root) {
        if (root == nullptr)
            return 0;
        return height(root->left) - height(root->right);
    }

    node* rightrotate(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(y->right));

        return x;
    }

    node* leftrotate(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    node* newnode(int val) {
        node* newnode = new node(val);
        newnode->left = nullptr;
        newnode->right = nullptr;
        return newnode;
    }

    node* insert(node* root, int val) {
        if (root == nullptr) {
            return newnode(val);
        }
        if (val > root->data) {
            root->right = insert(root->right, val);
        }
        else if (val < root->data) {
            root->left = insert(root->left, val);
        }
        else {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int bf = getbalance(root);

        if (bf > 1 && val < root->left->data) {
            return rightrotate(root);
        }
        if (bf < -1 && val > root->right->data) {
            return leftrotate(root);
        }
        if (bf > 1 && val > root->left->data) {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
        if (bf < -1 && val < root->right->data) {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }

        return root;
    }

node* minnode(node* root){
    while(root->left!=nullptr){
        root=root->left;}
    return root;
}
    node* deletenode(node* root,int val){
        if(root==nullptr){
            return root;
        }
        if(val<root->data){
            root->left=deletenode(root->left,val);

        }
        else if(val>root->data){
            root->right=deletenode(root->right,val);
        }
        else{
            if(root->left==nullptr){
                node* temp=root;
                root=root->right;
                delete temp;
                
            }
            else if(root->right==nullptr){
               node* temp =root;
               root=root->left;
               delete temp;
            }

            else{
                node* temp=minnode(root->right);
                root->data=temp->data;
                root->right=deletenode(root->right,temp->data);

            }
        }
        if(root==nullptr){
            return root;
        }
        root->height=1+max(height(root->left),height(root->right));
        int balancefactor=getbalance(root);

        if(balancefactor>1 && getbalance(root->left)>=0){
            return rightrotate(root);
        }
        if(balancefactor>1 && getbalance(root->left)<0){
            root->left=leftrotate(root->left);
            return rightrotate(root);

        }
        if(balancefactor<-1 && getbalance(root->right)<=0)
        {
            return leftrotate(root);
        }
        if(balancefactor<-1 && getbalance(root->right)>0){
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
    return root;

    }
    void preorder(node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }


int main() {
    node* root=nullptr;

    // Insert valuto the AVL tree
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    root=deletenode(root,5);
    // Print the AVL tree in preorder
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
