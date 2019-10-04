#include<iostream>
using namespace std;
typedef struct Node
{
  int data;
  struct Node* link;
}node;

//node* del_end(node* );
node* create_n(int n);
void display( node* );
node* reverse(node* );

int main()
{
  node*head=NULL;
  cout<<"\nenter no. of nodes : ";
  int n;
  cin>>n;
  cout<<"enter data for "<<n<<" nodes :";
  head=create_n(n);
  display(head);
  cout<<"\nhead :"<<head;
  //head=del_end(head);
  head=reverse(head);
  display(head);
  cout<<"\nhead :"<<head;

  return 0;
}

//display function
void display(node* head)
{
    node* temp=head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" -->";
        temp=temp->link;
    }
    cout<<"NULL"<<endl;
}
//create n nodes taking n as input from user
node* create_n(int n)
{
    node *head=NULL, *temp=NULL, *ptr=NULL;
    for(int i=0;i<n;i++){
        temp = new node();
        cin>>temp->data;
        temp->link=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            ptr=head;
            while(ptr->link != NULL)
                ptr=ptr->link;
            ptr->link=temp;
        }
    }
    return head;
}
//function to reverse a linklist

node* reverse(node* head)
{
  node *prev, *curr , *next ;
  prev =NULL;
  curr=head;
  if(curr==NULL)
    return curr;
  else if(curr->link == NULL)
    return curr;
  else{
    next = curr->link;
    curr->link = NULL;
    while(next!=NULL){
      prev =curr;
      curr=next;
      next=next->link;
      curr->link=prev;
    }

  }
  return curr;
}

//function to delete node at end
node *del_end(node* head )
{
  node *ptr,*prev=NULL;
  ptr=head;
  if(ptr==NULL)
  return ptr;
  else if(ptr->link==NULL)
  return ptr;
  else{
    while(ptr->link!=NULL){
      prev=ptr;
      ptr=ptr->link;
    }
    prev->link=NULL;
    delete ptr;
    return head;
  }
}
