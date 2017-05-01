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
double bernoulli(double p)
{
  double tep=-1,tepxx;
  
  tepxx= uniform_simulated(0,1);
  if (tepxx<=p) tep=(double)1; else tep=(double)0; 
  return(tep);
}
int main() {  

     double p,X1; 
     int i,m=100;

     p=0.3;
     printf(" 開始模擬 Bernoulli分配 資料\n");
	 for(i=0;i<m;++i)
	  { X1=bernoulli(p);  //模擬 Bernoulli(p)
        printf("%d  %f\n",i+1,X1);
       } 
return 0;
}


