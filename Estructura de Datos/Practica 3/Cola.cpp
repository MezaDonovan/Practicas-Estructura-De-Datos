#include <iostream>
#include "CNodo.h"
#include "CLista.h"

using namespace std;

//#Funciones CNodo

void CNodo::InsertarAdelante(float fData)
{

    CNodo *pNuevo = new CNodo;
    pNuevo -> pSig = this -> pSig;
    pNuevo -> pAnt = this;
    this -> pSig = pNuevo;
    this -> pSig -> pSig -> pAnt = pNuevo;
    pNuevo -> fCont =fData;
}

float CNodo::EliminarSiguiente()
{
    float nN;
    CNodo * nP = this -> pSig;
    nN = nP -> fCont;
    this -> pSig = this -> pSig -> pSig;
    this -> pSig -> pAnt = this;
    delete nP; return nN;
}

//#Funciones CLista

void CLista::InsertarInicio(float fData)
{
    Inicio.InsertarAdelante(fData);
}

void CLista::InsertarFinal(float fData)
{
    Final.pAnt->InsertarAdelante(fData);
}

bool CLista::IsEmpty()
{
    if(Inicio.pSig == &Final)
    {
        return true;
    }
    return false;
}

int CLista::Size()
{
    int ctn = 0;

    CNodo *nP = Inicio.pSig;

    while(nP != &Final)
    {
        ctn++;
        nP = nP -> pSig;
    }
    return ctn;
}

void CLista::Vaciar()
{
    CNodo *nP=Inicio.pSig;
    CNodo *nN;
    while (nP != &Final)
    {
        nN = nP;
        nP = nP ->pSig;
        delete nN;
    }
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CLista::CLista()
{
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CLista::~CLista()
{

}

void CLista::Imprime()
{
    CNodo *nP = Inicio.pSig;
    while(nP != &Final)
    {
        cout<<nP -> fCont<< endl;
        nP = nP ->pSig;
    }
}

void CLista::ImprimeFrente()
{
    int cv = 1;
    CNodo *nP = Inicio.pSig;
    while(nP != &Final)
    {
        nP = nP ->pSig;
        cv++;
        if (cv == Size()){
            cout<<nP -> fCont<< endl;
        }
    }

}

float CLista::EliminarInicio()
{
    return Inicio.EliminarSiguiente();
}

float CLista::EliminarFinal()
{
    return Final.pAnt->pAnt->EliminarSiguiente();
}

//#Main
int main()
{
  float data;
  int opc;
  CLista cola;


  do{
      printf("\nElige Una Opcion\n");
      printf("1-Vacia\n2-Llena\n3-Encolar\n4-Desencolar\n5-Imprime\n6-Frente\n7-Salir\n\n");
      scanf("%d",&opc);
      switch(opc)
      {
          case 1:
              cola.IsEmpty();
              if (cola.IsEmpty() == true){
                printf("\nLa Cola esta vacia\n");
              }else
              printf("\nLa Cola no Esta vacia\n");
              break;
          case 2:
              cola.Size();
              if (cola.Size() == 4){
                printf("\nLa Cola esta llena\n");
              }else
              printf("\nLa Cola no Esta llena\n");
              break;
          case 3:
            cola.Size();
            if (cola.Size() == 4){
                printf("\nLa Cola ya esta llena\n");
                break;
            }
            else if(cola.Size()==0){
                    for(int i = cola.Size() ; i<= 3; i++) {
                        printf("Introduzca un dato:\t");
                        cin >> data;
                        cola.InsertarFinal(data);
                        }
                        }
                        else
                        for(int i = cola.Size() ; i<= 3; i++) {
                            printf("Introduzca un dato:\t");
                            cin >> data;
                            cola.InsertarFinal(data);
                            }
              break;
          case 4:
              cola.IsEmpty();
              if (cola.IsEmpty() == true){
                printf("\nLa Cola esta vacia\n");
              }else{
              cola.EliminarFinal();
              }
              break;
          case 5:
              cola.IsEmpty();
              if (cola.IsEmpty() == true){
                printf("\nLa Cola esta vacia\n");
              }else{
              printf("\n");
              printf("\nCola :\n");
              cola.Imprime();
              }
              break;
          case 6:
              cola.IsEmpty();
              if (cola.IsEmpty() == true){
                printf("\nLa Cola esta vacia\n");
              }else{
              printf("\n");
              printf("\nFrente :\n");
              cola.ImprimeFrente();
              }
              break;
      }
  }while (opc != 7 || opc > 0 && opc < 7);
  printf("\nHasta Luego!\n");
}
