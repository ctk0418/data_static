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
double ret_semicircle_pdf(double mu,double R,double x)
{  double pdf,z;
  z=R*R-(x-mu)*(x-mu);
  if (z>0) pdf=2*exp(0.5*log(z))/(M_PI*R*R);
  else pdf=0;
  return(pdf); 
  }
int main() {  
     double mu,R;
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,X1;
     double lower,upper,result1;
     int n=100000000,i,j,n1,m=100;// n�O����������

     mu=10;
     R=20;
     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Semi circle ���t����Ʈw,....\n");  
     upper=mu+R;
     lower=mu-R;
     printf(" �����üƭȻP���v�K�ר��,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper);
       pdf=ret_semicircle_pdf(mu,R,X1);
       datastoreA[i]=X1; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" �إ߬۹�ֿn���ƪ���Ʈw,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" ��X�������,...\n");
       data=(double *)malloc(n*sizeof(double));
       for(i=0;i<m;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
         printf(" %d  %20.10f\n",i+1,data[i]);
      	}  
       system("pause");
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
return 0;
 }
