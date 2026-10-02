#include"student.h"
///////////////////////////////////////////////////////////////////////////////
void add_middle(sll **p)
{
	sll *n,*t=*p;
	int c=count_node(*p);
	n = malloc(sizeof(sll));
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while(1)
	{
		printf("Enter rollno, name and percentage\n");
		scanf("%d %s %f",&n->rollno,n->name,&n->percentage);
		if(n->rollno > 0)
		{
			if(n->percentage >= 0.0 && n->percentage <= 100.0)
			{
				break ;
			}
			else
			{
				printf("---------------------------\n");
				printf("Percentage is not in RANGE\n");
				printf("RANGE is  -->  0.0 - 100.0\n");
				printf("---------------------------\n");
			}
		}
		else
		{
			printf("---------------------------\n");
			printf("Rollno must be positive\n");
			printf("---------------------------\n");
		}
	}
	if(*p == 0)
	{
		n->next=*p;
		*p=n;
	}
	else
	{
		while(c>0)
		{
			if(t->rollno == n->rollno)
			{
				printf("---------------------\n");
				printf("Rollno already exist\n");
				printf("---------------------\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				return ;
			}
			t=t->next;
			c--;
		}
		t=*p;
		if(n->rollno < t->rollno)
		{
			n->next = *p;
			*p=n;
		}
		else
		{
			while((t->next!=0) && (n->rollno > t->next->rollno))
				t = t->next;
			n->next = t->next;
			t->next = n;
		}
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
///////////////////////////////////////////////////////////////////////////////
int count_node(sll *p)
{
	int c=0;
	while(p)
	{
		p=p->next;
		c++;
	}
	return c;
}
///////////////////////////////////////////////////////////////////////////////
