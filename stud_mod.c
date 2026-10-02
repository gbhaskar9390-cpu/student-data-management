#include"student.h"
/////////////////////////////////////////////////////////////////////////////////
void modify_node(sll *p)
{
	if(p == 0)
	{
		printf("--------------------------\n");
		printf("No Student record present\n");
		printf("--------------------------\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	char ch,name[50];
	int num,c=0;
	float ptg;
	int n1=count_node(p);
	printf("---------------------------\n");
	printf("R/r : Search by Rollno\nN/n : Search by Name\n");
	printf("P/p : Search by Percentage\n");
	printf("---------------------------\n");
	scanf(" %c",&ch);
	if(ch>='A' && ch<='Z')
		ch = ch^32;
	if(ch == 'r')
	{
		search_by_rollno(p);	
	}
	else if(ch == 'n')
	{
		printf("-----------\n");
		printf("Enter Name\n");
		printf("-----------\n");
		scanf("%s",name);
		sll *n=p,*t;
		c=0;
		int a[n1],i=0;
		while(n)
		{
			if(strcmp(n->name,name) == 0)
			{
				t=n;
				a[i++] = n->rollno;
				if(c == 0)
		                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("%d %s %f\n",n->rollno,n->name,n->percentage);
				c++;
			}
			n = n->next;
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if(c>1)
			search_by_rollno1(p,a,i);
		else if(c == 0)
		{
			printf("---------------------\n");
			printf("Unknown Name Entered\n");
			printf("---------------------\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return ;
		}
		else
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Enter Name and Percentage to Modify\n");
			scanf("%s %f",t->name,&ptg);
			if(ptg < 0 || ptg >100)
			{
				printf("---------------------------\n");
				printf("percentage is not in Range\n");
				printf("Range is -->  0  to  100\n");
				printf("---------------------------\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			else
			{
				t->percentage = ptg;
				printf("--------------\n");
				printf("Data Modified\n");
				printf("--------------\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
			}
		}
	}
	else if(ch == 'p')
	{
		printf("-----------------\n");
		printf("Enter Percentage\n");
		printf("-----------------\n");
		scanf("%f",&ptg);
		sll *n=p,*t;
		c=0;
		int a[n1],i=0;
		while(n)
		{
			if(n->percentage == ptg)
			{
				t=n;
				a[i++] = n->rollno;
				if(c == 0)
		                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("%d %s %f\n",n->rollno,n->name,n->percentage);
				c++;
			}
			n = n->next;
		}
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if(c>1)
			search_by_rollno1(p,a,i);
		else if(c == 0)
		{
			printf("---------------------------\n");
			printf("Unknown Percentage entered\n");
			printf("---------------------------\n");
	                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return ;
		}
		else
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Enter Name and Percentage to Modify\n");
			scanf("%s %f",t->name,&ptg);
			if(ptg < 0 || ptg >100)
			{
				printf("---------------------------\n");
				printf("percentage is not in Range\n");
				printf("Range is -->  0  to  100\n");
				printf("---------------------------\n");
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			else
			{
				t->percentage = ptg;
				printf("--------------\n");
				printf("Data Modified\n");
				printf("--------------\n");
			}
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
		}
	}
	else
	{
		printf("-----------------------\n");
		printf("Unknown Option Entered\n");
		printf("-----------------------\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}

}
/////////////////////////////////////////////////////////////////////////////////
void search_by_rollno(sll *p)
{
	int num;
	float ptg;
	printf("-------------\n");
	printf("Enter Rollno\n");
	printf("-------------\n");
	scanf("%d",&num);
	sll *n=p;
	int c=0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	while(n)
	{
		if(n->rollno == num)
		{
			c++;
			printf("%d %s %f\n",n->rollno,n->name,n->percentage);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Enter Name and Percentage to Modify\n");
			scanf("%s %f",n->name,&ptg);
			if(ptg < 0 || ptg >100)
			{
				printf("---------------------------\n");
				printf("percentage is not in Range\n");
				printf("Range is -->  0  to  100\n");
				printf("---------------------------\n");
			}
			else
			{
				n->percentage = ptg;
				printf("--------------\n");
				printf("Data Modified\n");
				printf("--------------\n");
			}
		}
		n = n->next;
	}
	if(c == 0)
	{
		printf("-----------------------\n");
		printf("Unknown rollno Entered\n");
		printf("-----------------------\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
/////////////////////////////////////////////////////////////////////////////////
void search_by_rollno1(sll *p,int *a,int n1)
{
	int num;
	float ptg;
	printf("-------------\n");
	printf("Enter Rollno\n");
	printf("-------------\n");
	scanf("%d",&num);
	int i,c=0;
	for(i=0;i<n1;i++)
	{
		if(a[i] == num)
		{
			c++;
			break ;
		}
	}
	if(c == 0)
	{
		printf("-----------------------\n");
		printf("Unknown rollno Entered\n");
		printf("-----------------------\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	sll *n=p;
	while(n)
	{
		if(n->rollno == num)
		{
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Enter Name and Percentage to Modify\n");
			scanf("%s %f",n->name,&ptg);
			if(ptg < 0 || ptg >100)
			{
				printf("---------------------------\n");
				printf("percentage is not in Range\n");
				printf("Range is -->  0  to  100\n");
				printf("---------------------------\n");
			}
			else
			{
				n->percentage = ptg;
				printf("--------------\n");
				printf("Data Modified\n");
				printf("--------------\n");
			}
		}
		n = n->next;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
/////////////////////////////////////////////////////////////////////////////////
void sort_data(sll *p)
{
	if(p==0)
	{
		printf("---------------------------\n");
		printf("No Student Records Present\n");
		printf("---------------------------\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	char ch;
	printf("---------------------------\n");
	printf("N/n : Sort with name\nP/p : Sort with Percentage\n");
	printf("---------------------------\n");
	scanf(" %c",&ch);
	if(ch>= 'A' && ch<= 'Z')
		ch = ch^32;
	sll *p1=p,*p2,t;
	int c=count_node(p);
	int i,j;
	if(ch == 'p')
	{
		if(c>1)
		{
			for(i=0;i<c-1;i++)
			{
				p2=p1->next;
				for(j=0;j<c-1-i;j++)
				{
					if(p1->percentage < p2->percentage)
					{
						t.rollno = p1->rollno;
						strcpy(t.name,p1->name);
						t.percentage = p1->percentage;

						p1->rollno = p2->rollno;
						strcpy(p1->name,p2->name);
						p1->percentage = p2->percentage;

						p2->rollno = t.rollno;
						strcpy(p2->name,t.name);
						p2->percentage = t.percentage;
					}
					p2=p2->next;
				}
				p1=p1->next;
			}
		}
	}
	////////////////////////
	else if(ch == 'n')
	{
		if(c>1)
		{
			for(i=0;i<c-1;i++)
			{
				p2=p1->next;
				for(j=0;j<c-1-i;j++)
				{
					if(strcmp(p1->name,p2->name)>0)
					{
						t.rollno = p1->rollno;
						strcpy(t.name,p1->name);
						t.percentage = p1->percentage;

						p1->rollno = p2->rollno;
						strcpy(p1->name,p2->name);
						p1->percentage = p2->percentage;

						p2->rollno = t.rollno;
						strcpy(p2->name,t.name);
						p2->percentage = t.percentage;
					}
					p2=p2->next;
				}
				p1=p1->next;
			}
		}
	}
	else
	{
		printf("-----------------------\n");
		printf("Unknown Option Entered\n");
		printf("-----------------------\n");
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Data is Sorted\n");
	printf("~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
/////////////////////////////////////////////////////////////////////////////////
