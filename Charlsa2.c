#include <stdio.h>
#include <stdlib.h>

typedef struct
{
     long start;
     long end;
} Interval;

int compare_intervals(const void *a, const void *b)
{
     return ((Interval *)a)->end - ((Interval *)b)->end;
}

int casoDePrueba()
{
     long int Numero;
     if (scanf("%ld", &Numero) == EOF)
     {
          return 0; // End of input
     }
     else
     {
          Numero *= 2;
          Interval *intervals = (Interval *)malloc(sizeof(Interval) * Numero);
          int i;
          for (i = 0; i < Numero; i += 2)
          {
               scanf("%ld %ld", &intervals[i].start, &intervals[i].end);
          }

          qsort(intervals, Numero, sizeof(Interval), compare_intervals);

          int comp_max = 0;
          int comp = 1;
          long lowestEnd = intervals[0].end;
          for (i = 0; i < Numero; i++)
          {
               if (intervals[i].start < lowestEnd)
               {
                    comp++;
               }
               else
               {
                    comp--;
               }
          }

          if (comp > comp_max)
          {
               comp_max = comp;
          }

          printf("%i\n", comp_max);
          free(intervals);

          return 1; // True
     }
}

int main()
{
     while (casoDePrueba())
          ;
     return 0;
}
