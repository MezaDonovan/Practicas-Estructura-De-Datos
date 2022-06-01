#include <stdio.h>
#include <stdlib.h>
#define TAMMAX 7

typedef int tipo_dato;

typedef struct{
    tipo_dato datos[TAMMAX];
    int ultimo;
}tipo_lista;

typedef int tipo_pos;

//FUNCIONES
void inicializa(tipo_lista*L);
int vacia(tipo_lista * L);
int llena(tipo_lista * L);
void inserta(tipo_dato e, tipo_pos pos, tipo_lista *L);
void elimina(tipo_pos pos, tipo_lista *L);
tipo_pos primero(tipo_lista * L);
tipo_pos ultimo(tipo_lista * L);
tipo_pos recupera(tipo_pos pos, tipo_lista * L);
void imprime(tipo_lista * L);
void anula(tipo_lista * L);
void burbuja (tipo_lista *L);
void insercion(tipo_lista *L);
void quickSort(tipo_lista * L,int extizq,int extder);
void mezcla(tipo_lista *L, tipo_dato extizq, tipo_dato extder);
int lineal(tipo_lista *L, tipo_dato elem, tipo_dato ultimo);
int binaria (tipo_lista *L, tipo_dato elem, tipo_dato ultimo);

//PRINCIPAL
int main(){
        tipo_dato dato,u;
        tipo_pos pos;
        tipo_lista Lista;
    inicializa(&Lista);
        int opc, B, opct;


        do{
                printf("\n\t°°||Practica 5||°°\n\n");
                printf("--1.Vacia--\n--2.Llena--\n--3.Inserta--\n--4.Elimina--\n--5.Primero--\n--6.Ultimo--\n--7.Recupera--\n--8.Imprime--\n--9.Anula--\n--10.Ordena--\n--11.Localiza--\n--12.Salir--\n");
                printf("\n\t**Ingresa El Numero De La Opcion Deseada**: \n\t");
                scanf("%d",&opc);
                switch(opc)
                {
                        case 1: printf("\t===VACIA===\n");
                                                                B=0;
                                                            B=vacia(&Lista);
                                                            if (B==1){
                                                                printf("La lista esta vacia\n");
                                                                break;
                                                            }
                                                            else{
                                                                printf("La lista NO esta vacia\n");
                                                                }
                                                                                        break;
                        case 2: printf("\t===LLENA===\n");
                                                            B=0;
                                                                B=llena(&Lista);
                                                            if (B==1){
                                                                printf("La lista esta llena\n");
                                                                break;
                                                            }
                                                            else{
                                                                printf("La lista NO esta llena\n");
                                                                }
                                                                                        break;
                        case 3: printf("\t===INSERTA===\n");
                                                            B=0;
                                                                B=llena(&Lista);
                                                            if (B==1){
                                                                printf(" No hay espacio para guardar\n");
                                                                break;
                                                            }
                                                            else{
                                                            printf("posicion donde desea guardar\n");
                                                            scanf("%i",&pos);
                                                            printf("Numero que desea guardar\n");
                                                            scanf("%i",&dato);
                                                            inserta(dato,pos,&Lista);
                                                                }
                                                                break;
                        case 4: printf("\t===ELIMINA===\n");
                                                                B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos para eliminar\n");
                                                                break;
                                                            }
                                                            else{
                                                            printf("Posicion del elemento que desea eliminar\n");
                                                            scanf("%i",&pos);
                                                            elimina(pos,&Lista);
                                                                }
                                                                break;
                        case 5: printf("\t===PRIMERO===\n");
                                                                B=0;
                                                                B=primero(&Lista);
                                                                if (B==-1){
                                                                        printf("Aun no hay datos");
                                                                }
                                                                else{
                                                                        printf("El primer dato esta en la posicion 0");
                                                                }
                                                                                        break;
                        case 6: printf("\t===ULTIMO===\n");
                                                                B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos\n");
                                                                break;
                                                            }
                                                            else {
                                                                printf("La posicion del ultimo dato es: %i",ultimo(&Lista));
                                                                }
                                                                                        break;
                        case 7: printf("\t===RECUPERA===\n");
                                                                B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos para recuperar\n");
                                                                break;
                                                            }
                                                            else{
                                                                 printf("Posicion del elemento que quiere recuperar:\n");
                                                                         scanf("%i",&pos);
                                                                         dato=recupera(pos,&Lista);
                                                                         if (dato<0){
                                                                                        printf("No es posible recuperar el elemento");
                                                                                        break;
                                                                                }
                                                                        else {
                                                                                printf("El dato de la posicion %i es : %i",pos,dato);
                                                                        }
                                                                }
                                                                                        break;
                        case 8: printf("\t===IMPRIME===\n");
                                                            B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos para mostrar\n");
                                                                break;
                                                            }
                                                            else{
                                                                imprime(&Lista);
                                                                }
                                                                                        break;
                        case 9: printf("\t===ANULA===\n");
                                                                B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos para anular\n");
                                                                break;
                                                            }
                                                            else{
                                                                anula(&Lista);
                                                                }
                                                                                        break;
                        case 10: printf("\t===ORDENA===\n");
                                                                B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos para ordenar\n");
                                                                break;
                                                            }
                                                            else {
                                                                do{
                                                                                printf("\n\t***ORDENAMIENTOS***\n");
                                                                                printf("1.Burbuja\n2.Insersion\n3.Quicksort\n4.Mergesort\n5.Regresar\n");
                                                                                printf("Selecciona una opcion: ");
                                                                                scanf("%d",&opct);
                                                                                switch(opct)
                                                                                {
                                                                                        case 1: printf("\t===LISTA ORDENADA CON METODO BURBUJA===\n");
                                                                                                                burbuja(&Lista);
                                                                                                                imprime(&Lista);
                                                                                                break;
                                                                                        case 2: printf("\t===LISTA ORDENADA CON INSERCION===\n");
                                                                                                                insercion(&Lista);
                                                                                                                imprime(&Lista);
                                                                                                break;
                                                                                        case 3: printf("\t===LISTA ORDENADA CON QuickSort===\n");
                                                                                                        u=ultimo(&Lista);
                                                                                                        quickSort(&Lista,0,u);
                                                                                                        imprime(&Lista);
                                                                                                break;
                                                                                        case 4: printf("\t===LISTA ORDENADA CON MEZCLA===\n");
                                                                                                        u=ultimo(&Lista);
                                                                                                        mezcla(&Lista,0,u);
                                                                                                        imprime(&Lista);
                                                                                                break;
                                                                                        case 5: opct=5;
                                                                                                break;
                                                                                        default:printf("Error esa opcion no existe\n");
                                                                        }
                                                                        }while(opct!=5);
                                                                }
                                                                break;
                        case 11:        printf("\t===LOCALIZA===\n");
                                                                B=0;
                                                                B=vacia(&Lista);
                                                            if (B==1){
                                                                printf(" No hay datos para localizar\n");
                                                                break;
                                                            }
                                                            else {
                                                                do{
                                                                                printf("\n\t***TIPOS DE LOCALIZACION***\n");
                                                                                printf("1.Lineal\n2.Binaria\n3.Regresar\n");
                                                                                printf("Selecciona una opcion: ");
                                                                                scanf("%d",&opct);
                                                                                switch(opct)
                                                                                {
                                                                                        case 1: printf("\t===BUSQUEDA LINEAL===\n");
                                                                                                                u=ultimo(&Lista);
                                                                                                                printf("Elemento que desea Buscar: ");
                                                                                                        scanf("%i",&dato);
                                                                                                        pos=lineal(&Lista,dato,u);
                                                                                                        if(pos==-1){
                                                                                                                printf("Dato no encontrado");
                                                                                                                break;
                                                                                                                }
                                                                                                                printf("El elemento se encuentra en la posicion: %i"),pos;
                                                                                                break;
                                                                                        case 2: printf("\t===BUSQUEDA BINARIA===\n");
                                                                                                                u=ultimo(&Lista);
                                                                                                                printf("Elemento que desea Buscar: ");
                                                                                                        scanf("%i",&dato);
                                                                                                        pos=binaria(&Lista,dato,u);
                                                                                                        if(pos==-1){
                                                                                                                printf("Dato no encontrado");
                                                                                                                break;
                                                                                                                }
                                                                                                                printf("El elemento se encuentra en la posicion: %i"),pos;
                                                                                                break;
                                                                                        case 3: opct=3;
                                                                                                break;
                                                                                        default:printf("Error esa opcion no existe\n");
                                                                        }
                                                                        }while(opct!=3);
                                                                }
                                                                break;
                        case 12: opc=12;
                                        printf("Gracias por usar el programa\n");
                                        break;

                        default:printf("Error esa opcion no existe\n");
                }
        }while(opc!=12);

        system("PAUSE");
        return 0;
}

