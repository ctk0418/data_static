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
double hyper_geometric(double NN,double success,double trialnumber)
{
  double tep=-1,tepx1,tepxx,pp2;
  int j,N,k,n,kk;
  
  tepxx=0;N=(int)NN;
  k=(int)success;
  n=(int)trialnumber;
  kk=N-k;  
  for(j=1;j<=n;++j)
   {tepx1=uniform_simulated(0,1);
    pp2=(double)k/(double)N;
    if (k<=0) tepx1=(double)0;
    else
    if (kk<=0) tepx1=(double)1;
    else
	if (tepx1<=pp2) { k--; tepx1=(double)1;	} else { tepx1=(double)0; kk--; }
	N--;
	tepxx=tepxx+tepx1;
      	      }  
   tep=tepxx;
   return(tep);
}
int main() {  
     double sample,p,phat,N,k,kk,E,*pr,tep; //模擬資料的儲存處 
     int i,samplesize,c1,c2;

      N=1000;
     samplesize=500; p=0.4;  k=N*p;
	 sample=hyper_geometric(N,k,(double)samplesize);  
	   // Hyper geoemtric(N,k,trialnumber)
	 phat=sample/(double)samplesize;
	 printf(" 實驗次數=%d , 符合要求個數=%d, 樣本比例=%f\n",samplesize,(int)sample,phat);
	 printf(" 母體個數=%d,  母體中符合要求個數=%d,\n",(int)N,(int)k);
	 printf(" 採用標準常態分配做區間估計\n");
	 kk=phat*(1-phat)/(double)samplesize;
	 kk=kk*(double)(N-samplesize)/(double)(N-1);
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
