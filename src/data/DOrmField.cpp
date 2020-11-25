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

#include "data/DOrmField.h"

#include <regex>

using namespace orm;

const StringMap<DOrmField::Type> DOrmField::TypeMap = {
    { TInt,                 "int" },
    { TDouble,              "double" },
    { TString,              "string" },
    { TList,                "(List<).+?(>)" },          // RegEx to match List<Type> where Type is typename
    { TCustom,              "Custom" },
};

DOrmField::DOrmField(void)
{
}

DOrmField::~DOrmField(void)
{
}

std::string DOrmField::typeToString(void) const
{
    std::string result;

    bool isList = m_type == TList;
    Type type;

    if (isList)
    {
        result += "List<";
        type = m_listType;
    }
    else
    {
        type = m_type;
    }

    bool isCustomType = type == TCustom;
    if (isCustomType)
    {
        result += m_customType;
    }
    else
    {
        result += TypeMap.string(type);
    }

    if (isList)
    {
        result += ">";
    }

    return result;
}

void DOrmField::typeFromString(const std::string &type)
{
    bool isList = std::regex_match(type, std::regex(TypeMap.string(TList)));
    if (isList)
    {
        parseListTypeFromString(type);
    }
    else
    {
        parseSimpleTypeFromString(type);
    }
}

void DOrmField::parseListTypeFromString(const std::string &type)
{
    std::size_t tagContentPos = type.find("<") + 1;
    std::size_t tagContentSize = type.find(">") - tagContentPos;

    m_type = TList;
    std::string listType = type.substr(tagContentPos, tagContentSize);

    Type simpleType = convertSimpleTypeFromString(listType);
    if (simpleType == TCustom)
    {
        m_customType = listType;
    }
}

void DOrmField::parseSimpleTypeFromString(const std::string &type)
{
    Type simpleType = convertSimpleTypeFromString(type);
    if (simpleType == TCustom)
    {
        m_customType = type;
    }
}

DOrmField::Type DOrmField::convertSimpleTypeFromString(const std::string &type)
{
    bool isStandardType = TypeMap.findString(type);
    if (isStandardType)
    {
        return TypeMap.value(type);
    }
    else
    {
        return TCustom;
    }
}
