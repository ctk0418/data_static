#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double ret_joint_function3(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=exp(-1*(x1*x1+x2*x2-x1*x2));
  return(ret_function); 
  }
 
int main() {  
     double ret_function,x1,x2,MIN,MAX; // ㄧ计 
     double lower1,upper1,lower2,upper2,sum,X1,X2,mid1,mid2,inc1,inc2;
     int n=100000,j;// n琌家览Ω计 
     char *ss;

     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	ret_function=ret_joint_function3(x1,x1);
     	if (ret_function>0 && j==0) { j=1; lower1=x1; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper1=x1;break; }
     	}
     j=0;
     for(x2=-1000000;x2<1000000;x2=x2+1)
     {
     	ret_function=ret_joint_function3(x2,x2);
     	if (ret_function>0 && j==0) { j=1; lower2=x2; continue; }
     	if (ret_function<=0 && j==1) { j=2; upper2=x2;break; }
     	}
     printf(" 家览縩だ,...\n");
     sum=0;
     inc1=(upper1-lower1)/(double)n;
     inc2=(upper2-lower2)/(double)n;
     for(X1=lower1;X1<upper1;X1+=inc1)
         for(X2=lower2;X2<upper2;X2+=inc2)
         {
          mid1=X1+0.5*inc1; mid2=X2+0.5*inc2; 
          if (mid1>mid2) { MIN=mid2; MAX=mid1;  } 
	      else  { MIN=mid1; MAX=mid2;  } 
          if (MIN>0.5*MAX) continue; 
          ret_function=ret_joint_function3(mid1,mid2);
          sum=sum+ret_function*inc1*inc2;   
	    } 
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
