/*
In this file, we define our main function and ensure that a valid input
date file is provided.
*/
#include <iostream>
#include <string>
#include<mpi.h>

#include "Case.hpp"
#include "Communication.hpp"

int main(int argn, char **args) {
  int rank, size;
  Communication::init_parallel(argn, args, rank, size);
  if (argn > 1) {
    std::string file_name{args[1]};
    Case problem(file_name, argn, args, rank);
    problem.simulate();
  } else {
    std::cout << "Error: No input file is provided to fluidchen." << std::endl;
    std::cout << "Example usage: /path/to/fluidchen /path/to/input_data.dat"
              << std::endl;
  }
  Communication::finalize();
}
