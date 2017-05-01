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
double ret_uniform_pdf(double alpha,double beta,double x)
{  double pdf;
  
  pdf=1/(beta-alpha);
  return(pdf); 
  }
double ret_rayleigh_pdf(double lamda,double c,double x)
{  double ret_function;
  
  if (x>=c)
  {
  ret_function=lamda*exp(-1*lamda*(x-c) *(x-c));
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
     double *datastoreA1,*datastoreA2,*datastoreB,*datastoreC;
	 double *data1,*data2,sum,pdf,X1,X2,tepX1,tepX2,tep;
	 double alpha1,beta1,lamda2,c2;
     double lower1,upper1,lower2,upper2,result1,x1,x2,ret_function,pdfx1,pdfx2;
     int n=100000000,j,n1;// n�O���������� 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
     alpha1=-10;beta1=10; lamda2=4.5;c2=0;
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	pdf=ret_rayleigh_pdf(lamda2,c2,x1);
     	if (pdf>0 && j==0) { j=1; lower2=x1; continue; }
     	if (pdf<=0 && j==1) { j=2; upper2=x1;break; }
     	}
     
     datastoreA1=(double *)malloc(n*sizeof(double));
     datastoreA2=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     lower1=alpha1; upper1=beta1;
     lower2=c2;
     printf(" �ݭn�@�q�ɶ��p�� �� 11 ���t����Ʈw,....\n");  
     printf(" ��������H���ܼƪ��p�X���v�K�ר��,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower1,upper1);
       pdfx1=ret_uniform_pdf(alpha1,beta1,X1);
       X2=uniform_simulated(lower2,upper2);
       pdfx2=ret_rayleigh_pdf(lamda2,c2,X2);
       pdf=pdfx1*pdfx2;
       if (pdf<=0) { --i; continue;    }
       datastoreA1[i]=X1; datastoreA2[i]=X2; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       printf(" �إ߬۹�ֿn���ƪ���Ʈw,...\n");
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       free(datastoreB);
       printf(" �إ��H���ܼƭȪ���Ʈw,...\n");
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         tepX1=datastoreA1[j];
         tepX2=datastoreA2[j];
         tep=tepX1*tepX1+tepX2*tepX2;
         if (tep>0) tep=exp(0.5*log(tep)); else tep=0;
         data1[i]=tep; 
         data2[i]=atan(tepX1/tepX2);
      	}  
       free(datastoreA1);free(datastoreA2);  free(datastoreC);
       Joint_plotx('Y',1,'Y',2,data1,data2,n,5);
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data1);
       printf(" �����Ƨ�.....\n");
	   Plotx(data1,n,'Y',1); 
	   printf(" �Ƨ�.....\n");
       Sortx(0,n,data2);
       printf(" �����Ƨ�.....\n");
	   Plotx(data2,n,'Y',2); 
	   free(data1);free(data2);
       free(Simulation); free(Simulationx);
return 0;
}
