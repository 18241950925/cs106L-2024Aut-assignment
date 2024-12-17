/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>

#include "utils.h"

std::string kYourName = "song yexin"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream input_file(filename);
  std::set<std::string> applicants;
  if (input_file.is_open()) {
    std::string applicant;
    while (std::getline(input_file, applicant)) {
      applicants.insert(applicant);
    }
    input_file.close();
  } else {
    std::cerr << "Error opening file: " << filename << std::endl;
    return {};
  }
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  auto equal_init = [&](std::string a,std::string b)
  {
    std::stringstream A(a),B(b);
    std::string a1,a2,b1,b2;
    A >> a1 >> a2;
    B >> b1 >> b2;
    if(a1[0]==b1[0] && a2[0]==b2[0])
    {
      return true;
    }
    return false;
  };
  std::queue<const std::string*> result;
  for(const auto& student:students)
  {
    if(equal_init(student, name))
    {
      result.push(&student);
    }
  }
  return result;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.empty())
  {
    return "NO MATCHES FOUND.";
  }
  std::string result=*matches.front();
  matches.pop();
  return result;
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
