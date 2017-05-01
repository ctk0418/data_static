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
double ret_function4_pdf_check(double x)
{  double ret_function;
  
  ret_function=exp(-0.5*x*x);
  if (ret_function<0.0001) ret_function=0;
  return(ret_function); 
  }
double ret_function4_pdf(double x)
{  double ret_function;
  
  ret_function=exp(-0.5*x*x);
  return(ret_function); 
  }
int main() {  
     double ret_function; // ��ƭ� 
     double lower,upper,X1,x1,sumfunction,sum,area;
	 // upper�O�ܼƪ��W����   lower�O�ܼƪ��U���� 
     int n=10,i,j;// n is ���έӼ� 
     char *ss;
     
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_function4_pdf_check(x1);
     	if (ret_function>0 && j==0) { j=1; lower=x1; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper=x1;break; }
     	}
     printf(" �����n��,...\n");
     sumfunction=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper); 
       ret_function=ret_function4_pdf(X1);
       if (ret_function<=0) { --i; continue;    }
       sumfunction=sumfunction+ret_function;   
	    } 
	 sumfunction=sumfunction/(double)n;
     area=upper-lower;
	 sum=sumfunction*area;
	 ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," �n��=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"�ƭȤ��R���L�n��",MB_OK);
     free(ss);
return (0);
}
