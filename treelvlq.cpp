#include<iostream>
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

node* leveloreder(node* root){
    if(root==nullptr){
        return root;
    }

    node* queue[100];
    int front=0,rear=0;

    queue[rear++]=root;

    while(front<rear){
        node* current=queue[front++];
        cout<<current->data<<" ";

        if(current->left!=nullptr){
            queue[rear++]=current->left;

        }
        if(current->right!=nullptr){
            queue[rear++]=current->right;
        }
        
    }
}
int main(){
    node* root=nullptr;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,0);
    root=insert(root,4);

    leveloreder(root);
    return 0;
}