void inicializa(tipo_lista*L){
        L->ultimo=-1;
}

int vacia(tipo_lista *L){
        if(L->ultimo==-1)
                return 1;//true
        else
                return 0;//false
}

int llena(tipo_lista * L){
        if(L->ultimo==TAMMAX-1)
                return 1;//true
        else
                return 0;//false
}

void inserta(tipo_dato e, tipo_pos pos, tipo_lista *L){
        int i;
        if(llena(L)||pos<0||pos>L->ultimo+1){
                printf("ERROR, dato no registrado");
                return;
        }
        else{                   //mensaje de error
                for(i=L->ultimo+1;i>pos;i--)
                        L->datos[i]=L->datos[i-1];
                L->datos[pos]=e;
                L->ultimo++;
        }
}

void elimina(tipo_pos pos, tipo_lista *L){
        int i;
        if(vacia(L)||pos<0||pos>L->ultimo){
                printf("ERROR, dato no eliminado");
                return;
                }
        else{           //mensaje de error
        for(i=pos;i<L->ultimo;i++)
                L->datos[i]=L->datos[i+1];
        L->ultimo--;
        }
}

tipo_pos primero(tipo_lista * L){
        if(vacia(L))
                return -1;
        else
                return 0;
}

tipo_pos ultimo(tipo_lista * L){
        return L->ultimo;
}

