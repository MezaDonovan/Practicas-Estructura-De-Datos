#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};

///Prototipos
void insertar(nodo *&, int);
void mostrar(nodo *);
void primero(nodo *, int);
void ultimo(nodo *);
void eliminar(nodo *&, int);
void anula(nodo *);

int main(){
    ///Operacion vacia
    nodo *lista = NULL;

    int opc, dato;

    do{
		system("cls");
		mostrar(lista);
        cout <<"\nLista Con Nodo"<<endl<<endl;
        cout <<"1.- Insertar\n2.- Eliminar\n3.- Primero\n4.- Ultimo\n5.- Anula\n6.- Salir"<<endl;
        cin >> opc;

        switch(opc){
        case 1:
            cout <<" -- INSERTAR --" <<endl<<endl;

            cout <<"Digite un numero: ";
            cin >> dato;
            insertar(lista, dato);
            system("cls");
            break;
        case 2:
            cout <<" -- ELIMINAR --" <<endl<<endl;

            cout <<"Borrando dato... "<<endl;
            eliminar(lista, dato);
            break;
        case 3:
            cout <<"El primer dato de la lista es: ";
            primero(lista, dato);
            cout<<""<<endl<<endl;
            break;
        case 4:
            cout <<"El ultimo dato de la lista es: ";
            ultimo(lista);
            cout<<""<<endl<<endl;
            break;
        case 5:
            cout <<" -- Lista anulada --" <<endl<<endl;
            anula(lista);

            break;
        case 6:
            break;

        default:
            cout <<"Opcion invalida"<<endl;
        }

    }while(opc != 6);

    getch();
    return 0;
}

///Operacion inserta
void insertar(nodo *& lista, int n){
    ///Operacion inicializa
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo -> dato = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while((aux1 != NULL)&&(aux1->dato <n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
     }

     nuevo_nodo->siguiente = aux1;
}
///Operacion imprime
void mostrar(nodo *lista){
    nodo *actual = new nodo();
    actual = lista;

    while(actual != NULL){
        cout <<actual->dato<<" -> ";
        actual = actual->siguiente;
    }
}

void primero(nodo *lista, int n){
    nodo *actual = new nodo();
    actual = lista;

    cout<<actual->dato<<endl;
}

void ultimo(nodo *lista){
    int ultimo = 0;

    while(lista != NULL){
        if((lista->dato) > ultimo){
            ultimo = lista->dato;
        }
        lista = lista->siguiente;
    }

    cout<<ultimo;

}

void eliminar(nodo *&lista, int n){
    if(lista != NULL){
        nodo *aux_borrar;
        nodo *anterior =NULL;

        aux_borrar = lista;

        while((aux_borrar != NULL)&&(aux_borrar->dato != n)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        if(aux_borrar == NULL){
            cout <<"Elemento no encontrado" <<endl;
        }else if(anterior == NULL){
                lista = lista->siguiente;
                delete aux_borrar;
                }else{
                    anterior->siguiente = aux_borrar->siguiente;
                    delete aux_borrar;
                 }
    }
}

void anula(nodo *lista){
    delete lista;
}


