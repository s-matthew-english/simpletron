#include <stdio.h>
#include <stdlib.h>

#include "assemblyHandler.c"
#include "virtualMachine.c"
// #include "compiler.c"

void printMemory(int arr[]){
  printf("\n");
  for(int i = 0 ; i < 100 ; i++){ printf("%d : %d\t\t", i, arr[i]); }
  printf("\n");
  return;
}
int main(int argc, char *argv[]){

  int memory[100] = { 0 };
  VM vm = {.memory = memory};

  if(argv[1] == NULL){
    inputAssemblyFromConsole(vm.memory);
  }else{
    inputAssemblyFromFile(vm.memory, argv[1]);
  }

  run(&vm);
  printMemory(memory);
  exit(EXIT_SUCCESS);
}

// void printArgv(int size, char arr[]){
//     printf("\n");
//     int nullCount = 0;
//     int i = 0;
//     while(nullCount < size){ 
//         if(!arr[i]){ nullCount++; }
//         printf("%d : %c\t\t", i, arr[i]); 
//         i++;
//     }
//     printf("\n");
//     return;
// }
