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

#include "data/DConfig.h"

using namespace orm;

const StringMap<DConfig::Database> DConfig::DatabaseMap = {
    { Database::SQLite,     "sqlite" },
    { Database::MySQL,      "mysql" },
};

const StringMap<DConfig::Framework> DConfig::FrameworkMap = {
    { Framework::Qt,        "qt" },
};

const StringMap<DConfig::Style> DConfig::StyleMap = {
    { Style::Classic,       "classic" },
    { Style::Detailed,      "detailed" },
};

DConfig::DConfig(void)
{
}

DConfig::~DConfig(void)
{
}

std::string DConfig::databaseToString(void) const
{
    return DatabaseMap.string(m_database);
}

std::string DConfig::frameworkToString(void) const
{
    return FrameworkMap.string(m_framework);
}

std::string DConfig::styleToString(void) const
{
    return StyleMap.string(m_style);
}

void DConfig::databaseFromString(const std::string &database)
{
    m_database = DatabaseMap.value(database);
}

void DConfig::frameworkFromString(const std::string &framework)
{
    m_framework = FrameworkMap.value(framework);
}

void DConfig::styleFromString(const std::string &style)
{
    m_style = StyleMap.value(style);
}

std::ostream &orm::operator<<(std::ostream &os, const DConfig &config)
{
    os << "{" << std::endl
       << "    Database: " << config.databaseToString() << std::endl
       << "    Framework: " << config.frameworkToString() << std::endl
       << "    Style: " << config.styleToString() << std::endl
       << "}";

    return os;
}
