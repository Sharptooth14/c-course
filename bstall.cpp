#include <iostream>
#include <string>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data = NULL;
        left = NULL;
        right = NULL;
    }
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
        cout << "Empty Binary Search Tree Created";
    }
    void insert(int value);
    Node *search(Node *root, int TargetValue);
    bool search(int TargetValue);
    int minimum();
    int LongestPath();
    int LongestPath(Node *root);
    void swap();
    void swap(Node *root);
    void inorderTraversal();
    void inorderTraversal(Node *pTemp);
    void menu();
    int maximum();
};
int BST::minimum()
{
    Node *pTemp;
    pTemp = root;
    if (pTemp->left == NULL)
    {
        return pTemp->data;
    }
    else
    {
        do
        {
            pTemp = pTemp->left;

        } while (pTemp->left != NULL);
        return pTemp->data;
    }
};
int BST::maximum()
{
    Node *pTemp;
    pTemp = root;
    if (pTemp->left == NULL)
    {
        return pTemp->data;
    }
    else
    {
        do
        {
            pTemp = pTemp->right;
        } while (pTemp->right != NULL);
        return pTemp->data;
    }
};
void BST::insert(int value)
{
    Node *pNew;
    pNew = new Node(value);
    if (root == NULL)
    {
        root = pNew;
        cout << "Root Created";
    }
    else
    {
        Node *pTemp;
        pTemp = root;
        do
        {
            if (value < pTemp->data)
            {
                if (pTemp->left == NULL)
                {
                    pTemp->left = pNew;
                    cout << "New Value Inserted to the left of " << pTemp->data;
                    break;
                }
                else
                {
                    pTemp = pTemp->left;
                }
            }
            else if (value > pTemp->data)
            {
                if (pTemp->right == NULL)
                {
                    pTemp->right = pNew;
                    cout << "New Value Inserted to the right of " << pTemp->data;
                    break;
                }
                else
                {
                    pTemp = pTemp->right;
                }
            }
            else
            {
                cout << "Duplicate Element Entered";
                break;
            }
        } while (pTemp != NULL);
    }
}
bool BST::search(int TargetValue)
{
    return search(root, TargetValue);
}
Node *BST::search(Node *root, int TargetValue)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (TargetValue < root->data)
    {
        return search(root->left, TargetValue);
    }
    else if (TargetValue > root->data)
    {
        return search(root->right, TargetValue);
    }
    else
    {
        return root;
    }
}
int BST::LongestPath()
{
    return LongestPath(root);
}
int BST::LongestPath(Node *root)
{
    int hl, hr;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        hl = LongestPath(root->left);
        hr = LongestPath(root->right);
        if (hl > hr)
        {
            return hl + 1;
        }
        else
        {
            return hr + 1;
        }
    }
}
void BST::swap()
{
    swap(root);
}
void BST::swap(Node *root)
{
    Node *temp;
    if (root->left != NULL)
    {
        swap(root->left);
    }
    if (root->right != NULL)
    {
        swap(root->right);
    }
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void BST::inorderTraversal()
{
    cout << endl
         << " In-Order Traversal is : ";
    inorderTraversal(root);
}
void BST::inorderTraversal(Node *pTemp)
{
    if (pTemp != NULL)
    {
        inorderTraversal(pTemp->left);
        cout << pTemp->data << " ";
        inorderTraversal(pTemp->right);
    }
}
void BST::menu()
{
    int num, n, TargetValue;
    int val;
    cout << "\n";
    cout << "\n1. Insert Node in Tree\n";
    cout << "2. Search Element in Tree \n";
    cout << "3. Node in Longest path\n";
    cout << "4. Minimum Number in Tree\n";
    cout << "5. Maximum Number in Tree\n";
    cout << "6. Swap (Mirror) the Tree\n";
    cout << "7. To Display Inorder Traversal of Tree\n";
    cout << "8. Exit\n";
    cout << "\n Enter Key : ";
    cin >> num;
    if (num == 1)
    {
        cout << "\nEnter number of Nodes :";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter Value : ";
            cin >> val;
            insert(val);
        }
        menu();
    }
    else if (num == 2)
    {
        cout << "Enter Element to Search :";
        cin >> TargetValue;
        if (search(TargetValue) == true)
        {
            cout << "Element Present";
        }
        else
        {
            cout << "Element Not Present";
        }
        menu();
    }
    else if (num == 3)
    {
        cout << "Number of Nodes in Longest Path is : ";
        cout << LongestPath();
        menu();
    }
    else if (num == 4)
    {
        cout << "The Minimum Element in Tree is : ";
        cout << minimum();
        menu();
    }
    else if (num == 5)
    {
        cout << "The Maximum Element in Tree is : ";
        cout << maximum();
        menu();
    }
    else if (num == 6)
    {
        swap();
        cout << "Tree is swapped";
        menu();
    }
    else if (num == 7)
    {
        cout << "Inorder Traversal of list is : ";
        inorderTraversal();
        menu();
    }
    else if (num == 8)
    {
        exit;
    }
    else
    {
        cout << "Wrong Input";
        menu();
    }
}

int main()
{
    BST bt;
    bt.menu();
    return 0;
}