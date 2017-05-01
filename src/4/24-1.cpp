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
double ret_uniform_pdf(double alpha,double beta,double x)
{  double pdf;
  
  pdf=1/(beta-alpha);
  return(pdf); 
  }
double  *uniform_database(double alpha,double beta,int datasize) 
{  
     double *datastoreA,*datastoreB,*datastoreC,*data,sum,pdf,x1,y,w;
     double lower,upper,result1,inc;
     int n=100000000,i,j,n1;// n�O���������� 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Uniform(alpha=%f,beta=%f) ���t����Ʈw,....\n",alpha,beta);  
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
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
      	}  
       free(datastoreA); free(datastoreB);  free(datastoreC);
       return (data);
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
     int n=100000000,i,j,n1;// n�O���������� 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Beta(alpha=%f,beta=%f) ���t����Ʈw,....\n",alpha,beta);  
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
     double *datastoreA1,*datastoreA2;
	 double *data1,*data2,sum,pdf,X1,X2,tepX1,tepX2;
	 double alpha1,beta1,alpha2,beta2;
     double lower1,upper1,lower2,uppuer2,result1,result2;
     int n=100000000,j,n1;// n�O���������� 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
       alpha1=0; beta1=1; alpha2=5.2; beta2=3.8;
       printf(" �p�� �� 24 ���t����Ʈw,....\n");  
       datastoreA1=uniform_database(alpha1,beta1,n);
       Sortx(0,n,datastoreA1);	//X1�����v��������Ʈw 
       datastoreA2=beta_database(alpha2,beta2,n);
       Sortx(0,n,datastoreA2);  //X2�����v��������Ʈw 
       data1=(double *)malloc(n*sizeof(double));
       data2=(double *)malloc(n*sizeof(double));
       for(i=0;i<n;++i) 
       { 
	     result1=uniform_simulated(0,1);  //�üƪ� 
         tepX1=datastoreA1[(int)((double)n*result1)];//����X1��� 
         result2=uniform_simulated(0,1);  //�üƪ� 
         tepX2=datastoreA2[(int)((double)n*result2)];//����X2��� 
         data1[i]=tepX1; 
         data2[i]=tepX2;
      	}  
       free(datastoreA1);free(datastoreA2);  
       Joint_plotx('X',1,'X',2,data1,data2,n,5);
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data1);
       printf(" �����Ƨ�.....\n");
	   Plotx(data1,n,'X',1); 
	   printf(" �Ƨ�.....\n");
       Sortx(0,n,data2);
       printf(" �����Ƨ�.....\n");
	   Plotx(data2,n,'X',2); 
	   free(data1);free(data2);
       free(Simulation); free(Simulationx);
return 0;
}
