#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int alumnosAregistrar;
int contadorDeregistros = 0;
int bandera = 0;
int checkedad;

struct Alumno{
  	char codigo[10];
  	char nombre[50];
  	char carrera[30];
  }aux;

void registrarAlumno(struct Alumno *alumnos){
  	if(contadorDeregistros<alumnosAregistrar){
       do{
            fflush(stdin);
            printf("\n\n\tIngrese el c%cdigo del alumno :    ", 162);
            gets(alumnos[contadorDeregistros].codigo);
            bandera = 0;
            for(int i = 0; i < strlen(alumnos[contadorDeregistros].codigo); i++)
            {
                if(!isdigit(alumnos[contadorDeregistros].codigo[i])) {
                    printf("\n El c%cdigo ingresado no es v%clido, asegurese de solo ingresar numeros enteros y positivos\n", 162, 160);
                    bandera = 1;
                    i = 1000;
                }
            }
            if(bandera == 0){
                for(int indice=0;indice<contadorDeregistros;indice++)
                {
                    if(strcmp(alumnos[contadorDeregistros].codigo, alumnos[indice].codigo)== 0)
                    {
                        printf("\n  Este c%cdigo ya est%c registrado. Por favor, trate de registrar un c%cdigo nuevo\n", 162, 160, 162);
                        bandera = 1;
                    }
                }
            }
        }while(bandera == 1);

        fflush(stdin);
        printf("\tIngrese el nombre del alumno :    ");
        gets(alumnos[contadorDeregistros].nombre);

        fflush(stdin);
        printf("\tIngrese la carrera del alumno :   ");
        gets(alumnos[contadorDeregistros].carrera);
        printf("\n Se ha registrado el alumno con exito");

        fflush(stdin);
        contadorDeregistros++;
    }else{
        printf("\n\tEl registro de alumnos se ha superado\n");}
    }

void mostrarAlumnos(struct Alumno *alumnos){
    if(contadorDeregistros>0)
    {
        printf("\n Mostrando alumnos registrados...\n");
        for(int contador=0;contador<contadorDeregistros;contador++){
        printf("\n\n\tC%cdigo  :   %s\n", 162, alumnos[contador].codigo);
        printf("\tNombre  :   %s\n",alumnos[contador].nombre);
        printf("\tCarrera :   %s\n", alumnos[contador].carrera);
        printf("\n");
        }
    }else{
        printf("\nNo se ha registrado ning%cn alumno\n", 163);
    }
  }

int buscarAlumno(struct Alumno *alumnos, char codigoBuscado[10]){
    if(contadorDeregistros>0)
    {
        for(int Index=0; Index<contadorDeregistros;Index++){
            if(strcmp(alumnos[Index].codigo, codigoBuscado)==0){
                printf("\n Alumno encontrado\n");
                printf("\n\n\tC%cdigo  :   %s\n", 162, alumnos[Index].codigo);
                printf("\tNombre  :   %s\n",alumnos[Index].nombre);
                printf("\tCarrera :   %s\n", alumnos[Index].carrera);
                return Index;
                }
        }
        printf("\n\tNo se encontr%c un alumno con el codigo especificado\n", 162);
        return -1;
    }else
        printf("\n No se ha registrado ningun alumno. Para usar esta opci%cn, por favor registre un alumno primero\n", 162);

  }

void eliminarAlumno(struct Alumno *alumnos, char codigoAeliminar[10]){
    int indiceAlumnoEncontrado=  buscarAlumno(alumnos, codigoAeliminar);
    int indice;
    int indice2;
    int confirmacion;

    if(indiceAlumnoEncontrado!=-1){
    printf("\n %cSeguro que deseas eliminar este alumno?\n\n\t1-Si\n\t2-No\n\t", 168);
    scanf("%i", &confirmacion);
    switch(confirmacion)
    {
        case 1:
            for(indice=0; indice<contadorDeregistros; indice) {
                for (indice2 = indiceAlumnoEncontrado; indice2<contadorDeregistros-1; indice2++ ){
                    strcpy(alumnos[indiceAlumnoEncontrado].codigo, alumnos[indice2+1].codigo);
                    strcpy(alumnos[indiceAlumnoEncontrado].nombre, alumnos[indice2+1].nombre);
                    strcpy(alumnos[indiceAlumnoEncontrado].carrera, alumnos[indice2+1].carrera);
                    }
            contadorDeregistros --;
            indice = contadorDeregistros;
           }
           printf("\n Se ha eliminado a este alumno con exito\n");
           break;
        case 2:
            printf("\n Regresando al men%c principal...\n", 163);
            break;
        default:
            printf("\n Opci%cn inv%clida\n", 162, 160);
            break;
       }

    }
}


int main(){//main
  int promedio_mayor;

    do
    {
        fflush(stdin);
        printf("\n Ingrese el n%cmero m%cximo de alumnos a registrar (MIN 2): ", 163, 160);
        scanf("%d", &alumnosAregistrar);
        if(alumnosAregistrar<2)
        {
            printf("\n El m%cnimo de alumnos a registrar es 2, por favor intentelo de nuevo\n", 161);
        }
    }while(alumnosAregistrar<2);


    struct Alumno alumnos[alumnosAregistrar];
    char codigoAbuscar[10];
  	int opcion;

    do{
    printf("\n\tREGISTRO DE ALUMNOS");
    printf("\n\n\t 1.- Registrar alumno\n\t 2.- Mostrar TODOS los alumnos\n\t 3.- Buscar alumno\n\t 4.- Eliminar alumno\n\t 5.-Salir del programa\t\n");
    printf("\n Ingrese la opcion que desea ejecutar :  ");
    fflush(stdin);
   	scanf("%d",&opcion);

   	 switch(opcion){
        case 1: registrarAlumno(alumnos);
              break;
        case 2: mostrarAlumnos(alumnos);
              break;
        case 3:printf("\n\t Ingrese el codigo que desea buscar :  ", 168, 130, 162);
             scanf("%s", &codigoAbuscar);
             buscarAlumno(alumnos, codigoAbuscar);
             break;
       case 4:
           if(contadorDeregistros==0){
            printf("\n\tAun no se han registrado alumnos\n");
          }else{
            printf("\n\tIngrese el codigo del Alumno a eliminar  :   ", 168, 130, 162);
            scanf("%s", &codigoAbuscar);
            eliminarAlumno(alumnos, codigoAbuscar);}
              break;
        case 5: printf("\n\t Gracias por utilizar nuestro programa!    \n\tSaliendo del programa...\n");
              break;
        default: printf("\n\tOpci%cn no v%clida\n", 162, 160);
            }
        }while(opcion!=5);

  return 0;
  	}
