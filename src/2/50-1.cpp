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
double ret_F_pdf(double df1,double df2,double x)
{  double ret_function, tep1,tep2,tep3;
  
  if (x>0)
  {
  tep1=exp((df1/2-1)*log(x));
  tep2=1+df1/df2*x;
  tep3=exp((-1*(df1+df2)/2)*log(tep2));
  ret_function=tep1*tep3;
  if (ret_function<0.000000001)  ret_function=0;
   }
  else ret_function=0;
  return(ret_function); 
  }

double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// 機率分配個數的宣告
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc,df1,df2;
     int n=100000000,j,n1;// n是模擬的次數 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 F 分配的資料庫,....\n");  
     df1=30; df2=50;
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	pdf=ret_F_pdf(df1,df2,x1);
     	if (pdf>0 && j==0) { j=1; lower=x1; continue; }
     	if (pdf<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	pdf=ret_F_pdf(df1,df2,x1);
     	if (pdf<=0) break;}
     upper=x1-0.00001;
     lower=0;
     inc=(upper-lower)/(double)n;
     printf(" 模擬中間值與機率密度函數,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf=ret_F_pdf(df1,df2,w);
       if (pdf<=0) { --i; continue;    }
       datastoreA[i]=w; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" 建立相對累積次數的資料庫,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" 建立隨機變數值的資料庫,...\n");
       data=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
      	}   
       printf(" 排序.....\n");
       Sortx(0,n,data);
       printf(" P(X1<=%f)=0.005,\n",data[(int)((double)n*0.005)]);
       printf(" P(X1<=%f)=0.01,\n",data[(int)((double)n*0.01)]);
       printf(" P(X1<=%f)=0.025,\n",data[(int)((double)n*0.025)]);
       printf(" P(X1<=%f)=0.05,\n",data[(int)((double)n*0.05)]);
       printf(" P(X1<=%f)=0.1,\n",data[(int)((double)n*0.1)]);
       printf(" P(X1<=%f)=0.9,\n",data[(int)((double)n*0.9)]);
       printf(" P(X1<=%f)=0.95,\n",data[(int)((double)n*0.95)]);
       printf(" P(X1<=%f)=0.975,\n",data[(int)((double)n*0.975)]);
       printf(" P(X1<=%f)=0.99,\n",data[(int)((double)n*0.99)]);
       printf(" P(X1<=%f)=0.995,\n",data[(int)((double)n*0.995)]);
       system("pause");
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
       free(Simulation); free(Simulationx);
return 0;
}

