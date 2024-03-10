// Esquema de la entrada: fin de la entrada
#include <stdio.h>
#include <malloc.h>

long horario[400000];
int casoDePrueba()
{
     long int Numero;
     if (scanf("%ld", &Numero) == EOF) // Leer el inicio del caso de prueba
          return 0;                     // false
     else
     {
          Numero *= 2;
          int i;
          int companeros = 0;
          int comp_max = 0;
          for (i = 0; i < Numero; i += 2)
          {
               scanf("%ld %ld", &horario[i], &horario[i + 1]);
               int j;
               for (j = i; j >= 0; j-=2)
               {
                    if ((horario[j] > horario[i] && horario[j] < horario[i + 1]) || (horario[j + 1] > horario[i] && horario[j + 1] < horario[i + 1]))
                         companeros++;
               }
               
               if (companeros > comp_max)
                    comp_max = companeros;

               companeros = 0;
               
          }
          
          printf("%i\n",comp_max);

          return 1; // true
     }

} // casoDePrueba

int main()
{

     while (casoDePrueba())
          ;

     return 0;

} // main
