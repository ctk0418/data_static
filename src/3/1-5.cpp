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
double ret_joint_function1(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=1;
  return(ret_function); 
  }
 
int main() {  
     double ret_function,count1=0; // ㄧ计 
     double lower1,upper1,lower2,upper2,sum,sum1,area,sumfunction,X1,X2;
     double tepX1,tepX2;
     int n=1000000000,i,flag;// n琌家览Ω计 
     char *ss;

     upper1=1; lower1=0; upper2=1; lower2=0;
     printf(" 家览縩だ,...\n");
     sumfunction=0;
     for(i=0;i<n;++i,count1+=1)
     { 
       flag=0;
       X1=uniform_simulated(lower1,upper1); 
       X2=uniform_simulated(lower2,upper2); 
       tepX1=cos(X1*M_PI);tepX2=sin(X2*M_PI);
       if (tepX1*tepX1+tepX2*tepX2>1) flag++;  //戈ぃ才 
       if (X1>X2*X2) flag++;//戈ぃ才 
       if (flag==2) { --i; continue;  }  //ㄢ贺璶―常琌ぃ才 
       ret_function=ret_joint_function1(X1,X2);
       sumfunction=sumfunction+ret_function;   
	    } 
     sumfunction=sumfunction/(double)n;
     area=(upper1-lower1)*(upper2-lower2)*(double)n/count1; // 縩 
	 sum=sumfunction*area;
     ss=(char *)malloc(1024*sizeof(char));
     sprintf(ss," 縩だ=%20.6f\n",sum);
     MessageBox(GetFocus(),ss,"计だ猂暗稬縩だ",MB_OK);
     free(ss);
return (0);
}
