//
//  main.c
//  Student Data Management Using Linked List Data Structure
//
//  Created by ABHISHEK KESTI on 18/07/26.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
   
typedef struct student
{
int rollno;
char name[20];
float marks;
struct student *next;
}SLL;
  
void Add_Student(SLL**);
void Display(SLL*);
int count_node(SLL*);
void reverse_print(SLL*);
void delete_node(SLL**);
void search(SLL*);
void update(SLL*);
int main(void)
{
SLL *headptr=0;
int op,c=0;
while(1)
{
printf("***********STUDENT DATA MANAGEMENT************\n");
printf("my dear! Enter your choice\n");
printf("1.Add Student\n");
printf("2.Display\n");
printf("3.Search\n");
printf("4.Update\n");
printf("5.Delete\n");
printf("6.Count\n");
printf("7.Reverse Print\n");
printf("8.Save\n");
printf("9.Load\n");
printf("10.Exit\n");
scanf("%d",&op);
printf("op=%d\n",op);
switch(op)
{
case 1:Add_Student(&headptr);break;
case 2:Display(headptr);break;
case 3:search(headptr);break;
case 4:update(headptr);break;
case 5:delete_node(&headptr);
case 6:c=count_node(headptr);
       printf("Num of student's are %d\n",c);
       break;
case 7:reverse_print(headptr);break;
case 10:exit(0);
default:printf("my dear! unknown choice\n");
}
}
}
void Add_Student(SLL **ptr)
{
       SLL *last,*n=malloc(sizeof(SLL));
       printf("Enter rollno,name & marks\n");
       scanf("%d %s %f",&n->rollno,n->name,&n->marks);
       n->next=0;
       if(*ptr==0)
           *ptr=n;
       else
       {
           last=*ptr;
           while(last->next)
               last=last->next;
           last->next=n;
       }
   }

void Display(SLL *ptr)
{
if(ptr==0)
{
printf("No records present\n");
 return;
 }
  printf("*************\n");
 while(ptr)
 {
 printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
  ptr=ptr->next;
 }
 printf("***********\n");
  }
  
 int count_node(SLL *ptr)
{
int c=0;
 while(ptr) {
 c++;
  ptr=ptr->next;
 }
 return c;
}
void reverse_print(SLL *ptr)
 {
 if(ptr==0)
 {
  printf("no records found\n");
  return;
  }
  printf("*************\n");
  int c=count_node(ptr);
  int i,j;
  SLL *t;
  for(i=0;i<c;i++)
  {
  t=ptr;
  for(j=0;j<c-1-i;j++)
  t=t->next;
 printf("%d %s %f\n",t->rollno,t->name,t->marks);
 }
 printf("*************\n");
}
 void delete_node(SLL **ptr)
 {
 if(*ptr==0)
 {
 printf("No record found\n");
 return;
 }
 char name[20];
 printf("Enter name to dlt\n");
 scanf("%s",name);
 SLL *prev,*del=*ptr;
 while(del)
 {
 if(strcmp(del->name,name)==0)
 {
 if(del==*ptr)
 *ptr=del->next;
 else
 prev->next=del->next;
 free(del);
return;
 }
 prev=del;
 del=del->next;
 }
 printf("No name found\n");
}
void search(SLL *ptr)
 {
 int n;
 if(ptr==0)
 {
 printf("records not found\n");
 return;
 }
 printf("enter roll to search\n");
 scanf("%d",&n);
 while(ptr)
{
 if(ptr->rollno==n)
 {
 printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
 return;
 }
 ptr=ptr->next;
 }
 printf("Rollno not found\n");
 }
 
 void update(SLL *ptr)
 {
 if(ptr==0)
 {
 printf("Records not found\n");
 return;
}
int n;
 printf("Enter roll.no to modify\n");
 scanf("%d",&n);
 while(ptr)
 {
 if(ptr->rollno==n)
 {
 printf("enter new name and marks\n");
 scanf("%s %f",ptr->name,&ptr->marks);
 printf("students details update successfully.\n");
 return;
 }
ptr=ptr->next;
 }
 printf("Student Roll.no not found\n");
}
