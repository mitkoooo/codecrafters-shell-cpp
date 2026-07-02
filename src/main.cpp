#include "commands.hpp"
#include "parser.hpp"

#include <iostream>
#include <string>


int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  CommandMap cmds;
  registerCommands(cmds);

  while (true) {
	  std::string line;
	  std::cout << "$ ";

	  // read user's input
	  std::getline(std::cin, line);

	  if (line.empty()) continue;

	  auto [cmd, args] = parseInput(line);

	  // Print an error message in exactly this format: {command}: command not found
	  if (!cmds.count(cmd)) {
		  std::cerr << cmd << ": command not found\n";
		  continue;
	  }

	  cmds[cmd](args);
  }

}
