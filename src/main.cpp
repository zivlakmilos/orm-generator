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

#include <iostream>

#include "Parser.h"
#include "data/DOrmField.h"

int main(int argc, char *argv[])
{
    orm::Parser parser;
    parser.parseFile("example.json");
    auto config = parser.getConfig();
    std::cout << *config << std::endl;

    orm::DOrmField field;
    field.typeFromString("List<int>");

    return 0;
}
