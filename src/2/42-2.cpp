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
double geometric (double p)
{
  double tep=-1,tepx1,pp2,tsum;
  int j;

   tepx1= uniform_simulated(0,1); 
   pp2=p;
   for(j=0;;++j)
   {
    if (j==0) tsum=pp2; else {pp2=pp2*(1-p);tsum=tsum+pp2;}
    if (tsum>=tepx1)  break; 
    }
    tep=(double)(j+1);
  return(tep);
}
int main() {  

     double p,X1;
     int i,m=100;

     p=0.2;
     printf(" 開始模擬 Geometric 分配 資料\n");
	 for(i=0;i<m;++i)
	  { X1= geometric(p);  // Geometric(p)
        printf("%d  %f\n",i+1,X1);
       } 
return 0;
}

