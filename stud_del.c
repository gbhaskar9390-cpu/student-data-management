#include"student.h"
///////////////////////////////////////////////////////////////////////////////
void delete_node(sll **p)
{
	if(*p == 0)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("No Student Record Present\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	printf("-----------------------------\n");
	char ch;
	printf("R/r : Enter rollno to Delete\nN/n : Enter Name to Delete\n");
	printf("-----------------------------\n");
	scanf(" %c",&ch);
	if(ch>='A' && ch<='Z')
		ch=ch^32;
	if(ch == 'r')
	{
		delete_by_rollno(p);
		return ;
	}
	else if(ch == 'n')
	{
		delete_by_name(p);
		return ;
	}
	else
	{
		printf("-----------------------\n");
		printf("Unknown option entered\n");
		printf("-----------------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}

}
///////////////////////////////////////////////////////////////////////////
void delete_by_rollno(sll **p)
{
	int num;
	printf("-------------\n");
	printf("Enter rollno\n");
	printf("-------------\n");
	scanf("%d",&num);
	sll *del=*p,*prev;
	int c=0;
	while(del)
	{
		if(del->rollno == num)
		{
			c++;
			if(del == *p)
				*p = del->next;
			else
				prev->next = del->next;
			free(del);
			printf("--------------\n");
			printf("Node Deleted\n");
			printf("--------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return ;
		}
		prev=del;
		del=del->next;
	}
	if(c == 0)
	{
		printf("-----------------------\n");
		printf("Unknown Rollno Entered\n");
		printf("-----------------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
}
///////////////////////////////////////////////////////////////////////////

void delete_by_rollno1(sll **p,int *a,int n)
{
	int num;
	printf("-------------\n");
	printf("Enter rollno\n");
	printf("-------------\n");
	scanf("%d",&num);
	sll *del=*p,*prev;
	int c=0;
	int i;
	for(i=0;i<n;i++)
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
		printf("Unknown Rollno Entered\n");
		printf("-----------------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	while(del)
	{
		if(del->rollno == num)
		{
			if(del == *p)
				*p = del->next;
			else
				prev->next = del->next;
			free(del);
			printf("--------------\n");
			printf("Node Deleted\n");
			printf("--------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return ;
		}
		prev=del;
		del=del->next;
	}
}

///////////////////////////////////////////////////////////////////////////
void delete_by_name(sll **p)
{
	char s[50];
	printf("-------------\n");
	printf("Enter Name\n");
	printf("-------------\n");
	scanf("%s",s);
	sll *del=*p,*prev,*t1,*t2;
	int n=count_node(*p);
	int c=0,a[n],i=0;
	while(del)
	{
		if(strcmp(del->name,s) == 0)
		{
			t1 = del;
			t2 = prev;
			c++;
			a[i++] = del->rollno;
			printf("%d %s %f\n",del->rollno,del->name,del->percentage);
		}
		prev = del;
		del=del->next;
	}
	///////////////////////////////////////
	if(c == 0)
	{
		printf("---------------------\n");
		printf("Unknown Name Entered\n");
		printf("---------------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	else if(c == 1)
	{
		if(t1 == *p)
			*p = t1->next;
		else
			t2->next = t1->next;
		free(t1);
		printf("--------------\n");
		printf("Node Deleted\n");
		printf("--------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	///////////////////////////////////////
	else
		delete_by_rollno1(p,a,i);

}
///////////////////////////////////////////////////////////////////////////
void delete_all(sll **p)
{
	if(*p == 0)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("No Student Record Present\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	sll *del=*p;
	int i=1;
	printf("~~~~~~~~~~~~~~~~~~~~~\n");
	while(del)
	{
		*p = del->next;
		free(del);
		printf("Node %d is Deleted\n",i);
		sleep(1);
		i++;
		del=(*p);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
///////////////////////////////////////////////////////////////////////////
