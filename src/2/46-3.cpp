#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_spc1_pdf(double a,double b,double x)
{  double ret_function,tep1;
  
  tep1=exp((a-1)*log(x));
  ret_function=a*b/(a+b)*(tep1+1/b);
  return(ret_function); 
  }
int main() {  
     double lower,upper,inc,a,b,y,w,pdf;
     double moment1,moment2,moment3,moment4,mean,var,sigma,gamma1,gamma2;
     int n=100000000,i,j,n1;// n琌家览Ω计 

     a=10;b=1;
     upper=1;
     lower=0;
     inc=(upper-lower)/(double)n;
     printf(" 家览い丁籔诀瞯盞ㄧ计,...\n");
     moment1=0;moment2=0,moment3=0,moment4=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf= ret_spc1_pdf(a,b,w);
       if (pdf<=0) { --i; continue;    } 
       moment1=moment1+w*pdf*inc;
       moment2=moment2+w*w*pdf*inc;
       moment3=moment3+w*w*w*pdf*inc;
       moment4=moment4+w*w*w*w*pdf*inc;
          } 
       mean=moment1;
       var=moment2-mean*mean;
       sigma=exp(0.5*log(var));
       gamma1=moment3-3*moment2*moment1+2*moment1*moment1*moment1;
       gamma1=gamma1/(var*sigma);
       gamma2=moment4-4*moment3*moment1+6*moment2*moment1*moment1-3*moment1*moment1*moment1*moment1;
       gamma2=gamma2/(var*var);
       printf(" E(X1)=%f\n",mean);
       printf(" Var(X1)=%f\n",var);
       printf(" X1熬篈玒计=%f\n",gamma1);
       printf(" X1畃篈玒计=%f\n",gamma2);
       system("pause");
return 0;   }

