#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
typedef struct student
{
	int rollno;
	char name[50];
	float percentage;
	struct student *next;
}sll;

extern void add_middle(sll **);
extern void delete_node(sll **);
extern void print_all(sll *);
extern void modify_node(sll *);
extern void save_in_file(sll *);
extern void sort_data(sll *);
extern void delete_all(sll **);
extern void reverse_link(sll **);
extern int count_node(sll *);
extern void delete_by_rollno(sll **);
extern void delete_by_name(sll **);
extern void search_by_rollno(sll *);
extern void delete_by_rollno1(sll **, int *, int);
extern void search_by_rollno1(sll * , int *, int);

