#include <iostream>
#include <unordered_set>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string userCmd;
  std::unordered_set<std::string> cmds;

  std::cout << "$ ";

  // read user's input
  std::getline(std::cin, userCmd);

  // Print an error message in exactly this format: {command}: command not found
  if (!cmds.count(userCmd)) {
	  std::cout << userCmd << ": command not found\n";
  }

}
