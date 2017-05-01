#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double dividewangxx=(double)32767*(double)32767*(double)32767;
double uniform_simulated(double alpha,double beta)
{
   double tep1,tep=0,dividewangx;
 
   again:
   tep1=((double)rand()*(double)32767*(double)32767+(double)rand()*(double)32767+(double)rand())/dividewangxx;
   if (tep1<0 || tep1>1) goto again;
   tep=alpha+tep1*(beta-alpha);  
   return(tep);
}
double binomial(double trialnumber,double p)
{
  double tep=-1,tepx1,tepxx;
  int j;
  
  tepxx=0;
  for(j=1;j<=(int)trialnumber;++j)
   {tepx1=uniform_simulated(0,1);
	if (tepx1<=p) tepx1=(double)1; else tepx1=(double)0; 
	tepxx=tepxx+tepx1;
      	      }
   tep=tepxx;
  return(tep);
}

int main() {  

     double p,trialnumber,X1;
     int i,m=100;

     trialnumber=100; p=0.5;
     printf(" 開始模擬 Binomial 分配 資料\n");
	 for(i=0;i<m;++i)
	  { X1=binomial(trialnumber,p);  //模擬 Binomial (trialnumber,p)
        printf("%d  %f\n",i+1,X1);
       } 
return 0;
}

