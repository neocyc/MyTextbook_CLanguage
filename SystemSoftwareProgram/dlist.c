#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dlist.h"

/*
//Datastructure Manual//
data formate: real of data put in int data,"structpoint" of recode data put in *prior(prior struct of location) and *next(next struct of location) 

//Function Manual//
Function_1:auto create data, and put it(data) in "doublelist of node"

Function_2:print doublelist of data

Function_3:search data by node location

Function_4:insert data by location

Function_5:delete data by location

Function_6:clear and delete all data and remove data in memory

note:
int n is node of amount
int i is node data location
int data is node data of input content
head is data of structpoint means data start from it
*/

//define datastructure double_listnode,and it can use to declare name as "double_listnode_t" replace to code of "struct double_listnode"
struct _Double_ListNode{
 void* data;
 struct _Double_ListNode *prior, *next;
};

//define structurepoint of double_listnode,and it can use declare name as "double_listnode_p" replace to code of "struct double_listnode*"
//typedef struct Double_ListNode* double_listnode_p;

//function define
static void dlistnode_insert(double_listnode_p head, int i, void* data);
static void dlistnode_shownode(double_listnode_p head);

//declare Function_1
static double_listnode_p dlist_init(int n)
{

//declare struct ? of structpoint by double_listnode_p
 double_listnode_p head;
 
/*
 note:
 this code "head = &head;" can not use to static,only can use to runtime
*/
 head = (double_listnode_p)malloc(sizeof(double_listnode_t));

/*
 //Pseudocode Manual//
 head->prior = head->next = head;
 
 note:head of *prior,*next is malloc() find location in momery by "= head"
*/
//initial variable head
 head->prior = head; 
 head->next = head;

 printf("head location:%p \n", &head);
 printf("head data(generate by malloc):%p \n", head);
 printf("[show head struct of data] \n");
 dlistnode_shownode(head);

 printf("put data...... \n [start] \n");
 for(int i = 0; i < n; i++)
 {
	printf("[%d] \n",(i+1));
  	dlistnode_insert(head, (i+1), (char*)(i+1));
 }
 printf("[the end] \n");

 printf("[show again head struct of data] \n");
 dlistnode_shownode(head);
 
 return head;
}

//declare Function_2
static void dlistnode_print(double_listnode_p head, DListDataPrintFunc print)
{
 double_listnode_p p = head->next;
 
 printf("------ start print ------ \n");
/* 
 printf("p real location:%p \n", &p);
 printf("structpoint p data:%p \n", p);
 printf("p data: \n");
 show_node(p);
 
 printf("head real location:%p \n", &head);
 printf("structpoint head data:%p \n", head);
 printf("head data: \n");
 show_node(head);
*/

 printf("show data content fornate: \n (now data location)(prior data location)data(next data location) \n");
 int i = 0;
 while(p != head)
 {
 	i = i+1;
  	printf("[%d] \n", i);
  	printf(" (%p) ", p);
  	printf(" (%p) ", p->prior);
  	print(p->data);
  	printf(" (%p) \n", p->next);
   
  	p = p->next;
 }
 printf("\n");

 printf("------ end print ------ \n");

 /*
 printf("p real location:%p \n", &p);
 printf("structpoint p data:%p \n", p);
 printf("again p data: \n");
 show_node(p);
 
 printf("head real location:%p \n", &head);
 printf("structpoint head data:%p \n", head);
 printf("again head data: \n");
 show_node(head);
 */

}

/* list search function */
void dlist_foreach(double_listnode_p head, DListDataVisitFunc visit, void* ctx)
{
 double_listnode_p p = head->next;
 while(p != head)
 {
 	visit(ctx, p->data);
 	p = p->next;
 }
 
}

//call back Function
//print()
static void print_int(void* data)
{
 printf(" %d ",(int)data);
}

static void print_char(void* data)
{
 printf(" %c ",(char)data);
}

//sum()
static void sum_cb(void* ctx, void* data)
{
 long long* result = ctx;
 *result += (int)data;

 printf("%d \n",*result);
}

/*
//toupper()
static void str_toupper(void* ctx, void* data)
{
 char *dataT = ctx;
 if(islower(data) != 0)
 {
 	*dataT = toupper(data);
 	printf("%c \n",*dataT);
 }
 //printf("%c \n",dataT);
}
*/

