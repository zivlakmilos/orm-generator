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

#ifndef _ORM_PARSER_H_
#define _ORM_PARSER_H_

#include <string>
#include <memory>
#include <nlohmann/json.hpp>

#include "data/DConfig.h"

namespace orm
{

class Parser
{
public:
    Parser(void);
    ~Parser(void);

    void parseFile(const std::string &filePath);

    inline std::shared_ptr<DConfig> getConfig(void) { return m_config; };

private:
    void parseConfig(const nlohmann::json &json);

    std::shared_ptr<DConfig> m_config;
};

};

#endif // _ORM_PARSER_H_
