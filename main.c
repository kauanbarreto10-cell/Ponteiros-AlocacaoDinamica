#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers,int size); // ler todos os valores para os espaços
float numbers_average(int *numbers,int size); // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers);        // desaloca a variável alocada
int maior_numero(int *numbers, int size);  // encontra o maior número do conjunto de dados
int menor_numero(int *numbers, int size);  // encontra o menor número do conjunto de dados
void pares(int *numbers, int size);        // exibe os números pares do conjunto de dados
void impares(int *numbers, int size);      // exibe os números ímpares do conjunto de dados
int compare_function(const void *a, const void *b); //Organiza o vetor criado em ordem crescente de numeros
// **************************************************************************

// **************************** Implementação ******************************

int *numbers_create(int size){
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}
void numbers_read(int *numbers, int size) {
  if (numbers != NULL){
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
int maior_numero(int *numbers, int size){
  if (numbers != NULL && size > 0){
  int maior = numbers[0];
    for (int i = 1; i < size; i++)
      if (numbers[i] > maior)
        maior = numbers[i];
  return maior;
  }
  return 0;
}
int menor_numero(int *numbers, int size){
  if (numbers != NULL && size > 0){
    int menor = numbers[0];
      for (int i = 1; i < size; i++)
        if (numbers[i] < menor)
          menor = numbers[i];
  return menor;
  }
  return 0;
}
void pares(int *numbers, int size){
  printf("Numeros Pares:[");
  if (numbers != NULL && size > 0){

    for(int i = 0; i < size; i++)
      if (numbers[i] % 2 == 0)
        printf("%d,", numbers[i]);
  }
  printf("]\n");
}
void impares(int *numbers, int size){
  printf("Numeros Impares: [");
  if (numbers != NULL && size > 0){
    for(int i = 0; i < size; i++)
      if (numbers[i] % 2 != 0)
        printf("%d,", numbers[i]);
  }
  printf("]\n");
}
int compare_function(const void *a, const void *b){
    int A = *(int *)a;
    int B = *(int *)b;
      return A - B;
}
void numbers_destroy(int *numbers) { free(numbers); 
}

// *************************************************************************

int main() {
  srand(time(NULL));
  int *numbers; 
  int size=rand() % 100; 
  numbers = numbers_create(size);
  numbers_read(numbers, size);
  qsort(numbers, size, sizeof(int), compare_function);
  float avg = numbers_average(numbers, size); 
  numbers_show (numbers,size);
  printf("Media = %.2f\n", avg);
  int mor = maior_numero(numbers, size);
  printf("Maior numero: %d\n", mor);
  int men = menor_numero(numbers, size);
  printf("Menor numero: %d\n", men);
  pares (numbers, size);
  impares (numbers, size);
  numbers_destroy(numbers);
  return 0;
}