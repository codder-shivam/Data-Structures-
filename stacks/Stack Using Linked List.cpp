
#include<iostream>
using namespace std;

typedef struct nodetype
{
    int data;
    struct nodetype* next;
}stack;

stack* create(stack*);
int isempty(stack*);
void push(stack** , int);
int pop(stack**);
void display(stack*);
void dispose(stack**);


int main()
{
    stack* top = create(top);
    cout<<"\nenter ur choice : ";
    cout<<"\n 1. Push  \n 2. Pop    \n 3. Display  \n 4. Exit   \n 5. IsEmpty ? \n";
    int flag=1;
    while(flag){
        int choice,item;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\nenter element: ";cin>>item;
                    push(&top,item);
                    break;
            case 2: cout<<pop(&top)<<endl;
                    break;
            case 3: display(top);
                    break;
            case 4: exit(0);
            case 5: (isempty(top))?cout<<"stack is empty! \n":cout<<"stack is not empty !\n";
                    break;
            default: cout<<"Invalid Input ! ";
                     flag=0;   break;
        }
    }
    return 0;
}

stack* create(stack* top)
{
    top=NULL;
    cout<<"\nSTACK CREATED SUCCESSFULLY !\n";
}
int isempty(stack* root)
{
        return !root;
}

void push( stack** top, int item)
{
    stack* temp = new stack();
    if(temp == NULL){
        cout<<"\n memory not allocated! \n process terminated... ";
        return ;
    }
    temp->data=item;
    temp->next=*top;
    *top = temp;
}
int pop(stack** top)
{
    int temp=0;
    if(isempty(*top))
    {
        cout<<"\n stack is empty ! \n process terminated... ";
        return temp;
    }
    temp = (*top)->data;
    stack* node = *top;
    *top = (*top)->next;
    delete(node);
    cout<<" \nitem popped :";
    return temp;
}
void display(stack* top)
{
    cout<<"STACK : ";
    while(!isempty)
    {
        cout<<top->data<<"  ";
        top=top->next;
    }
    cout<<"END"<<endl;
}
