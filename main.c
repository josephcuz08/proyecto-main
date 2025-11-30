#include <stdio.h>
#include "array_list.h"

int main() {
	
	// 3.1 Crear lista con capacidad mínima de 3
	ArrayList *myArrayList = arraylist_create(3);
	
	// 3.2 Agregar 4 elementos con add
	int *a = (int*) malloc(sizeof(int)); *a = 10;
	int *b = (int*) malloc(sizeof(int)); *b = 20;
	int *c = (int*) malloc(sizeof(int)); *c = 30;
	int *d = (int*) malloc(sizeof(int)); *d = 40;
	
	arraylist_add(myArrayList, a);
	arraylist_add(myArrayList, b);
	arraylist_add(myArrayList, c);
	arraylist_add(myArrayList, d);
	
	// Insertar 1 elemento con insert()
	int *x = (int*) malloc(sizeof(int)); *x = 99;
	arraylist_insert(myArrayList, 2, x);
	
	// 3.3 Obtener un elemento e imprimirlo
	int *valor = (int*) arraylist_get(myArrayList, 2);
	printf("Elemento en indice 2: %d\n", *valor);
	
	// 3.4 Eliminar 2 elementos
	arraylist_remove(myArrayList, 1); // Elimina el 20
	arraylist_remove(myArrayList, 2); // Dependiendo del reordenamiento
	
	// Mostrar lista final
	printf("\nLista final:\n");
	for (int i = 0; i < myArrayList->size; i++) {
		printf("%d ", *(int*) myArrayList->data[i]);
	}
	printf("\n");
	
	// Liberar memoria
	arraylist_free(myArrayList);
	
	return 0;
}

