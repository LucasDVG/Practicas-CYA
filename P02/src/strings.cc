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

#include "../lib/strings.h"
//#include "../lib/tools.h"

strings::strings(std::string chain_input, std::string alphabet_input) {
  chain_ = chain_input;
  alphabet_ = alphabet_input;
  chain_length_ = chain_input.length();
}

void strings::ShowAlphabet(strings chain) {
  std::cout << "{";
  for (int i{0}; i < alphabet_.length(); ++i) {
    if (i < alphabet_.length()) {
      std::cout << ", ";
    }
    std::cout  << alphabet_[i];
  }
  std::cout << "}" << std::endl;
}

void strings::ShowLength() {

}

void strings::ShowReverse() {

}

void strings::ShowPrefix() {

}

void strings::ShowSuffix() {

}

