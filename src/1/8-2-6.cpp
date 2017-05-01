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
double ret_function8_pdf(double x)
{  double tep1,tep2,ret_function;
  
  if (x>0 && x<1) 
  {
  	tep1=exp(5*log(x)); 
  	tep2=exp(8*log(1-x));
    ret_function=tep1*tep2;
  }
  else ret_function=0;
  return(ret_function); 
  }
int main() {  
     double ret_function; // ㄧ计 
     double lower,upper,X1,sumfunction,sum,area;
	 // upper琌跑计   lower琌跑计 
     int n=1000,i;// n is だ澄计 
     char *ss;
     
     upper=1;
     lower=0;
     printf(" 家览縩だ,...\n");
     sumfunction=0;
     for(i=0;i<n;++i)
     { 
       X1=uniform_simulated(lower,upper); 
       ret_function=ret_function8_pdf(X1);
       sumfunction=sumfunction+ret_function;   
	    } 
	 sumfunction=sumfunction/(double)n;
     area=upper-lower;
	 sum=sumfunction*area;
	 ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.10f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
