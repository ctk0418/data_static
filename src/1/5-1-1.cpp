#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_function5_pdf(double x)
{  double tep1,ret_function;
  
  tep1=1+cos(x*M_PI)*cos(x*M_PI);
  ret_function=exp(-0.5*x*x)/tep1;
  return(ret_function); 
  }
int main() {  
     double ret_function; // ��ƭ� 
     double lower,upper,inc,w,y,x1,sum;
	 // upper�O�ܼƪ��W����   lower�O�ܼƪ��U���� 
     int n=10000000,i,j;// n is ���έӼ� 
     char *ss;
     
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_function5_pdf(x1);
     	if (ret_function>0 && j==0) { j=1; lower=x1; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	ret_function=ret_function5_pdf(x1);
     	if (ret_function<=0) break;}
     upper=x1-0.00001;
     for(x1=lower-1;;x1+=0.00001)
     {
     	ret_function=ret_function5_pdf(x1);
     	if (ret_function>0) break;}
     lower=x1-0.00001;
     inc=(upper-lower)/(double)n;
     printf(" �����n��,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       ret_function=ret_function5_pdf(w);
       sum=sum+ret_function*inc;   
	    } 
	 ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," �n��=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"�ƭȤ��R���L�n��",MB_OK);
     free(ss);
return (0);
}
