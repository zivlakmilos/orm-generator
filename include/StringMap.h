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

#include <string>
#include <unordered_map>
#include <initializer_list>
#include <utility>

#ifndef _ORM_STRING_MAP_H_
#define _ORM_STRING_MAP_H_

namespace orm
{

template <typename T>
class StringMap
{
public:
    StringMap(std::initializer_list<std::pair<T, std::string>> il)
    {
        for (auto it = il.begin(); it != il.end(); it++)
        {
            m_keyStringMap[it->first] = it->second;
            m_stringKeyMap[it->second] = it->first;
        }
    }

    ~StringMap(void) = default;

    inline std::string string(const T &key) const { return m_keyStringMap.at(key); }
    inline T value(const std::string &key) const { return m_stringKeyMap.at(key); }

private:
    std::unordered_map<T, std::string> m_keyStringMap;
    std::unordered_map<std::string, T> m_stringKeyMap;
};

};

#endif // _ORM_STRING_MAP_H_
