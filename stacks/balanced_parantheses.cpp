#include <iostream>
#include<string.h>
using namespace std;

typedef struct stackNode
{
    char data;
    struct stackNode* next;
}stack;
stack* top=NULL;

stack* create(stack*);
void display(stack*);
void push(stack** , char);
bool isempty(stack*);
char compare(char);
char pop(stack**);
void dispose(stack**);

int main() {
    int t;
    cin>>t;
    while(t--){
        string expr;
        cin>>expr;
        stack* top=create(top);
        int len=expr.size();
        for(int i=0;i<len;i++)
        {
            if( (expr[i] == '[') || (expr[i] == '{') || (expr[i] =='(') )
            {
                push(&top,expr[i]);
            }
            else
            {
                if(isempty(top))
                {
                    dispose(&top);
                    cout<<"not balanced\n";
                    break;
                }
                else
                {
                    char temp=pop(&top);
                    char var=compare(expr[i]);
                    if(temp != var)
                    {
                        cout<<"not balanced\n";
                        dispose(&top);
                        break;
                    }
                }
            }
        }
        if(!isempty(top))
        {
            cout<<"not balanced\n";
            dispose(&top);
            return 0;
        }
        else
            cout<<"balanced\n";
    }
	return 0;
}
void display(stack* top)
{
    stack*temp=top;
    while(temp!=NULL)
        cout<<temp->data<<"->";
    cout<<"END\n";

}
void dispose(stack** top)
{
    stack* temp;
    while(*top!=NULL)
    {
        temp=*top;
        *top=(*top)->next;
        delete(temp);
    }
}
stack* create(stack* top)
{
    top=NULL;
    return top;
}
void push(stack** top, char c)
{
    stack* temp= new stack();
    if(temp==NULL)
        exit(0);
    temp->data=c;
    temp->next=*top;
    *top=temp;
}
bool isempty(stack* top)
{
    if(top==NULL)
        return true;
    return false;
}
char compare(char c)
{
    char local;
    switch(c){
        case ')' : local='(';
                    break;
        case '}' : local='{';
                    break;
        case ']' : local='[';
                    break;
        default: cout<<"not balanced\n";
                    exit(0);
    }
    return local;
}
char pop(stack** top)
{
    char local = (*top)->data;
    stack* temp= *top;
    *top = (*top)->next;
    delete(temp);
    return local;
}





