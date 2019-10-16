#include<iostream>
#define MAX 10
using namespace std;

typedef struct array_queue
{
    int front, rear;
    int elements[MAX];
} queue;

void create( queue*);
int isempty(queue*);
int isfull(queue*);
void enqueue(queue*, int);
int dequeue(queue*);
int peek(queue);
void display(queue*);

int main()
{
    queue Q;
    create(&Q);
    cout<<"\nenter ur choice : ";
    cout<<"\n 1. enqueue  \n 2. Dequeue    \n 3. Display  \n 4. Peek \n 5. Exit   \n";

    while(1){
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1: int item;
                    cout<<"element : ";cin>>item;
                    enqueue(&Q , item);
                    break;
            case 2: if(dequeue(&Q) == 0)
                        cout<<"queue is empty!\n";
                    else
                        cout<<dequeue(&Q)<<"deleted...\n";
                    break;
            case 3: display(&Q);
                    break;
            case 4: if(peek(Q) == -1)cout<<"queue is empty\n";
                    else
                        cout<<peek(Q)<<"is at front\n";
                    break;
            case 5: exit(0);
                    break;
            default: cout<<"Invalid Input ! ";
                    return 1;
        }
    }

    return 0;
}

void create( queue* q)
{
    q->front = q->rear = -1;
    cout<<"Queue created successfully !!!\n";
}

int isempty(queue* q)
{
    int temp = 1;
    if( (q->front == -1) )
        return temp;
    return !temp;
}
int isfull(queue* q)
{
    int temp = 1;
    if( (q->front == 0) && (q->rear == MAX-1) )
        return temp;
    return !temp;
}
void enqueue(queue* q, int item)
{
    if(isfull(q) == 1){cout<<"no more space \n";return ;}
    if(isempty(q) == 1)
    {
        q->front = q->rear = 0;
    }
    else if(q->rear == MAX-1){
        for(int i=q->front;i <= q->rear;i++)
            q->elements[i-q->front] = q->elements[i];
        q->rear = q->rear - q->front + 1;
        q->front=0;
    }
    else
        q->rear++ ;
    q->elements[q->rear] = item;
}
int dequeue(queue*q)
{
    if(isempty(q) == 1)
        return 0;
    int temp = q->elements[(q->front)];
    if(q->front == q->rear )
        q->rear = q->front = -1;
    else
        q->front++;
    return temp;
}
int peek(queue q)
{
    if(isempty(&q) == 1)
        return -1;
    else
        return q.elements[q.front];
}
void display(queue *q)
{
    if(isempty(q) == 1)
    {
        cout<<"queue is empty !\n";
        return;
    }
    int i=0;
    cout<<"queue : ";
    while(i<q->front)
    {
        cout<<"__ ";
        i++ ;
    }
    for(i=q->front;i <= q->rear;i++)
        cout<<q->elements[i]<<" ";

    cout<<endl<<"Front:"<<q->front<<" Rear:"<<q->rear<<endl;
}
