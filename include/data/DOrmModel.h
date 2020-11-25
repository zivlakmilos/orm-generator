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

#ifndef _ORM_DORM_MODEL_H_
#define _ORM_DORM_MODEL_H_

#include <memory>
#include <vector>
#include <functional>
#include <ostream>

#include "StringMap.h"
#include "data/DOrmField.h"

namespace orm
{

class DOrmModel
{
public:
    DOrmModel(void);
    ~DOrmModel(void);

    inline std::string getName(void) const { return m_name; }
    inline std::string getTableName(void) const { return m_tableName; }

    inline void setName(const std::string &name) { m_name =  name; }
    inline void setColumnName(const std::string &tableName) { m_tableName = tableName; }

    void addField(const std::shared_ptr<DOrmField> &field);

    void fieldsIterate(const std::function<void(std::shared_ptr<DOrmField>)> &callback);

    friend std::ostream &operator<<(std::ostream &os, const DOrmModel &ormModel);

private:
    std::string m_name;
    std::string m_tableName;
    std::vector<std::shared_ptr<DOrmField>> m_fields;
};

std::ostream &operator<<(std::ostream &os, const DOrmModel &ormModel);

};

#endif // _ORM_DORM_MODEL_H_
