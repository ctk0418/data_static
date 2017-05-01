#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_function6_pdf(double x)
{  double tep1,ret_function;
  
  if (x<0) x=-1*x;
  if (x>0) tep1=exp(0.5*log(x)); else tep1=0;
  ret_function=exp(-1*tep1);
  return(ret_function); 
  }
int main() {  
     double ret_function; // ㄧ计 
     double lower,upper,inc,w,y,x1,sum;
	 // upper琌跑计   lower琌跑计 
     int n=10,i,j;// n is だ澄计 
     char *ss;
     
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_function6_pdf(x1);
     	if (ret_function>0 && j==0) { j=1; lower=x1; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	ret_function=ret_function6_pdf(x1);
     	if (ret_function<=0) break;}
     upper=x1-0.00001;
     for(x1=lower-1;;x1+=0.00001)
     {
     	ret_function=ret_function6_pdf(x1);
     	if (ret_function>0) break;}
     lower=x1-0.00001;
     inc=(upper-lower)/(double)n;
     printf(" 家览縩だ,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       ret_function=ret_function6_pdf(w);
       sum=sum+ret_function*inc;   
	    } 
	 ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
