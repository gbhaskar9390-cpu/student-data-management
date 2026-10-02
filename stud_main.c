#include"student.h"
int main()
{
	sll *hp=0;
	char ch;
	while(1)
	{
		printf("*************************************\n");
		printf("******<  STUDENT RECORD MENU  >******\n");
		printf("*************************************\n");
		printf("A/a : Add new record\nD/d : Delete a record\nS/s : Show the list\nM/m : Modify a record\nV/v : Save records in FILE\nE/e : Exit\nT/t : Sort the list\nL/l : Delete all the records\nR/r : Reverse the list\n");
		printf("Enter your choice : ");
		scanf(" %c",&ch);
		if(ch>='A' && ch<='Z')
			ch = ch^32;
		switch(ch)
		{
			case 'a' : add_middle(&hp);
				   break;
			case 'd' : delete_node(&hp);
				   break;
			case 's' : print_all(hp);
				   break;
			case 'm' : modify_node(hp);
				   break;
			case 'v' : save_in_file(hp);
				   break;
			case 't' : sort_data(hp);
				   break;
			case 'l' : delete_all(&hp);
				   break;
			case 'r' : reverse_link(&hp);
				   break;
			case 'e' : printf("--------------------------\n");
				   printf("S/s : Save and exit\n");
				   printf("E/e : Exit without saving\n");
				   printf("--------------------------\n");
				   scanf(" %c",&ch);
				   if(ch>='A' && ch<='Z')
					   ch = ch^32;
				   if(ch == 's')
				   {
					   save_in_file(hp);
					   delete_all(&hp);
					   return 0;
				   }
				   else	
				   {
					   delete_all(&hp);
					   return 0;
				   }
			default  : printf("Unknown Option\n");		
		}
	}
	return 0;
}
