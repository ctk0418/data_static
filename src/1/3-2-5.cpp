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
double ret_function3_pdf(double x)
{ double ret_function;
   
  ret_function=x*cos(x*x*M_PI)+exp(x)*cos(x*M_PI)*cos(x*M_PI);
  return(ret_function); 
  }
int main() {  
     double ret_function; // ��ƭ� 
     double lower,upper,sum,area,sumfunction,X1;
	 // upper�O�ܼƪ��W����   lower�O�ܼƪ��U���� 
     int n=10000,i;// n is ���έӼ� 
     char *ss;

     upper=1; lower=0;
     printf(" �����n��,...\n");
     sumfunction=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper); 
       ret_function=ret_function3_pdf(X1);
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
