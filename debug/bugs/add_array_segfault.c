#include <stdio.h>

int add_array(int *a, int *b, int n){
  int sum = 0;
  int i = 0;
  //seguia mal el n+1
  for (i = 0; i < n; i++) {
    sum += abs(a[i]);
    sum += abs(b[i]);
  };
  return sum;
}

int main(int argc, char **argv) {
  int *a, *b;
  int n = 3;
  int i, sum;
// el problema es que *a esta en la posicion de memoria 0x0 al correr main
// se arregla agregando esto:
//  a = (int*) malloc(n * sizeof(int));  //memory allocated using malloc
//  b = (int*) malloc(n * sizeof(int));  //memory allocated using malloc
  for (i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
  }
  sum = add_array(a, b, 3);
  printf("The addition is %d\n", sum);
  return 0;
}


// al compilar con el flag -Wall agrega esto:
//add_array_segfault.c:23:6: aviso: puede ser que se utilice ‘a’ sin inicializar en esta función [-Wuninitialized]
//add_array_segfault.c:24:6: aviso: puede ser que se utilice ‘b’ sin inicializar en esta función [-Wuninitialized]
// asi que el error salta!


