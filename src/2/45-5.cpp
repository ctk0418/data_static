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
double combination01(int n,int m)
{
    int i=0;
    double sum=1,tep1,tep2;
    if(m>0 || n>=m )
    {
       for(i=0;i<m;++i)
       { tep1=(double)(m-i);
         tep2=double(n-i);
        sum*=tep2/tep1; }
        }
    return(sum);
}
double hypergoemetric(int N, int k, int n, int x)/*X~Hypergeometric(N,k,n), P(X=x) 诀瞯 */ 
{
      double tep3=0,tep1,tep2,data;
      int begin,end;
      
      begin=n+k-N;
      if (begin<0) begin=0;
      if (n>k) end=k; else end=n;
      if (x>=begin && x<=end)
      {      
        tep1=combination01(k,x);
        tep2=combination01(N-k,n-x);
        data=combination01(N,n);
        tep3=tep1*tep2/data;
        } 
      if (x<begin) tep3=0;
      if (x>end) tep3=2;
      return(tep3);
    }
double *hyper_geoemtric_pdf(int N, int k, int n)
{
  int i;
  double tep;
  double *bp;
  
  bp=(double *)malloc((n+1)*sizeof(double));
  for(i=0;i<=n;++i) bp[i]=0;
  for(i=0;i<=n && i<=k;++i)
  {
    tep= hypergoemetric( N,  k,  n, i);
    bp[i]=tep;
    }
  return(bp);
}
int main() {  
     double sample,p,phat,N,k,kk,E,*pr,tep; //家览戈纗矪 
     int i,samplesize,c1,c2;

       N=100;
       samplesize=20; p=0.4;  k=N*p;
	   sample=hyper_geometric(N,k,(double)samplesize);  
	   // Hyper geoemtric(N,k,trialnumber)
	   phat=sample/(double)samplesize;
	   pr=hyper_geoemtric_pdf((int)N,(int)k,samplesize);
	   printf(" 龟喷Ω计=%d , 才璶―计=%d, 妓セゑㄒ=%f\n",samplesize,(int)sample,phat);
	   printf(" ダ砰计=%d,  ダ砰い才璶―计=%d,\n",(int)N,(int)k);
	   printf(" 蹦ノHyper geometricだ皌暗跋丁︳璸\n");
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
