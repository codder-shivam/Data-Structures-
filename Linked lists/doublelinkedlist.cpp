#include<iostream>
using namespace std;

//userdefined data type i.e. a data type NODE is created 
typedef struct NODE
{
  struct NODE* prev;
  int data;
  struct NODE* next;
}node;
//global pointers head and tail
node *head, *tail;

void create(node**, node**, int );        // function to add new nodes in list 
void display( node* );                    // function to display the list created
void display_rev( node* );                // function to display in reverse direction using tail pointer
int search(node* , int );                 // function to search for any input element and to return its location in the list 
void insert_loc( node** , node** );       // function to insert new node in list at a location given by user

int main()
{
    cout<<"\nEnter size of list :";
    int n;cin>>n;
    create(&head, &tail, n);
    display(head);
    display_rev(tail);
    cout<<"\nhead ="<<head<<"  tail="<<tail;
    // item is the element to be searched oin list
    int item;
    cout<<"\n enter item for search :";cin>>item;
    cout<<"element is present at location "<<search(head,item);
    insert_loc(&head,&tail);
    display(head);
    display_rev(tail);
    cout<<endl;
    return 0;
}

 // FUNCTION DEFINITIONS

void create(node** head, node** tail, int n)  // value of head and tail pointer is passed htrough reference
{
  node*temp=NULL;
  // enter size of list to be created
  cout<<"\n enter data for "<<n<<" nodes :\n";
  for(int i=0;i<n;i++)
  {
    temp= new node();
    cin>>temp->data;
    if(*head == NULL)  // if list is empty
    {
      *head=temp;
      temp->prev=NULL;
      temp->next=NULL;
    }
    // atleast one node is ctreated till this point
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

//  insert function inserts "element" in list at position next to the location of "item" in list
void insert_loc(node** head, node** tail)
{
  if(*head == NULL)return;
  int element,item;
  cout<<"\n enter element to insert : ";cin>>element;
  cout<<"\n enter item after which to insert : ";cin>>item;
  int loc=search(*head,item);
  node* temp= *head;
  if(loc==0){                 // if list is empty
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

// search function finds the locatin of "item" in list
// it returns an integer value i.e. '0' if element is not found and 'n' (1 to size) if found 
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
