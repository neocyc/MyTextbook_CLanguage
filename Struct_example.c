#include <stdio.h>
#include <stdlib.h>

/*
//SampleCode_doublelist//
0.
struct its_double_listnode{};
deftype struct its_double_listnode* sdlistnodept;

struct double_listnode
{
 int data;
 sdlistnodept prior;
 sdlistnodept next;
}

//note:0. same as 1.

1.
struct double_listnode
{
 int data;
 stuuct double_listnode *prior,*next;
};

2.
typedef struct double_listnode double_listnode_t;

[1. + 2.]
typedef struct double_listnode{
 int data;
 struct double_listnode *prior,*next;
}double_listnode_t;

3.
typedef struct double_listnode* double_listnode_p;

[1. + 2. + 3.]
note:
 *prior and *next recode data location of struct,*double_listnode_p is a "structpoint"

typedef struct double_listnode{
 int data;
 struct double_listnode *prior,*next;
}double_listnode_t,* double_listnode_p;
*/

/*
//Instruction Manual//

1.
data formate:
three variable,one put data and two put data of address(data in memory location of Hexadecimal number) name as "point",but this "point" is "structpoint" not pointVariable.

2.
"structpoint" is a data to recode struct of location in memory,and it(data) put in pointVariable. 
*/

struct double_listnode
{
 int data;
 int data2;
};

struct double_listnode *dln_p;

int main(void)
{
 struct double_listnode x;
 x.data = 8;
 x.data2 = 100;

 printf("struct location:%p \n",&x);
 printf("structpoint data:%p \n",dln_p); // is not &x?
 printf("struct int data:%d \n",x.data);
 printf("struct int data location:%p \n",&(x.data));
 printf("struct int data2:%d \n",x.data2);
 printf("struct int data2 location:%p \n",&(x.data2));
 printf("struct size:%d \n",sizeof(x)); // int+int = 4+4 =8

/*
structpoint operation:
structpoint variable get data(dln_p->data same as (*dln_p).data) replace "struct varible" get data(x.data)
 
note:
structpoint (*dln_p) replace struct variable x,both are variable name

example:
structVarible same as variable,structpoint same as pointVariable(but its datatype is struct),both have the same useage
*/

 dln_p = &x;
 printf("x structpoint data:%p \n",dln_p); // is &x
 printf("x strut data by structpoint:%d \n",dln_p->data); 
 printf("x struct data by structVariable:%d \n",x.data);
 
 struct double_listnode *xpt;
 printf("structpoint:%p \n",dln_p);
 printf("x structpoint:%p \n",xpt); // is not dln_p? , because it can not auto execute code "xpt = &x;"
  
/*
difference of point:pointVariable,structpoint
 
note:
sampleCode_1. "structpoint" can be use as pointVariable,and both have the same useage
 
sampleCode_2. structVariable name is not necessarily
 
sampleCode_3. "structpoint" is not NULL,it can operate struct of data,but not ensure its(structVarible) variableSpace range is enough. 
 
sampleCode_4. generate value by malloc() give "structpoint" the data(free space in memory of loaction recode).and it can operate struct of data
 
summary:
1. "structpoint" of data can be varible location or pointVariable location or structpoint its location or malloc()

2. "structpoint" of data use malloc() can ensure its(structVariable) variableSpace range is enough,because malloc() can check memory space.on the contrary,others can not,because they can not check memory space.

3. malloc() every time return "value" is new location data,these ones(return data) can not repeat(unstable)."&" return "value" is variable location data,these ones(return data) are stable.so we create data put in memory,the best choice is use malloc() to put our data,because it(data) can not be covered 
 */

//sampleCode_1
 int y = 50;
 int *ypt;
 struct double_listnode sy;
 struct double_listnode *sypt;

 printf("varible y location:%p \n",&y);
 printf("set variable y point...... \n");
 ypt = &y;
 printf("pointVariable *ypt of data:%p \n",ypt); //is &y
 
 printf("structVariable sy location:%p \n",&sy);
 printf("set struct sy structpoint...... \n");
 sypt = &sy;
 printf("structpoint of data:%p \n",sypt); //is &sy

 printf("pointVarible of data(variable y location) put in structpoint...... \n");
 sypt = ypt;
 printf("structpoint of data:%p \n",sypt); // is &y

//sampleCode_2
 int z = 5;
 int *zpt = &z;
 struct double_listnode *zspt;
 
 printf("variable z location:%p \n",&z);
 printf("pointVriable of data:%p \n",zpt); 
 printf("strctpoint of data:%p \n",zspt); 
 
/*
 zspt = &z; same as the pseudocode:

 struct double_listnode z = {5,NULL};
 struct double_listnode *zspt = &z;
  
 note:
 it only can use "runtime",do not use "static"
*/

 printf("set struct ? of point...... \n"); 
 zspt = &z;
 printf("structpoint of data:%p \n",zspt); // is &z
/*
 printf("struct ? data:%d \n",double_listnode.data); // error: ? undeclare
 printf("struct ? data2:%d \n",double_listnode.data2); //error: ? undeclare
*/
 printf("struct ? data by structpoint:%d \n",zspt->data); // is 5(int z=5;)
 printf("struct ? data2 by structpoint:%d \n",zspt->data2); // is default value
/*
 printf("struct ? data3 by structpoint:%d \n",zspt->data3); // error:struct has not data3,variable not exist
*/

//note:this operate,its structVariable has not varibleName,onle has structpoint

//sampleCode_3
 struct double_listnode *kspt;
 printf("structpoint of data:%p \n",kspt); // is NULL,but it has location
/* 
printf("struct ? data by structpoint:%d \n",kspt->data); // error:structpoint data is NULL,it(memory) not location call "NULL",of course can not find data in memory.so return "Segmentation fault".
 printf("struct ? data2 by structpoint:%d \n",kspt->data2); //error:data2 resoult same as data
*/

/*
 &kspt->data same as the pseudocode:
  
 kspt = &kspt; // use "structpoint" location(memory) to its data
 kspt->data; //use structpoint operate struct of data
 
 note:
 it only can use "runtime",do not use "static" 
*/

 //&kspt->data = 7;
 //&kspt->data2 = 666;
 printf("auto set struct ? of point...... \n"); 
 printf("struct ? data by structpoint:%d \n",&kspt->data); // is 7
 printf("struct ? data2 by structpoint:%d \n",&kspt->data2); // is 666
 
//sampleCode_4 
 struct double_listnode *vspt;
 struct double_listnode *mspt;

/* non-malloc */
 printf("set struct ? point...... \n");
 vspt = &mspt;
 printf("structpoint vspt data:%p \n",vspt);
 vspt->data = 2; 
 printf("[first time]struct ? data by structpoint:%d \n",vspt->data);
 
 printf("set struct ? point...... \n");
 vspt = &mspt;
 printf("structpoint vspt data:%p \n",vspt);
 printf("[second time]struct ? data by structpoint:%d \n",vspt->data);

/* malloc */
 printf("set struct ? point by malloc...... \n");
 mspt = malloc(sizeof(struct double_listnode));
 printf("structpoint mspt data:%p \n",mspt);
 mspt->data = 7; 
 printf("[first time]struct ? data by structpoint:%d \n",mspt->data);
 
 printf("set struct ? point by malloc...... \n");
 mspt = malloc(sizeof(struct double_listnode));
 printf("structpoint mspt data:%p \n",mspt);
 printf("[second time]struct ? data by structpoint:%d \n",mspt->data);

 return 0;
}
