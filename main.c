#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers,
                  int size); // ler todos os valores para os espaços
float numbers_average(int *numbers,
                      int size);           // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers);        // desaloca a variável alocada
// **************************************************************************

// **************************** Implementação ******************************

int *numbers_create(int size) {
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}

void numbers_read(int *numbers, int size) {
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      numbers[i] = rand() % 50;
  }
}

float numbers_average(int *numbers, int size) {
  float sum = 0.0;
  if (numbers != NULL)
    for (int i = 0; i < size; i++)
      sum += numbers[i];
  if (sum != 0)
    return sum / (float)size;
  return 0;
}

void numbers_show(int *numbers, int size) {
  printf("[");
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      if (i == (size - 1))
        printf("%d", numbers[i]);
      else
        printf("%d, ", numbers[i]);
  }
  printf("]\n");
}

void numbers_destroy(int *numbers) { free(numbers); }

// *************************************************************************

int main() {
  srand(time(NULL));
  int *numbers; 
  int size=rand() % 100; 
  numbers = numbers_create(size);
  numbers_read(numbers, size);
  float avg = numbers_average(numbers, size); 
  numbers_show (numbers,size);
  printf("Media = %.2f", avg);
  numbers_destroy(numbers);
  return 0;
}