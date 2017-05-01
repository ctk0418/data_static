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

double ret_normal_pdf(double mu,double sigma,double x)
{  double ret_function,z,tep1;
  
  z=(x-mu)/sigma;
  tep1=exp(0.5*log(2*M_PI))*sigma;
  ret_function=exp(-0.5*z*z)/tep1;
  return(ret_function); 
  }
int main() {  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc,mu,sigma;
     int n=100000000,i,j,n1;// n是模擬的次數 
     FILE *file;

     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 Normal 分配的資料庫,....\n");  
     mu=0; sigma=1;
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	pdf=ret_normal_pdf(mu,sigma,x1);
     	if (pdf>0 && j==0) { j=1; lower=x1; continue; }
     	if (pdf<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	pdf=ret_normal_pdf(mu,sigma,x1);
     	if (pdf<=0) break;}
     upper=x1-0.00001;
     for(x1=lower-1;;x1+=0.00001)
     {
     	pdf=ret_normal_pdf(mu,sigma,x1);
     	if (pdf>0) break;}
     lower=x1-0.00001;
     inc=(upper-lower)/(double)n;
     printf(" 模擬中間值與機率密度函數,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf= ret_normal_pdf(mu,sigma,w);
       if (pdf<=0) { --i; continue;    }
       datastoreA[i]=w; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" 建立相對累積次數的資料庫,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" 輸出模擬資料,...\n");
       data=(double *)malloc(n*sizeof(double));
       file=fopen("C:\\simulated_book\\tep\\暫存資料01.txt","w");
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
         fprintf(file,"%20.10f\n",data[i]);   }  
       fclose(file);
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
return 0;   }

