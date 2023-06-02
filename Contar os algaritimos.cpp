#include <iostream>
#include <cstdlib>
using namespace std;

struct manipulaNumeros
{
    int contaAlgarismos(long long int num)
    {
       int cont=0;num=abs(num);
       if(num==0) return 1;
       while(num>0)
       {  cont++;    num/=10; } 
       return cont;
   }
   void quocresto(int a, int b)
   { 
     int aux;
     if(a<=0 || b<=0)
     { cout<<"\nSem resultados\n";return;}
     
     if(a<b) {aux=a; a=b; b=aux;}
     cout<<"\nQuociente: "<<a/b<<"\nResto: "<<a%b;
   }
};

int main()
{  
   long long int n; int n1,n2;
   manipulaNumeros num;
   cout<<"\nDigite um numero inteiro: ";   
   cin>>n; 
   cout<<"\nTotal de Algarismos: "<<num.contaAlgarismos(n);
   cout<<"\n\nDigite um numero inteiro: ";
   cin>>n1;    
   cout<<"\nDigite outro numero inteiro: ";  
   cin>>n2;  
   num.quocresto(n1,n2);
   cout<<"\n\n";
   system("pause");
}


