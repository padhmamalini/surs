#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node *next;
}node;

struct node *createNewNode(int data)
{
  struct node * new = (struct node*)malloc (sizeof(struct node));
  if(NULL == new)
    {
      printf("Malloc failed\n");
      return;
    }
  new->data = data;
  new->next = NULL;
  return new;
}

void insertatBeginning(struct node **head, int data)
{
 
  struct node * new = createNewNode(data); 
  if((*head) == NULL)
  {
    *head = new;
    return;
  }
  else 
  {
     new->next = *head;  
     *head = new;
  }  

}

void insertatEnd(struct node **head, int data)
{
  struct node *temp = NULL;
  struct node * new = createNewNode(data); 
  if((*head) == NULL)
  {
    *head = new;
  }
  else 
  {
    temp = *head;
    while(temp->next != NULL)
      temp = temp->next;

    temp->next = new;  
  }  

}

void insertatPos(struct node **head, int data, int pos)
{
  struct node *temp = NULL;
  struct node * new = createNewNode(data); 
  if((*head) == NULL)
  {
    printf("List is empty, inserted at beginning\n");
    *head = new;
  }
  else 
  {
    temp = *head;
    int i = 0;
    for (i = 1; i < pos-1; i++)
    {
      if(temp->next != NULL)
      temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
  }  

}

void delatBeginning(struct node ** head)
{
   if ((*head) == NULL)
   {
     printf("List is empty\n");
     return;
   }

   if((*head)->next == NULL)
   {
     *head = NULL;
     printf("Deleted 1 entry, List is empty now\n");
     return;
   }
   struct node * temp = *head;   
   (*head) = temp->next;
   free (temp);

}

void delatEnd(struct node ** head)
{
   if ((*head) == NULL)
   {
     printf("List is empty\n");
     return;
   }

   if((*head)->next == NULL)
   {
     *head = NULL;
     printf("Deleted 1 entry, List is empty now\n");
     return;
   }
   struct node * temp = *head;
   while(temp->next->next !=NULL )
     temp = temp->next;

   free(temp->next);
   temp->next = NULL;
    
}

void delatPos(struct node ** head, int pos)
{
   if ((*head) == NULL)
   {
     printf("List is empty\n");
     return;
   }

   if((*head)->next == NULL)
   {
     *head = NULL;
     printf("Deleted 1 entry, List is empty now\n");
     return;
   }
   struct node * temp = *head;
   int i = 0;
   for (i = 1; (i < pos-1) && temp!= NULL; i++)
   {
     if(temp->next != NULL)
     temp = temp->next;
   }

   if (temp == NULL || temp->next == NULL)
   {
     printf("Reached end\n");
     return;
   }

   struct node *next = temp->next->next;
   free(temp->next);
   temp->next = next;
}

void delElement(struct node ** head, int data)
{
   if ((*head) == NULL)
   {
     printf("List is empty\n");
     return;
   }

   struct node *temp = *head;
   struct node *prev = *head;
   if(temp!= NULL && temp->data == data)
   {
       printf("Element found\n");
       *head = temp->next;
       free(temp);
       return;
   }

   while(temp != NULL && temp->data != data)
   { 
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL)
   {
     printf("Element not found\n");
     return;
   }

   prev->next = temp->next;
   printf("Deleted %d\n", temp->data);
   free(temp);
}

void delAllOccur(struct node ** head, int data)
{
   if ((*head) == NULL)
   {
     printf("List is empty\n");
     return;
   }

   struct node *temp = *head;
   struct node *prev;
   while(temp!= NULL && temp->data == data)
   {
       printf("Element found\n");
       *head = temp->next;
       free(temp);
       temp = *head;
   }
   
   while(temp != NULL)
   {
     while(temp != NULL && temp->data != data)
     { 
        prev = temp;
        temp = temp->next;
     }

     if (temp == NULL)
     {
       printf("Element not found\n");
       return;
     }

     prev->next = temp->next;
     printf("Deleted %d\n", temp->data);
     free(temp);
     temp = prev->next;
   }
}

void delDuplicates(struct node ** head)
{
   if ((*head) == NULL)
   {
     printf("List is empty\n");
     return;
   }

   struct node * ptr1, *ptr2, *dup;
   ptr1 = *head;

   while(ptr1 != NULL && ptr1->next != NULL)
   {
     ptr2 = ptr1;

     while(ptr2->next != NULL)
     {
       if(ptr1->data == ptr2->next->data)
       {
         dup = ptr2->next;
         ptr2->next = ptr2->next->next;
         free(dup);
       }

       else
       {
         ptr2 = ptr2->next;
       }

     }
     ptr1 =  ptr1->next;
   }
}

void display(struct node *head)
{
  struct node *temp = head;
    printf("LIST:\n====\n");
  if(head == NULL)
    printf("EMPTY LIST\n");
  while (temp !=NULL)
  {
    printf("->%d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void reverseList(struct node **head)
{
  struct node *curr = *head; 
  struct node *prev = NULL;
  struct node *next = NULL;

  while(curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}


int main()
{
  struct node *head = NULL;
  int choice;
  int data;
  int pos;
  while (1)
  {
  printf("1. Insert at the beginning\n"); 
  printf("2. Insert at the end\n"); 
  printf("3. Insert at the given position\n"); 
  printf("4. Delete the first node \n"); 
  printf("5. Delete the last node \n"); 
  printf("6. Delete the node at the given position\n"); 
  printf("7. Delete the given element\n"); 
  printf("8. Delete all the occurences of the given element\n"); 
  printf("9. Display\n"); 
  printf("10. Quit\n"); 
  printf("11. Delete duplicates\n"); 
  printf("12. Reverse List\n"); 
  printf("Enter your choice:\n");
  scanf("%d", &choice);
  switch (choice)
  {
    case 1:
      printf("Enter the data\n");
      scanf("%d", &data);
      insertatBeginning(&head, data); 
      break;

    case 2:
      printf("Enter the data\n");
      scanf("%d", &data);
      insertatEnd(&head, data); 
      break;

    case 3:
      printf("Enter the data and pos\n");
      scanf("%d %d", &data, &pos);
      insertatPos(&head, data, pos);
      break;

    case 4:
      printf("Deleting first node\n");
      delatBeginning(&head);
      break;

    case 5:
      printf("Deleting last node\n");
      delatEnd(&head);
      break;

    case 6:
      printf("Enter the pos\n");
      scanf("%d", &pos);
      delatPos(&head, pos);
      break;

    case 7:
      printf("Enter the element to be deleted\n");
      scanf("%d", &data);
      delElement(&head, data);
      break;

    case 8:
      printf("Enter the element to be deleted\n");
      scanf("%d", &data);
      delAllOccur(&head, data);
      break;

    case 9:
      display(head);
      break;
    case 10:
      printf("The list is \n");
      display(head);
      exit(0);
      break;
      
    case 11:
      delDuplicates(&head);
      break;

    case 12:
      reverseList(&head);
      break;

  }
  }
  
  return 0;
}
