#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};
void insertatend(node* &head,int val){
	node* newnode=new node(val);
	
	if (head==NULL){
		head=newnode;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	node* head=NULL;
	insertatend(head,4);
	insertatend(head,5);
	insertatend(head,6);
	display(head);
}
