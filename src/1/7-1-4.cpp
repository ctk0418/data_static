#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_function7_pdf(double x)
{  double tep1,ret_function;
  
  if (x>0) 
  {
  	tep1=exp(5*log(x)); 
    ret_function=tep1*exp(-1*x);
  }
  else ret_function=0;
  return(ret_function); 
  }
int main() {  
     double ret_function; // ��ƭ� 
     double lower,upper,inc,w,y,x1,sum;
	 // upper�O�ܼƪ��W����   lower�O�ܼƪ��U���� 
     int n=10000,i,j;// n is ���έӼ� 
     char *ss;
     
     j=0;
     for(x1=1;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_function7_pdf(x1);
     	if (ret_function<=0 && j==0) { j=1; upper=x1; continue; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	ret_function=ret_function7_pdf(x1);
     	if (ret_function<=0) break;}
     upper=x1-0.00001;
     lower=0;
     inc=(upper-lower)/(double)n;
     printf(" �����n��,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       ret_function=ret_function7_pdf(w);
       sum=sum+ret_function*inc;   
	    } 
	 ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," �n��=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"�ƭȤ��R���L�n��",MB_OK);
     free(ss);
return (0);
}
