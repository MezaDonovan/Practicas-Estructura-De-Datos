#include <stdio.h>
int main(){
  int b,tt,a=1; //Variables,b(bucle),tt(tamaño triangulo),a(asteriscos)
do {
  a=1;
  printf("\nIngrese un numero entero positivo para el triangulo: \n");

  scanf("%d",&tt);

  printf("\n");

  for(int sr=1; sr<=tt ; sr++)//saltos de renglon y modificacion de la variable "a"
  {
    for(int im=1; im<=a ; im++)//impresion de los asteriscos
    {
      printf("*");
    }
    printf("\n");//saltos de linea
    a= a+1;//operacion para imprimir un "*" mas en cada linea
  }
  printf("--------------------------------------------------------------");//Corte de triangulo

  printf("\n¿Quiere hacer otro triangulo? Si = 1, No = 2\n");//Pregunta para el bucle
  scanf("%d",&b);
} while(b==1);//Funcion bucle
printf("\nFinalizando programa\n");
return 0;
}
