#include "commands.hpp"
#include "process_utils.hpp"
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

	  if (cmds.count(cmd)) {
      cmds.at(cmd)(args);
      continue;
	  }

    executeExternalCommand(cmd, args);

  }
}
