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

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <Vector>

#include "../../MessageProcessing/Actors/Sender.h"
#include "../../DataModels/Information/Information.h"
#include "../../DataModels/MsgInfo/MsgInfo.h"
#include "../VirtualTable/VirtualTable.h"

enum EventType {
    Something // TODO
};

class MachineUtils { //  Acts like an interface

    public:
    
        bool CheckPermission(std::string command, Sender sender);

        Information DecompressInfo(void * encryptedInfo);

        void * DecryptInfo(void * encryptedInfo);

        void * EncryptCompressedData(void * compressetInfo);

        void * CompressData(MsgInfo data);

        uint16_t GetRecordsAmmount();

        bool DataLookUp(MsgInfo data);

        bool hasSpace(void * encryptedData);

        void LogEvent(std::string msg, EventType eventType);

        bool SaveData(void * data);

        bool SaveData(MsgInfo data);

        void UpdateTable(void * data, uint16_t dataOwner);

        VirtualTable GetVirtualTable();

        std::vector<Information> GetDataInArray(MsgInfo dataInfo);

};
