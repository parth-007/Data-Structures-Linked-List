#include<conio.h>
#include<alloc.h>
#include<stdio.h>
#include<stdlib.h>
#define m (struct node *)malloc(sizeof(nn))
struct node
{
	int data;
	struct node *next;
}*first=NULL,*last=NULL,*prev,*curr,*nn,*q;
void disp()
{
	if(first==NULL)
	{
		printf("\n LL Empty");
	}
	else if(first==last)
	{
		printf("\n %5d",first->data);
	}
	else
	{
		curr=first;
		while(curr!=NULL)
		{
			printf("\n %5d",curr->data);
			curr=curr->next;
		}
	}
}
void create()
{
	int val;
	printf("\n Enter value (-1 For Exit):");
	scanf("%d",&val);
	while(val!=-1)
	{
	nn=m;
	nn->data=val;
	nn->next=NULL;
	if(first==NULL)
	{
		first=nn;
	}
	else
	{
		last->next=nn;
	}
	last=nn;
	printf("\n Enter Value:(-1 For Exit):");
	scanf("%d",&val);
	}
}
void ifirst()
{
	int val;
	if(first==NULL)
	{
		printf("\n Enter Value:");
		scanf("%d",&val);
		nn=m;
		nn->data=val;
		nn->next=NULL;
		if(first==NULL)
		{
			first=nn;
		}
		else
		{
			last->next=nn;
		}
		last=nn;
	}
	else
	{
		printf("\n Enter Value:");
		scanf("%d",&val);
		nn=m;
		nn->data=val;
	    //	nn->next=NULL;

		nn->next=first;
		first=nn;
	}
}
void ilast()
{
	int val;
	printf("\n Enter Value:");
	scanf("%d",&val);
	nn=m;
	nn->data=val;
	nn->next=NULL;

	if(first==NULL)
	{
		first=nn;
	}
	else
	{
		last->next=nn;
	}
	last=nn;
}
void ipos()
{
	int val,count=1,pos;
	int c1=0;
	q=first;
	while(q!=NULL)
	{

		c1++;
		q=q->next;
	}
       //	printf("\n %d",c1);

	printf("\n Enter Position:");
	scanf("%d",&pos);
	if(pos<0)
	{
		printf("\n Enter Valid Value Between 1 and %d",c1+1);
	}
	else if(pos>c1+1)
	{
		printf("\n Enter Valid Value Between 1 and %d",c1+1);
	}
	else if(pos==count)
	{
		printf("\nEnter Value:");
		scanf("%d",&val);
		nn=m;
		nn->data=val;
		nn->next=NULL;

	       if(first==NULL)
	       {
		first=nn;
	       }
	       else
	       {
		nn->next=first;
	       }
	       first=nn;
	}
	else
	{
	     printf("\nEnter Value:");
		scanf("%d",&val);
		nn=m;
		nn->data=val;
		nn->next=NULL;

	prev=NULL;
	curr=first;
	while(count<pos)
	{
		prev=curr;
		curr=curr->next;
		count++;
	}

	prev->next=nn;
	nn->next=curr;
	//Important Comment

	if(prev==last)
	last=nn;
	}
}
void fdel()
{
	int val;
	if(first==NULL)
	{
		printf("\n LL EMpty");
	}
	else if(first==last)
	{
		printf("\n Deleted Value is=%5d",first->data);
		free(first);
	}
	else
	{
		printf("\n Deleted Value is=%5d",first->data);
		prev=first;
		first=prev->next;
		free(prev);

	}
}
void ldel()
{
	if(first==NULL)
	{
		printf("\n LL Empty");
	}
	else if(first==last)
	{
		printf("\n Deleted Value is =%d",first->data);
		free(first);

	}
	else
	{
		curr=first;
		while(curr->next!=last)
		{
			curr=curr->next;
		}
		printf("\n Deleted Value is=%5d",last->data);
		free(last);
		curr->next=NULL;
		last=curr;
	}
}
void pdel()
{
	int c2=0,count=1,pos;
	q=first;
	while(q!=NULL)
	{
		c2++;
		q=q->next;
	}
	if(first==NULL)
	{
		printf("\n LL Empty");
	}
	else if(first==last)
	{
		printf("\n Deleted Value is=%5d",first->data);
		free(first);
	}

	else
	{
	printf("\n Enter Position:");
	scanf("%d",&pos);

		if(pos<0)
		{
			printf("\n Enter Position Between 1 and %d",c2);
		}
		else if(pos>c2)
		{
			printf("\n Enter Position BetWeen 1 and %d",c2);
		}
		else if(pos==c2)
		{
		curr=first;
		while(curr->next!=last)
		{
			curr=curr->next;
		}
		printf("\n Deleted Value is=%5d",last->data);
		free(last);
		curr->next=NULL;
		last=curr;
		}
		else if(pos==count)
		{
		printf("\n Deleted Value is=%5d",first->data);
		prev=first;
		first=prev->next;
		free(prev);
		}
		else
		{
			curr=first;
			prev=NULL;
			while(count<pos)
			{
				prev=curr;
				curr=curr->next;
				count++;
			}
			printf("\n Deleted Value is=%5d",curr->data);
			prev->next=curr->next;

		}
	}
}
void main()
{
	int ch1,ch2,ch3;
	clrscr();
	do
	{
		clrscr();
		printf("\n 1.Create List");
		printf("\n 2.Insert Node");
		printf("\n 3.Delete Node");
		printf("\n 4.Display List");
		printf("\n 5.Exit");
		printf("\n Enter Your Choice:");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
			create();
			break;
			case 2:
			do
			{
				printf("\n 1.Insert Before First Node");
				printf("\n 2.Insert At Position");
				printf("\n 3.Insert After Last Node");
				printf("\n 4.Exit");
				printf("\n Enter Your Choice:");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
					ifirst();
					break;
					case 2:
					ipos();
					break;
					case 3:
					ilast();
					break;
					case 4:
					break;
					default:
					printf("\n Wrong Input");
				}
			}while(ch2!=4);
			break;
			case 3:
			do
			{
				printf("\n 1.Delete First Node");
				printf("\n 2.Delete At Position");
				printf("\n 3.Delete At last");
				printf("\n 4.Exit");
				printf("\n Enter Your Choice:");
				scanf("%d",&ch3);
				switch(ch3)
				{
					case 1:
					fdel();
					break;
					case 2:
					pdel();
					break;
					case 3:
					ldel();
					break;
					case 4:
					printf("\n-->>Use Diffrent Menu Items Plz");
					break;
					default:
					printf("\n Wrong Input");
				}
			}while(ch3!=4);
			break;
			case 4:
			disp();
			break;
			case 5:
			exit(0);
			break;
			default:
			printf("\n Wrong Input");
		}getch();
	}while(ch1!=5);
}

