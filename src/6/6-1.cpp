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
     int n=100000000,i,j,n1;// n�O���������� 

     datastoreA=(double *)malloc(n*sizeof(double));
     datastoreB=(double *)malloc(n*sizeof(double));
     datastoreC=(double *)malloc(n*sizeof(double));
     printf(" �ݭn�@�q�ɶ��p�� Normal(mu=%f,sigma=%f) ���t����Ʈw,....\n",mu,sigma);  
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
	     result1=uniform_simulated(0,1);  //�üƪ� 
         j=serach_index(datastoreC,result1,0,n-1);
         data[i]=datastoreA[j]; 
          }  
       free(datastoreA); free(datastoreB); free(datastoreC);
       return (data);
  }

double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastoreA;
	 double *data1,*data2,*data3,*data4,sum,pdf,*X;
	 double mu,sigma,EX,VarX;
     double lower1,upper1,lower2,upper2,result1,result2,result3;
     double samplemean,S2,SSE,S,adjc;
     int n=100000000,j,n1,datasize;// n�O���������� 

  Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
  Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     
       datasize=10;
       mu=10;sigma=5; 
       printf(" �p�� �� 6 ���t����Ʈw,....\n");  
       datastoreA=normal_database(mu,sigma,n);
       Sortx(0,n,datastoreA);	//X1�����v��������Ʈw 
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
	     result1=uniform_simulated(0,1);  //�üƪ� 
         X[j]=datastoreA[(int)((double)n*result1)];//�����N�˥���� 
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
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data1);
       printf(" �����Ƨ�.....\n");
	   Plotx(data1,n,'Y',1); 
	   printf(" �Ƨ�.....\n");
       Sortx(0,n,data2);
       printf(" �����Ƨ�.....\n");
	   Plotx(data2,n,'Y',2); 
	   Joint_plotx('W',1,'W',2,data3,data4,n,5);
       printf(" �Ƨ�.....\n");
       Sortx(0,n,data3);
       printf(" �����Ƨ�.....\n");
	   Plotx(data3,n,'W',1); 
	   printf(" �Ƨ�.....\n");
       Sortx(0,n,data4);
       printf(" �����Ƨ�.....\n");
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

