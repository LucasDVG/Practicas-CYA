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

#ifndef STRINGS_H
#define STRINGS_H

#include <iostream> 
#include <string>

class strings {
 public:
  //Contructor
  strings();
  //Destructor
  ~strings();
  //Métodos
  void ShowAlphabet();
  void ShowLength();
  void ShowReverse();
  void ShowPrefix();
  void ShowSuffix();
 private:
  std::string alphabet;
  std::string chain;
};

#endif //STRINGS_H