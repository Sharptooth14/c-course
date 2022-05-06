#include <iostream>
using namespace std;

class node
{
public:
    int data;
    
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
        

    }
};
 
int getLength(node* head){
    int length  = 0;
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}
void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);   //New Node is Created

    if (head == NULL)  // If the List is Empty then the Head Node points to the newly created node
    {
        head = n;
        return;
    }

    node *temp = head;   //Pointer temp uses the address stored at Head Node to go to the beginning of the List
    while (temp->next != NULL)    //Loop to Traverse the List
    {
        temp = temp->next;
    }
    temp->next = n; //the address of new node is stored at the previous node
}

void InsertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;   // New node copies the Address stored at Head
    head = n;   // Head node points to the newly created node
}
void InsertAtIndex(node * &head,int val,int index){
	
	if(index==0){
		InsertAtHead(head,val);
	}
	if(index==getLength(head)){
		InsertAtTail(head,val);
	}
	int count =0;
	node * temp =head;
	while(temp!=NULL){
		if (count == index-1 || count == index +1){
			node * n = new node(val);
			n->next = temp->next;
			temp->next = n;
			break;
		}
		temp = temp->next;
		count++;
	}
	if(index<0 || index> getLength(head)){
		cout<<"invalid index "<<index<<endl;
		return;
	}
	
	
}
bool searchList(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void displayList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deleteAtHead(node* &head){
    node* todelete = head;  //to delete points to the address soted at node
    head = head->next; // head points to the first node 
    delete todelete; //first node gets deleted
}
void deleteNode(node* &head , int val){

    if (head==NULL)
    {
        return;
    }
    if (head->next==NULL)
    {
        deleteAtHead(head);
    }
    
    node* temp = head;
    while (temp->next->data!= val) //temp->next->data != val finds the (n-1)th node
    {
        temp = temp->next;
    }
    node* todelete = temp->next; // Pointer to the node to be deleted
    temp->next = temp->next->next;   // it links the (n-1)th node to the (n+1)th node
    delete todelete; //Deletes the node at which todelete points to
}
node* reverseList(node* &head){
    node* prevPtr = NULL;
    node* current = head;
    node* nextPtr;
    while (current!=NULL){
    
        nextPtr = current->next;
        current->next = prevPtr;
        prevPtr = current;
        current = nextPtr;
    }
    return prevPtr; //This is the new head of hte reversed list
}
node* reverseRecursive(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

node* reverseK(node* &head , int k){
    node* prevPtr = NULL;
    node* current = head;
    node* nextPtr;
    int count = 0;
    while (current!=NULL && count<k)
    {
        nextPtr = current->next;
        current->next = prevPtr;
        prevPtr = current;
        current = nextPtr;
        count++;
    }
    if (nextPtr != NULL)
    {
        head->next = reverseK(nextPtr,k);
    }
    
    return prevPtr;
}

int main()
{
    node *head = NULL;
    InsertAtHead(head,0);
    InsertAtIndex(head,1,1);
    InsertAtIndex(head,2,2);
    InsertAtIndex(head,3,3);
    InsertAtIndex(head,4,4);
    InsertAtIndex(head,5,5);
    displayList(head);
    InsertAtIndex(head,6,3);
    displayList(head);
    // node* ReverseHead = reverseList(head);
    // displayList(ReverseHead);
    // node* RecursionReverse = reverseRecursive(head);
    // displayList(RecursionReverse);
    // node* revK =reverseK(head,3);
    // displayList(revK);
    return 0;
}