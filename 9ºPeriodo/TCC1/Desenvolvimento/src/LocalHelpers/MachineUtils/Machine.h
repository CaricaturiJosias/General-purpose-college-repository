/**
 * @file MachineUtils.h
 * @author Gabriel Cezario (gabriel.argacezario@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

class Machine {
    
    double memory;

    std::string virtualTablePath;

    public: 

        double GetMemory() { return memory; }

        std::string GetVirtualTablePath() { return virtualTablePath; }
};