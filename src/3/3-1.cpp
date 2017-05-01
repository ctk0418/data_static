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
double ret_joint_function3(double x1,double x2)
{ 
  double ret_function;
  
  ret_function=exp(-1*(x1*x1+x2*x2-x1*x2));
  return(ret_function); 
  }
int main() {  
     double ret_function,count1=0; // ㄧ计 
     double lower1,upper1,X1,x1,lower2,upper2,X2,x2,sumfunction,sum,area;
	 // upper琌跑计   lower琌跑计 
     int n=1000000000,i,j;// n is だ澄计 
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
     sumfunction=0;
     for(i=0;i<n;++i,count1+=1)
     { 
       X1=uniform_simulated(lower1,upper1); 
       X2=uniform_simulated(lower2,upper2); 
       ret_function=ret_joint_function3(X1,X2);
       if (ret_function<=0) { --i; continue;   }
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
