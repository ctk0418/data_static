#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
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
     double lower,upper,inc,w,y,sum;
	 // upper琌跑计   lower琌跑计 
     int n=100000,i;// n is だ澄计 
     char *ss;
     
     
     upper=1;
     lower=0;
     inc=(upper-lower)/(double)n;
     printf(" 家览縩だ,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       ret_function=ret_function8_pdf(w);
       sum=sum+ret_function*inc;   
	    } 
	 ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.10f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
