#include "commands.hpp"

void registerCommands(CommandMap &cmds) {
  cmds["exit"] = exitCommand; 
  cmds["echo"] = echoCommand;
  cmds["type"] = [&cmds](const CommandArgs& args) {
    typeCommand(args, cmds);
  };

  cmds["pwd"] = pwdCommand;
  cmds["cd"] = cdCommand;
}
