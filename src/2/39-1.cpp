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
double bernoulli(double p)
{
  double tep=-1,tepxx;
  
  tepxx= uniform_simulated(0,1);
  if (tepxx<=p) tep=(double)1; else tep=(double)0; 
  return(tep);
}
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastore,p; //������ƪ��x�s�B 
     int n=100000000;// ���������� 

     Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
     Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //�ŧi������Ʈw�Ŷ�
     p=0.3;
     printf(" �}�l���� Bernoulli���t ���\n");
	 for(i=0;i<n;++i)
	   datastore[i]=bernoulli(p);  //���� Bernoulli(p)
	 printf(" �}�l�ƧǸ��\n");
	 Sortx(0,n,datastore); //�ƧǼ������
	 printf(" �Ƨǧ���\n");
	 Plotx(datastore,n,'X',1); //������Ʀ��Ƥ��t�ϥܻP�έp�Y�� 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}
