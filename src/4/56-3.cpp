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
double ret_normal_pdf(double mu,double sigma,double x)
{  double ret_function,z,tep1;
  
  z=(x-mu)/sigma;
  tep1=exp(0.5*log(2*M_PI))*sigma;
  ret_function=exp(-0.5*z*z)/tep1;
  return(ret_function); 
  }
double  *normal_database(double mu,double sigma,int datasize)  
{ 
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc;
     int n=100000000,i,j,n1;// n是模擬的次數 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 Normal(mu=%f,sigma=%f) 分配的資料庫,....\n",mu,sigma);  
     j=0;
     for(x1=-1000000;x1<1000000;x1=x1+1)
     {
     	pdf=ret_normal_pdf(mu,sigma,x1);
     	if (pdf>0 && j==0) { j=1; lower=x1; continue; }
     	if (pdf<=0 && j==1) { j=2; upper=x1;break; }
     	}
     for(x1=upper-1;;x1+=0.00001)
     {
     	pdf=ret_normal_pdf(mu,sigma,x1);
     	if (pdf<=0) break;}
     upper=x1-0.00001;
     for(x1=lower-1;;x1+=0.00001)
     {
     	pdf=ret_normal_pdf(mu,sigma,x1);
     	if (pdf>0) break;}
     lower=x1-0.00001;
     inc=(upper-lower)/(double)n;
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf= ret_normal_pdf(mu,sigma,w);
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
       return (data);
  }
double ret_uniform_pdf(double alpha,double beta,double x)
{  double pdf;
  
  pdf=1/(beta-alpha);
  return(pdf); 
  }
double  *uniform_database(double alpha,double beta,int datasize) 
{  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc;
     int n=100000000,i,j,n1;// n是模擬的次數 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 Uniform(alpha=%f,beta=%f) 分配的資料庫,....\n",alpha,beta);  
     upper=beta;
     lower=alpha;
     inc=(upper-lower)/(double)n;
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf=ret_uniform_pdf(alpha,beta,w);
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
       free(datastoreA); free(datastoreB);  free(datastoreC);
       return (data);
}
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// 機率分配個數的宣告
     double *datastoreA1,*datastoreA2;
	 double *data1,*data2,*data3,sum,pdf,X1,X2,tepX1,tepX2;
	 double mu1,sigma1,alpha2,beta2;
     double lower1,upper1,lower2,upper2,result1,result2;
     int n=100000000,j,n1;// n是模擬的次數 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
       mu1=10;sigma1=5; alpha2=-100;beta2=100;
       printf(" 計算 例 56 分配的資料庫,....\n");  
       datastoreA1=normal_database(mu1,sigma1,n);
       Sortx(0,n,datastoreA1);	//X1的機率模擬器資料庫 
       datastoreA2=uniform_database(alpha2,beta2,n);
       Sortx(0,n,datastoreA2);  //X2的機率模擬器資料庫 
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       data3=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         tepX1=datastoreA1[(int)((double)n*result1)];//模擬X1資料 
         result2=uniform_simulated(0,1);  //亂數表 
         tepX2=datastoreA2[(int)((double)n*result2)];//模擬X2資料 
         data1[i]=tepX1; 
         data2[i]=tepX2;
         data3[i]=2+5*tepX1*tepX1+tepX2;
      	}  
       free(datastoreA1);free(datastoreA2);  
       Joint_plotx('X',1,'e',1,data1,data2,n,5);
       Joint_plotx('e',1,'Y',1,data2,data3,n,5);
       Joint_plotx('X',1,'Y',1,data1,data3,n,5);
       printf(" 排序.....\n");
       Sortx(0,n,data1);
       printf(" 完成排序.....\n");
	   Plotx(data1,n,'X',1); 
	   printf(" 排序.....\n");
       Sortx(0,n,data2);
       printf(" 完成排序.....\n");
	   Plotx(data2,n,'e',1); 
	   Sortx(0,n,data3);
       printf(" 完成排序.....\n");
	   Plotx(data3,n,'Y',1); 
	   free(data1);free(data2);free(data3);
       free(Simulation); free(Simulationx);
return 0;
}

