#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "estruct.h"


// Estructura Lista
typedef struct tipoLista
               { TElemento listaElemento[5];
                 int tamanhoLista;
                 int posicionLista;
                      } TLista;

bool vacia(TLista *pLista)
{
    if(pLista->tamanhoLista == 0)
        { printf("\n -> Lista vacia\n\n");
           }
           else
            printf("\n -> La lista no esta vacia\n\n");
}

bool llena(TLista *pLista)
{
    if(pLista->tamanhoLista == 5)
        { printf("\n -> Lista llena\n\n");
           }
           else
            printf("\n -> La lista no esta llena\n\n");
}

// Inicializar
void criarLista(TLista *pLista)
{
     pLista->tamanhoLista = 0;
     pLista->posicionLista = 0;
	 printf("\n -> Lista Inicializada!!!\n\n");
}


// Insertar
void inserirElemento(TLista *pLista)
{
	 int elementoAuxiliar;

	 if(pLista->tamanhoLista == 0)
	   {
	       printf("\n -> Deme un numero: ");
     	   scanf("%d",&elementoAuxiliar);
     	   pLista->listaElemento[pLista->tamanhoLista].elemento = elementoAuxiliar;
	       pLista->tamanhoLista++;
		   printf("\n");
	   }

	 else if(pLista->tamanhoLista < 5)
	 		{
			  printf( "\n -> Deme un numero: ");
     	      scanf("%d",&elementoAuxiliar);
     	      printf("\n");

			  for( int i = 0; i < pLista->tamanhoLista;  i++ )
			     { if(elementoAuxiliar < pLista->listaElemento[i].elemento)
					 { pLista->posicionLista = i;
			           for( int j = pLista->tamanhoLista; j > pLista->posicionLista; j-- )
              		      { pLista->listaElemento[j].elemento = pLista->listaElemento[j-1].elemento;
						    	}
					   pLista->listaElemento[pLista->posicionLista].elemento = elementoAuxiliar;
					   pLista->tamanhoLista++;
					   break;
                      }
			     }

				if(elementoAuxiliar > pLista->listaElemento[pLista->tamanhoLista-1].elemento)
				  { pLista->listaElemento[pLista->tamanhoLista].elemento = elementoAuxiliar;
					pLista->tamanhoLista++; }
		    }
		    else
          { printf("\n -> Lista llena !\n\n"); }
}

// Eliminar
void excluirElemento(TLista *pLista)
{
	 if(pLista->tamanhoLista == 0 )
	   {
	      printf("\n -> Lista Vacia!!!\n\n");
	   }
	 else {
	 	  	 printf("\n -> Deme la posicion del dato a borrar: ");
             scanf("%d",&pLista->posicionLista);

             if((pLista->posicionLista >= 0) && (pLista->posicionLista <= 4 ))
               {
                	for( int i = pLista->posicionLista; i < pLista->tamanhoLista; i++ )
                	    {
                	    	pLista->listaElemento[i] = pLista->listaElemento[i+1];
                	    }

					pLista->tamanhoLista--;
					printf("\n -> Dato eliminado!!!\n\n");
               }
               else {
               		      printf("\n -> Posicion no encontrada  !!!\n\n");
                    }
         }

}


// Imprimir
void mostrarLista(TLista *pLista)
{
     if(pLista->tamanhoLista == 0)
         { printf("\n -> Lista Vacia!\n\n");
           }
     else
         {
           printf("\n-> Contenido de la Lista:\n\n");
           for( int i = 0; i < pLista->tamanhoLista; i++)
              { printf("   Posicion: ");
                printf("%d",i);
                printf("   Elemento: ");
                printf("%d\n",pLista->listaElemento[i].elemento);
              }
           }
     printf("\n");
}

using namespace std;

int main(int argc, char *argv[])
{
    // Menu
    TLista lista;
    int opcion;

    do {
        cout << "*******************************\n";
        cout << " [ 01 ] - Inicializar          \n";
        cout << " [ 02 ] - Insertar             \n";
        cout << " [ 03 ] - Eliminar             \n";
	    cout << " [ 04 ] - Vacia                \n";
        cout << " [ 05 ] - Llena                \n";
        cout << " [ 06 ] - Imprimir             \n";
        cout << " [ 07 ] - Sair                 \n";
        cout << "*******************************\n";
        cout << " Elija una opcion: ";
        cin >> opcion;
        cout << "*******************************\n\n";

        switch(opcion){

                      case 1 : {  system("CLS");
                                  criarLista(&lista);
                                  break;
                                   }

                      case 2 : {  system("CLS");
                                  inserirElemento(&lista);
                                  break;
                                   }

                      case 3 : {  system("CLS");
                                  excluirElemento(&lista);
                                  break;
                                   }

                      case 4 : {  system("CLS");
                                  vacia(&lista);
                                  break;
                                  }

                      case 5 : {  system("CLS");
                                  llena(&lista);
                                  break;
                                  }

					  case 6 : {  system("CLS");
                                  mostrarLista(&lista);
                                  break;
                                  }
                      }
    } while(opcion!=7);

    system("PAUSE");
    return EXIT_SUCCESS;
}
