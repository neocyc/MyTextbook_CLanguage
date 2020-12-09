/*
 1.static variable and runtime variale has default value put in memory
 2.runtime of static variable has default value "NULL" put in memory 
 3.static pointvariable has default value "NULL" put in memory 
 4.runtime pointvariale has default value put in memory
 5.const of pointvariable has default value "NULL" put in memory on static/runtime

note: in this "default value" is OS generate
*/

#include<stdio.h>
int bg;
int *ptg;
const int *eg;
const int cg;
typedef int bgd;
typedef int* ptgd;
typedef const int cgd;
typedef const int* egd;

int main(void)
{
 printf("hellowork! \n");
 
 int b;
 bgd bgg;
 static int bs;
 int *pt;
 ptgd *ptt;
 static int *pts;
 egd egg;
 const int *e;
 const int d;
 cgd cgg;

 printf("variable b on runtime:%d \n",b);
 printf("bg on static:%d \n",bg);
 printf("def bg on runtime:%d \n",bgg);
 printf("varible static bs on runtime:%p \n",bs);

 printf("varible pt on runtime:%p \n",pt);
 printf("*ptg on static :%p \n",ptg);
 printf("def *ptg on runtime:%p \n",ptt);
 printf("varible static pts on runtime:%p \n",pts);

 printf("varible const d on runtime:%d \n",d);
 printf("const cg on static:%d \n",cg);
 printf("def cg on runtime:%d \n",cgg);

 printf("varible constPoint *e on runtime:%p \n",e);
 printf("constPointoint *eg on static:%p \n",eg);
 printf("def *eg on runtime:%p \n",egg);

 return 0;
}
