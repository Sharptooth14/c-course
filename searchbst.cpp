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
        data = 0;
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
        cout << "empty root is created" << endl;
    }
    void insert(int val);
};
void bst::insert(int val)
{
   node *pnew;
   pnew = new node(val);
   pnew->data = val;
   if(root==NULL)
   {
       root = pnew;
       cout<<"root created"<<endl;
   }
   else 
   {
       node *temp;
       temp = root;
       do 
       {
           if(val<temp->data)
           {
               if(temp->left==NULL)
               {
                   temp->left=pnew;
                   cout<<"val is inserted in left of "<<temp->data<<endl;
                   break;
               }
               else
               {
                   temp->left=temp;
               }
           }
           else if(val>temp->data)
           {
               if(temp->right==NULL)
               {
                   temp->right=pnew;
                   cout<<"val is inserted in right of "<<temp->data<<endl;
                   break;
               }
               else
               {
                   temp->right=temp;
               }
           }
           else 
           {
               cout<<"duplicate value is found"<<endl;
           }
       }while(temp!=NULL);
   }
}
int main()
{
    bst a;
    a.insert(12);
    a.insert(13);
    a.insert(16);
    a.insert(17);
    a.insert(50);
    return 0;
}
