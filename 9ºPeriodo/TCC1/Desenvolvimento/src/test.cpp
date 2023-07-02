/**
 * @file test.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-27
 *
 * @copyright Copyright (c) 2023
 *
 */

// This is to test anything lmao

#include "../3pp/pugixml-1.13/src/pugixml.hpp"
#include <iostream>

using namespace pugi;

int main()
{
    xml_document doc;

    xml_parse_result result = doc.load_file("xmltest.xml");

    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;
}