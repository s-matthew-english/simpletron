#include <stdio.h>

#define MEMSIZE 10
#define TERMINATE -99999

/* Input/output operations: */
#define READ 10       // Read a word from the terminal into a specific location in memory.
#define WRITE 11      // Write a word from a specific location in memory to the terminal.

/* Load/store operations: */
#define LOAD 20       // Load a word from a specific location into the accumulator.
#define STORE 21      // Store a word from the accumulator into a specific location in memory.

/* Arithmetic operations: */
#define ADD 30        // Add a word from a specific location in memory to the word in the accumulator (leave result in accumulator).
#define SUBTRACT 31   // Subtract a word from a specific location in memory from the word in the accumulator (leave result in accumulator).
#define DIVIDE 32     // Divide a word from a specific location in memory into the word in the accumulator (leave result in accumulator).
#define MULTIPLY 33   // Multiply a word from a specific location in memory by the word in the accumulator (leave result in accumulator).

/* Transfer of control operations: */ 
#define BRANCH 40     // Branch to a specific location in memory.
#define BRANCHNEG 41  // Branch to a specific location in memory if the accumulator is negative. 
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero.
#define HALT 43       // Halt- i.e., the program has completed its task. 

// 1007
// 1008
// 2007
// 3008
// 2109
// 1109
// 4300
// -99999

void printMemoryContents(int memory[]) {
  for(int i = 0; i < 10; i++) {
    printf("%d",memory[i]);
  }
}

void readInputFromConsole(int memory[]) {
    int i = 0; 
    int operationCode; 
    printf("Enter Byte Code:\n");

    while(operationCode != TERMINATE){
        scanf("%d", &operationCode);
        if(operationCode == TERMINATE){
            break;
        }
        memory[i] = operationCode;
        i++;
    }
    return;
}

/* 
 * This function takes the first two
 * digits of the input parameter.
 */
int getOpCode(int aggregateValue) {
    return aggregateValue / 100;
}

/* 
 * This function takes the last two
 * digits of the input parameter.
 */
int getOperand(int aggregateValue) {
    return aggregateValue % 100;
}

void executeByteCode(int memory[], int accumulator) {
  int programCounter = 0;
  int operationCode;
  int operand;

  while(programCounter < 10) {

    operationCode = getOpCode(memory[programCounter]);
    //printf("operationCode: %d\n", operationCode);
    operand = getOperand(memory[programCounter]);
    //printf("operand: %d\n", operand);

    switch(operationCode) {
      case READ:
        printf("READ: ");
        scanf("%d", &memory[operand]);
        programCounter++;
        break;
      case WRITE:
        printf("WRITE: ");
        printf("%d\n", memory[operand]);
        programCounter++;
        break;
      case LOAD:
        printf("load: %d\n", operand);
        accumulator = memory[operand];
        programCounter++;
        break;
    case STORE :
        printf("store: %d\n", operand);
        memory[operand] = accumulator;
        programCounter++;
        break;
      case ADD:
        accumulator = memory[operand] + accumulator;
        programCounter++;
        break;
      case HALT:
        programCounter = 10;
        break;
    }
  }
}

int main()
{

  int memory[MEMSIZE] = { 0 };
  int accumulator;

  readInputFromConsole(memory);

  executeByteCode(memory, accumulator);

  return 0;

}
