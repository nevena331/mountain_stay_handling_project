#include "Hut.h"
#include "Room.h"
#include <iostream>
#include <iomanip>

Hut::Hut(const std::string& name, double lat, double lon, int alt,
         bool dining, bool electricity, bool water)
    : SleepingPlace(name, lat, lon, alt),
      hasDiningHall(dining),
      hasElectricity(electricity),
      hasWater(water) {}

Hut::~Hut() {}

void Hut::addRoom(std::shared_ptr<Room> room) {
    if (room) {
        rooms.push_back(room);
    }
}

int Hut::getRoomCount() const {
    return rooms.size();
}

std::shared_ptr<Room> Hut::getRoom(int index) const {
    if (index >= 0 && index < static_cast<int>(rooms.size())) {
        return rooms[index];
    }
    return nullptr;
}

bool Hut::getDiningHall() const {
    return hasDiningHall;
}

bool Hut::getElectricity() const {
    return hasElectricity;
}

bool Hut::getWater() const {
    return hasWater;
}

void Hut::setDiningHall(bool hasDining) {
    hasDiningHall = hasDining;
}

void Hut::setElectricity(bool hasElec) {
    hasElectricity = hasElec;
}

void Hut::setWater(bool hasWtr) {
    hasWater = hasWtr;
}

std::string Hut::getDescription() const {
    return "Hut with amenities and " + std::to_string(rooms.size()) + " rooms";
}

std::string Hut::getAmenities() const {
    std::string amenities = "";
    amenities += (hasDiningHall ? "✓ Dining hall" : "✗ Dining hall");
    amenities += " | ";
    amenities += (hasElectricity ? "✓ Electricity" : "✗ Electricity");
    amenities += " | ";
    amenities += (hasWater ? "✓ Water" : "✗ Water");
    return amenities;
}

void Hut::printInfo() const {
    std::cout << "\n╔══════════════════════════════════════════════════╗\n";
    std::cout << "║           HUT: " << std::left << std::setw(31) << name << "║\n";
    std::cout << "╟──────────────────────────────────────────────────╢\n";
    std::cout << "║ Location: " << std::fixed << std::setprecision(4)
              << latitude << "°, " << longitude << "° | Altitude: "
              << altitude << " m\n";
    std::cout << "║ Amenities: " << getAmenities() << "\n";
    std::cout << "║ Rooms: " << rooms.size() << "\n";
    
    if (!rooms.empty()) {
        std::cout << "╟──────────────────────────────────────────────────╢\n";
        std::cout << "║ ROOMS:\n";
        for (size_t i = 0; i < rooms.size(); ++i) {
            if (rooms[i]) {
                std::cout << "║   " << (i + 1) << ". Room - "
                          << rooms[i]->getBedCount() << " beds\n";
            }
        }
    }
    
    std::cout << "╚══════════════════════════════════════════════════╝\n";
}
