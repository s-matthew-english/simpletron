# define READ       10
# define WRITE      11

# define LOAD       20
# define STORE      21

# define ADD        30
# define SUBTRACT   31
# define DIVIDE     32
# define MULTIPLY   33

# define BRANCH     40
# define BRANCHNEG  41
# define BRANCHZERO 42
# define HALT       43

typedef struct{
  int *memory;
  int accumulator;
  int instructionCounter;
  int instructionRegister;
  int operationCode;
  int operand;
} VM;

int getOperationCode(int full){ return full / 100; }

int getOperand(int full){ return full % 100; }

void operate(VM* vm){
  vm->instructionRegister = vm->memory[vm->instructionCounter];
  vm->operationCode = getOperationCode(vm->instructionRegister);
  vm->operand = getOperand(vm->instructionRegister);

  switch(vm->operationCode) {
    case READ :
      printf("READ: ");
      scanf("%d", &vm->memory[vm->operand]);
      vm->instructionCounter++;
      break;
    case WRITE :
      // printf("WRITE: ");
      printf("%d, \n", vm->memory[vm->operand]);
      vm->instructionCounter++;
      break;
    case LOAD :
      // printf("load: \n");
      vm->accumulator = vm->memory[vm->operand];
      vm->instructionCounter++;
      break;
    case STORE :
      // printf("store: \n");
      vm->memory[vm->operand] = vm->accumulator;
      vm->instructionCounter++;
      break;
    case ADD :
      vm->accumulator = vm->accumulator + vm->memory[vm->operand];
      vm->instructionCounter++;
      break;
    case SUBTRACT :
      vm->accumulator = vm->accumulator - vm->memory[vm->operand];
      vm->instructionCounter++;
      break;
    case DIVIDE :
      if(vm->accumulator == 0 && vm->memory[vm->operand] != 0){
        printf("Terminated: Attempt to divide by zero");
        vm->instructionCounter = 100;
      }else{
        vm->accumulator = vm->memory[vm->operand] / vm->accumulator;
        vm->instructionCounter++;
      }
      break;
    case MULTIPLY :
      vm->accumulator = vm->memory[vm->operand] * vm->accumulator;
      vm->instructionCounter++;
      break;
    case BRANCH :
      vm->instructionCounter = vm->operand;
      break;
    case BRANCHNEG :
      if(vm->accumulator < 0){
        vm->instructionCounter = vm->operand;
      }else{
        vm->instructionCounter++;
      }
      break;
    case BRANCHZERO :
      if(vm->accumulator == 0){
        vm->instructionCounter = vm->operand;
      }else{
        vm->instructionCounter++;
      }
      break;
    case HALT :
      vm->instructionCounter = 100;
      break;
    default:
      printf("INVALID operationCode: '%d'", vm->operationCode);
      vm->instructionCounter = 100;
      break;
  }
  return;
}

void run(VM* vm){
  while(vm->instructionCounter < 100){
    operate(vm);
  }
  return;
}
