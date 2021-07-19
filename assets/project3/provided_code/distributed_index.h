#pragma once
#include <string>
#include <iostream>

typedef unsigned int UUID;

struct DistributedIndex {
    UUID Key;
    std::string ServerIP;
    unsigned int DiskSector;

    bool operator== (const DistributedIndex& other) const {
        return this->Key == other.Key;
    }

    bool operator< (const DistributedIndex& other) const {
        return this->Key < other.Key;
    }

    bool operator> (const DistributedIndex& other) const {
        return this->Key > other.Key;
    }

    operator UUID() const { return Key; }

    friend std::ostream& operator<<(std::ostream& out, const DistributedIndex& index);

    friend bool operator< (const UUID& uuid, const DistributedIndex& index);
    friend bool operator< (const DistributedIndex& index, const UUID& uuid);

    friend bool operator> (const UUID& uuid, const DistributedIndex& index);
    friend bool operator> (const DistributedIndex& index, const UUID& uuid);

    friend bool operator<= (const UUID& uuid, const DistributedIndex& index);
    friend bool operator<= (const DistributedIndex& index, const UUID& uuid);

    friend bool operator>= (const UUID& uuid, const DistributedIndex& index);
    friend bool operator>= (const DistributedIndex& index, const UUID& uuid);

    friend bool operator== (const UUID& uuid, const DistributedIndex& index);
    friend bool operator== (const DistributedIndex& index, const UUID& uuid);
};

std::ostream& operator<<(std::ostream& out, const DistributedIndex& index)
{
    return out << "{ Key: 0x" << std::hex << std::uppercase << index.Key  << std::dec
               << ", IP: " << index.ServerIP
               << ", Disk Sector: " << index.DiskSector << " }";
}

bool operator< (const UUID& uuid, const DistributedIndex& index) {
    return uuid < index.Key;
}

bool operator< (const DistributedIndex& index, const UUID& uuid) {
    return index.Key < uuid;
}

bool operator> (const UUID& uuid, const DistributedIndex& index) {
    return uuid > index.Key;
}

bool operator> (const DistributedIndex& index, const UUID& uuid) {
    return index.Key > uuid;
}


bool operator<= (const UUID& uuid, const DistributedIndex& index) {
    return uuid <= index.Key;
}

bool operator<= (const DistributedIndex& index, const UUID& uuid) {
    return index.Key <= uuid;
}

bool operator>= (const UUID& uuid, const DistributedIndex& index) {
    return uuid >= index.Key;
}

bool operator>= (const DistributedIndex& index, const UUID& uuid) {
    return index.Key >= uuid;
}

bool operator== (const UUID& uuid, const DistributedIndex& index) {
    return uuid == index.Key;
}

bool operator== (const DistributedIndex& index, const UUID& uuid) {
    return index.Key == uuid;
}