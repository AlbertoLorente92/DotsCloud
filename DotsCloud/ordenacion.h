#ifndef ORDENACION_H
#define ORDENACION_H
#include "Pareja.h"
#include <stdlib.h>

/*			 ORDENACION RAPIDA

Nuestro pivote es i(la posicion 0 al principio), y vamos ordenando los dem�s elementos a izquierda o derecha del pivote,
dependiendo de si es menor o mayor que el pivote. Cuando esto operaci�n acaba, tenemos al pivote en su posici�n y adem�s
tenemos ordenados a la izquierda del pivote los menores, y a la derecha del pivote los mayores de �ste.
Ahora recursivamente vamos haciendo la misma operaci�n en los dos bloques(izquierda y derecha)
que nos han quedado divididos por el pivote hasta que nos quede s�lo un elemento a cada lado del pivote. 
Al acabar estan todos los elementos ordenados.
*/
void quickSort (Pareja<double,double> v[],int num);

void quickSortY (Pareja<double,double> v[],int num);


#endif