#include<iostream>
#include<list>
using namespace std;


class node{
public:
int data;
node* next;

node(int val){
    data=val;
    next=nullptr;
}
};

class graph{
public:
    
    int n;
    list<int> *adjlst;

    graph(int v){
        n=v;
        adjlst=new list<int>[v];

    }
    void addedge(int u,int v,bool bi){
        adjlst[u].push_back(v);
        if(bi){
            adjlst[v].push_back(u);
        }
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<i<<"-->";
        // node* temp=adjlst[i].head;
        for(auto it:adjlst[i]){
            cout<<it<<" ";
        }
        cout<<endl;       
        }
    }
    void bfs(int searchval){
         // Mark all the vertices as not visited
    bool* visited= new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
         // Create a queue for BFS 
         list<int> queue;
         // Mark the current node as visited and enqueue it
        visited[searchval]=true;
        queue.push_back(searchval);
         // 'i' will be used to get all adjacent 
        // vertices of a vertex 
        list<int>:: iterator i;
        while(!queue.empty()){
        // Dequeue a vertex from queue and print it
        searchval=queue.front();
        cout<<searchval<<" ";
        queue.pop_front();
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue i
        for( i=adjlst[searchval].begin();i!=adjlst[searchval].end();i++){             //you can also use this but then dont use //list<int>:: iterator i;// above 
              if(!visited[*i]){                                                                    // for(auto it:adjlst[s]){
                 visited[*i]=true;                                                                //      if(!visited[it]){
                  queue.push_back(*i);                                                            //        visited[it]=true;                                                                   //        queue.push_back(it);    
            }                                                                                     //     queue.push_back(*i)
        }
        }
    delete[] visited;
    }
};

int main(){
    graph g(4);
    g.addedge(0, 1,true); 
    g.addedge(0, 2,true); 
    g.addedge(1, 2,false); 
    g.addedge(2, 0,true); 
    g.addedge(2, 3,false); 
    g.addedge(3, 3,true); 

    g.display();

cout<<"breadth first search "<<endl;
    g.bfs(0);

}
