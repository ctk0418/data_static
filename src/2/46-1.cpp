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

double ret_spc1_pdf(double a,double b,double x)
{  double ret_function,tep1;
  
  tep1=exp((a-1)*log(x));
  ret_function=a*b/(a+b)*(tep1+1/b);
  return(ret_function); 
  }
int main() {  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,y,w;
     double lower,upper,result1,inc,a,b;
     double mean,var,sigma,gamma1,gamma2;
     int n=100000000,i,j,n1;// n�O���������� 

     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� �S�w ���t����Ʈw,....\n");  
     a=10;b=1;
     upper=1;
     lower=0;
     inc=(upper-lower)/(double)n;
     printf(" ���������ȻP���v�K�ר��,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf= ret_spc1_pdf(a,b,w);
       if (pdf<=0) { --i; continue;    }
       datastoreA[i]=w; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" �إ߬۹�ֿn���ƪ���Ʈw,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       data=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
           }  
       mean=0;
       for(i=0;i<n;++i) mean=mean+data[i];
       mean=mean/(double)n;
       var=0;
       for(i=0;i<n;++i) var=var+(data[i]-mean)*(data[i]-mean);
       var=var/(double)n;
       sigma=exp(0.5*log(var));
       gamma1=0;
       for(i=0;i<n;++i) gamma1=gamma1+(data[i]-mean)*(data[i]-mean)*(data[i]-mean)/(var*sigma);
       gamma1=gamma1/(double)n;
       gamma2=0;
       for(i=0;i<n;++i) gamma2=gamma2+(data[i]-mean)*(data[i]-mean)*(data[i]-mean)*(data[i]-mean)/(var*var);
       gamma2=gamma2/(double)n;
       printf(" E(X1)=%f\n",mean);
       printf(" Var(X1)=%f\n",var);
       printf(" X1���A�Y��=%f\n",gamma1);
       printf(" X1�p�A�Y��=%f\n",gamma2);
       system("pause");
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
return 0;   }

