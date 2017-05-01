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
double ret_function5_pdf_check(double x)
{  double tep1,ret_function;
  
  tep1=1+cos(x*M_PI)*cos(x*M_PI);
  ret_function=exp(-0.5*x*x)/tep1;
  if (ret_function<0.0001) ret_function=0;
  return(ret_function); 
  }
double ret_function5_pdf(double x)
{  double tep1,ret_function;
  
  tep1=1+cos(x*M_PI)*cos(x*M_PI);
  ret_function=exp(-0.5*x*x)/tep1;
  return(ret_function); 
  }
int main() {  
     double ret_function; // ㄧ计 
     double lower,upper,X1,x1,sumfunction,sum,area;
	 // upper琌跑计   lower琌跑计 
     int n=1000,i,j;// n is だ澄计 
     char *ss;
     
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_function5_pdf_check(x1);
     	if (ret_function>0 && j==0) { j=1; lower=x1; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper=x1;break; }
     	}
     printf(" 家览縩だ,...\n");
     sumfunction=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper); 
       ret_function=ret_function5_pdf(X1);
       if (ret_function<=0) { --i; continue;    }
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
