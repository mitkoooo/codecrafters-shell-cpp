#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using CommandArgs = std::vector<std::string>;

using Command = 
	std::function<void(const std::vector<std::string>&)>;

using CommandMap =
	std::unordered_map<std::string, Command>;

void registerCommands(CommandMap& cmds);

void cdCommand(const CommandArgs& args);
void echoCommand(const CommandArgs& args);
void exitCommand(const CommandArgs& args);
void pwdCommand(const CommandArgs& args);
void typeCommand(const CommandArgs& args, const CommandMap& cmds);

