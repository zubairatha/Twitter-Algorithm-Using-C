#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct btnode
{
    char value[MAX];
    struct btnode *l;
    struct btnode *r;
}*temp=NULL,*t1;
 
struct btnode *root = NULL;
int flag;

struct btnode* newnode(char *value)
{
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    strcpy(temp->value,value);
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

void printPreorder(struct btnode* node, int n)
{
    if (node == NULL)
        return;
    for(int i=0;i<n;i++)
    printf("-");

    printf("%s\n", node->value);
    printPreorder(node->l, n+1);
    printPreorder(node->r, n);
}

void printSiblings(struct btnode* node)
{
    int i=1;
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp=node;
    if (temp == NULL)
        return;
    printf("\nChoose the tweet you want to reply to.\n");
    printf("%d.%s\n",i,temp->value);
    i=i+1;
    temp=temp->r;
    while(temp!=NULL)
    {
        printf("%d.%s\n",i,temp->value);
        i=i+1;
        temp=temp->r;
    }
}

void findTweet(struct btnode* node,char *tw)
{
    int ch,ch2;
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    struct btnode *temp2 = (struct btnode *)malloc(sizeof(struct btnode));
    temp=node;
    printSiblings(temp);
    printf("\nType your choice: ");
    scanf("%d",&ch);
    for(int i=1;i<ch;i++)
    {
        temp=temp->r;
    }
    if(temp->l!=NULL)
    {
        printf("\n1.Reply to chosen tweet\n2.Reply to subtweet\nChoose one of the above options: ");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1:
            temp2=temp->l;
            while(temp2->r!=NULL)
            temp2=temp2->r;
            temp2->r=newnode(tw);
            return;
            break;
            case 2:
            findTweet(temp->l,tw);
            break;
            default:
            printf("\nInvalid choice try again.\n");
        }
    }
    else
    {
        temp->l=newnode(tw);
    }
}

int main()
{
    printf("---MENU---\n1.New Tweet\n2.Reply to a tweet\n3.Display\n4.Exit\n");
    int ch,ch2;
    char tw[MAX];
    while(1)
    {
        printf("\nEnter a choice from the menu: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter your tweet: ");
            scanf("%s",tw);
            if(root==NULL)
            {
                root=newnode(tw);
            }
            else
            {
                struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
                temp=root;
                while(temp->r!=NULL)
                temp=temp->r;
                temp->r=newnode(tw);
            }
            break;
            case 2:
            if(root==NULL)
            printf("Thread Empty!!! Try again.");
            else
            {
                printf("\nEnter your tweet: ");
                scanf("%s",tw);
                struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
                temp=root;
                findTweet(temp,tw);
            }
            break;
            case 3:
            printPreorder(root, 0);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Invalid option. Try again");
        }
    }
    return 0;
}
