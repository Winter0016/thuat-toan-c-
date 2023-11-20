
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

class List{
private:
    Node *head, *tail;
public:

    List(){
        this->head = this->tail = NULL;
    }
    Node* _head(){return this->head;}

void add_tail(int x) {
        Node* p = new Node;
        p->val = x;
        p->next = NULL;

        if (head == NULL)
            head = tail = p;
        else {
            tail->next = p;
            tail = p;
        }
    }

    List(const List& other) {
        head=tail=NULL;
        for(Node*tem=other.head;tem!=NULL;tem=tem->next) {
            add_tail(tem->val);
        }
    }
   ~List() {
        while(head != NULL){
            Node* p = head;
            head = head->next;
            delete p;
         }
         tail = NULL;
    }
};

void X(List a){
    if (a._head() == NULL){
        cout << "NULL" << endl;
    }
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l;
    //Read list
    int x;
    do{
        cin >> x;
        l.add_tail(x);
    } while(x != 0);


    List l2 = l;

    Node*p = l._head(), *q = l2._head();
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    for(int i = 0; i < 2e3; i++){
        X(l2);
        cout << i << endl;
    }

    return 0;
}
