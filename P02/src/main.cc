#include <iostream>
#include <fstream>
#include <string>

#include "./tools.h"

int main (int argc, char* argv[]) {
  if (argc == 4) {
    std::string filein = argv[1];
    ManageFilein(filein);
    std::string fileout = argv[2];
    int opcode = std::stoi(argv[3]);
    switch (opcode){
      case 1:
        
        break;
      
      case 2:

        break;
  
      case 3:

        break;
  
      case 4:
      
        break;
  
      default:
        break;
    }
  } else if (argv[1] != "--help") {
    ThrowError();
    return 1;
  } else {
    Help();
    return 0;
  }
  return 0;
}