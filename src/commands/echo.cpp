#include "commands.hpp"

#include <iostream>

void echoCommand (const CommandArgs& args) {
		int n = args.size();
		for (int i = 0; i < n; i++) {
      std::cout << args[i];
      i == n - 1 ? std::cout << '\n' : std::cout << ' ';
    }
};
