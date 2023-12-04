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
node* createchild(int val){
    node* newnode=new node(val);
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}
node* insert(node* root,int val){
    if(root==nullptr){
        return createchild(val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}
node* findmin(node* root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;

}
node* deletenode(node* root,int val){
    if(root==nullptr){
        return root;
    }
    else if(val<root->data){
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
            node* temp=root;
             root=root->left;
            delete temp;
           
        }
        else {
            node* temp= findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
        return root;
    }


    
}
void inorder(node* root){
        if(root!=nullptr){
            
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

    }

    bool search(node* root,int val){
        if(root==nullptr) {
            return false;
        }
        else if( root->data==val){
            return true;
        }
        else if(val>root->data){
            return search(root->right,val);
        }
        else{
            return search(root->left,val);
        }

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
           if(current->right!=nullptr)
            {
                q.push(current->right);
            }

            q.pop();
        }
    }

int main(){
    node* root=createchild(3);
    
   root=insert(root,2);
   root=insert(root,4);
   root=insert(root,7);
   root=insert(root,6);
   root=insert(root,5);


   inorder(root);
   root=deletenode(root,3);

   cout<<"\n\n\n\n";

   inorder(root);

   search(root,5);
   if(search(root,5)){
    cout<<"value found"<<endl;
   }
   else {
    cout<<"val not found";
   }

    levelorder(root);

    return 0;

}
