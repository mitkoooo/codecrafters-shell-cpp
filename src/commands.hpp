#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using Command = 
	std::function<void(const std::vector<std::string>&)>;

using CommandMap =
	std::unordered_map<std::string, Command>;

void registerCommands(CommandMap& cmds);
