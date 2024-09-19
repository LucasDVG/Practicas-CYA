// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología 
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Lucas de Vera Gil
// Correo: alu0101550145@ull.edu.es
// Fecha: 19/09/2024
// Archivo main.cc: 
// Referencias:
// Historial de revisiones
//        18/09/2024 - Iniciación del proyecto (funciones básicas). 

#include <iostream>
#include <fstream>
#include <string>

#include "../lib/tools.h"
#include "../lib/strings.h"

int main (int argc, char* argv[]) {
  std::string help{argv[1]};
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
  } else if (argc == 2 && help == "--help") {
    ShowHelp();
    return 0;
  } else if (argc > 4 || argc < 2) {
    ShowError();
    return 1;
  }
  return 0;
}