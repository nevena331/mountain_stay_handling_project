#include "Room.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Room::Room(int beds, double price, bool bathroom, const std::string& number)
    : bedCount(beds), pricePerBed(price), hasOwnBathroom(bathroom), roomNumber(number) {}

Room::~Room() {}

int Room::getBedCount() const {
    return bedCount;
}

double Room::getPricePerBed() const {
    return pricePerBed;
}

bool Room::hasPrivateBathroom() const {
    return hasOwnBathroom;
}

std::string Room::getRoomNumber() const {
    return roomNumber;
}

void Room::setBedCount(int beds) {
    if (beds > 0) {
        bedCount = beds;
    }
}

void Room::setPricePerBed(double price) {
    if (price >= 0) {
        pricePerBed = price;
    }
}

void Room::setPrivateBathroom(bool hasPrivate) {
    hasOwnBathroom = hasPrivate;
}

void Room::setRoomNumber(const std::string& number) {
    roomNumber = number;
}

double Room::getTotalPrice() const {
    return bedCount * pricePerBed;
}

std::string Room::getDescription() const {
    std::ostringstream oss;
    oss << bedCount << " beds, " << std::fixed << std::setprecision(2)
        << pricePerBed << " BGN/bed";
    if (hasOwnBathroom) {
        oss << ", with private WC";
    }
    return oss.str();
}

void Room::printInfo() const {
    std::cout << "\n  ┌─ ROOM " << roomNumber << " ─┐\n";
    std::cout << "  │ Beds: " << bedCount << "\n";
    std::cout << "  │ Price per bed: " << std::fixed << std::setprecision(2)
              << pricePerBed << " BGN\n";
    std::cout << "  │ Total price: " << std::fixed << std::setprecision(2)
              << getTotalPrice() << " BGN\n";
    std::cout << "  │ WC: " << (hasOwnBathroom ? "✓ Private" : "✗ Shared")
              << "\n";
    std::cout << "  └─────────────────────┘\n";
}
