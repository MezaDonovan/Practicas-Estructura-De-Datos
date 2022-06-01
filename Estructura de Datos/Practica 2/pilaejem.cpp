#include <iostream>
#define TAMPILA 10
using namespace std;

typedef int tipo_dato;

typedef struct {
    tipo_dato datos[TAMPILA];
    int tope;
} Pila;


void inicializa(Pila *p)
{
    p->tope = -1;

}

bool vacia(Pila *p){
    return p->tope == -1;
}

bool llena(Pila *p){
    return p->tope == TAMPILA-1;
}

void push(Pila *p, tipo_dato elem)
{
    if(llena(p)){
        //imprimir mensaje de error


    }

    else {

        p->tope++;
        p->datos[p->tope] = elem;
    }


}

tipo_dato pop(Pila *p){

    if(vacia(p)){
        //imprimir mensaje de error


    } else {

        p->tope--;

        return p->datos[p->tope + 1];
    }
}

tipo_dato top(Pila *p){

    if(vacia(p)){
        //imprimir mensaje de error


    } else {

        return p->datos[p->tope];
    }
}

void imprimir(Pila *p)
{

    std::cout << "imprimiendo: " << std::endl;
    for(int i = 0 ; i <= p->tope ; i++){
        cout<<p->datos[i] <<" ";
    }
    std::cout << std::endl;
}

int main()
{
    Pila miPila1, miPila2;

    inicializa(&Pila);


    std::cout << "Apilar:" << std::endl;
    push(&miPila, 1);
    imprimir(&miPila);
    push(&miPila, 2);
    imprimir(&miPila);
    push(&miPila, 3);
    imprimir(&miPila);

    std::cout << "Desapilar:" << std::endl;

    std::cout << pop(&miPila) << std::endl;
    std::cout << pop(&miPila) << std::endl;
    std::cout << pop(&miPila) << std::endl;


    return 0;
}
