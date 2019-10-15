#include<iostream>
#define MAX 10
using namespace std;

typedef struct stak
{
    int top;
    int data[MAX];
}stacks;

stacks create(stacks);
int isempty( stacks*);
int isfull( stacks*);
stacks push( stacks );
void pop(stacks*);
void display(stacks);

int main()
{
    stacks s=create(s);
    stacks S= create(S);
    cout<<"\nenter ur choice : ";
    cout<<"\n 1. Push  \n 2. Pop    \n 3. Display  \n 4. Exit   \n";

    while(1){
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1: s=push(s);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(s);
                    break;
            case 4: exit(0);
                    break;
            default: cout<<"Invalid Input ! ";
                    return 1;
        }
    }
    return 0;
}

stacks create(stacks s)
{
    s.top=-1;
    cout<<"\nSTACK CREATED SUCCESSFULLY !\n";
    return s;
}
int isempty( stacks* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
int isfull( stacks* s)
{
    if(s->top == MAX-1)
        return 1;
    return 0;
}
stacks push( stacks s)
{
    int var = isfull(&s);
    if(var == 1){
        cout<<"\n stack is full ! \n process terminated... ";
        return s;
    }
    cout<<"\nenter element to be pushed :";
    int item;cin>>item;
    s.data[++(s.top)]=item;
    return s;
}
void pop(stacks* s)
{
    int var = isempty(s);
    if(var == 1){
        cout<<"\n stack is empty ! \n process terminated... ";
        return ;
    }
    cout<<endl;
    cout<<s->data[(s->top)--]<<" is popped from stack. ";
    return ;
}
void display(stacks s)
{
    cout<<"STACK : ";
    for(int i=0;i<=(s.top);i++)
    {
        cout<<s.data[i]<<"  ";
    }
    cout<<"END ["<<s.top<<"]"<<endl;
}
