#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_joint_function1(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=1;
  return(ret_function); 
  }
 
int main() {  
     double ret_function,tepX1,tepX2; // ㄧ计 
     double lower1,upper1,lower2,upper2,sum,X1,X2,mid1,mid2,inc1,inc2;
     int n=100000,flag=0;// n琌家览Ω计 
     char *ss;

     upper1=1; lower1=0; upper2=1; lower2=0;
     printf(" 家览縩だ,...\n");
     sum=0;
     inc1=(upper1-lower1)/(double)n;
     inc2=(upper2-lower2)/(double)n;
     for(X1=lower1;X1<upper1;X1+=inc1)
         for(X2=lower2;X2<upper2;X2+=inc2)
         { 
          flag=0;
          mid1=X1+0.5*inc1; mid2=X2+0.5*inc2; 
          tepX1=cos(mid1*M_PI);tepX2=sin(mid2*M_PI);
          if (tepX1*tepX1+tepX2*tepX2>1) flag++; 
          if (mid1>mid2*mid2) flag++;//戈ぃ才 
          if (flag==2)  continue; 
          ret_function=ret_joint_function1(mid1,mid2);
          sum=sum+ret_function*inc1*inc2;   
	    } 
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
