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
double hyper_geometric(double NN,double success,double trialnumber)
{
  double tep=-1,tepx1,tepxx,pp2;
  int j,N,k,n,kk;
  
  tepxx=0;N=(int)NN;
  k=(int)success;
  n=(int)trialnumber;
  kk=N-k;  
  for(j=1;j<=n;++j)
   {tepx1= uniform_simulated(0,1);
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
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastore,N,k,trialnumber; //������ƪ��x�s�B
     int n=100000000;// ���������� 

   Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
   Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //�ŧi������Ʈw�Ŷ�
     N=100; k=40; trialnumber=20;
     printf(" �}�l���� Hyper geometric ���t ���\n");
	 for(i=0;i<n;++i)
	   datastore[i]= hyper_geometric(N,k,trialnumber);
     // Hyper geoemtric(N,k,trialnumber)
	 printf(" �}�l�ƧǸ��\n");
	 Sortx(0,n,datastore); //�ƧǼ������
	 printf(" �Ƨǧ���\n");
	 Plotx(datastore,n,'X',1); //������Ʀ��Ƥ��t�ϥܻP�έp�Y�� 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}

