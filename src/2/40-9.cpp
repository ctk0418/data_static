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
double combination(int n,int x,double p)
{
    int i=0;
    double sum=1,tep1,tep2;
    
    if (n==1)
    {  if(x==0) sum=1-p;
       else sum=p;  }
    else
    {
    if(p>0.5) { p=1-p; x=n-x; }
    if(x>0 && n>=x )
       for(i=0;i<x;++i)
       {  tep2=double(n-i)*(double)p;
          tep1=(double)(x-i);
          sum*=tep2/tep1;
       }
    for(i=0;i<n-x;++i)
        sum*=1-p;    }
    return(sum);
}
double *binomial_pdf(int n,double p)
{
  int i;
  double tep;
  double *bp;
  
  bp=(double *)malloc((n+1)*sizeof(double));
  for(i=0;i<=n;++i)
  {
    tep=combination(n,i,p);
    bp[i]=tep;
    }
  return(bp);
}
int main() {  
     double sample,p,phat,kk,E,*pr,tep; //家览戈纗矪 
     int i,samplesize,c1,c2;

       samplesize=20; p=0.3; 
	   sample=binomial((double)samplesize,p);  //Binomial (samplesize,p)
	   phat=sample/(double)samplesize;
	   pr=binomial_pdf(samplesize,phat);
	   printf(" 龟喷Ω计=%d , 才璶―计=%d, 妓セゑㄒ=%f\n",samplesize,(int)sample,phat);
	   printf(" 蹦ノBinomialだ皌暗跋丁︳璸\n");
	   tep=0;
       for(i=0;i<=samplesize;++i) 
       { 
        tep=tep+pr[i];
	    if (tep>=0.005) { c1=i; break;}
	   }
       for(i=0;i<=samplesize;++i) 
       { 
        tep=tep+pr[i];
	    if (tep>=0.995) { c2=i; break;}
	     }
	   printf(" 99%% C.I. for 才璶―计\n");
	   printf("%d<=才璶―计<=%d\n",c1,c2);
	   printf(" 99%% C.I. for ダ砰ゑㄒ(p)\n");
       printf("%f<=ダ砰ゑㄒ(p)<=%f\n",(double)c1/(double)samplesize,(double)c2/(double)samplesize);
       E=((double)c2/(double)samplesize-(double)c1/(double)samplesize)/2;
   	   printf("程粇畉=E=%f\n",E);
       tep=0;
       for(i=0;i<=samplesize;++i) 
       { 
        tep=tep+pr[i];
	    if (tep>=0.025) { c1=i; break;}
	   }
       for(i=0;i<=samplesize;++i) 
       { 
        tep=tep+pr[i];
	    if (tep>=0.975) { c2=i; break;}
	     }
	   printf(" 95%% C.I. for 才璶―计\n");
	   printf("%d<=才璶―计<=%d\n",c1,c2);
	   printf(" 99%% C.I. for ダ砰ゑㄒ(p)\n");
       printf("%f<=ダ砰ゑㄒ(p)<=%f\n",(double)c1/(double)samplesize,(double)c2/(double)samplesize);
       E=((double)c2/(double)samplesize-(double)c1/(double)samplesize)/2;
   	   printf("程粇畉=E=%f\n",E);
       tep=0;
       for(i=0;i<=samplesize;++i) 
       { 
        tep=tep+pr[i];
	    if (tep>=0.05) { c1=i; break;}
	   }
       for(i=0;i<=samplesize;++i) 
       { 
        tep=tep+pr[i];
	    if (tep>=0.95) { c2=i; break;}
	     }
	   printf(" 90%% C.I. for 才璶―计\n");
	   printf("%d<=才璶―计<=%d\n",c1,c2);
	   printf(" 90%% C.I. for ダ砰ゑㄒ(p)\n");
       printf("%f<=ダ砰ゑㄒ(p)<=%f\n",(double)c1/(double)samplesize,(double)c2/(double)samplesize);
       E=((double)c2/(double)samplesize-(double)c1/(double)samplesize)/2;
   	   printf("程粇畉=E=%f\n\n",E);
   	   system("pause");
       
	   free(pr);
return 0;
}
