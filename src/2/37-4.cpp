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
   return(ret); }
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
int main() {  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,X1,x1;
     double lower,upper,result1,df1,df2;
     int n=100000000,i,j,n1,m=100;// n�O���������� 

     // 1st total simulating data storage after operation
     datastoreA=(double *)malloc(n*sizeof(double));
     // 2nd total simulating data storage after operation
     datastoreB=(double *)malloc(n*sizeof(double));
     // 3rd total simulating data storage after operation
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� F ���t����Ʈw,....\n");  
     df1=10; df2=10;
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {  pdf=ret_F_pdf(df1,df2,x1);
     	if (pdf>0 && j==0) { j=1; lower=x1; continue; }
     	if (pdf<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {  pdf= ret_F_pdf(df1,df2,x1);
     	if (pdf<=0) break;}
     upper=x1-0.00001;
     for(x1=lower-1;;x1+=0.00001)
     {  pdf= ret_F_pdf(df1,df2,x1);
     	if (pdf>0) break;}
     lower=x1-0.00001;
     printf(" �����üƭȻP���v�K�ר��,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { X1=uniform_simulated(lower,upper);
       pdf= ret_F_pdf(df1,df2,X1);
       datastoreA[i]=X1; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" �إ߬۹�ֿn���ƪ���Ʈw,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       printf(" ��X�������,...\n");
       data=(double *)malloc(m*sizeof(double));
       for(i=0;i<m;++i) 
       {  result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
         printf(" %d  %20.10f\n",i+1,data[i]);   }  
       system("pause");
	   free(data);
       free(datastoreA); free(datastoreB); free(datastoreC);
return 0;
}
