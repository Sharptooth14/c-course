#include <iostream>
using namespace std;
class node
{
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
        cout << "empty tree created" << endl;
    }
    void insert(int val);
};
void bst::insert(int val)
{
    node *pnew;
    pnew = new node(val);
    pnew->data = val;
    if (root == NULL)
    {
        root = pnew;
        cout << "root ceated" << endl;
    }
    else
    {
        node *ptemp;
        ptemp = root;
        do
        {
            if (val < ptemp->data)
            {
                if (ptemp->left == NULL)
                {
                    ptemp->left = pnew;
                    cout << "new value inserted in left of" << ptemp->data << endl;
                    break;
                }
                else
                {
                    ptemp = ptemp->right;
                }

            }
            else{
                cout<<"duplicate value found"<<endl;
            }
        }while(ptemp!=NULL);
    }
}
int main(){
    bst b;
    b.insert(50);
    b.insert(34);    
    b.insert(67);
    b.insert(89);
    b.insert(90);
    b.insert(78);
    return 0;

}
    