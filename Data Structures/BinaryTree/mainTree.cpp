#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    struct Node *left;
    struct Node *right;

    Node(T value)
    {
        data = value;
        left = right = nullptr;
    }
};

template <typename T>
Node<T> *insert(Node<T> *root, T value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

template <typename T>
int height(Node<T> *node)
{
    if (node == nullptr)
        return -1;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + max(leftHeight, rightHeight);
}

template <typename T>
int countLeaves(Node<T> *node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;

    return countLeaves(node->left) + countLeaves(node->right);
}

template <typename T>
int countNodes(Node<T> *node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

template <typename T>
void deleteTree(Node<T> *node)
{
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

template <typename T>
int findMax(Node<T> *node)
{
    if (node == nullptr)
    {
        throw runtime_error("Tree is empty");
    }

    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node->data;
}

template <typename T>
int findMaxInBinaryTree(Node<T> *node)
{
    if (node == nullptr)
        return INT_MIN;

    int current = node->data;
    int leftMax = findMaxInBinaryTree(node->left);
    int rightMax = findMaxInBinaryTree(node->right);

    return max(current, max(leftMax, rightMax));
}

template <typename T>
void inorder(Node<T> *node)
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

template <typename T>
void preorder(Node<T> *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

template <typename T>
void postorder(Node<T> *node)
{
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    Node<int> *root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    cout << "Height of the binary tree is: " << height(root) << endl;
    cout << "Number of leaves in the binary tree is: " << countLeaves(root) << endl;
    cout << "Number of nodes in the binary tree is: " << countNodes(root) << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}