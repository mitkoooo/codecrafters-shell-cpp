#pragma once

#include <string>
#include <utility>
#include <vector>

using ParsedInput =
	std::pair<std::string, std::vector<std::string>>;

ParsedInput parseInput(const std::string& line);
