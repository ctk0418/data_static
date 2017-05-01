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
double ret_weibull_pdf(double alpha,double beta,double gamma,double x)
{  double ret_function,tep1,tep2,tep3,tep4;
  if (x>=alpha)  
  { tep1=(x-alpha)/beta;
   tep2=exp((gamma-1)*log(tep1));
   tep3=exp(gamma*log(tep1));
   tep4=exp(-1*tep3);
   ret_function =gamma*tep2*tep4/beta;
   if (ret_function<0.0000000001)   ret_function=0; }
  else ret_function=0;
  return(ret_function); 
  }
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,X1,x1;
     double lower,upper,result1,alpha,beta,gamma;
     int n=100000000,j,n1;// n�O���������� 
  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Weibull ���t����Ʈw,....\n");  
     alpha=2;  beta=3; gamma=4;
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	pdf= ret_weibull_pdf(alpha,beta,gamma,x1);
     	if (pdf>0 && j==0) { j=1; lower=x1; continue; }
     	if (pdf<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	pdf= ret_weibull_pdf(alpha,beta,gamma,x1);
     	if (pdf<=0) break;}
     upper=x1-0.00001;
     lower=alpha;
     printf(" �����üƭȻP���v�K�ר��,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper);
       pdf= ret_weibull_pdf(alpha,beta,gamma,X1);
       datastoreA[i]=X1; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" �إ߬۹�ֿn���ƪ���Ʈw,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" �إ��H���ܼƭȪ���Ʈw,...\n");
       data=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]/(1+datastoreA[j]); 
      	}   
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data);
       printf(" �����Ƨ�.....\n");
	   Plotx(data,n,'Y',1); //������Ʀ��Ƥ��t�ϥܻP�έp�Y�� 
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
       free(Simulation); free(Simulationx);
return 0;
 }