tipo_pos recupera(tipo_pos pos, tipo_lista * L){
        if(vacia(L)||pos<0||pos>L->ultimo){
                printf("ERROR, posicion invalida o lista vacia");
                return 0;
        }                                                                       //mensaje de error
        else
                return L->datos[pos];
}

void imprime(tipo_lista * L){
        int i;
        for (i=0;i<=L->ultimo;i++)
                printf("posicion: %i\t dato:  %i\n\n",i,L->datos[i]);
}

void anula(tipo_lista * L){
        L->ultimo=-1;
}

void burbuja(tipo_lista * L){
        tipo_dato i,j,aux,bandera;
        tipo_dato n=L->ultimo;
        for(i=0;i<n;i++){
                bandera=0;
                for(j=n-1;j>=i;j--){
                        if(L->datos[j]>L->datos[j+1]){
                                aux=L->datos[j];
                                L->datos[j]=L->datos[j+1];
                                L->datos[j+1]=aux;
                                bandera=1;
                        }
                }
                if(bandera==0){
                        break;
                }
        }
}

void insercion(tipo_lista *L){
        tipo_dato j,i,aux;
        for(i=1;i<=L->ultimo;i++){
                aux=L->datos[i];
                for(j=i;j>0 && aux<L->datos[j-1];j--){
                        L->datos[j]=L->datos[j-1];
                }
        if(i!=j){
                L->datos[j]=aux;
                }
        }
}

void quickSort(tipo_lista * L,int extizq,int extder){
    tipo_dato aux1,aux2,aux3,s;

    if(extizq >= extder){
        return;
    }

    aux1 = L->datos[(extizq + extder) / 2];
    L->datos[(extizq + extder) / 2] = L->datos[extder];
    L->datos[extder] = aux1;

    int i = extizq;
    int j = extder;
    while(i < j){
        while(i < j && L->datos[i] <= L->datos[extder]){
            i = i + 1;
        }
        while(i < j && L->datos[j] >= L->datos[extder]){
            j = j - 1;
        }
        if(i != j){
            aux2 = L->datos[i];
            L->datos[i] = L->datos[j];
            L->datos[j] = aux2;
        }
    }
    if(i != extder){
        aux3 = L->datos[i];
        L->datos[i] = L->datos[extder];
        L->datos[extder] = aux3;
    }

        quickSort(L,extizq,i-1);
    quickSort(L,i+1,extder);
    return;
}

void mezcla(tipo_lista *L, tipo_dato extizq, tipo_dato extder){
        tipo_dato i,j,x,medio,n;
        medio=(extizq + extder) / 2;
        int temp[L->ultimo];

        if(extizq>=extder){
                return;
        }
        mezcla (L,extizq,medio);
        mezcla (L,medio+1,extder);
        for (n=0; n<=L->ultimo;n++){
                temp[n]=L->datos[n];
        }
        i=extizq;
        j=medio+1;
        x=extizq;

        while(i<=medio && j<=extder){
                while(i<=medio && temp[i]<=temp[j]){
                        L->datos[x]=temp[i];
                        i=i+1;
                        x=x+1;
                }
        if (i<=medio){
                while(j<=extder && temp[j]<=temp[i]){
                        L->datos[x] = temp[j];
                        j=j+1;
                        x=x+1;
                }
        }
        }

while(i<=medio){
        L->datos[x]=temp[i];
        i=i+1;
        x=x+1;
}
while(j<=extder){
        L->datos[x]=temp[j];
        j=j+1;
        x=x+1;
}
}

int lineal(tipo_lista *L, tipo_dato elem, tipo_dato ultimo){
        int i;
        for(i=0;i<=L->ultimo;i++){
                if(elem==L->datos[i]){
                        return i;
                }
        }
        return -1;
}

int binaria (tipo_lista *L, tipo_dato elem, tipo_dato ultimo){
        int i,j,medio;
        i=0;
        j=ultimo;
        while(i<=j){
                medio=(i+j)/2;
                if(L->datos[medio]==elem){
                        return medio;
                }
                if(elem<L->datos[medio]){
                        j=medio-1;
                }
                else {
                        i=medio+1;
                }
        }
        return -1;
}
