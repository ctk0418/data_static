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
double ret_joint_function1(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=1;
  return(ret_function); 
  }
 
int main() {  
     double ret_function; // ��ƭ� 
     double lower1,upper1,lower2,upper2,sum,sum1,area,sumfunction,X1,X2;
     int n=100000000,i;// n�O���������� 
     char *ss;

     upper1=1; lower1=-1; upper2=2; lower2=-2;
     printf(" �����n��,...\n");
     sumfunction=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower1,upper1); 
       X2=uniform_simulated(lower2,upper2); 
       ret_function=ret_joint_function1(X1,X2);
       sumfunction=sumfunction+ret_function;   
	    } 
     sumfunction=sumfunction/(double)n;
     area=(upper1-lower1)*(upper2-lower2); //���n 
	 sum=sumfunction*area;
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," �n��=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"�ƭȤ��R���L�n��",MB_OK);
     free(ss);
return (0);
}