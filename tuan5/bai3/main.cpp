#include <iostream>
using namespace std;
class Tree {
private:
    struct node {
        int key;
        node* left;
        node*right;
    };
    node*root;

public:
    class Tree_iterator {
    private:
        node* node;
    public:
         bool end() {
            return node == NULL;
        }

        void goright() {

        }
        void goleft(){

        }

        int& value() {
            return node->val;
        }
        friend class Tree;
    };
    Tree() {
        this->root = NULL;
    }

    Tree_iterator start() {
        Tree_iterator kq;
        kq.node = this->root;
        return kq;
    }
    void insertree(x)
        if(root==NULL){
            root->key=x;
            root->left=NULL;
            root->right=NULL;
        }
        else if(x>root->key){
            insertreeleft(root->left,x)
        }
    }

};
int main()
{

    Tree a;

    while(true){
        int x; cin >> x;
        if (x == 0) break;
        a.insert(x);
    }

    cout << a.height() << endl;
    for(auto i = a.begin(); i != a.end(), i.advance()){
        cout << i.value() << endl;
    }

    return 0;
}
