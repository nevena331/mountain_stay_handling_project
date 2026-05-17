#pragma once
#include "SleepingPlace.h"
#include "Room.h"
#include <vector>
#include <memory>


class Hut : public SleepingPlace {
private:
    std::vector<std::shared_ptr<Room>> rooms;
    bool hasDiningHall;
    bool hasElectricity;
    bool hasWater;

public:

    Hut(const std::string& name, double lat, double lon, int alt,
        bool dining = true, bool electricity = true, bool water = true);

    virtual ~Hut();

    Hut(const Hut&) = delete;
    Hut& operator=(const Hut&) = delete;

    Hut(Hut&&) noexcept = default;
    Hut& operator=(Hut&&) noexcept = default;

    void addRoom(std::shared_ptr<Room> room);

    int getRoomCount() const;

    std::shared_ptr<Room> getRoom(int index) const;

    bool getDiningHall() const;
    bool getElectricity() const;
    bool getWater() const;

    void setDiningHall(bool hasDining);
    void setElectricity(bool hasElec);
    void setWater(bool hasWtr);

    std::string getDescription() const override;

    void printInfo() const override;

    std::string getAmenities() const;
};

