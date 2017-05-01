#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <c:\\simulated_book\\include_dll\\DLL_function_type.cpp>
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
double negative_binomialx(double r,double p)
{
  double tep=-1,tepx1,pp2,tepxx,tsum;
  int j,ii;
 
   tepxx=0;
   for(ii=0;ii<(int)r;++ii)
    {
     tepx1= uniform_simulated(0,1);  pp2=p;
	 for(j=0;;++j)
     {
      if (j==0) tsum=pp2; else {pp2=pp2*(1-p);tsum=tsum+pp2;}
      if (tsum>=tepx1)  break; 
      }
     tepxx=tepxx+(double)(j+1);
    }
    tep=tepxx;
  return(tep);
}
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastore,p,r; //������ƪ��x�s�B
     int n=100000000;// ���������� 

   Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
   Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //�ŧi������Ʈw�Ŷ�
     r=5; p=0.4;
     printf(" �}�l���� Negative Binomial ���t ���\n");
	 for(i=0;i<n;++i)
	   datastore[i]= negative_binomialx(r,p);  // Negative Binomial (r,p)
	 printf(" �}�l�ƧǸ��\n");
	 Sortx(0,n,datastore); //�ƧǼ������
	 printf(" �Ƨǧ���\n");
	 Plotx(datastore,n,'X',1); //������Ʀ��Ƥ��t�ϥܻP�έp�Y�� 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}

