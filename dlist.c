#include <stdio.h>
#include <stdlib.h>

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
typedef struct double_listnode{
 int data;
 struct double_listnode *prior,*next;
}double_listnode_t;

//define structurepoint of double_listnode,and it can use declare name as "double_listnode_p" replace to code of "struct double_listnode*"
typedef struct double_listnode* double_listnode_p;

//function define
static void insert_double_listnode(double_listnode_p head,int i,int data);
static void show_node(double_listnode_p head);

//declare Function_1
static double_listnode_p init_double_list(int n)
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

 printf("head location:%p \n",&head);
 printf("head data(generate by malloc):%p \n",head);
 printf("[show head struct of data] \n");
 show_node(head);

 printf("put data...... \n [start] \n");
 for(int i=0;i<n;i++)
 {
  printf("[%d] \n",(i+1));
  insert_double_listnode(head,(i+1),(i+1));
 }
 printf("[the end] \n");

 printf("[show again head struct of data] \n");
 show_node(head);

 return head;
}

//declare Function_2
static void print_double_listnode(double_listnode_p head)
{
 double_listnode_p p = head -> next;

 
 printf("------ start print ------ \n");
/* 
 printf("p real location:%p \n",&p);
 printf("structpoint p data:%p \n",p);
 printf("p data: \n");
 show_node(p);
 
 printf("head real location:%p \n",&head);
 printf("structpoint head data:%p \n",head);
 printf("head data: \n");
 show_node(head);
*/

 printf("show data content fornate: \n (now data location)(prior data location)data(next data location) \n");
 int i = 0;
 while(p != head)
 {
  i=i+1;
  printf("[%d] \n",i);
  printf(" (%p) ",p);
  printf(" (%p) ",p->prior);
  printf(" %d ",p->data);
  printf(" (%p) \n",p->next);
   
  p = p -> next;
 }
 printf("\n");

 printf("------ end print ------ \n");

 /*
 printf("p real location:%p \n",&p);
 printf("structpoint p data:%p \n",p);
 printf("again p data: \n");
 show_node(p);
 
 printf("head real location:%p \n",&head);
 printf("structpoint head data:%p \n",head);
 printf("again head data: \n");
 show_node(head);
 */

}

//declare Function_3
static double_listnode_p get_double_listnode(double_listnode_p head,int i)
{
 double_listnode_p p = head;
 int j=0;

 while(p -> next != head && j < i)
 {
  p = p -> next;
  j++;
 }

 if(i == j)
 {
  printf("(1)You find [%d] data...... \n(2)Your search resoult:%d(in memory - %p) \n",i,p -> data,p);
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
static void insert_double_listnode(double_listnode_p head,int i,int data)
{
//search or find prior node
 double_listnode_p p = NULL;
 
 p = get_double_listnode(head,(i-1));
 
 printf("(3)insert data content:");
 if(p == NULL)
 {
  fprintf(stderr,"position error \n");
  exit(-1);
 }

//insert data to node
 double_listnode_p tmp;

 tmp = (double_listnode_t *)malloc(sizeof(double_listnode_t));
 tmp -> data = data;
 tmp -> prior = p;
 tmp -> next = p -> next;
 
 p -> next -> prior = tmp;
 p -> next = tmp;

 printf("%d \n",tmp->data);
 printf("(4)data location:%p \n",tmp);
}

//declare Function_5
static void delete_double_listnode(double_listnode_p head,int i)
{
//search or find prior node
 double_listnode_p p = NULL;

 p = get_double_listnode(head,i);
 printf("(3)delete data \n");
 if(p == NULL || p == head )
 {
  fprintf(stderr,"position error \n");
  exit(-1);
 }

//delete data to node
 p->prior->next = p->next;
 p->next->prior = p->prior;

 printf("(4)data location [%d] (in memory - %p) \n",i,p);
 free(p);
}

//declare Function_6
static void destroy_double_list(double_listnode_p head)
{
 double_listnode_p s,p = head->next,enddt;

 printf("start location in memory - %p \n",head);

 int i = 0;
 while(p != head)
 {
  i = i+1;
  s = p;
  p = p->next;
  printf("[%d] release (memory -%p) \n",i,s);
  enddt = p;
  free(s);
 }

 printf("end location in memory - %p \n",enddt);

 free(head);
}

/*
 declare Function_7:show struct "double_listnode" of data

 note:it(function) use to "debug"
*/
static void show_node(double_listnode_p node)
{
 double_listnode_p nodedata = node;
 printf("this struct of data is...... \n");
 printf("int data:%d \n",nodedata->data);
 printf("*prior:%p \n",nodedata->prior);
 printf("*next:%p \n",nodedata->next); 
}

/*
//Parameter set//
 n is node of amount
 l is node data location
 insertdt is insert data content
*/
int n = 5; 
int l;
int insertdt;

int main(void)
{
 printf("create doublelist of node data...... \n");
 double_listnode_p head = init_double_list(n);
 printf("data location recode in memory - %p \n",head);

 printf("print data...... \n");
 print_double_listnode(head);
 
 printf("search data...... \n");
 printf("input data location:");
 scanf("%d",&l);
 get_double_listnode(head,l);

 printf("insert data...... \n");
 printf("input data location:");
 scanf("%d",&l);
 printf("input data content:");
 scanf("%d",&insertdt); 
 insert_double_listnode(head,l,insertdt);
 printf("(5)end insert \n");
 printf("print insert resoult...... \n");
 print_double_listnode(head);

 printf("delete data...... \n");
 printf("input data location:");
 scanf("%d",&l);
 delete_double_listnode(head,l);
 printf("print delete resoult...... \n");
 print_double_listnode(head);

 printf("\n delete and remove dobulekist data,and release memory...... \n");
 destroy_double_list(head);
 printf("finish remove!! \n");

 return 0;
}
