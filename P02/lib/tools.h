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

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

void ShowError () {
  std::cerr << "Error al inicializar el porgrama, utilice <nombre del ";
  std::cerr << "programa> --help, para saber como funciona" << std::endl;
}

void ShowHelp () {
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

void CheckVariables () {

}

void ManageFilein (std::string filein) {
  std::ifstream input_file(filein);
  if (!input_file.is_open()) {
    std::cerr << "No se ha podido abrir el archivo ->" << filein << std::endl;
  }
  std::vector<std::string> words;
  std::string word;
  int counter {0};
  while(input_file >> word) {
    words.push_back(word);
  }
  for (const auto &i : words) {
    std::cout << i << std::endl;
  }
  input_file.close();
}

#endif //TOOLS_H