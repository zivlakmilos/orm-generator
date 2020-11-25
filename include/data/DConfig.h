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

#ifndef _ORM_DCONFIG_H_
#define _ORM_DCONFIG_H_

#include <memory>
#include <ostream>

#include "StringMap.h"

namespace orm
{

class DConfig
{
public:
    DConfig(void);
    ~DConfig(void);

    enum Database
    {
        SQLite,
        MySQL,
    };

    enum Framework
    {
        Qt,
    };

    enum Style
    {
        Classic,
        Detailed,
    };

    inline Database getDatabase(void) const { return m_database; };
    inline Framework getFramework(void) const { return m_framework; };
    inline Style getStyle(void) const { return m_style; };

    inline void setDatabase(Database database) { m_database = database; };
    inline void setFramework(Framework framework) { m_framework = framework; };
    inline void setStyle(Style style) { m_style = style; };

    std::string databaseToString(void) const;
    std::string frameworkToString(void) const;
    std::string styleToString(void) const;

    void databaseFromString(const std::string &database);
    void frameworkFromString(const std::string &framework);
    void styleFromString(const std::string &style);

    friend std::ostream &operator<<(std::ostream &os, const DConfig &config);

private:
    static const StringMap<Database> DatabaseMap;
    static const StringMap<Framework> FrameworkMap;
    static const StringMap<Style> StyleMap;

    Database m_database;
    Framework m_framework;
    Style m_style;
};

std::ostream &operator<<(std::ostream &os, const DConfig &config);

};

#endif // _ORM_DCONFIG_H_
