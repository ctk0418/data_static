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
double poisson(double lamda)
{
  double tep=-1,tepx1,pp2,tsum,tepx2,px1;
  int j,nn,i;
  
   if (lamda<=20)
   {
   tepx1=uniform_simulated(0,1);
   pp2=exp(-1*lamda);tsum=pp2;
   for(j=0;;++j)
   if (tsum>=tepx1)  break; else { pp2=pp2*lamda/(double)(j+1); tsum=tsum+pp2;}
   tep=(double)j;   }
   else
   {
   	nn=(int)lamda;tepx2=0;
   	for(i=1;i<nn;++i)
   	{
   	 tepx1=uniform_simulated(0,1);
     pp2=exp(-1);tsum=pp2;
     for(j=0;;++j)
      if (tsum>=tepx1)  break; else { pp2=pp2/(double)(j+1); tsum=tsum+pp2;}
      tepx2=tepx2+(double)j;
	    }
	px1=lamda-(double)(nn-1);
	if (px1>0)
	{
	tepx1=uniform_simulated(0,1); 
	pp2=exp(-1*px1);tsum=pp2;
    for(j=0;;++j)
    if (tsum>=tepx1)  break; else { pp2=pp2*px1/(double)(j+1); tsum=tsum+pp2;}
    tepx2=tepx2+(double)j;  
	tep=tepx2;	}
   }
  return(tep);
}
double  simulation_fuction(importFunction *Simulation,int pdf,double p1,double p2,double p3,double p4)
 {  return(Simulation[pdf-1](p1,p2,p3,p4));   }
int main() {  
#include <c:\\simulated_book\\include_dll\DLL_usage_function_name.cpp>

     char *s;
     int i,add,libnumber=7,libnumber1=27;// ���v���t�Ӽƪ��ŧi
     double *datastore,lamda; //������ƪ��x�s�B 
     int n=100000000;// ���������� 

     Simulation=(importFunction *)malloc(libnumber*sizeof(importFunction));
     Simulationx=(importFunction *)malloc(libnumber1*sizeof(importFunction));
     
#include <c:\\simulated_book\\include_dll\\DLL_function_load.cpp>
     datastore=(double *)malloc(n*sizeof(double)); //�ŧi������Ʈw�Ŷ�
     lamda=5;
     printf(" �}�l���� Poisson ���t ���\n");
	 for(i=0;i<n;++i)
	   datastore[i]=poisson(lamda);  //Poisson(lamda)
	 printf(" �}�l�ƧǸ��\n");
	 Sortx(0,n,datastore); //�ƧǼ������
	 printf(" �Ƨǧ���\n");
	 Plotx(datastore,n,'X',1); //������Ʀ��Ƥ��t�ϥܻP�έp�Y�� 
	 free(datastore);
     free(Simulation); free(Simulationx);
return 0;
}
