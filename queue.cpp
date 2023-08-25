#include <iostream>
using namespace std;

// the queue work by FIFO (first in first out)
//! fist type of queue is simple queue 

//? implemintation of simple queue by arrays
#define size 5  // make the siz of queue (constant)
// front var refer to the first element in queue , when queue empty that sould be -1 (not refer to any thing)
// front var rear to the first element in queue , when queue empty that sould be -1
int queue[size];  int front=-1  ; int rear=-1; 


void enqueue(int value) // enter element fun
{
    if (rear==size-1)
    {
        cout<<"cant add \n";
    }
    else
    {
        if (front==-1)
        {
            front++;
        }
        queue [rear++]= value;
    }
}

void dequeue() // out element fun
{
    if ((rear==-1 && front==-1) || front > rear)  // if queue is empty( dosent enter any item before or delete all item in it ) 
    {
        cout<<"queue is empty \n";
    }
    else
    {
        front++;
    }
}

int peak()
{
     if ((rear==-1 && front==-1) || front > rear) 
    {
        cout<<"queue is empty \n";
        return -1;
    }
    else
    {
        return queue [front];
    }
}
 
void display ()
{
     if ((rear==-1 && front==-1) || front > rear) 
    {
        cout<<"queue is empty \n";
        
    }
    else
    {
        for (int i =front; i<=rear; i++)
        {
            cout<< queue [i]<<"\t";
        }
    }
    cout<<endl;
}


void enqueue_circular(int value)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        cout << "Queue is full\n";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear ++;
        if (rear == size)
        {
            rear = 0;
        }
        queue[rear] = value;
    }
}

void dequeue_circular()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front ++;
            if (front == size)
            {
                front = 0;
            }
        }
    }
}

void display_circular()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << "\t";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << queue[i] << "\t";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << "\t";
            }
        }
        cout << endl;
    }
}


//! implementation of queue by linked list
struct node   
{
    int data;
    node * next; 
};

node * head =NULL;
node* front_linkedlist=NULL;
node* rear_linkedlist=NULL;

void enqueue_linkedlist(int value)
{
    node*new_node = new node;
    new_node->data=value;
    new_node->next=NULL;
    if(front_linkedlist==NULL) //if it first node
    {
        front_linkedlist= rear_linkedlist=new_node;
    }
    else
    {
        rear_linkedlist->next =new_node;
        rear_linkedlist=new_node;
    }
   
}

void dequeue_linkedlist()
{
    if (front_linkedlist==NULL)
    {
        cout<<"this queue is empty \n";
    }
    else if(rear_linkedlist==front_linkedlist)
    {
        node* first_node = front_linkedlist;
        front_linkedlist= rear_linkedlist=NULL;
        free(first_node);
    }
    else
    {

        node* first_node = front_linkedlist;
        front_linkedlist = first_node->next;
        free(first_node);
    }
}
   
int peak_linkedlist()
{
    if (front_linkedlist==NULL)
    {
        cout<<"queue is empty\n";
        return-1;
    }
    else
    {
        return front_linkedlist->data;
    }
}

void display_linkedlist()  
{
    if(front_linkedlist==NULL) 
    {
        cout<<"it is empty queue\n ";
    }
    else 
    {
        node* current_node =front_linkedlist;
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
    /*enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    dequeue();
    display();
    cout<<peak()<<" =peak \n";*/

    /*cout<<"here queue circular\n";
    enqueue_circular(5);
    enqueue_circular(15);
    enqueue_circular(25);
    display_circular();
    dequeue_circular();
    display_circular();*/

    cout<<"here queue by linked list\n";
    enqueue_linkedlist(5);
    enqueue_linkedlist(15);
    enqueue_linkedlist(25);
    display_linkedlist();
    dequeue_linkedlist();
    display_linkedlist();
    cout<<peak_linkedlist()<<" =peak  \n";

    return(0);
}
