#include"student.h"
///////////////////////////////////////////////////////////////////////////////
void print_all(sll *p)
{
	if(p == 0)
	{
		printf("--------------------------\n");
		printf("No Student Record Present\n");
		printf("--------------------------\n");
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Rollno.  Name  Percentage\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while(p)
	{
		printf("%d %s %f\n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
///////////////////////////////////////////////////////////////////////////////
void reverse_link(sll **p)
{
	if(*p==0)
	{
		printf("----------------------------\n");
		printf("No Student Records Presentt\n");
		printf("----------------------------\n");
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	int i=0,c=count_node(*p);
	sll **a,*n=*p;
	a=malloc(sizeof(sll *)*c);
	while(n)
	{
		a[i++]=n;
		n=n->next;
	}
	for(i=c-1;i>0;i--)
		a[i]->next=a[i-1];
	a[0]->next=0;
	*p=a[c-1];
	printf("----------------------\n");
	printf("Nodes Reverse Linked\n");
	printf("----------------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
///////////////////////////////////////////////////////////////////////////////
