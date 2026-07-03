#include "process_utils.hpp"

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
