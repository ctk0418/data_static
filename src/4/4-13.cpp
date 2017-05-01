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
int serach_index(double *df,double result,int n_begin,int n_end)
 {
   int i;
   int ret;
   
   if (n_begin==n_end) return(n_end);
   if (n_begin+1==n_end) return(n_end);
   if (result<df[(n_begin+n_end)/2])
   ret=serach_index(df,result,n_begin,(n_begin+n_end)/2);
   else if (result>df[(n_begin+n_end)/2])
   ret=serach_index(df,result,(n_begin+n_end)/2,n_end);
   else if (result==df[(n_begin+n_end)/2]) return((n_begin+n_end)/2);
   return(ret);
 }
double ret_joint_function4(double x1,double x2)
{ 
  double ret_function;
  
  if (x1>0 && x2>0)
  {
  ret_function=exp(-1*(x1+x2+x1*x2));
  if (ret_function<0.00000001) ret_function=0;}
  else ret_function=0;
  return(ret_function); 
  }
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// 機率分配個數的宣告
     double *datastoreA1,*datastoreA2,*datastoreB,*datastoreC;
	 double *data1,*data2,sum,pdf,X1,X2,tepX1,tepX2,tep,count1=0;
     double lower1,upper1,lower2,upper2,result1,x1,x2,ret_function;
     int n=100000000,j,n1;// n是模擬的次數 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_joint_function4(x1,x1);
     	if (ret_function>0 && j==0) { j=1; lower1=x1; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper1=x1;break; }
     	}
     lower1=0;
     j=0;
     for(x2=-1000000;x2<1000000;x2=x2+1)
     {
     	ret_function=ret_joint_function4(x2,x2);
     	if (ret_function>0 && j==0) { j=1; lower2=x2; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper2=x2;break; }
     	}
     lower2=0;
     datastoreA1=(double *)malloc(n*sizeof(double));
     datastoreA2=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 例 4 分配的資料庫,....\n");  
     printf(" 模擬兩個隨機變數的聯合機率密度函數,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower1,upper1);
       X2=uniform_simulated(lower2,upper2);
       pdf=ret_joint_function4(X1,X2);
       if (pdf<=0) { --i; continue;    }
       datastoreA1[i]=X1; datastoreA2[i]=X2; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" 建立相對累積次數的資料庫,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       free(datastoreB);
       printf(" 建立隨機變數值的資料庫,...\n");
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i,count1+=1) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         j=serach_index(datastoreC,result1,0,n-1);
         tepX1=datastoreA1[j]; tepX2=datastoreA2[j];
         tep=tepX1*tepX1+tepX2*tepX2;
         if (tep<2 || tep>50)  { --i; continue;}
		 data1[i]=tepX1;
		 data2[i]=tepX2; 
	    }
	   printf("P(符合要求)=%f\n",(double)n/count1);
       free(datastoreA1);free(datastoreA2);  free(datastoreC);
       Joint_plotx('X',1,'X',2,data1,data2,n,5);
       printf(" 排序.....\n");
       Sortx(0,n,data1);
       printf(" 完成排序.....\n");
	   Plotx(data1,n,'X',1); 
	   printf(" 排序.....\n");
       Sortx(0,n,data2);
       printf(" 完成排序.....\n");
	   Plotx(data2,n,'X',2); 
	   free(data1);free(data2);
       free(Simulation); free(Simulationx);
return 0;
}


