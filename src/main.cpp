#include "commands.hpp"
#include "path_utils.hpp"
#include "process_utils.hpp"
#include "parser.hpp"

#include <iostream>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
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

	  std::optional<std::string> exec = getExecutable(cmd);
    std::vector<char*> argv = makeArgv(cmd, args);

	  if (!exec) {
      std::cerr << cmd << ": command not found\n";
      continue;
    }

	  pid_t pid = fork();

    if (pid == -1) {
      std::cerr << "fork failed: " << std::strerror(errno) << '\n';
    }

    if (pid == 0) {
      // Child process
      execv(exec->c_str(), argv.data());

      // Only reached if execvp fails
      std::cerr << "execvp failed: " << std::strerror(errno) << '\n';
      _exit(127);
    }
	
    // Parent process
    int status;
    waitpid(pid, &status, 0);
  }
}
