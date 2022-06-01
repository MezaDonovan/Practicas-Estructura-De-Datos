#define TAM 255
#define VACIA -1
#include <iostream>
#include <cstring>

using namespace std;
class pila_arre
{
   private:
      int tam;
      int tos;
      char datos[TAM];

   public:
      pila_arre()
      {
          tam =TAM;
          tos = VACIA;
      }

      bool vacia()
      {
          return tos == VACIA;
      }
      bool llena()
      {
          return tos == tam-1;
      }
      char top()
      {
        char val = '\0';
        if(!vacia())
           val = datos[tos];
        return val;

      }
      void push(char val)
      {
          if(!llena())
             datos[++tos]= val;
          else
             cout << "\nPila llena el dato " << val << " no se puede agregar" << endl;
      }
      char pop()
      {
          char val='\0';
          if(!vacia())
             val = datos[tos--];
          else
             cout << "\nPila vacia, no se puede eliminar" << endl;
          return val;
      }

};
class convierte_expresion
{
    public:
            void postfij(char ei[], char ep[])
        {
            pila_arre pa;

            int i = 0,j=0;
            while(ei[i] != '\0')
            {
                if(ei[i] >= 'a' && ei[i] <= 'z' || ei[i]>='A' && ei[i] <= 'Z')
                {
                    ep[j] = ei[i];
                    i++;
                    j++;
                }
                else
                    if(ei[i]=='(')
                    {
                        pa.push(ei[i]);
                        i++;
                    }
                else
                     if(ei[i]==')')
                     {
                        while( pa.top() != '(')
                        {
                            ep[j]= pa.pop();
                            j++;
                        }
                            if(pa.top() == '(')
                               {
                                   pa.pop();
                               }
                            i++;
                    }
				else
                    if(ei[i]=='^')
                    {
                        pa.push(ei[i]);
                        i++;
                    }
                    else
                        if(ei[i]=='+' || ei[i]=='-' || ei[i]=='*' || ei[i]=='/')
                        {
                            if(ei[i]=='+' || ei[i] == '-')
                            {
                                while(!pa.vacia() && pa.top() != '(')
                                    {
                                        ep[j]=pa.pop();
                                        j++;
                                    }
                                pa.push(ei[i]);
                                i++;
                            }
                            else
                            {
                                if(ei[i]=='*' || ei[i]=='/')
                                {
                                    while(!pa.vacia() && pa.top() != '(' && (pa.top()=='*'|| pa.top()=='/'))
                                    {
                                        ep[j]=pa.pop();
                                        j++;
                                    }

                                    pa.push(ei[i]);
                                    i++;
                                }
                           }

                       }
                       else
                       {
                           cout<<"CARACTER INVALIDO"<<endl;
                           ei[i] = '\0';
                       }

            }

            while(!pa.vacia())
            {
                ep[j]=pa.pop();
                j++;
            }
       ep[j] = '\0';

       }

};

int main () {

    char expresion_infij[TAM];
    char expresion_postfij[TAM];
    convierte_expresion ce;
    cout << "\t\tIngrese la expresion a convertir: \t\t" << endl;
    cin.getline (expresion_infij, TAM-1); //  lee la cadena getline() y pone como ultimo caracter '\0' caracter nulo
    ce.postfij(expresion_infij, expresion_postfij);
    cout << "\n\t\tExpresion posfija: \t\t\n"  << expresion_postfij << endl;
    return 0;
}
