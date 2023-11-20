#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int value) {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class list {
public:
    Node* head;
    Node* tail;

    list() {
        head = NULL;
        tail = NULL;
    }

    void add_front(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void add_back(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
};

void initialize_list(list& a) {
    a.head = NULL;
    a.tail = NULL;
}

int main() {
    list a;
    initialize_list(a);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

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
        }
    } while (x != 3);

    for (Node* it = a.head; it != NULL; it = it->next) {
        cout << it->value << " ";
    }

    Node* curr = a.head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
