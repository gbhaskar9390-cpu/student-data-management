#include"student.h"
///////////////////////////////////////////////////////////////////////////////
void save_in_file(sll *p)
{
	FILE *fp;
	fp=fopen("student.data","r+");
	fseek(fp,0,SEEK_END);
	if(p == 0)
	{
		printf("--------------------------\n");
		printf("No Student Record Present\n");
		printf("--------------------------\n");
	        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return ;
	}
	while(p)
	{
		fprintf(fp,"%d %s %f\n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
	fclose(fp);
	printf("------------------------\n");
	printf("Data is saved in FILE\n");
	printf("------------------------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
///////////////////////////////////////////////////////////////////////////////
