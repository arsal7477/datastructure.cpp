#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
node* insert(node* root,int val){
    if(root==nullptr){
        return new node(val);
    }
    if(val>root->data){
        root->right=insert(root->right,val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    return root;
}

void levelorder(node* root){
    if(root==nullptr){
        return;
    }
    queue<node*> q;

    q.push(root);

    while(!q.empty()){

        node* current=q.front();
        cout<<current->data<<" ";

        if(current->left!=nullptr){
            q.push(current->left);
        }
        if(current->right!=nullptr){
            q.push(current->right);
        }
        q.pop();

    }
}
int main(){
    node* root=nullptr;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,0);
    root=insert(root,4);

    levelorder(root);
}