#include <iostream>
using namespace std;

// the stack work by (LIFO) last in first out
// uesd for revears element(num,words) or for --> and <-- button 


//! stack implementation by arrays
#define size 5 // make the siz of stack (constant)
int stack [size], top=-1;  // the top var is related to the index of last element in stack
void push(int value)
{
    if (top== size-1)
    {
        cout<<"cant add more element to this stack (stack overflow )\n";
        return;
    }
    stack[++top]=value;
}

int pop()
{
    if (top== -1)
    {
        cout<<"stack underflow\n"; 
    }
    return stack[top--];
}

int peak()
{
    if (top== -1)
    {
        cout<<"stack underflow\n";
    }
    return stack[top];
    
}

void display ()

{ 
    if (top==-1)
    {
        cout<<"stack underflow\n";
        return;
    }
    for (int i=top; i>=0;i--)
    {
        cout<<stack[i]<<"\n";
    }
    cout<<"\n";
}


//! stack implementation by linked list(by insert all element at begninng to be in LIFO)
struct node  
{
    int data;
    node * next; 
};
 
node* top_linkedlist = NULL; // the head refer to the first element in linked always so we could say it refer to the top of stack

//? to replace all occurrence of  any word( uesd when change var name/fun name to up date all code to the new one)
//? ues ctrl + h
//todo (int deff) is just for make the fun by arrays deffernt than fun by linked list  (over loading)

void push (int value ,int deff) // insert_at_bignning linked list operation = push stack operation
{
    node*new_node = new node;
    new_node->data=value;
    new_node->next=top_linkedlist;
    top_linkedlist =new_node;
}


void pop (int deff)     // delete_at_bignning linked list operation = pop stack operation
{
    if (top_linkedlist==NULL) //top==-1 in arrays
    {
        cout<<"stack underflow \n";
    }
    else
    {
        node* first_node =top_linkedlist;
        top_linkedlist = first_node->next;
        free(first_node);
    }
}

int peak (int deff)     
{
    if (top_linkedlist==NULL) //top==-1 in arrays
    {
        cout<<"stack underflow \n";
    }
    else
    {
        return(top_linkedlist->data);
    }
}

void display(int deff)  
{
    node* current_node;
    if(top_linkedlist==NULL) 
    {
        cout<<"stack underflow ";
    }
    else 
    {
        current_node=top_linkedlist;
        while( current_node != NULL)
        {
            cout<<current_node->data<<"\t";
            current_node= current_node->next;
        }

    }
    cout<<endl;
}


int main()
{
    // to implemnt stack by linked list add more parameter after the needed one "
    push(5,0);
    push(15,0);
    push(25,0);
    display(0);
    pop(0);
    display(0);
    cout<<peak(0)<<" after peak\n";
    display(0);
    return 0;

}


