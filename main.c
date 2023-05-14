#include "treemap.c"
#include "heap.c"
#include "list.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BARRA "-------------------------------------------------------"


//Se definen las estructuras de datos y TDA usadas en el programa.
typedef struct Pair{//Lista de Items para cada jugador
  void* key;
  void* data;
  List* nodoady;
}Pair;           

struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}

void RegistrarTarea(Heap heap, TreeMap *map, tarea1){
  
}

void mostrarMenu() {//Función que se encarga de desplegar el menu cada vez que se ingresa al programa.
  puts(BARRA);
  printf("                   Administrador de prioridades\n");
  puts(BARRA);
  printf("\nSeleccione una opción:\n\n1. 1. Agregar tarea\n2. Establecer precedencia entre   tareas\n3. Mostrar tareas por hacer\n4. Marcar tarea como completada\n5. Deshacer última acción\n6. Cargar datos de tareas desde un archivo de texto\n0. Salir\n\n");
  puts(BARRA);
}

int main(){
  TreeMap* map = createTreeMap();
  Heap* heap = createHeap();
  char tarea1[31];
  char tarea2[31];
  int prioridad;
  unsigned short numIngresado;
  char nombreArchivo[31];
  int largoName;

  while (true) {
    mostrarMenu();
    
    scanf("%hu", &numIngresado);
    
    while (numIngresado > 6 || numIngresado < 0) {
      printf("Ingrese un número válido \n");
      scanf("%hu", &numIngresado);
    }
    
    if (numIngresado == 0) {
      printf("\n");
      puts(BARRA);
      printf("                  FIN DEL PROGRAMA\n");
      puts(BARRA);
      return 0;
    }
    if (numIngresado == 1) {
      printf("Ingrese el nombre de la tarea\n");
      scanf(" %[^\n]", tarea1);
      largoName = strlen(tarea1);
      
      while (largoName > 31 || largoName < 1) {
      printf("Ingrese un nombre válido (hasta 30 caracteres)\n");
      scanf(" %[^\n]", tarea1);
      largoName = strlen(tarea1);
      }
      printf("Ingrese la prioridad de la tarea\n");
      scanf(" %i", &prioridad);
      
      //RegistrarTarea(heap, map, tarea1);
    }
    if (numIngresado == 2) {
      printf("Ingrese el nombre de la primer tarea\n");
      scanf(" %[^\n]s", tarea1);
      printf("Ingrese el nombre de la segunda tarea\n");
      scanf(" %[^\n]s", tarea2);
      //Precedencia(tarea1, tarea2);
    }
    if (numIngresado == 3) {
      //mostrarTareas(map);
    }
    if (numIngresado == 4) {
      printf("Ingrese el nombre de la tarea completada\n");
      scanf(" %[^\n]", tarea1);
      //borrarTarea(map,tarea1);
    }
    if (numIngresado == 5) {
      //deshacer(map);
    }
    if (numIngresado == 6) {
      printf("Escriba el nombre del archivo\n");
      scanf(" %[^\n]", nombreArchivo);
      setbuf(stdout, NULL);

      FILE *archivo = fopen(nombreArchivo,"rt");
      if (archivo == NULL) {
        printf("* Error al abrir el archivo.\n");
      } 
      else{
        //importar(map, archivo);
        printf("* Archivo importado con éxito\n");
      }
    }
  }
}