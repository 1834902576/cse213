#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node
{
    int data;
    node *next;
    node *prev;
};
node *head=NULL;
node *head_2=NULL;
node *list=NULL;
node *list1=NULL;
node *list2=NULL;
void menu();
node* create_list();
node* create_list_2();
void Insert_At();
void delete_front();
node* merge_list(node *list1, node *list2);
node* print_reverse(node *list);
void display(node *temp);
int main()
{
    head = create_list();
    head_2 = create_list_2();
    menu();
    return 0;
}
void menu()
{
    int choice;
    do
    {
        system("cls");
        printf("Double Way Linked List");
        printf("\n1. Insert At\n");
        printf("2. Delete Front\n");
        printf("3. Copy Recursively\n");
        printf("4. Merge Two List\n");
        printf("5. Display Reverse\n");
        printf("6. Display\n");
        printf("7. Close\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        if(choice==1)
        {
            printf("List: ");
            display(head);
            Insert_At();
            getchar();
            printf("\nPress Enter to Continue");
            getchar();
        }
        else if(choice==2)
        {
            delete_front();
            getchar();
            printf("\nPress Enter to Continue");
            getchar();
        }
        else if(choice==3)
        {
            getchar();
            printf("\nPress Enter to Continue");
            getchar();
        }
        else if(choice==4)
        {
            list1 = head;
            list2 = head_2;
            list = merge_list(list1, list2);
            printf("\nAfter Merge Two List: ");
            display(list);
            getchar();
            printf("\nPress Enter to Continue");
            getchar();
        }
        else if(choice==5)
        {
            printf("List: ");
            display(head);
            head = print_reverse(head);
            printf("\nReverse List: ");
            display(head);
            getchar();
            printf("\nPress Enter to Continue");
            getchar();
        }
        else if(choice==6)
        {
            printf("List: ");
            display(head);
            getchar();
            printf("\nPress Enter to Continue");
            getchar();
        }
        else if (choice == 7)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid Option, Please Option Between '1 to 7'");
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
    }
    while(choice!=7);
}
node* create_list()
{
    node *a, *b, *c, *d;
    a = (node *) malloc(sizeof(node));
    b = (node *) malloc(sizeof(node));
    c = (node *) malloc(sizeof(node));
    d = (node *) malloc(sizeof(node));
    a->data = 101;
    a->next = b;
    b->data = 102;
    b->next = c;
    c->data = 103;
    c->next = d;
    d->data = 104;
    d->next = NULL;
    return a;
}
node* create_list_2()
{
    node *a, *b, *c, *d;
    a = (node *) malloc(sizeof(node));
    b = (node *) malloc(sizeof(node));
    c = (node *) malloc(sizeof(node));
    d = (node *) malloc(sizeof(node));
    a->data = 10;
    a->next = b;
    b->data = 15;
    b->next = c;
    c->data = 20;
    c->next = d;
    d->data = 25;
    d->next = NULL;
    return a;
}
void Insert_At()
{
   node *ptr, *temp;
   int item, index, i;
   ptr = (node *) malloc(sizeof(node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW");
   }
   else
   {
       temp=head;
       printf("\nEnter the Index: ");
       scanf("%d",&index);
       for(i=0;i<index;i++)
       {
           temp = temp->next;
           if(temp == NULL)
           {
               printf("\n There are less than %d elements: ", index);
               return;
           }
       }
       printf("Enter value: ");
       scanf("%d",&item);
       ptr->data = item;
       ptr->next = temp->next;
       ptr -> prev = temp;
       temp->next = ptr;
       temp->next->prev=ptr;
       printf("\nnode inserted\n");
   }
}
void delete_front()
{
    node *new_node;
    if(head == NULL)
    {
        printf("UNDERFLOW");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("Node Deleted\n");
    }
    else
    {
        new_node = head;
        head = head -> next;
        head -> prev = NULL;
        free(new_node);
        printf("Node Deleted\n");
    }
}
node* merge_list(node *list1, node *list2)
{
    node *head, *temp;
    head = list1;
    while(list1->next)
    {
        list1 = list1->next;
    }
    list1->next = list2;
    return head;
}
node* print_reverse(node *list)
{
    node *first, *current, *temp;
    first = list;
    current = list->next;
    first->next = NULL;
    while(current)
    {
        temp = current->next;
        current->next = first;
        first = current;
        current = temp;
    }
    return first;
}
void display(node *temp)
{
    node *new_node;
    new_node = head;
    if(new_node==NULL)
    {
        printf("EMPTY\n");
    }
    while(new_node != NULL)
    {
        printf("%d ",new_node->data);
        new_node=new_node->next;
    }
}
