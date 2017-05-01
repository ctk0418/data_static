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
double negative_binomialx(double r,double p)
{
  double tep=-1,tepx1,pp2,tepxx,tsum;
  int j,ii;
 
   tepxx=0;
   for(ii=0;ii<(int)r;++ii)
    {
     tepx1= uniform_simulated(0,1);  pp2=p;
	 for(j=0;;++j)
     {
      if (j==0) tsum=pp2; else {pp2=pp2*(1-p);tsum=tsum+pp2;}
      if (tsum>=tepx1)  break; 
      }
     tepxx=tepxx+(double)(j+1);
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
     double *datastore,p,r; //模擬資料的儲存處
     int n=100000000;// 模擬的次數 

   Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
   Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //宣告模擬資料庫空間
     r=5; p=0.4;
     printf(" 開始模擬 Negative Binomial 分配 資料\n");
	 for(i=0;i<n;++i)
	   datastore[i]= negative_binomialx(r,p);  // Negative Binomial (r,p)
	 printf(" 開始排序資料\n");
	 Sortx(0,n,datastore); //排序模擬資料
	 printf(" 排序完成\n");
	 Plotx(datastore,n,'X',1); //模擬資料次數分配圖示與統計係數 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}

