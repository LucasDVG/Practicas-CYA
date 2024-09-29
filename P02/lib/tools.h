// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Lucas de Vera Gil
// Correo: alu0101550145@ull.edu.es
// Fecha: 19/09/2024
// Archivo tools.h:
// Referencias:
// Historial de revisiones
//        18/09/2024 - Iniciación del proyecto (funciones básicas).
//        20/09/2024 - Se establecen las funciones de "Show(...)" y el manejo
//                     del opcode en su totalidad.
//        21/09/2024 - Simplifico la lectura del fichero "filein.txt".

#ifndef TOOLS_H
#define TOOLS_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "strings.h"

/// @brief Mustra error cuando el programa no encuntra los parámetros necesarios para así hacer saber al usuario como usarlo.
void ShowErrorParameter() {
  std::cerr << "Error al inicializar el porgrama, utilice <nombre del ";
  std::cerr << "programa> --help, para saber como funciona" << std::endl;
}

/// @brief Muestra un error cuando el programa no consigue/encuentra el archivo que el usuario le a marcado.
void ShowErrorFile() {
  std::cerr << "Error al abrir el archivo, asegurese de la posción del ";
  std::cerr << "archivo que quiere escribir." << std::endl;
  std::cerr << "Para saber más inicialice el programa con <nombre del ";
  std::cerr << "programa> --help";
}

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

/// @brief Este método separa el la línea del archivo que acaba de leer, para así, separarlo en cadena y alfabeto.
/// @param line
/// @return Devuelve un pair, el cual contiene la separacion del string.
std::pair<std::string, std::string> SeparateStrings(std::string line) {
  std::string chain = line.substr(0, line.find(" "));
  std::string alphabet = line.substr(line.find(" ") + 1, line.length());
  return std::make_pair(chain, alphabet);
}

/// @brief Este método simplifica el uso del opcode y divide el funcionamiento del programa en distintas llamadas a varios métodos.
/// @param opcode
/// @param chain
void ManageOpcode(int opcode, Strings chain, int power, std::ofstream &output_file) {
  switch (opcode) {
    case 1:
      chain.ShowAlphabet(chain, output_file);
      break;
    case 2:
      chain.ShowLength(chain, output_file);
      break;
    case 3:
      chain.ShowReverse(chain, output_file);
      break;
    case 4:
      chain.ShowPrefix(chain, output_file);
      break;
    case 5:
      chain.ShowSuffix(chain, output_file);
      break;
    case 6: 
      chain.ShowPower(chain, power, output_file);
    default:
      break;
  }
}

#endif  // TOOLS_H