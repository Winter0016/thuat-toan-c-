#include <iostream>
using namespace std;

struct node {
    node* next;
    int value;
};

class list {
public:
    node* head;
    node* tail;

    void add_front(int b) {
        node* p = new node;
        p->value = b;
        p->next = head;
        head = p;
        if (tail == NULL) {
            tail = p;
        }
    }

    void add_back(int b) {
        node* p = new node;
        p->value = b;
        p->next = NULL;
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void finda(int a, int b) {
        node* p = head;
        while (p != NULL) {
            if (p->value == a) {
                node* p2 = new node;
                p2->value = b;
                p2->next = p->next;
                p->next = p2;
                if (p == tail) {
                    tail = p2;
                }
                return;
            }
            p = p->next;
        }
        add_front(b);
    }
};

void initialize_list(list& a) {
    a.head = NULL;
    a.tail = NULL;
}

int main() {
    list a;
    initialize_list(a);

    int x, b, c;
    do {
        cin >> x;
        switch (x) {
            case 0:
                cin >> b;
                a.add_front(b);
                break;
            case 1:
                cin >> b;
                a.add_back(b);
                break;

            case 2:
                cin >> b >> c;
                a.finda(b, c);
                break;
        }
    } while (x != 3);

    for (auto it = a.head; it; it = it->next) {
        cout << it->value << " ";
    }

    return 0;
}
