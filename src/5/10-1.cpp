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
double ret_quadratic_pdf(double a,double b,double x)
{ double pdf,alpha,beta;
  beta=(a+b)/2;
  alpha=12/((b-a)*(b-a)*(b-a));
  pdf=alpha*(x-beta)*(x-beta);
  return(pdf); 
  }
double *quadratic_database(double a,double b,int datasize)
{  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc;
     int n=100000000,i,j,n1;// n是模擬的次數 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" 需要一段時間計算 U quadratic(a=%f,b=%f) 分配的資料庫,....\n",a,b);  
     upper=b;
     lower=a;
     inc=(upper-lower)/(double)n;
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf= ret_quadratic_pdf(a,b,w);
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
     double *datastoreA1,*datastoreA2,*datastoreA3;
	 double *data1,*data2,*data3,sum,pdf,X1,X2,X3,tepX1,tepX2,tepX3,angle1,angle2,r,tep;
	 double a1,b1,a2,b2,a3,b3;
     double lower1,upper1,lower2,upper2,result1,result2,result3;
     int n=100000000,j,n1;// n是模擬的次數 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
       a1=-10;b1=10;a2=-10; b2=10; a3=-10;b3=10;
       printf(" 計算 例 10 分配的資料庫,....\n");  
       datastoreA1=quadratic_database(a1,b1,n);
       Sortx(0,n,datastoreA1);	//X1的機率模擬器資料庫 
       datastoreA2=quadratic_database(a2,b2,n);
       Sortx(0,n,datastoreA2);  //X2的機率模擬器資料庫 
       datastoreA3=quadratic_database(a3,b3,n);
       Sortx(0,n,datastoreA3);  //X2的機率模擬器資料庫 
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       data3=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //亂數表 
         tepX1=datastoreA1[(int)((double)n*result1)];//模擬X1資料 
         result2=uniform_simulated(0,1);  //亂數表 
         tepX2=datastoreA2[(int)((double)n*result2)];//模擬X2資料 
         result3=uniform_simulated(0,1);  //亂數表 
         tepX3=datastoreA3[(int)((double)n*result3)];//模擬X2資料 
         angle2=atan(tepX3/tepX2);
         tep=tepX2*tepX2+tepX3*tepX3;
		 if (tep>0) tep=exp(0.5*log(tep)); else { --i; continue;} 
         angle1=atan(tep/tepX1);
         r=tepX1*tepX1+tepX2*tepX2+tepX3*tepX3;
         if (r>0) r=exp(0.5*log(r)); else r=0;
         data1[i]=r; 
         data2[i]=angle1;
         data3[i]=angle2;
      	}  
       free(datastoreA1);free(datastoreA2);  free(datastoreA3); 
       Joint_plotx('Y',1,'Y',2,data1,data2,n,5);
       Joint_plotx('Y',1,'Y',3,data1,data3,n,5);
       Joint_plotx('Y',2,'Y',3,data2,data3,n,5);
       printf(" 排序.....\n");
       Sortx(0,n,data1);
       printf(" 完成排序.....\n");
	   Plotx(data1,n,'Y',1); 
	   printf(" 排序.....\n");
       Sortx(0,n,data2);
       printf(" 完成排序.....\n");
	   Plotx(data2,n,'Y',2); 
	   Sortx(0,n,data3);
       printf(" 完成排序.....\n");
	   Plotx(data3,n,'Y',3); 
	   free(data1);free(data2);free(data3);
       free(Simulation); free(Simulationx);
return 0;
}

