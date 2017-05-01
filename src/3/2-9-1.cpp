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
double ret_joint_function2(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=x1+x2;
  return(ret_function); 
  }
 
int main() {  
     double ret_function,count1; // ��ƭ� 
     double lower1,upper1,lower2,upper2,sum,area,sumfunction,X1,X2,tepX1,tep2;
     int n=100000000,i,flag;// n�O���������� 
     char *ss;

     upper1=5; lower1=0; upper2=5; lower2=0;
     printf(" �����n��,...\n");
     sumfunction=0;
     for(i=0;i<n;++i,count1+=1)
     { flag=0;
       X1=uniform_simulated(lower1,upper1); 
       X2=uniform_simulated(lower2,upper2); 
       if (X1>0) tepX1=exp(0.5*log(X1)); else tepX1=X1;
       if (X2<tepX1*cos(X1*M_PI) || X1*cos(X1*M_PI)<X2) flag=1;
       tep2=atan(X1*X2);
	   if (tep2<0.1) flag=1; 
       if (flag==1){ --i; continue; } //��Ƥ��ŦX
       ret_function=ret_joint_function2(X1,X2);
       sumfunction=sumfunction+ret_function;   
	    } 
     sumfunction=sumfunction/(double)n;
     area=(upper1-lower1)*(upper2-lower2)*(double)n/count1; // ���n 
	 sum=sumfunction*area;
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," �n��=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"�ƭȤ��R���L�n��",MB_OK);
     free(ss);
return (0);
}