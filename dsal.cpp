#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node *left, *right;
    friend class bst;

public:
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    
};
class bst
{
    node *root;

public:
    bst()
    {
        root = NULL;
        cout << "empty bst created" << endl;
    }
    void insert(int val);
};
void bst::insert(int val)
{
    node *pnew;
    pnew = new node(val);
    if (root == NULL)
    {
        root = pnew;
        cout << "\nroot created\n";
    }
    else
    {
        node *temp;
        temp = root;
        do
        {
            if (val < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = pnew;
                    cout << pnew->data<<" is inserted in left of " << temp->data << endl;
                    break; 
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (val > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = pnew;
                    cout <<pnew->data<< " val is inserted in right of " << temp->data << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout << "duplicate value is found" << endl;
            }
        } while (temp != NULL);
    }
}
int main()
{
    bst b;
    b.insert(07);
    b.insert(03);
    b.insert(05);
    b.insert(02);
    b.insert(01);
    return 0;
} 
