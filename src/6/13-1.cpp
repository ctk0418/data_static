#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
double dividewangxx=(double)32767*(double)32767*(double)32767;
#include <c:\\simulated_book\\include_dll\\DLL_function_type.cpp>
double uniform_simulated(double alpha,double beta)
{
   double tep1,tep=0,dividewangx;
 
   again:
   tep1=((double)rand()*(double)32767*(double)32767+(double)rand()*(double)32767+(double)rand())/dividewangxx;
   if (tep1<0 || tep1>1) goto again;
   tep=alpha+tep1*(beta-alpha);  
   return(tep);
}
int serach_index(double *df,double result,int n_begin,int n_end)
 {
   int i;
   int ret;
   
   if (n_begin==n_end) return(n_end);
   if (n_begin+1==n_end) return(n_end);
   if (result<df[(n_begin+n_end)/2])
   ret=serach_index(df,result,n_begin,(n_begin+n_end)/2);
   else if (result>df[(n_begin+n_end)/2])
   ret=serach_index(df,result,(n_begin+n_end)/2,n_end);
   else if (result==df[(n_begin+n_end)/2]) return((n_begin+n_end)/2);
   return(ret);
 }
double ret_beta_pdf(double alpha,double beta,double x)
{  double pdf;
  if (x>0 && x<1) pdf=exp((alpha-1)*log(x))* exp((beta-1)*log(1-x));
  else pdf=0;
  return(pdf); 
  }
double *beta_database(double alpha,double beta,int datasize)
{  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc;
     int n=100000000,i,j,n1;// n是模擬的次數 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 Beta(alpha=%f,beta=%f) 分配的資料庫,....\n",alpha,beta);  
     upper=1;
     lower=0;
     inc=(upper-lower)/(double)n;
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf=ret_beta_pdf(alpha,beta,w);
       if (pdf<=0) { --i; continue;    }
       datastoreA[i]=w; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       data=(double *)malloc(datasize*sizeof(double));
       for(i=0;i<datasize;++i) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
         }  
       free(datastoreA); free(datastoreB); free(datastoreC);
       return(data);   }
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// 機率分配個數的宣告
     double *datastoreA;
	 double *data1,*data2,*data3,*data4,sum,pdf,*X;
	 double alpha,beta,EX,VarX;
     double lower1,upper1,lower2,upper2,result1,result2,result3;
     double samplemean,S2,SSE,S,adjc;
     int n=100000000,j,n1,datasize;// n是模擬的次數 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
       datasize=10;
       alpha=5.2;beta=4.8;
       printf(" 計算 例 13 分配的資料庫,....\n");  
       datastoreA=beta_database(alpha,beta,n);
       Sortx(0,n,datastoreA);	//X1的機率模擬器資料庫 
       EX=0;
       for(i=0;i<n;++i)  EX=EX+datastoreA[i];
       EX=EX/(double)n;
       VarX=0;
       for(i=0;i<n;++i)  VarX=VarX+(datastoreA[i]-EX)*(datastoreA[i]-EX);
       VarX=VarX/(double)(n-1);
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       data3=(double *)malloc(n*sizeof(double));
       data4=(double *)malloc(n*sizeof(double));
       X=(double *)malloc(datasize*sizeof(double));
       adjc=exp(0.5*log((double)datasize));
       for(i=0;i<n;++i) 
       { 
         for(j=0;j<datasize;++j)
         {
	     result1=uniform_simulated(0,1);  //亂數表 
         X[j]=datastoreA[(int)((double)n*result1)];//模擬意樣本資料 
          }
         samplemean=0;
         for(j=0;j<datasize;++j) samplemean=samplemean+X[j];
         samplemean=samplemean/(double)datasize;
		 SSE=0;
         for(j=0;j<datasize;++j) SSE=SSE+(X[j]-samplemean)*(X[j]-samplemean);
         S2=SSE/(double)(datasize-1);
         data1[i]=samplemean; 
         data2[i]=S2;
         if (S2>0) S=exp(0.5*log(S2)); else { --i; continue;  }
         data3[i]=adjc*(samplemean-EX)/S;
         data4[i]=SSE/VarX;
      	}  
       free(datastoreA);
       Joint_plotx('Y',1,'Y',2,data1,data2,n,5);
       printf(" 排序.....\n");
       Sortx(0,n,data1);
       printf(" 完成排序.....\n");
	   Plotx(data1,n,'Y',1); 
	   printf(" 排序.....\n");
       Sortx(0,n,data2);
       printf(" 完成排序.....\n");
	   Plotx(data2,n,'Y',2); 
	   Joint_plotx('W',1,'W',2,data3,data4,n,5);
       printf(" 排序.....\n");
       Sortx(0,n,data3);
       printf(" 完成排序.....\n");
	   Plotx(data3,n,'W',1); 
	   printf(" 排序.....\n");
       Sortx(0,n,data4);
       printf(" 完成排序.....\n");
	   Plotx(data4,n,'W',2); 
	   printf(" P(W1<=%f)=0.005,\n",data3[(int)((double)n*0.005)]);
       printf(" P(W1<=%f)=0.01,\n",data3[(int)((double)n*0.01)]);
       printf(" P(W1<=%f)=0.025,\n",data3[(int)((double)n*0.025)]);
       printf(" P(W1<=%f)=0.05,\n",data3[(int)((double)n*0.05)]);
       printf(" P(W1<=%f)=0.1,\n",data3[(int)((double)n*0.1)]);
       printf(" P(W1<=%f)=0.9,\n",data3[(int)((double)n*0.9)]);
       printf(" P(W1<=%f)=0.95,\n",data3[(int)((double)n*0.95)]);
       printf(" P(W1<=%f)=0.975,\n",data3[(int)((double)n*0.975)]);
       printf(" P(W1<=%f)=0.99,\n",data3[(int)((double)n*0.99)]);
       printf(" P(W1<=%f)=0.995,\n",data3[(int)((double)n*0.995)]);
       system("pause");
       printf(" P(W2<=%f)=0.005,\n",data4[(int)((double)n*0.005)]);
       printf(" P(W2<=%f)=0.01,\n",data4[(int)((double)n*0.01)]);
       printf(" P(W2<=%f)=0.025,\n",data4[(int)((double)n*0.025)]);
       printf(" P(W2<=%f)=0.05,\n",data4[(int)((double)n*0.05)]);
       printf(" P(W2<=%f)=0.1,\n",data4[(int)((double)n*0.1)]);
       printf(" P(W2<=%f)=0.9,\n",data4[(int)((double)n*0.9)]);
       printf(" P(W2<=%f)=0.95,\n",data4[(int)((double)n*0.95)]);
       printf(" P(W2<=%f)=0.975,\n",data4[(int)((double)n*0.975)]);
       printf(" P(W2<=%f)=0.99,\n",data4[(int)((double)n*0.99)]);
       printf(" P(W2<=%f)=0.995,\n",data4[(int)((double)n*0.995)]);
       system("pause");
	   free(data1);free(data2);free(data3);free(data4);free(X);
       free(Simulation); free(Simulationx);
return 0;
}

