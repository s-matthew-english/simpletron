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

// READ to location 07:                     1007 
// READ to location 08:                     1008
// LOAD word from 07 into accumulator:      2007
// ADD word from 08 to word in accumulator: 3008
// STORE word from accumulator to memory:   2109
// WRITE the word stored in 09 to terminal: 1109
// HALT the program:                        4300
// TERMINATE:                               -99999

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
 *
 * For example, `2007 / 100 = 20.07`, 
 * the `0.7` will be truncated when
 * we store the value as an int.  
 */
int getOpCode(int aggregateValue) {
    return aggregateValue / 100;
}

/* 
 * This function takes the last two
 * digits of the input parameter.
 * 
 * For example, `4300 % 100 = 0`,
 * additionally, `2109 % 100 = 9`, 
 * so we throw away the first two 
 * digits and store only the last. 
 */
int getOperand(int aggregateValue) {
    return aggregateValue % 100;
}

void executeByteCode(int memory[], int accumulator) {
  int programCounter = 0;
  int operationCode;
  int operand;

  while(programCounter < 10) {

    // Extract first two digits.
    operationCode = getOpCode(memory[programCounter]);
    //printf("operationCode: %d\n", operationCode);

    // Extract last two digits.
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
        printf("operand: %d\n", operand);
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
