#include <iostream>
#include <stack>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

public:
    Tree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    int height() {
        return heightRecursive(root);
    }

    class TreeIterator {
    private:
        std::stack<TreeNode*> nodeStack;

    public:
        TreeIterator(TreeNode* root) {
            pushLeftNodes(root);
        }

        bool end() {
            return nodeStack.empty();
        }

        void advance() {
            if (!end()) {
                TreeNode* node = nodeStack.top();
                nodeStack.pop();
                pushLeftNodes(node->right);
            }
        }

        int value() {
            if (!end()) {
                return nodeStack.top()->val;
            }
            throw std::runtime_error("Iterator has reached the end.");
        }

    private:
        void pushLeftNodes(TreeNode* node) {
            while (node != nullptr) {
                nodeStack.push(node);
                node = node->left;
            }
        }
    };

    TreeIterator begin() {
        return TreeIterator(root);
    }

    TreeIterator end() {
        return TreeIterator(nullptr);
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->val) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->val) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    int heightRecursive(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = heightRecursive(node->left);
        int rightHeight = heightRecursive(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
};

int main() {
    Tree a;

    while (true) {
        int x;
        std::cin >> x;
        if (x == 0)
            break;
        a.insert(x);
    }

    std::cout << a.height() << std::endl;
    for (auto it = a.begin(); !it.end(); it.advance()) {
        std::cout << it.value() << std::endl;
    }

    return 0;
}
