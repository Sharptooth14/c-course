#include <iostream>
#include <queue>

using namespace std;

class Tree;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node() // Default Con
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int value) // Parameterized
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class Tree;
};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    void inorderTraversal()
    {
        cout << endl
             << " In-Order Traversal is : ";
        inorderTraversal(root);
    }
    void inorderTraversal(Node *pTemp)
    {
        if (pTemp != NULL)
        {
            inorderTraversal(pTemp->left);
            cout << pTemp->data << " ";
            inorderTraversal(pTemp->right);
        }
    }

    void preOrderTraversal()
    {
        cout << endl
             << " Pre-Order Traversal is : ";
        preOrderTraversal(root);
    }
    void preOrderTraversal(Node *pTemp)
    {

        if (pTemp != NULL)
        {
            cout << pTemp->data << " ";
            preOrderTraversal(pTemp->left);
            preOrderTraversal(pTemp->right);
        }
    }

    void postOrderTraversal()
    {
        cout << endl
             << " Post-Order Traversal is : ";
        postOrderTraversal(root);
    }
    void postOrderTraversal(Node *pTemp)
    {

        if (pTemp != NULL)
        {
            postOrderTraversal(pTemp->left);
            postOrderTraversal(pTemp->right);
            cout << pTemp->data << " ";
        }
    }
    void insert(int value)
    {
        char dir;
        // 1. Allocate Memory and Store data
        Node *pNew;
        pNew = new Node(value);

        // Check if Tree is empty
        if (root == NULL)
        {
            root = pNew;
            cout << "Root created" << endl;
        }
        else
        {
            Node *pTemp;
            pTemp = root;
            do
            {

                cout << "Where to insert ( Left->L / Right->R ) of " << pTemp->data;
                cin >> dir;
                if (dir == 'L' || dir == 'l')
                {
                    if (pTemp->left == NULL)
                    {
                        pTemp->left = pNew;
                        cout << "Insertion in the left of " << pTemp->data << " is successful" << endl;
                        break;
                    }
                    else
                    {
                        pTemp = pTemp->left;
                    }
                }
                else if (dir == 'R' || dir == 'r')
                {
                    if (pTemp->right == NULL)
                    {
                        pTemp->right = pNew;
                        cout << "Insertion in the right of " << pTemp->data << " is successful" << endl;
                        break;
                    }
                    else
                    {
                        pTemp = pTemp->right;
                    }
                }
                else
                    cout << "Provide correct direction information (L/l for Left and R/r for right" << endl;

            } while (pTemp != NULL);
        }
    }

    void levelWiseTraversal()
    {
        queue<Node *> q;
        Node *pTemp;
        pTemp = root;

        if (pTemp != NULL) // If Tree is existing
        {
            q.push(pTemp);
            while (!q.empty())
            {
                pTemp = q.front();
                q.pop();
                cout << pTemp->data;
                if (pTemp->left != NULL)
                    q.push(pTemp->left);
                if (pTemp->right != NULL)
                    q.push(pTemp->right);
            }
        }
        else
        {
            cout << "Tree is Empty";
        }
    }
};

int main()
{
    int n, val;
    Tree bt;

    cout << "Please give Number of nodes in Binary Tree";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a value";
        cin >> val;
        bt.insert(val);
    }
    bt.levelWiseTraversal();

    /*bt.inorderTraversal();
    bt.preOrderTraversal();
    bt.postOrderTraversal();
    */
    return 0;
}