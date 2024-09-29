// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Lucas de Vera Gil
// Correo: alu0101550145@ull.edu.es
// Fecha: 19/09/2024
// Archivo strings.cc:
// Referencias:
// Historial de revisiones
//        19/09/2024 - Inicializo las funciones getter, constructor y destrictpro

#include <fstream>

#include "../lib/strings.h"

/// @brief Constructor del programa, de la clase "String", permitiendo almacenar en un objeto los valores que componen la cadena, el alfabeto y tamaño de la cadena.
/// @param chain_input
/// @param alphabet_input
Strings::Strings(std::string chain_input, std::string alphabet_input) {
  chain_ = chain_input;
  alphabet_ = alphabet_input;
  chain_length_ = chain_input.length();
}

/// @brief
Strings::~Strings() {}

/// @brief
/// @return
const std::string &Strings::getAlphabet() { return alphabet_; }

/// @brief
/// @return
const std::string &Strings::getChain() { return chain_; }

/// @brief
/// @return
const int &Strings::getChainLength() { return chain_length_; }

/// @brief
/// @param chain
/// @return
std::string Strings::ReverseString(Strings chain) {
  std::string to_reverse_string{chain.getChain()};
  int length = (to_reverse_string.length() - 1);
  std::string reversed;
  for (int i{length}; i >= 0; --i) {
    reversed.push_back(to_reverse_string.at(i));
  }
  return reversed;
}

///// @brief Esta función busca detecta si existe una igualdad entre los simbolos usados para crear la cadena y el alfabeto dado. 
///// @param chain
///// @return Devuelve true, si no a encontrado ninguna discrepancia, y false, si no existe una igualdad entre los símbolos que se usan.
bool Strings::CheckChain(Strings chain) {
  for (char symbol_chain : chain.getChain()) {
    bool symbol_found{false};
    for (char symbol_alphabet : chain.getAlphabet()) {
      if (symbol_alphabet == symbol_chain) {
        symbol_found = true;
        break;
      }
    }
    if (!symbol_found) {
      return false;
    }
  }
  return true;
}

/// @brief Muestra en el fichero el alfabeto de la cadena solicitada.
/// @param chain
void Strings::ShowAlphabet(Strings chain, std::ofstream &output_file) {
  if (chain.getChain().length() != 1 && !(chain.getChain().find("&"))) {
    if (!CheckChain(chain)) {
      std::cerr << "La cadena " << chain.getChain() << ", formada a partir ";
      std::cerr << "del alfabeto " << chain.getAlphabet() << " no contiene ";
      std::cerr << "no contienen los mismos símbolos." << std::endl;
    } else {
      output_file << "{ ";
      for (unsigned i{0}; i < chain.getAlphabet().length(); ++i) {
        if (i == chain.getAlphabet().length() - 1) {
          output_file << chain.getAlphabet().at(i);
        } else {
          output_file << chain.getAlphabet().at(i) << ", ";
        }
      }
      output_file << "}" << std::endl;
    }
  } else {
    output_file << "{ ";
      for (unsigned i{0}; i < chain.getAlphabet().length(); ++i) {
        if (i == chain.getAlphabet().length() - 1) {
          output_file << chain.getAlphabet().at(i);
        } else {
          output_file << chain.getAlphabet().at(i) << ", ";
        }
      }
      output_file << "}" << std::endl;
  }
}

/// @brief Muestra por el fichero la longitud de la cadena que se pasa por parámetros.
/// @param chain
void Strings::ShowLength(Strings chain, std::ofstream &output_file) {
  if (chain.getChain().length() == 1 && (!chain.getChain().find("&"))) { 
    output_file << 0 << std::endl;
  } else if (chain.getChain().find("&")) {
    output_file << chain.getChainLength() << std::endl;
  }
}

/// @brief Metodo que ayuda a liverar cierta carga de ShowSuffix(), pasando la cadena que le es dada por parametro, devolviendola al revés.
/// @param chain
void Strings::ShowReverse(Strings chain, std::ofstream &output_file) {
  std::string to_reverse_string{chain.chain_};
  int length = (to_reverse_string.length() - 1);
  for (int i{length}; i >= 0; --i) {
    output_file << to_reverse_string.at(i);
  }
  output_file << std::endl;
}

/// @brief Metodo que muestra por el fichero todas las opciones de sufijos contruibles haciendo uso del algebra de conjuto, y tratando las cadenas vacías.
/// @param chain
void Strings::ShowPrefix(Strings chain, std::ofstream &output_file) {
  if (chain.getChain().length() == 1 && (!chain.getChain().find("&"))) { 
    output_file << "{&}" << std::endl;
  } else if (chain.getChain().find("&")) {
    output_file << "{&, ";
    for (int i{0}; i < chain.getChainLength(); ++i) {
      if (!(i == 0)) {
        output_file << ", ";
      }
      for (int j{0}; j <= i; ++j) {
        output_file << chain.getChain().at(j);
      }
    }
    output_file << "}" << std::endl;
  }
}

/// @brief Metodo que muestra por el fichero todas las opciones de prefijos contruibles haciendo uso del algebra de conjuto, y tratando las cadenas vacías.
/// @param chain
void Strings::ShowSuffix(Strings chain, std::ofstream &output_file) {
  if (chain.getChain().length() == 1 && (!chain.getChain().find("&"))) {
    output_file << "{&}" << std::endl;
  } else if (chain.getChain().find("&")) {
    output_file << "{&, ";
    std::string reversed_string = ReverseString(chain);
    for (unsigned i{0}; i < reversed_string.length(); ++i) {
      if (!(i == 0)) {
        output_file << ", ";
      }
      std::string to_rite;
      for (unsigned j{0}; j <= i; ++j) {
        to_rite.push_back(reversed_string.at(j));
      }
      int total_length = (to_rite.length() - 1);
      for (int j{total_length}; j >= 0; --j) {
        output_file << to_rite.at(j);
      }
    }
    output_file << "}" << std::endl;
  }
}

void Strings::ShowPower(Strings chain, int power, std::ofstream &output_file) {
  if (chain.getChain().length() == 1 && (!chain.getChain().find("&"))) {
    output_file << "&" << std::endl;
  } else if (chain.getChain().find("&")) {
    for (int i{0}; i < power; ++i) {
      for (unsigned j{0}; j < chain.getChain().length(); ++j) {
        output_file << chain.getChain().at(j);
      }
    }
    output_file << std::endl;
  }
}