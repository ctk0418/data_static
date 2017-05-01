#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <c:\\simulated_book\\include_dll\\DLL_function_type.cpp>
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
   {tepx1= uniform_simulated(0,1);
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
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// 機率分配個數的宣告
     double *datastore,N,k,trialnumber,phat,p,tep1; //模擬資料的儲存處
     int n=100000000;// 模擬的次數 

   Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
   Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //宣告模擬資料庫空間
     N=1000; k=400; trialnumber=100;
     p=k/N;
     printf(" 開始模擬 Hyper geometric 分配 資料\n");
     tep1=p*(1-p)*(N-trialnumber)/(N-1);
     tep1=exp(0.5*log(tep1));
	 for(i=0;i<n;++i)
	   {
	   	phat=hyper_geometric(N,k,trialnumber)/100;
	   	if (phat<=0 || phat>=1) { --i; continue;  	}
	   	datastore[i]=10*(phat-p)/tep1;
	   }
     // Hyper geoemtric(N,k,trialnumber)
	 printf(" 開始排序資料\n");
	 Sortx(0,n,datastore); //排序模擬資料
	 printf(" 排序完成\n");
	 Plotx(datastore,n,'X',1); //模擬資料次數分配圖示與統計係數 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}

