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
//        19/09/2024 - Cambié la estructura del main.cc para hacer que siga el
//                     flujo del programa.

#include <fstream>
#include <iostream>
#include <string>

#include "../lib/clients.h"
#include "../lib/strings.h"
#include "../lib/tools.h"

/// @brief Muestra toda la información necesaria para que el usuario pueda manejar de forma correcta el programa.
void ShowHelp() {
  std::cout << "Este programa busca usar los conceptos básicos sobre los ";
  std::cout << "símbolos, alfabetos y cadenas y lenguajes." << std::endl;
  std::cout << std::endl;
  std::cout << "Para ejecutar este programa tendrá que seguir el siguiente ";
  std::cout << "orden al ejecutar ->" << std::endl;
  std::cout << ":$ <nombre del programa> <nombre del archivo de entrada>.txt ";
  std::cout << "<nombre del archivo de salida>.txt <número del 1 al 5, para ";
  std::cout << "realizar una acción distinta>." << std::endl << std::endl;
  std::cout << "Acciones del opcode: " << std::endl;
  std::cout << "1. Escribe en el fichero de salida cada una de las cadenas.";
  std::cout << std::endl;
  std::cout << "2. Escribe en el fichero de salida las distintas logitudes de ";
  std::cout << "cada cadena." << std::endl;
  std::cout << "3. Escribe en el fichero de salida la inversa de cada cadena.";
  std::cout << std::endl;
  std::cout << "4. Escribe en el fichero de salida el conjunto de prefijos ";
  std::cout << "correspondientes a cada cadena." << std::endl;
  std::cout << "5. Escribe en el fichero de salida el conjuto de sufijos de ";
  std::cout << "cada cadena." << std::endl;
}

/// @brief Main del programa, maneja los argumentos que se le pasan por línea de comandos y evita que algunos errores traspasen.
/// @param argc
/// @param argv
/// @return
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::string show_help = argv[1];
    if (argc <= 4 || argc >= 5) {
      std::string filein = argv[1];
      std::string fileout = argv[2];
      int opcode = std::stoi(argv[3]), power;
      if (argc == 5) {
        power = std::stoi(argv[4]);
        //std::cout << power;
      } else {
        power = 0;
        //std::cout << power;
      }
      std::ifstream input_file(filein);
      std::ofstream output_file(fileout);
      if (!input_file.is_open() || !output_file.is_open()) {
        ShowErrorParameter();
        return 1;
      }
      std::string line;
      while (getline(input_file, line)) {
        std::pair<std::string, std::string> string_pair = SeparateStrings(line);
        Strings chain(string_pair.first, string_pair.second);
        if (argc == 5) {
          ManageOpcode(opcode, chain, power, output_file);
        } else {
          ManageOpcode(opcode, chain, power, output_file);
        }
      }
      output_file << std::endl;
      return 0;
    } else if (argc == 2 && show_help == "--help") {
      ShowHelp();
      return 0;
    } else {
      ShowErrorParameter();
      return 1;
    }
  } else {
    ShowErrorParameter();
    return 1;
  }
}