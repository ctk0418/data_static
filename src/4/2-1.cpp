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
double ret_joint_function1(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=x1+x2;
  return(ret_function); 
  }
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastoreA1,*datastoreA2,*datastoreB,*datastoreC;
	 double *data1,*data2,sum,pdf,X1,X2;
     double lower1,upper1,lower2,upper2,result1,inc;
     int n=100000000,j,n1;// n�O���������� 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
     datastoreA1=(double *)malloc(n*sizeof(double));
     datastoreA2=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� �� 2 ���t����Ʈw,....\n");  
     upper1=1;   lower1=0;
     upper2=1;   lower2=0;
     printf(" ��������H���ܼƪ��p�X���v�K�ר��,...\n");
     sum=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower1,upper1);
       X2=uniform_simulated(lower2,upper2);
       pdf=ret_joint_function1(X1,X2);
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
         data1[i]=datastoreA1[j]; 
         data2[i]=datastoreA2[j];
      	}  
       free(datastoreA1);free(datastoreA2);  free(datastoreC);
       Joint_plotx('X',1,'X',2,data1,data2,n,5);
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data1);
       printf(" �����Ƨ�.....\n");
	   Plotx(data1,n,'X',1); 
	   printf(" �Ƨ�.....\n");
       Sortx(0,n,data2);
       printf(" �����Ƨ�.....\n");
	   Plotx(data2,n,'X',2); 
	   free(data1);free(data2);
       free(Simulation); free(Simulationx);
return 0;
}

