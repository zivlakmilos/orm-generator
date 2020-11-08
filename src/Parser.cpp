/* 
 * This file is part of the ORM Generator distribution (https://github.com/zivlakmilos/orm-generator).
 * Copyright (c) 2020 Miloš Zivlak (zi@zivlak.rs).
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Parser.h"

#include <fstream>
#include <nlohmann/json.hpp>

using namespace orm;

using Json = nlohmann::json;

Parser::Parser(void)
{
}

Parser::~Parser(void)
{
}

void Parser::parseFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    nlohmann::json json = nlohmann::json::parse(file);

    if (json.find("config") == json.end())
    {
        // TODO:: Config missing error
    }

    auto config = json["config"];
    parseConfig(config);
}

void Parser::parseConfig(const nlohmann::json &json)
{
    m_config = std::make_shared<DConfig>();

    if (json.find("database") != json.end())
    {
        m_config->databaseFromString(json["database"]);
    }

    if (json.find("framework") != json.end())
    {
        m_config->frameworkFromString(json["framework"]);
    }

    if (json.find("style") != json.end())
    {
        m_config->styleFromString(json["style"]);
    }
}
