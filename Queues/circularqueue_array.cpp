#include<iostream>
#define MAX 10
using namespace std;

typedef struct queue_array
{
    int front, rear;
    int data[MAX];
}queue;

//FUNCTIONS USED
void create(queue*);
int isempty(queue*);
int isfull(queue*);
void enqueue(queue*, int);
int dequeue(queue*);
int peek(queue*);
void display(queue*);

//main program driver
int main()
{
    queue Q;         // variabe of struct queue created
    create(&Q);
    //MENU driven program
    cout<<"\nenter ur choice : ";
    cout<<"\n 1. enqueue  \n 2. Dequeue    \n 3. Display  \n 4. Peek \n 5. Exit   \n";

    while(1){
        int choice,var;
        cin>>choice;     //enter function to  perform
        cout<<endl;
        switch(choice)
        {
            case 1: int item;
                    cout<<"element : ";cin>>item;
                    enqueue(&Q , item);   // item is added in queue
                    break;
            case 2: var = dequeue(&Q);    // dequeue performed
                    if(var == -2)         // if list is empty
                        break;
                    else
                        cout<<var<<" deleted...\n";   // deletion succesfull if queue is not empty
                    break;
            case 3: display(&Q);    // display queue if not empty
                    break;
            case 4: var = peek(&Q);  // returns front element of the queue
                    if(var == -2)
                        break;         // if list is empty then break
                    else
                        cout<<var<<" is at front\n";
                    break;
            case 5: exit(0);
                    break;
            default: cout<<"Invalid Input ! ";   // leaves the program if invlaid input is entered
                    return 1;
        }
    }

    return 0;
}
 // main ends

void create(queue* q)
{
    q->front = q->rear = -1;  // initializes the variables front and rear of array to -1 i.e. the sentinel value
    cout<<"\n Queue created !";
}
int isempty(queue* q) // returns 1 if list is empty and returns 0 if list contains atleast one element
{
    if(q->front == -1)
        return 1;
    else
        return 0;
}

int isfull(queue* q)
{
    // retuns 1 if queue does not contain any space left to be filled  otherwise returns 0
    if( ( (q->front == 0) && (q->rear == MAX-1) ) || (q->front == q->rear + 1) )
        return 1;
    else
        return 0;
}
void enqueue(queue* q, int x)
{
    if(isfull(q) == 1){ // checks for empty space
        cout<<"\n queue overflow !";
        return ;
    }
    else if(q->front == -1)   // if queue is empty then after equeue operation both front and rear will be same
        q->front = q->rear = 0;
    else if(q->rear == MAX -1)  // if rear is filled at MAX but contains space in beginning indices of array
        q->rear = 0;
    else
        q->rear++;      // normal enqueue operation
    q->data[q->rear] = x; // x is the input element
}
int dequeue(queue* q)
{
    int temp = -2;
    if(isempty(q) == 1)
    {   // checks for empty queue
        cout<<"\n queue is empty !";
        return temp;  // queue is empty
    }
    temp = q->data[q->front];  // stores the data value of front element

    if(q->front == q->rear) // if queue contains single element
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;  // for normal dequeue operation  OR when rear < front
    return temp;
}

int peek(queue* q)
{
    if(isempty(q) == 1)
        {
        cout<<"\n queue is empty !";
        return -2;
        }
    return q->data[q->front];   // returns the front element of queue
}
void display(queue* q)
{
    if(isempty(q) == 1){
        cout<<"\n Queue is empty !";
        return;
    }
    int i=0;
    cout<<"\nQUEUE : ";
    if(q->rear < q->front) // case when queue is like 10,2,4, , , ,10,20,40,6  i.e. front: 6, rear:2  (rear<front)
    {
        for(i=0 ; i<= q->rear ; i++)
            cout<<q->data[i]<<" ";
        while(i<q->front)    // when no element is present at middle indices
            {
                cout<<"__ ";
                i++;
            }
        for(i=q->front ; i<MAX ; i++)
            cout<<q->data[i]<<" ";
    }
    else
    {        // when front > rear
        for(i=0; i < q->front ; i++)
            cout<<"__ ";
        while(i<= q->rear)
            {
                cout<<q->data[i]<<" ";
                i++;
            }
    }
    cout<<"front :"<<q->front<<" rear :"<<q->rear<<endl;
}
