/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

/* #### Please don't change this line! #### */
int run_autograder();
#include "class.h"
int main() {
  // STUDENT TODO: Construct an instance of your class!
  auto ship = new Ship<iron>(std::string("xzl"));
  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"