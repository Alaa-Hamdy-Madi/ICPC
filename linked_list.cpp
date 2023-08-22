







#include <iostream>
using namespace std ;

struct node   // defined a new data type is node 
{
    int data;
    node * next; //the pointer will refer to another node ,so the data type =node
};

node * head =NULL; // AT FIRST THE LINKED LIST IS EMPTY SO THE HEAD  DOSENT REFER TO ANOTHER NODE



void insertnewnode(int value ) // should enter the value  
{
    node * new_node =new node; // defined  new node
    node* last;                // defined pointer to refer to the last node in the linked list
    new_node ->data= value;    // fill the part of data with value
    new_node->next= NULL;      // fill the part of next with pointer refer to the next node here null becues we need to insert it  at the last
    
    if (head ==NULL) // check if  the linked list is empty so this is will be the first node in it 
    {
        head= new_node; // conect the head with first node and make it refer to it place
    }
    else  // if not empty , thats mean there is another node befor the new one
    {
        last =head; // start search until reach the last node ( it  next part == NULL)
        while (last->next != NULL)
        {
            last= last->next; // skip to the next node
        }
        last-> next= new_node; // conect the last node with new node and make it refer to it place
    }
    
}

void display()  // defined  func to print the linked list
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

void deletenode (int value)
{
    node* current ,* previous  ;
    current =head;
    previous =head;
    if (current->data ==value)
        {
            head=current->next;
            free(current);
            return;
        }
    
    while(current->data !=value )
        {
            previous = current;
            current=current->next;
        }
    previous->next = current->next;
    free(current);

}


void insert_at_bignning(int value)
{
    node*new_node = new node;
    new_node->data=value;
    new_node->next=head;
    head =new_node;

}

void delete_at_bignning()
{
    if (head==NULL)
    {
        cout<<"this  linked ilst is empty \n";
    }
    else
    {
        node* first_node = head;
        head = first_node->next;
        free(first_node);
    }
}

void delete_at_end()
{
    if (head==NULL)
    {
        cout<<"this  linked ilst is empty \n";
    } 
    else if (head->next==NULL)
    {   free(head);
        head=NULL;
    }
    else
    {
        node*current=head;
        while (current-> next->next !=NULL)
        {
             current=current->next;
        }
        free(current->next);
        current->next=NULL;

    }
}

void insert_before_item(int value, int newvalue)
{
    node* current=head;
    while (current != NULL && current->next->data != value)
    {
        current= current->next;
    }
    node* new_node= new node;
    new_node ->data=newvalue;
    new_node ->next = current->next;
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
{ // creat the linked list with 4 node  and then print it
    insertnewnode(5);
    insertnewnode(10);
    insertnewnode(15);
    insertnewnode(20);
    display();
    deletenode(10);
    display();
    insert_at_bignning(10);
    display();
    delete_at_bignning();
    display();
    delete_at_end();
    display();
    insert_before_item(15,10);
    display();
    cout<< count()<< " is the number of items in this linked list \n";
    cout<< "Is 5 an item in this linked list? "<< search(5)<<endl;
    cout<< "Is 3 an item in this linked list? "<< search(3)<<endl;
    replace(5,3);
    display();
    return 0;
}
