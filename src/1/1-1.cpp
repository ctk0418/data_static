#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_function1_pdf(double x)
{ double ret_function;
   
  ret_function=1;
  return(ret_function); 
  }
int main() {  
     double ret_function; // ��ƭ� 
     double lower,upper,inc,w,y,sum;
	 // upper�O�ܼƪ��W����   lower�O�ܼƪ��U���� 
     int n=100000000,i;// n is ���έӼ� 
     char *ss;

     upper=1; lower=0;
     inc=(upper-lower)/(double)n; //�C�Ӥp�Ϭq������ 
     printf(" �����n��,...\n");
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       ret_function=ret_function1_pdf(w);
       sum=sum+ret_function*inc;   
	    } 
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," �n��=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"�ƭȤ��R���L�n��",MB_OK);
     free(ss);
return (0);
}
