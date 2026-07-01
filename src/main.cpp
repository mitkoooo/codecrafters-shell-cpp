#include <iostream>
#include <functional>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::unordered_map<std::string, std::function<void()>> cmds;

  cmds["exit"] = []() {
	exit(0);	
  };

  while (true) {
	  std::string userCmd;
	  std::cout << "$ ";

	  // read user's input
	  std::getline(std::cin, userCmd);

	  // Print an error message in exactly this format: {command}: command not found
	  if (!cmds.count(userCmd)) {
		  std::cerr << userCmd << ": command not found\n";
		  continue;
	  }

	  cmds[userCmd]();
  }

}
