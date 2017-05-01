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
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// 機率分配個數的宣告
     double *datastore,p,trialnumber,phat; //模擬資料的儲存處 
     int n=100000000;// 模擬的次數 

     Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
     Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //宣告模擬資料庫空間
     trialnumber=100; p=0.5;
     printf(" 開始模擬 Binomial 分配 資料\n");
	 for(i=0;i<n;++i)
	   {
	   	phat=binomial(trialnumber,p)/100;  //模擬 Binomial (trialnumber,p)
	   	if (phat<=0 || phat>=1) { --i; continue; 	}
	   	datastore[i]=10*(phat-p)/exp(0.5*log(phat*(1-phat)));
	   }
	 printf(" 開始排序資料\n");
	 Sortx(0,n,datastore); //排序模擬資料
	 printf(" 排序完成\n");
	 Plotx(datastore,n,'W',1); //模擬資料次數分配圖示與統計係數 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}
