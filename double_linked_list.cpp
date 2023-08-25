#include <iostream>
using namespace std;
struct  node
{
    int data;
    node* next;
    node* prev;
};

node* head =NULL;


void insert_first(int value)
{
    node* new_node=new node;
    new_node->data=value;
    new_node->prev=NULL;

    if (head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
}

void display()  
{
    node* current_node;
    if(head==NULL) 
    {
        cout<<"it is empty linked list ";
    }
    else 
    {
        current_node=head;
        while( current_node != NULL)
        {
            cout<<current_node->data<<"\t";
            current_node= current_node->next;
        }

    }
    cout<<endl;
}

void insert_last(int value)
{
    node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;

    if (head==NULL)
    {
        head=new_node;
        new_node->prev=NULL;
    }
    else
    {
        node*current=head;
        while (current->next!=NULL)
        {
            current=current->next;
        }
        new_node->prev=current;
        current->next=new_node;
    }
}

void delete_first()
{
    if (head==NULL)
    {
        cout<<"this double linked list is empty\n";
        return;
    }
    else
    {
        node* first=head;
        head= first->next;
        first->next->prev=NULL;
        free(first);
    }
}

void delete_last()
{
    if (head==NULL)
    {
        cout<<"this double linked list is empty\n";
        return;
    }
    node*current=head;
    while (current->next->next!=NULL)
    {
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
}

void delete_item(int value)
{
    if (head == NULL)
    {
        cout << "This double linked list is empty\n";
        return;
    }
    
    node *current = head;
    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }
    
    if (current->next == NULL)
    {
        cout << "Item with value " << value << " not found in the list\n";
        return;
    }
    
    node *item = current->next;
    current->next = item->next;
    
    if (item->next != NULL)
    {
        item->next->prev = current;
    }
    
    free(item);
}


void insert_before_item(int value, int newvalue)
{
    node* current=head;
    if (current->data ==value || current ==NULL)
    {
        insert_first(newvalue);
        return;
    }
    while (current != NULL && current->next->data != value)
    {
        current= current->next;
    }
    node* new_node= new node;
    new_node ->data=newvalue;
    new_node ->prev = current;
    new_node ->next = current->next;
    current->next->prev=new_node;
    current->next=new_node ;

}

int count()
{
    node* current=head;
    int count =0;
    while  (current != NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

bool search(int value)
{
   node* current=head;
   while  (current != NULL)
    {
        if (current->data==value)
        {
            return true;
        }
        current=current->next;
    } 
    return false; 
}

void replace(int value ,int newvalue)
{
   node* current=head;
   while  (current != NULL)
    {
        if (current->data==value)
        {
            current->data=newvalue;
            return;
        }
        current=current->next;
    } 
    
}

int main()
{
   insert_first(5);
   insert_first(10);
   insert_first(3);
   display();
   insert_last(15);
   display();
   delete_first();
   display();
   delete_last();
   display();
   delete_item(5);
   display();
   insert_before_item(10,4);
   display();
   cout<< count()<< " is the number of items in this linked list \n";
   cout<< "Is 5 an item in this double linked list? "<< search(5)<<endl;
   cout<< "Is 10 an item in this double linked list? "<< search(10)<<endl;
   replace(10,3);
   display();
   return 0; 
}