//declare Function_3
static double_listnode_p dlistnode_get(double_listnode_p head, int i)
{
 double_listnode_p p = head;
 int j = 0;

 while((p->next != head) && (j < i))
 {
  	p = p->next;
  	j++;
 }

 if(i == j)
 {
  	printf("(1)You find [%d] data...... \n(2)Your search resoult:%d(in memory - %p) \n", i, p->data, p);
  	
	return p;
 }
 else
 {
  	fprintf(stderr,"NULL,not find data! \n");
  	exit(-1);
  	
	return NULL;
 }
}

//declare Function_4
static void dlistnode_insert(double_listnode_p head, int i, void* data)
{
//search or find prior node
 double_listnode_p p = NULL;
 
 p = dlistnode_get(head, (i-1));
 
 printf("(3)insert data content:");
 if(p == NULL)
 {
  	fprintf(stderr,"position error \n");
  	
	exit(-1);
 }

//insert data to node
 double_listnode_p tmp;

 tmp = (double_listnode_p)malloc(sizeof(double_listnode_t));
 tmp->data = data;
 tmp->prior = p;
 tmp->next = p->next;
 
 p->next->prior = tmp;
 p->next = tmp;

 printf("%d \n", tmp->data);
 printf("(4)data location:%p \n", tmp);
}

//declare Function_5
static void dlistnode_delete(double_listnode_p head, int i)
{
//search or find prior node
 double_listnode_p p = NULL;

 p = dlistnode_get(head, i);
 printf("(3)delete data \n");
 if(p == NULL || p == head)
 {
  	fprintf(stderr,"position error \n");
  
	exit(-1);
 }

//delete data to node
 p->prior->next = p->next;
 p->next->prior = p->prior;

 printf("(4)data location [%d] (in memory - %p) \n", i, p);
 free(p);
}

//declare Function_6
static void dlist_destroy(double_listnode_p head)
{
 double_listnode_p s, enddt;

 printf("start location in memory - %p \n", head);

 double_listnode_p p = head->next;
 int i = 0;
 while(p != head)
 {
  	i = i+1;
  	s = p;
  	p = p->next;
  	
	printf("[%d] release (memory -%p) \n", i, s);
  	enddt = p;
  	free(s);
 }

 printf("end location in memory - %p \n", enddt);
 free(head);
}

/*
 declare Function_7:show struct "double_listnode" of data

 note:it(function) use to "debug"
*/
static void  dlistnode_shownode(double_listnode_p node)
{
 double_listnode_p nodedata = node;
 
 printf("this struct of data is...... \n");
 printf("void* data:%d \n", nodedata->data);
 printf("*prior:%p \n", nodedata->prior);
 printf("*next:%p \n", nodedata->next); 
}

/*
//Parameter set//
 n is node of amount
 l is node data location
 insertdt is insert data content
*/

int main(void)
{
 int n = 5;
 int l;
 char insertdt[10];
 //int insertdt;

 printf("create doublelist of node data...... \n");
 double_listnode_p head = dlist_init(n);
 printf("data location recode in memory - %p \n", head);

 printf("print data...... \n");
 dlistnode_print(head, print_char);
 
 printf("search data...... \n");
 printf("input data location:");
 scanf("%d", &l);
 dlistnode_get(head, l);

 printf("insert data...... \n");

 for(int i=0;i<2;i++){

 printf("input data location:");
 scanf("%d", &l);
 printf("input data content:");
 //scanf("%s", &insertdt); 
 scanf("%d", &insertdt);

 //dlistnode_insert(head, l, strdup(insertdt));
 dlistnode_insert(head, l, &insertdt);
 printf("(5)end insert \n");

}

 printf("print insert resoult...... \n");
 dlistnode_print(head, print_int);

 printf("delete data...... \n");
 printf("input data location:");
 scanf("%d", &l);

 dlistnode_delete(head, l);

 printf("print delete resoult...... \n");
 dlistnode_print(head, print_int);

 long long sum = 0;
 dlist_foreach(head,sum_cb,&sum);

 //char inputcontext[10];
 //dlist_foreach(head,str_toupper,&inputcontext);

 printf("\n delete and remove dobulekist data,and release memory...... \n");
 dlist_destroy(head);
 printf("finish remove!! \n");

 return 0;
}
