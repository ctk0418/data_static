#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_function2_pdf(double x)
{ double ret_function;
   
  ret_function=cos(x);
  return(ret_function); 
  }
int main() {  
     double ret_function; // ㄧ计 
     double lower,upper,inc,w,y,sum;
	 // upper琌跑计   lower琌跑计 
     int n=100,i;// n is だ澄计 
     char *ss;

     upper=M_PI/2; lower=0;
     inc=(upper-lower)/(double)n; //–跋琿 
     printf(" 家览縩だ,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       ret_function=ret_function2_pdf(w);
       sum=sum+ret_function*inc;   
	    } 
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
