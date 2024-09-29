// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Lucas de Vera Gil
// Correo: alu0101550145@ull.edu.es
// Fecha: 19/09/2024
// Archivo strings.h:
// Referencias:
// Historial de revisiones
//        19/09/2024 - Creo la clase alphabet para simplificar el uso de métodos
//                     y la creación de objetos relacionados al objetivo de
//                     trabajo.
//        21/09/2024 - Añado el método ReverseString() para reducir el método
//                     ShowSuffix, y añado el método ChekSymbols()

#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>
#include <fstream>
#include <string>

/// @brief La clase busca la creacion de objetos del tipo "String", como manejar sus metodos y obtener valores, esta clase está basada en los conjuntos, cadenas y symbolos del algebra básica.
class Strings {
 public:
  // Contructor
  Strings(std::string chain, std::string alphabet);
  // Destructor
  ~Strings();
  // Métodos
  bool AlreadyPushed(const std::string &alphabet_checked, char symbol_to_check);
  std::string ReverseString(Strings chain);
  std::string CheckSymbols(Strings chain);
  bool CheckChain(Strings chain); 
  void ShowAlphabet(Strings chain, std::ofstream &output_file);
  void ShowLength(Strings chain, std::ofstream &output_file);
  void ShowReverse(Strings chain, std::ofstream &output_file);
  void ShowPrefix(Strings chain, std::ofstream &output_file);
  void ShowSuffix(Strings chain, std::ofstream &output_file);
  // Getters
  const std::string &getAlphabet();
  const std::string &getChain();
  const int &getChainLength();

 private:
  std::string alphabet_;
  std::string chain_;
  int chain_length_;
};

#endif  // STRINGS_H