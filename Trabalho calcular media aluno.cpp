#include <iostream>

using namespace nandin;

int main(int argc, char** argv) 
{
	float vet[10], media, nota1, nota2 ;
	int c;
	for(c=0;c<=3;c++)
	{	cout<<"Digite a primeira nota:"<<endl;
	    cin>>nota1;
	    cout<<"Digite a primeira nota:"<<endl;
	    cin>>nota2;
	    cout<<"A media do aluno: "<<endl;
	    vet[c]=(nota1+nota2)/2;
		cout<< vet[c]<<endl;
    }
    
    for(c=0;c<=3;c++)
    {
      media = media + vet[c];	
	}
	
	cout<< "Media da turma: "<<media/3;
	return 0;
}
