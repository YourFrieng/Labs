#pragma once
#include <iostream>
#include<thread>
class Cooling_chamber
{
protected:
    //std::thread func;
    int temperature;
    int minTemp;
    bool isOn;
    bool isOpen;
    bool isCharged;
    std::string SerialNumber;
    void makeCold();
    void cool();

public:
    Cooling_chamber();
    std::string getSerial();
    void turnOn();
    void turnOff();
    void charge();
    void disableCharge();
    virtual void Open();
    virtual void Close();

};

class Dispanser {
    double juiceLeft;
public:
    Dispanser();
    void pourJuice(double);
    void plusJuice();

};

class Human {
public:
    void open(Cooling_chamber&);
    void close(Cooling_chamber&);
    void insertPlug(Cooling_chamber&);
    void stretchOutPlug(Cooling_chamber&);
    void pushOnButton(Cooling_chamber&);
    void makeJuice(Dispanser*);
    void addJuice(Dispanser*);
    void readSerialNum(Cooling_chamber&);
};

class Fridge : public Cooling_chamber
{
    bool isLampOn;
public:
    Fridge();
    ~Fridge();
    Dispanser* fridge_disp;
    void turnLamp();
    void Open();
    void Close();
};

class Freeze : public Cooling_chamber
{

public:
    Freeze();
    void makeIce();

};
