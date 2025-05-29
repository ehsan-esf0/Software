#include <iostream>
#include <queue>
#include <limits>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;

    Node(T value)
    {
        data = value;
        left = right = nullptr;
    }
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;

    Node<T> *insert(Node<T> *node, T value)
    {
        if (node == nullptr)
            return new Node<T>(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node<T> *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node<T> *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node<T> *node)
    {
        if (node != nullptr)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void levelOrder(Node<T> *node)
    {
        if (node == nullptr)
            return;

        queue<Node<T> *> q;
        q.push(node);

        while (!q.empty())
        {
            Node<T> *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    int height(Node<T> *node)
    {
        if (node == nullptr)
            return -1;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int countLeaves(Node<T> *node)
    {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int countNodes(Node<T> *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void deleteTree(Node<T> *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    T findMaxInBinaryTree(Node<T> *node)
    {
        if (node == nullptr)
            return numeric_limits<T>::lowest();

        T current = node->data;
        T leftMax = findMaxInBinaryTree(node->left);
        T rightMax = findMaxInBinaryTree(node->right);

        return max(current, max(leftMax, rightMax));
    }

    bool identical(Node *Node1, Node *Node2)
    {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        if (node1 != nullptr &&node2 1 = nullptr)
            return (node1->data == node2->data) && identical(node1->left, node2->left) && identical(node1->right, node2->right);

        return false;
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(T value)
    {
        root = insert(root, value);
    }

    void printInorder()
    {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printPreorder()
    {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void printPostorder()
    {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    int height()
    {
        return height(root);
    }

    int countLeaves()
    {
        return countLeaves(root);
    }

    int countNodes()
    {
        return countNodes(root);
    }

    void clear()
    {
        deleteTree(root);
        root = nullptr;
    }

    ~BinaryTree()
    {
        clear();
    }

    T findMaxInBinaryTree()
    {
        return findMaxInBinaryTree(root);
    }

    bool isEqual(BinaryTree<T> &other)
    {
        return identical(root, other.root);
    }
};
