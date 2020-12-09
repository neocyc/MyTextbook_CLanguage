#include<stdio.h>
#include<stdlib.h>

int main(void)
{
 printf("hellowork! \n");


 int b=8;
 int* pt20;

 pt20 = &b;
 int pt1 = (int)pt20;
 double pt3 = (double)pt1;
 
 printf("b of address:%p \n",&b);
 printf("b of address number put in pt20 :%p \n",pt20);
 printf("go to pt20 get data(b of address) and then find data by address and get it(b of data):%d \n",*pt20);
 printf("point to int resoult of data(adress):%p(address),%d(int) \n",pt1,pt1);
 printf("int to double of data:%p \n",pt3);
 
/*
 1.declare variable,it default value is OS generate(static/runtime) and put in memory
 2.varible can recode memory location,but not complete(data can truncated)
*/
 
 int c;
 printf("int c; \n");
 printf("int c of data:%d \n",c); //int c no data so put ? ans:OS generate value
 printf("int c of address:%p \n",&c); //int c in memery of location
 printf("int c of data by address:%d \n",*(&c)); //get data by address

 c = &c;
 printf("int c=&c; \n");
 printf("int c of data:%d \n",c); //int c have data put ? ans:int c of address
 printf("int c of address:%p \n",&c); //int c in memery of location
 printf("int c of data by address:%d \n",*(&c)); //get data by addrss

/*
 1.declare pointVariable,it default value is NULL(static)/OS generate(runtime) and put in memory
 2.pointVariable can recode complete memory location
*/

 int* d;
 printf("int* d; \n");
 printf("int* d of data:%p \n",d); //int* d no data so put ? ans:OS generate
 printf("int* d of address:%p \n",&d); //int* d in memery of location
 printf("int* d of data by address:%p \n",*(&d)); //get data by address

 d = &d;
 printf("int* d=&d; \n");
 printf("int* d of data:%p \n",d); //int* d have data put ? ans:int* d of address
 printf("int* d of address:%p \n",&d); //int* d in memery of location
 printf("int* d of data by address:%p \n",*(&d)); //get data by addrss

 
 int e = 8;
 int* pte = &e;
 int f = 5;
 int* ptf = &f;

 printf("org data;\n");
 printf("data of e:%d \ne of location:%p \n",e,pte);
 printf("data of f:%d \nf of location:%p \n",f,ptf);

 ptf = &e;
 
/*
 Code Instruction Manual:
 
 int* ptfe = *(&ptf); 
 *ptfe = 70;

 same as *(*(&ptf))=70;
*/
 *(*(&ptf)) = 70;

 printf("tamper e by f of address; \n");
 printf("data e:%d \n",e);
 printf("data of e by f of location:%d \n",*(*(&ptf)));
 printf("f of location:%p \n",ptf);

/*
 runtime const variable of data can be change by pointVariable in runtime
 
 note:static const variable can nat be change by pointVariable
*/
 const int g = 8;
 int *fpt = (int*)&g;

 printf("before const data g:%d \n",g);

 *fpt = 15;

 printf("after const data g:%d \n",g);

/*
 "&" and malloc()
*/
 int *vhpt;
 int *mhpt;

/* non-malloc */
 printf("poinrtVariable vhpt:%p \n",vhpt);
 
 printf("set vhpt data by \"& \"...... \n");
 vhpt = &vhpt;
 printf("[first time]vhpt data:%p \n",vhpt);
 printf("vhpt location:%p \n",&vhpt);

 printf("set vhpt data by \"& \"...... \n");
 vhpt = &vhpt;
 printf("[second time]vhpt data:%p \n",vhpt);
 printf("vhpt location:%p \n",&vhpt);

/* malloc */
 printf("poinrtVariable mhpt:%p \n",mhpt);
 printf("set mhpt data by malloc()...... \n");
 mhpt = malloc(sizeof(mhpt));
 printf("[first time]vhpt data:%p \n",mhpt);
 printf("vhpt location:%p \n",&mhpt);

 printf("set mhpt data by malloc()...... \n");
 mhpt = malloc(sizeof(mhpt));
 printf("[first time]vhpt data:%p \n",mhpt);
 printf("vhpt location:%p \n",&mhpt);

 return 0;
}
