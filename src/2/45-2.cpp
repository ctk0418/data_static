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
double hyper_geometric(double NN,double success,double trialnumber)
{
  double tep=-1,tepx1,tepxx,pp2;
  int j,N,k,n,kk;
  
  tepxx=0;N=(int)NN;
  k=(int)success;
  n=(int)trialnumber;
  kk=N-k;  
  for(j=1;j<=n;++j)
   {tepx1=uniform_simulated(0,1);
    pp2=(double)k/(double)N;
    if (k<=0) tepx1=(double)0;
    else
    if (kk<=0) tepx1=(double)1;
    else
	if (tepx1<=pp2) { k--; tepx1=(double)1;	} else { tepx1=(double)0; kk--; }
	N--;
	tepxx=tepxx+tepx1;
      	      }  
   tep=tepxx;
   return(tep);
}
int main() {  

     double N,k,trialnumber,X1;
     int i,m=100;

     N=100; k=40; trialnumber=20;
     printf(" 開始模擬 Hyper geometric 分配 資料\n");
	 for(i=0;i<m;++i)
	  { X1= hyper_geometric(N,k,trialnumber);
       // Hyper geoemtric(N,k,trialnumber)
        printf("%d  %f\n",i+1,X1);
       } 
return 0;
}

