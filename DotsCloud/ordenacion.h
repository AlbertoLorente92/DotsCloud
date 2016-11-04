#ifndef ORDENACION_H
#define ORDENACION_H
#include "Pareja.h"
#include <stdlib.h>
#include "Pair.h"
/*			 ORDENACION RAPIDA

Nuestro pivote es i(la posicion 0 al principio), y vamos ordenando los demás elementos a izquierda o derecha del pivote,
dependiendo de si es menor o mayor que el pivote. Cuando esto operación acaba, tenemos al pivote en su posición y además
tenemos ordenados a la izquierda del pivote los menores, y a la derecha del pivote los mayores de éste.
Ahora recursivamente vamos haciendo la misma operación en los dos bloques(izquierda y derecha)
que nos han quedado divididos por el pivote hasta que nos quede sólo un elemento a cada lado del pivote. 
Al acabar estan todos los elementos ordenados.
*/
void quickSort (Pareja<double,double> v[],int num);

void quickSortY (Pareja<double,double> v[],int num);


#endif