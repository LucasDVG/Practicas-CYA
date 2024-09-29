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

/// @brief Este método separa el la línea del archivo que acaba de leer, para así, separarlo en cadena y alfabeto.
/// @param line
/// @return Devuelve un pair, el cual contiene la separacion del string.
std::pair<std::string, std::string> SeparateStrings(std::string line) {
  std::string chain = line.substr(0, line.find(" "));
  std::string alphabet = line.substr(line.find(" ") + 1, line.length());
  return std::make_pair(chain, alphabet);
}

#endif  // TOOLS_H