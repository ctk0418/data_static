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

double ret_pareto1_pdf(double lamda,double c,double x)
{  double ret_function;
  if (x>=0)  ret_function=lamda*exp((lamda-1)*log(x/c));
  else ret_function=0;
  return(ret_function); 
  }
int main() {  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc,lamda,c;
     int n=100000000,i,j,n1,m=100;// n�O���������� 

     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Pareto 1 ���t����Ʈw,....\n");  
     lamda=5.5; c=2;
     upper=c;
     lower=0;
     inc=(upper-lower)/(double)n;
     printf(" ���������ȻP���v�K�ר��,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf= ret_pareto1_pdf(lamda,c,w);
       if (pdf<=0) { --i; continue;    }
       datastoreA[i]=w; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" �إ߬۹�ֿn���ƪ���Ʈw,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" ��X�������,...\n");
       data=(double *)malloc(m*sizeof(double));
       for(i=0;i<m;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
         printf(" %d  %20.10f\n",i+1,data[i]);   }  
       system("pause");
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
return 0;   }

