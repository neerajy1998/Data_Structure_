

/* Program of priority queue using linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct pqnode
{
	int priority;
	int data;
	struct pqnode *next;
}pqnode;

pqnode *front=NULL;
pqnode *rear=NULL;

void enqueue(pqnode **,pqnode **, int ,int);
void display(pqnode *,pqnode *);
int dequeue(pqnode **,pqnode **);
void main(void)
{
	int choice,item,priority;
	while(1)
	{
		printf("\n1.Insert\n");
		printf("2.Display\n");
		printf("3.Delete\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
        while('\n'!=getchar()){;}
        

		switch(choice)
		{
			 case 1:
				printf("Input the item to be added in the queue : ");
				scanf("%d",&item);
      				while('\n'!=getchar()){;}
				printf("Enter its priority : ");
				scanf("%d",&priority);
        		        while('\n'!=getchar()){;}
     				enqueue(&front,&rear,item, priority);
 				break;
			 case 2:
				printf("Displaying the queue:\n");
				display(front,rear);
				break;
			 case 3:
				printf("Deleting  the element  in queue:\n");
				item=dequeue(&front,&rear);
				printf("Deleted element  in queue is %d:\n",item);
				break;

			 default :
				printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
    return;
}/*End of main()*/

void enqueue(pqnode **front,pqnode **rear,int item,int priority)
{
	pqnode *new,*p,*q;
	
	new=(pqnode *)malloc(sizeof(pqnode));
	if(new==NULL)
	{
		printf("Memory not available\n");
		return ;
	}
	new->data=item;
	new->priority=priority;
	/*Queue is empty or item to be added has priority more than first element*/
	if( NULL==*front)
	{
		new->next=NULL;    
		*front=new;
		*rear=new;
		return;
	}

	if (new->priority < (*front)->priority)
	{
		new->next=*front;
		*front=new;
		return ;

	}
	if (new->priority > (*rear)->priority)
	{
		(*rear)->next=new;
		new->next=NULL;
		*rear=new;
		return ;
	}

	else
	{
		p = *front;
		while( p->next!=NULL && (new->priority)>(p->priority) )
		{
			q=p;
			p=p->next;
		}
		q->next=new;
		new->next=p;
	}
}/*End of insert()*/
void display(pqnode *front,pqnode *rear)
{	
	pqnode *p,*q;
	p=front;
	q=rear;
	if(NULL==front)
	{
		printf("List is empty\n");
		return ;
	}

	while(NULL!=p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	return ;
}
int dequeue(pqnode **front,pqnode **rear)
{
	pqnode *p;
	if(NULL==*front)
	{
		printf("Queue is empty\n");	
		return -1;
	}
	p=*front;
	int item;
	item=p->data;
	if (*front==*rear)
	{
		*front=NULL;
		*rear=NULL;
	}
	else
	{
		*front=p->next;
	}
	free (p);
	p=NULL;
	return item;
}




