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
double ret_kumaraswamy_pdf(double a,double b,double x)
{  double pdf,tep1,tep2,tep3;
  
  tep1=a*b*exp((a-1)*log(x));
  tep2=1-exp(a*log(x));
  tep3=exp((b-1)*log(tep2));
  pdf=tep1*tep3;
  return(pdf); 
  }
int main() {  
     double a,b;
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,X1;
     double lower,upper,result1;
     int n=100000000,i,j,n1,m=100;// n是模擬的次數

     a=4; 
     b=10;
     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 Kumaraswamy分配的資料庫,....\n");  
     upper=1;
     lower=0;
     printf(" 模擬亂數值與機率密度函數,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper);
       pdf=ret_kumaraswamy_pdf(a,b,X1);
       datastoreA[i]=X1; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" 建立相對累積次數的資料庫,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" 輸出模擬資料,...\n");
       data=(double *)malloc(n*sizeof(double));
       for(i=0;i<m;++i) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
         printf(" %d  %20.10f\n",i+1,data[i]);
      	}  
       system("pause");
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
return 0;
 }

