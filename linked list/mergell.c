#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
} *s1 = NULL, *s2 = NULL, *s3 = NULL;

struct node* create(struct node *start, int x)
{
     struct node *newnode, *t;
     newnode = (struct node *)(malloc(sizeof(struct node)));
     newnode->data = x;
     newnode->next =NULL;

     t = start;
     if (start == NULL || start->data < x)
     {
          newnode->next = start;
          start = newnode;
          return start;
     }

     while (t->next != NULL && t->next->data > x)
     {
        t=t->next;
     }  newnode->next = t->next;
          t->next = newnode;


          return start;
}

void merge(struct node *s1, struct node *s2, struct node **s3){


*s3=NULL;

      if (s1 == NULL)
    {
        *s3 = s2;
        return;
    }
    else if (s2 == NULL)
    {
        *s3 = s1;
        return;
    }
     
     struct node *t1, *t2;
     t1 = s1, t2 = s2;

     while (t1!=NULL && t2!=NULL)
     {

          if (t1->data > t2->data)
          {
               *s3=create(*s3, t1->data);
               t1 = t1->next;
          }
          else if (t1->data < t2->data)
          {
               *s3=create(*s3, t2->data);
               t2 = t2->next;
          }
          else
          {
               *s3=create(*s3, t1->data);
               t1 = t1->next;
               t2 = t2->next;
          }
     }

     while (t1!= NULL)
     {
          *s3=create(*s3, t1->data);
          t1 = t1->next;
     }

     while (t2!= NULL)
     {
          *s3=create(*s3, t2->data);
          t2 = t2->next;
     }

     
}

void display(struct node *start)
{
     struct node *t = start;
     if (start == NULL)
     {
          printf("\nList emtpty");
          return;
     }
     while (t != NULL)
     {
          printf("\t %d", t->data);
          t = t->next;
     }
}

int main()
{

     int choice = 1;
     while (choice)
     {
          printf("\n1.Enter in first linked list\n2.Enter in second linked list\n3.Merge first two\n4.Display\n5.Enter your choice: ");
          scanf("%d", &choice);

          switch (choice)
          {

          case 1:
               printf("\nEnter the element: ");
               int el;
               scanf("%d", &el);
              s1=create(s1, el);
               break;
          case 2:
               printf("\nEnter the element: ");
               int ele;
               scanf("%d", &ele);
              s2=create(s2, ele);
               break;

          case 3:
               merge(s1, s2, &s3);
               printf("\nMerge successful");
               break;
          case 4:
               printf("\nEnter the list you want to print 1,2 or 3: ");
               int list;
               scanf("%d", &list);
               switch (list)
               {
               case 1:
                    display(s1);
                    break;
               case 2:
                    display(s2);
                    break;
               case 3:
                    display(s3);
                    break;

               default:
                    printf("\nWrong choice");
               }
               break;

          case 5:
               printf("\nExitting program");
               exit(0);

          default:
               printf("\nEnter valid choice!");
          }
     }

     return 0;
}