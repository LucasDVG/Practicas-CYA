#ifndef CLIENTS_H
#define CLIENTS_H

#include "strings.h"

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
    default:
      break;
  }
}

#endif