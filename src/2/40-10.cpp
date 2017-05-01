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

double binomial(double trialnumber,double p)
{
  double tep=-1,tepx1,tepxx;
  int j;
  
  tepxx=0;
  for(j=1;j<=(int)trialnumber;++j)
   {tepx1=uniform_simulated(0,1);
	if (tepx1<=p) tepx1=(double)1; else tepx1=(double)0; 
	tepxx=tepxx+tepx1;
      	      }
   tep=tepxx;
  return(tep);
}
int main() {  
     double sample,p,phat,kk,E; //模擬資料的儲存處 
     int i,samplesize;

     samplesize=500; p=0.3; 
	 sample=binomial((double)samplesize,p);  //Binomial (samplesize,p)
	 phat=sample/(double)samplesize;
	 printf(" 實驗次數=%d , 符合要求個數=%d, 樣本比例=%f\n",samplesize,(int)sample,phat);
	 printf(" 採用標準常態分配做區間估計\n");
	 kk=phat*(1-phat)/(double)samplesize;
	 kk=exp(0.5*log(kk));
	 printf("  99%% C.I. for 母體比例(p)\n");
	 printf("  [%20.10f,%20.10f]\n",phat-2.326*kk,phat+2.326*kk);
	 E=2.326*kk;
	 printf("最大誤差=E=%f\n",E);
	 printf("  95%% C.I. for 母體比例(p)\n");
	 printf("  [%20.10f,%20.10f]\n",phat-1.96*kk,phat+1.96*kk);
	 E=1.96*kk;
	 printf("最大誤差=E=%f\n",E);
	 printf("  95%% C.I. for 母體比例(p)\n");
	 printf("  [%20.10f,%20.10f]\n",phat-1.645*kk,phat+1.645*kk);
	 E=1.645*kk;
	 printf("最大誤差=E=%f\n\n",E);
	 
	 system("pause");
return 0;
}
