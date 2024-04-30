#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
#define MAX 100

void ordena (int *vet, int tamanho, int tipo);

main() {
  int x, vet[TAM], escolha;
  srand(time(NULL));
  for(x = 0; x < TAM; x++){
    vet[x] = rand() % MAX + 1;
  }
  printf("Vetor gerado:\n ");
  for(x = 0; x < TAM; x++){
    if(x == TAM - 1){
      printf("%i\n", vet[x]);
    }
    else{
      printf("%i - ", vet[x]);
    }
  }
  printf("\nVocê deseja ordenar de forma crescente ou decrescente? \n[0] crescente \n[1] decrescente\n");
  scanf("%i", &escolha);
  getchar();
  while(escolha != 0 && escolha != 1){
    printf("Opção inválida, digite novamente: ");
    scanf("%i", &escolha);
    getchar();
  }
  ordena(vet, TAM, escolha);
  printf("\nVetor ordenado:\n ");
  for(x = 0; x < TAM; x++){
    if(x == TAM - 1){
      printf("%i\n", vet[x]);
    }
    else{
      printf("%i - ", vet[x]);
    }
  }
  getchar();
}

void ordena (int *vet, int tamanho, int tipo){
  int x, y, maior, dif, vet2[tamanho];
  for(x = 0; x < tamanho; x++){
    vet2[x] = *(vet + x);
  }
  if(tipo == 0){
    do{
      dif = 0;
      for(x = 0; x < tamanho - 1; x++){
        if(*(vet + x) > *(vet + x + 1)){
          dif++;
          maior = *(vet + x);
          *(vet + x) = *(vet + x + 1);
          *(vet + x + 1) = maior;
        }
      }
    }while(dif != 0);
  }
  else{
    do{
      dif = 0;
      for(x = 0; x < tamanho - 1; x++){
        if(*(vet + x) < *(vet + x + 1)){
          dif++;
          maior = *(vet + x);
          *(vet + x) = *(vet + x + 1);
          *(vet + x + 1) = maior;
        }
      }
    }while(dif != 0);
  }
}