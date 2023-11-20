
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;


template <class T>
class List{

private:
    struct Node{
        T val;
        Node* next;
    };

    Node *head, *tail;
public:
    List(){
        this->head = this->tail = NULL;
    }

    void add_tail(T x){
        Node*p = new Node;
        p->val = x;
        p->next = NULL;

        if (this->head == NULL){
            this->head = this->tail = p;
        } else {
            this->tail->next = p;
            this->tail = p;
        }
    }

    T reduce(const T& initial_value
             , std::function<T(T aggergated, T current_value)> binary_op){
        T aggregated = initial_value;
        auto p = head;
        auto i = 0;
        while(p != NULL){
            aggregated = binary_op(aggregated, p->val);
            p = p->next;
            i++;
        }

        return aggregated;
    }
};

class fract{
private:
    long numerator_, denominator_;
    long numerator, denominator;
    void reduce();

public:
    fract (int x, int y);
    fract();
    fract operator+(fract b);
    friend ostream& operator << (ostream &s , fract& f);
    friend istream& operator >> (istream &s , fract& f);
};

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List<fract> l;
    int n;
    cin >> n;
    //Read list
    fract x;
    while(1){
        try{
            if(cin >> x){
                l.add_tail(x);
            }
            else {
                break;
            }
        } catch(std::domain_error e){
            /// just ignore
        }

    }
    fract sum = l.reduce(fract(0, 1), [](fract a, fract b) {
        return a + b;
    });

    cout << sum << endl;

    return 0;

}


