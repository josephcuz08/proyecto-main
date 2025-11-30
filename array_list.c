
#include <stdlib.h>
#include "array_list.h"

// Crear lista
ArrayList* arraylist_create(int capacity) {
	ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
	list->data = (void**) malloc(sizeof(void*) * capacity);
	list->size = 0;
	list->capacity = capacity;
	return list;
}

// Aumentar capacidad
void arraylist_resize(ArrayList *list) {
	list->capacity *= 2;
	list->data = (void*) realloc(list->data, sizeof(void) * list->capacity);
}

// Agregar al final
void arraylist_add(ArrayList *list, void *element) {
	if (list->size == list->capacity) {
		arraylist_resize(list);
	}
	list->data[list->size] = element;
	list->size++;
}

// Insertar en posición
void arraylist_insert(ArrayList *list, int index, void *element) {
	if (index < 0 || index > list->size) return;
	
	if (list->size == list->capacity) {
		arraylist_resize(list);
	}
	
	for (int i = list->size; i > index; i--) {
		list->data[i] = list->data[i - 1];
	}
	
	list->data[index] = element;
	list->size++;
}

// Obtener elemento
void* arraylist_get(ArrayList *list, int index) {
	if (index < 0 || index >= list->size) return NULL;
	return list->data[index];
}

// Eliminar elemento
void arraylist_remove(ArrayList *list, int index) {
	if (index < 0 || index >= list->size) return;
	
	for (int i = index; i < list->size - 1; i++) {
		list->data[i] = list->data[i + 1];
	}
	list->size--;
}

// Liberar memoria
void arraylist_free(ArrayList *list) {
	free(list->data);
	free(list);
}
