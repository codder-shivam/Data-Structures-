#include<iostream>
using namespace std;

typedef struct NODE
{
  struct NODE* prev;
  int data;
  struct NODE* next;
}node;
node *head, *tail;

void create(node**, node**, int );
void display( node* );
void display_rev( node* );
int search(node* , int );
void insert_loc( node** , node** );

int main()
{
    cout<<"\nEnter size of list :";
    int n;cin>>n;
    create(&head, &tail, n);
    display(head);
    display_rev(tail);
    cout<<"\nhead ="<<head<<"  tail="<<tail;
    //int item;
    //cout<<"\n enter item for search :";cin>>item;
    //cout<<"element is present at location "<<search(head,item);
    insert_loc(&head,&tail);
    display(head);
    display_rev(tail);
    cout<<endl;
    return 0;
}

void create(node** head, node** tail, int n)
{
  node*temp=NULL;
  cout<<"\n enter data for "<<n<<" nodes :\n";
  for(int i=0;i<n;i++)
  {
    temp= new node();
    cin>>temp->data;
    if(*head == NULL)
    {
      *head=temp;
      temp->prev=NULL;
      temp->next=NULL;
    }
    else{
      node* ptr = *head;
      while(ptr->next != NULL)
        ptr=ptr->next;
      ptr->next = temp;
      temp->prev = ptr;
      temp->next = NULL;
    }
    *tail=temp;
  }
  return;
}

void display(node* temp)
{
    while(temp!=NULL){
        cout<<temp->data<<" -->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void display_rev(node* temp)
{
    while(temp!=NULL){
        cout<<temp->data<<" -->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}

void insert_loc(node** head, node** tail)
{
  if(*head == NULL)return;
  int element,item;
  cout<<"\n enter element to insert : ";cin>>element;
  cout<<"\n enter item after which to insert : ";cin>>item;
  int loc=search(*head,item);
  node* temp= *head;
  if(loc==0){
    temp=*tail;
  //  while(temp->next!=NULL)
    //  temp=temp->next;
  }
  for(int i=1;i<loc;i++){
    temp=temp->next;
  }
  node *alpha= new node();
  alpha->data=element;
  alpha->next=temp->next;
  if(temp->next != NULL)
    (temp->next)->prev=alpha;
  else
    *tail=alpha;
  temp->next=alpha;
  alpha->prev=temp;
}

int search(node* temp , int item )
{
  if(temp==NULL)
    return 0;
  int loc,count;
  while(temp!= NULL){
    count++;
    if(temp->data == item)
      {loc=count; break;}
    temp=temp->next;
  }
  return loc;
}
