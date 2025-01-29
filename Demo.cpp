#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int rcount;
    int lcount;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->rcount = 0;
        this->lcount = 0;
    }
};

class Binary_Tree
{
    static int idx;

public:
    Node *root = NULL;

    // Using Array
    Node *addNode(int nodes[])
    {
        idx++;
        if (nodes[idx] == -1)
        {
            return NULL;
        }

        Node *newNode = new Node(nodes[idx]);
        newNode->left = addNode(nodes);
        newNode->right = addNode(nodes);

        return newNode;
    }

    bool isPBT(int count)
    {
        count = count + 1;
        while (count % 2 == 0)
            count = count / 2;

        if (count == 1)
            return true;
        else
            return false;
    }

    Node *addNode2(Node *root, int data)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            return newNode;
        }

        if (root->rcount == root->lcount)
        {
            root->left = addNode2(root->left, data);
            root->lcount += 1;
        }
        else if (root->rcount < root->lcount)
        {
            if (isPBT(root->lcount))
            {
                root->right = addNode2(root->right, data);
                root->rcount += 1;
            }
            else
            {
                root->left = addNode2(root->left, data);
                root->lcount += 1;
            }
        }
        return root;
    }

    // Search Function
    bool search(Node *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }

        if (root->data == data)
        {
            return true;
        }

        // Recursively search in left and right subtrees
        return search(root->left, data) || search(root->right, data);
    }

    // Pre-order Traversal
    void preOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // In-order Traversal
    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    // Post-order Traversal
    void postOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};

int Binary_Tree::idx = -1;

int main()
{
    Binary_Tree bt;
    // int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    // Node *root = bt.addNode(nodes);
    // cout << "Tree Traversals:" << endl;

    // cout << "Pre-Order Traversal: ";
    // bt.preOrder(root);
    // cout << endl;

    // cout << "In-Order Traversal: ";
    // bt.inOrder(root);
    // cout << endl;

    // cout << "Post-Order Traversal: ";
    // bt.postOrder(root);
    // cout << endl;

    int a;
    cout << "Enter the number of nodes you want to add: ";
    int numNodes;
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++)
    {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> a;
        bt.root = bt.addNode2(bt.root, a);
    }

    bt.preOrder(bt.root);
    cout << endl;
    bt.inOrder(bt.root);
    cout << endl;
    bt.postOrder(bt.root);
    // int searchData;
    // cout << "Enter a value to search in the tree: ";
    // cin >> searchData;

    // if (bt.search(bt.root, searchData))
    // {
    //     cout << "Data " << searchData << " is found in the tree." << endl;
    // }
    // else
    // {
    //     cout << "Data " << searchData << " is not found in the tree." << endl;
    // }

    return 0;
}