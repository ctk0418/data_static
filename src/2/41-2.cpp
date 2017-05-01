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
double poisson(double lamda)
{
  double tep=-1,tepx1,pp2,tsum,tepx2,px1;
  int j,nn,i;
  
   if (lamda<=20)
   {
   tepx1=uniform_simulated(0,1);
   pp2=exp(-1*lamda);tsum=pp2;
   for(j=0;;++j)
   if (tsum>=tepx1)  break; else { pp2=pp2*lamda/(double)(j+1); tsum=tsum+pp2;}
   tep=(double)j;   }
   else
   {
   	nn=(int)lamda;tepx2=0;
   	for(i=1;i<nn;++i)
   	{
   	 tepx1=uniform_simulated(0,1);
     pp2=exp(-1);tsum=pp2;
     for(j=0;;++j)
      if (tsum>=tepx1)  break; else { pp2=pp2/(double)(j+1); tsum=tsum+pp2;}
      tepx2=tepx2+(double)j;
	    }
	px1=lamda-(double)(nn-1);
	if (px1>0)
	{
	tepx1=uniform_simulated(0,1); 
	pp2=exp(-1*px1);tsum=pp2;
    for(j=0;;++j)
    if (tsum>=tepx1)  break; else { pp2=pp2*px1/(double)(j+1); tsum=tsum+pp2;}
    tepx2=tepx2+(double)j;  
	tep=tepx2;	}
   }
  return(tep);
}
int main() {  

     double lamda,X1;
     int i,m=100;

     lamda=5;
     printf(" 開始模擬 Poisson 分配 資料\n");
	 for(i=0;i<m;++i)
	  { X1= poisson(lamda);  //Poisson(lamda)
        printf("%d  %f\n",i+1,X1);
       } 
return 0;
}

