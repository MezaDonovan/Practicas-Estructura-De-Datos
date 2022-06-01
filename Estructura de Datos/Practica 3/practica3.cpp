#include <iostream>
#include<stdlib.h>
//Definimos el tamaño de la cola
#define max 5

using namespace std;
class CCola
{
	private:
		int cola[max];
		int final;
		int frente;
		int tamanio;
	public:
		CCola();
	    void agregar(int);
		void sacar();
		void imprimir();
		void EleFinal();
		bool vacia();
		bool llena();
		~CCola();
};
//-------------------------------------------------
CCola::CCola()
{
	final=-1;
	frente=0;
	tamanio=0;

	for(int i=0;i<max;i++)
	{
		cola[i]=0;
	}
}
//-----------------------------------------------------
bool CCola::llena()
{
	if(tamanio==max-1)
	{
	    cout<<"La Cola Esta llena\n";
		return 1;
	}
	else
	{
	    cout<<"La Cola No Esta llena\n";
		return 0;
	}
}
//----------------------------------------------------
bool CCola::vacia()
{
	if(final==frente)
	{
	    cout<<"La Cola Esta Vacia\n";
		return 1;
	}
	else
	{
	    cout<<"La Cola Esta Vacia\n";
		return 0;
	}
}
//------------------------------------------------------
void CCola::agregar(int elemento)
{
	if(llena()==1)
	{
		cout<<"Cola llena, este dato no fue insertado"<<endl;
		system("pause");
	}
	else
	{
	    tamanio++;
		final++;
		cola[final]=elemento;
		cout<<"Dato Insertado"<<endl;
    }
}
//-----------------------------------------------------
void CCola::sacar()
{
	if(vacia()==1)
	{
		cout<<"La Cola Esta Vacia"<<endl;
	}
	else
	{
		cout<<"Dato Extraido:"<<cola[frente]<<endl;
		frente++;
		tamanio--;
	}
}
//------------------------------------------------------------------
void CCola::EleFinal()
{
	if(vacia()==1)
	{
		cout<<"La Cola Esta Vacia"<<endl;
	}
	else
	{
		cout<<"El Ultimo Elemento Ingresado Es:"<<cola[final]<<endl;
	}
}
//------------------------------------------------------------------------
void CCola::imprimir()
{
	if(vacia()==1)
	{
		cout<<"La Cola Esta Vacia"<<endl;

	}
	else
	{
		cout<<"Datos En Cola"<<endl;
		for(int i=frente;i<=final;i++)
		{
			cout<<cola[i]<<endl;
		}
	}
}
//-----------------------------------------------------------
CCola::~CCola()
{
  {
	final=-1;
	for(int i;i<max;i++)
		{
			cola[i]=0;
		}
	}
}

int main(int argc, char** argv)
{
	CCola co;
	int ele;
	int dato;
	int opc;

	do
	{
		system("cls");
		cout<<"MENU\n"<<endl;;

		cout<<"COLA ESTATICA\n"<<endl;

		cout<<"1°Encolar"<<endl;
		cout<<"2°Desencolar"<<endl;
		cout<<"3°Imprimir Cola"<<endl;
		cout<<"4°Tope"<<endl;
		cout<<"5°Vacia"<<endl;
		cout<<"6°LLena"<<endl;
		cout<<"7°Salir"<<endl;

		cout<<"\nElige Una Opcion"<<endl;
		cin>>opc;

		system("Cls");

		switch(opc)
		{
			case 1:
			{
				cout<<"Introduce El Dato A Ingresar"<<endl;
				cin>>dato;
				co.agregar(dato);
				break;
			}
			case 2:
			{
				co.sacar();
				system("pause");
				break;
			}
			case 3:
			{
				co.imprimir();
				system("pause");
				break;
			}
			case 4:
			{
				co.EleFinal();
				system("pause");
				break;
			}
			case 5:
			{
				co.vacia();
				system("pause");
				break;
			}
			case 6:
			{
				co.llena();
				system("pause");
				break;
			}
			default:
			{

			}
		}
	}
	while(opc<7);
	return 0;
}
