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
double ret_arcsin_pdf(double mu,double c,double x)
{  double pdf,z;
  z=(x-mu)/c;
  z=1-z*z;
  if (z>0) pdf=exp(-0.5*log(z))/M_PI;
  else pdf=0;
  return(pdf); 
  }
double *arcsin_database(double mu,double c,int datasize)
{  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc;
     int n=100000000,i,j,n1;// n�O���������� 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Arcsin(mu=%f,c=%f) ���t����Ʈw,....\n",mu,c);  
     upper=mu+c;
     lower=mu-c;
     inc=(upper-lower)/(double)n;
     sum=0;
     for(y=lower+inc,i=0;y<=upper && i<n;y=y+inc, ++i)
     { 
       w=y-inc/2;
       pdf=ret_arcsin_pdf(mu,c,w);
       if (pdf<=0) { --i; continue;    }
       datastoreA[i]=w; datastoreB[i]=pdf; 
       sum=sum+pdf;    } 
       n1=i;datastoreC[0]=datastoreB[0]/sum;
       for(j=1;j<n;++j) 
      	 datastoreC[j]=datastoreB[j]/sum+datastoreC[j-1];
       data=(double *)malloc(datasize*sizeof(double));
       for(i=0;i<datasize;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
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
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastoreA;
	 double *data1,*data2,*data3,sum,pdf,*X;
	 double mu,c;
     double lower1,upper1,lower2,upper2,result1,result2,result3;
     int n=100000000,j,n1,datasize;// n�O���������� 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
       datasize=10;
       mu=10;c=5; 
       printf(" �p�� �� 2 ���t����Ʈw,....\n");  
       datastoreA=arcsin_database(mu,c,n);
       Sortx(0,n,datastoreA);	//X1�����v��������Ʈw 
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       data3=(double *)malloc(n*sizeof(double));
       X=(double *)malloc(datasize*sizeof(double));
       for(i=0;i<n;++i) 
       { 
         for(j=0;j<datasize;++j)
         {
	     result1=uniform_simulated(0,1);  //�üƪ� 
         X[j]=datastoreA[(int)((double)n*result1)];//�����N�˥���� 
          }
         Sortx(0,datasize,X);
         data1[i]=X[0]; 
         data2[i]=X[1];
         data3[i]=X[datasize-1];
      	}  
       free(datastoreA);
       Joint_plotx('Y',1,'Y',2,data1,data2,n,5);
       Joint_plotx('Y',1,'Y',3,data1,data3,n,5);
       Joint_plotx('Y',2,'Y',3,data2,data3,n,5);
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data1);
       printf(" �����Ƨ�.....\n");
	   Plotx(data1,n,'Y',1); 
	   printf(" �Ƨ�.....\n");
       Sortx(0,n,data2);
       printf(" �����Ƨ�.....\n");
	   Plotx(data2,n,'Y',2); 
	   Sortx(0,n,data3);
       printf(" �����Ƨ�.....\n");
	   Plotx(data3,n,'Y',3); 
	   free(data1);free(data2);free(data3);free(X);
       free(Simulation); free(Simulationx);
return 0;
}

