#include "process_utils.hpp"
#include "path_utils.hpp"

#include <iostream>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

std::vector<char*> makeArgv(
    std::string& command,
    std::vector<std::string> &args
  ) {
  std::vector<char*> argv;
  argv.reserve(args.size() + 2);

  argv.push_back(command.data());

  for (std::string& arg : args) {
    argv.push_back(arg.data());
  }
  
  argv.push_back(nullptr);

  return argv;
}

void executeExternalCommand(std::string &command, std::vector<std::string> &args) {
	  std::optional<std::string> exec = getExecutable(command);
    std::vector<char*> argv = makeArgv(command, args);

	  if (!exec) {
      std::cerr << command << ": command not found\n";
      return;
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
