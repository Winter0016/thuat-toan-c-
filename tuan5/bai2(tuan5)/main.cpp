#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

class List {
private:
    struct Node {
        int val;
        Node* next;
    };
    Node *head, *tail;

public:
    class linked_list_iterator {
    private:
        Node* node;
    public:

        bool end() {
            return node == NULL;
        }

        void advance() {
            node = node->next;
        }

        int& value() {
            return node->val;
        }
        friend class List;
    };

    List() {
        this->head = this->tail = NULL;
    }

    linked_list_iterator start() {
        linked_list_iterator kq;
        kq.node = this->head;
        return kq;
    }

    void add_tail(int x) {
        Node* p = new Node;
        p->val = x;
        p->next = NULL;

        if (this->head == NULL) {
            this->head = this->tail = p;
        } else {
            this->tail->next = p;
            this->tail = p;
        }
    }
};

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l;
    // Read list
    int x;
    do {
        cin >> x;
        l.add_tail(x);
    } while (x != 0);

    for (auto i = l.start(); !i.end(); i.advance()) {
        i.value() = i.value() * 2;
    }

    for (auto i = l.start(); !i.end(); i.advance()) {
        cout << i.value() << endl;
    }

    return 0;
}
