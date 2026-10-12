#pragma once

#include <string>
#include <abyssparse.hpp>
#include <abyssutils/math/Vector2D.hpp>

std::string absolutePath(const std::string&, const std::string&);
int64_t     configStringToInt(const std::string& VALUE);
int         createPoolFile(size_t size, std::string& name);
std::string spawnSync(const std::string& cmd);
void        spawnAsync(const std::string& cmd);
std::string getUsernameForCurrentUid();
