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

#ifndef _ORM_DORM_FIELD_H_
#define _ORM_DORM_FIELD_H_

#include <memory>
#include <ostream>

#include "StringMap.h"

namespace orm
{

class DOrmField
{
public:
    DOrmField(void);
    ~DOrmField(void);

    enum Type
    {
        TInt,
        TDouble,
        TString,
        TList,
        TCustom,
    };

    inline std::string getName(void) const { return m_name; }
    inline std::string getColumnName(void) const { return m_ColumnName; }

    inline void setName(const std::string &name) { return m_name; }
    inline void setColumnName(const std::string &columnName) { return m_ColumnName; }

    std::string typeToString(void) const;

    void typeFromString(const std::string &type);

    friend std::ostream &operator<<(std::ostream &os, const DOrmField &ormField);

private:
    static const StringMap<Type> TypeMap;

    void parseListTypeFromString(const std::string &type);
    void parseSimpleTypeFromString(const std::string &type);
    Type convertSimpleTypeFromString(const std::string &type);

    Type m_type;
    Type m_listType;
    std::string m_customType;

    std::string m_name;
    std::string m_columnName;
};

std::ostream &operator<<(std::ostream &os, const DOrmField &ormField);

};

#endif // _ORM_DORM_FIELD_H_
