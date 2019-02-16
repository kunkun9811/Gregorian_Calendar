#include <iostream>
#include <queue>

#include "test1.hpp" 

using namespace std;

class taskPtrCmpr{
    public: 
        bool operator()(Todo *&lhs, Todo *&rhs){
            return *lhs < *rhs;
        }
};

void printTask(priority_queue<Todo*, vector<Todo*>, taskPtrCmpr> tempQueue){
    while(!tempQueue.empty()){
        cout << *(tempQueue.top()) << endl;
        tempQueue.pop();
    }
}

int main(){
    
    Todo *a = new Todo();
    Todo *b = new Todo();
    Todo *c = new Todo();
    Todo *d = new Todo();
    Todo *e = new Todo();
    Todo *f = new Todo();
    Todo *g = new Todo();

    priority_queue<Todo*, vector<Todo*>, taskPtrCmpr> pq;
    
    a->task = "3 Importance";
    a->importance = 3;
    
    b->task = "1 Importance";
    b->importance = 1;
    
    c->task = "2 Importance";
    c->importance = 2;
    
    d->task = "4 Importance";
    d->importance = 4;
    
    e->task = "5 Importance";
    e->importance = 5;
    
    f->task = "Second 4 importance";
    f->importance = 4;
    
    g->task = "second 1 Importance";
    g->importance = 1;
    
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    pq.push(f);
    pq.push(g);

    
    cout << "This is tempQueue: " << endl;
    printTask(pq);
    
    cout << endl << endl;
    
    cout << "This is pq: " << endl;
    while(!pq.empty()){
        cout << *(pq.top()) << endl;
        pq.pop();
    }
    
    return 0;
}