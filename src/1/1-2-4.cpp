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
double ret_function1_pdf(double x)
{ double ret_function;
   
  ret_function=1;
  return(ret_function); 
  }
int main() {  
     double ret_function; // ㄧ计 
     double lower,upper,sum,area,sumfunction,X1;
	 // upper琌跑计   lower琌跑计 
     int n=10000,i;// n is だ澄计 
     char *ss;

     upper=1; lower=0;
     printf(" 家览縩だ,...\n");
     sumfunction=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper); 
       ret_function=ret_function1_pdf(X1);
       sumfunction=sumfunction+ret_function;   
	    } 
     sumfunction=sumfunction/(double)n;
     area=upper-lower;
	 sum=sumfunction*area;
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
