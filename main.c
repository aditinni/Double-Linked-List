#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}*first=NULL;
int A[10];

void create(int A[], int n)
{
    struct Node *t,*last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev = last;
        last->next=t;
        last=t;
    }

}
void Search(struct Node *p,int key)
{


        if(p->data==key)
        {
            printf("The element founded is %d \n",p->data);
        }
        else
        {
            printf("Element not found!");
        }


}
void insertatbeg(struct Node *p, int x)
{
    if(p==NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        struct Node *t =(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
        printf("Element inserted %d \n",x);
    }
}

void insertatpos(struct Node *p, int pos, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int i;
    for(i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    if(p->next)
    {
    t->data=x;
    t->next=p->next;
    p->next->prev=t;
    t->prev=p;
    p->next=t;
    }

}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("element %d \n",p->data);
        p=p->next;
    }

}
 void deleteatbeg(struct Node *p)
    {
        int x = p->data;
        p->next->prev=NULL;
        first=first->next;
        free(p);
    }
void deleteatpos(struct Node *p, int pos)
{
    int x;
    int i;
    for(i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    x= p->data;
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
}



void main()
{
   int ch;
   int n,i;
   int pos;
   int key;

   int y,x;
   do
   {
       printf("1.create DLL\n 2.Display\n 3.find element\n 4.Insert at beg\n 5.insert at a position\n 6.delete at begining\n 7.delete at pos\n 8.exit\n");
       printf("Enter your choice \n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:

           printf("Enter the no. of elements \n");
           scanf("%d",&n);
           printf("Enter the element \n");
           for(i=0;i<n;i++)
           {
               scanf("%d",&A[i]);
           }
           create(A,n);
           break;

           case 2:
           Display(first);
           break;
           case 3:

           printf("Enter the element to search \n");
           scanf("%d",&key);
           Search(first,key);
           break;

           case 4:

           printf("Enter the element to insert \n");
           scanf("%d",&x);
           insertatbeg(first,x);
           break;
           case 5:
           printf("Enter the position to enter \n");
           scanf("%d",&pos);
           printf("Enter the element to insert \n");
           scanf("%d",&y);
           insertatpos(first,pos,y);
           break;

           case 6:
            deleteatbeg(first);
            printf("Element is deleted display the list \n");
            break;
            case 7:

            printf("Enter the position \n");
            scanf("%d",&pos);
            deleteatpos(first,pos);
           break;



            case 8:
             printf("Enter 0 to exit \n");
           scanf("%d",&ch);

           break;


       }
   }while(ch!=0);

}
