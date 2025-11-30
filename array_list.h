#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
	void **data;      // Arreglo de punteros genéricos
	int size;         // Cantidad de elementos almacenados
	int capacity;     // Capacidad actual del arreglo
} ArrayList;

// Funciones del ArrayList
ArrayList* arraylist_create(int capacity);
void arraylist_add(ArrayList *list, void *element);
void arraylist_insert(ArrayList *list, int index, void *element);
void* arraylist_get(ArrayList *list, int index);
void arraylist_remove(ArrayList *list, int index);
void arraylist_free(ArrayList *list);

#endif
