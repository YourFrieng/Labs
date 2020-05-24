#include "Header.h"

Freeze::Freeze()
{

    temperature = 10;
    minTemp = -10;
    isOn = false;
    isOpen = false;
    isCharged = false;
    SerialNumber = "Heh Corporation Serial Number";
}

void Freeze::makeIce()
{
    std::cout << "Your Ice, sir" << std::endl;
}




void Cooling_chamber::makeCold()
{

    //TODO make asynchronous programming
    /*
    while (true)
    {

        fout << "Temperature: " << temperature << std::endl;
        if (temperature > minTemp)
            temperature -= 1;
        else {
            temperature += 3;
        }
        if (doTh == false) {
            break;
        }
    }
    */
    std::cout << "Temperature: " << temperature << std::endl;

}

Cooling_chamber::Cooling_chamber()
{

    temperature = 10;
    minTemp = 3;
    isOn = false;
    isOpen = false;
    isCharged = false;
    SerialNumber = "Heh Corporation Serial Number";
}







std::string Cooling_chamber::getSerial()
{
    return SerialNumber;
}

void Cooling_chamber::cool()
{
    //func = std::thread(&Cooling_chamber::makeCold, this);
    makeCold();
}

void Cooling_chamber::turnOn()
{
    if (isCharged != 0) {
        std::cout << "Starting system" << std::endl;
        this->isOn = true;
        this->cool();
    }
}

void Cooling_chamber::turnOff()
{
    std::cout << "Shutdowning system" << std::endl;
    //func.detach();
    this->isOn = false;
}

void Cooling_chamber::charge()
{
    this->isCharged = true;
}

void Cooling_chamber::disableCharge()
{
    if (this->isOn == false)
        this->isCharged = false;
    else {
        int answ;
        std::cout << "Your fridge is turn On, are you sure for disable charge?\n 1-Yes; 2-No" << std::endl;
        std::cin >> answ;
        if (answ == 1)
        {
            //func.detach();
            this->isCharged = false;
        }
        else
            std::cout << "\nThanks for saving your system" << std::endl;
    }
}

void Cooling_chamber::Open()
{
    std::cout << "Freeze is open" << std::endl;
    this->isOpen = true;
}

void Cooling_chamber::Close()
{
    std::cout << "Freeze is close" << std::endl;
    this->isOpen = false;
}

void Human::open(Cooling_chamber& A)
{
    A.Open();
}

void Human::close(Cooling_chamber& A)
{
    A.Close();
}

void Human::insertPlug(Cooling_chamber& A)
{
    A.charge();
}

void Human::stretchOutPlug(Cooling_chamber& A)
{
    A.disableCharge();
}

void Human::pushOnButton(Cooling_chamber& A)
{
    static int i = 0;
    ++i;
    if (i % 2 == 0) {
        A.turnOff();
    }
    else {
        A.turnOn();
    }
}

void Human::makeJuice(Dispanser* A)
{
    double volume;
    std::cout << "Please indicate volume of your dishes (in liters)" << std::endl;
    std::cin >> volume;
    A->pourJuice(volume);
}

void Human::addJuice(Dispanser* A)
{
    A->plusJuice();
}

void Human::readSerialNum(Cooling_chamber& A)
{
    std::cout << "Serial number, I don`t know why you need this, but it`s isn`t my problem: " << A.getSerial() << std::endl;
}

Dispanser::Dispanser()
{
    juiceLeft = 0;
}

void Dispanser::pourJuice(double volume)
{
    if (this->juiceLeft < volume) {
        std::cout << "Now you have: " << juiceLeft << " l of juice" << std::endl;
        std::cout << "Please replenish juice" << std::endl;
    }
    else {
        std::cout << "Your juice, sir" << std::endl;
        juiceLeft -= volume;
        std::cout << "Now you have: " << juiceLeft << " l of juice" << std::endl;
    }
}

void Dispanser::plusJuice()
{
    int Add;
    std::cout << "Please add juice to container" << std::endl;
    std::cin >> Add;
    this->juiceLeft += Add;
    std::cout << "Now you have: " << juiceLeft << " l of juice" << std::endl;
}

Fridge::Fridge()
{
    temperature = 10;
    minTemp = 3;
    isOn = false;
    isOpen = false;
    isCharged = false;
    SerialNumber = "Heh Corporation Serial Number";
    fridge_disp = new Dispanser;
}

Fridge::~Fridge() {
    delete fridge_disp;
}

void Fridge::turnLamp()
{

    if (isOpen != 0) {
        isLampOn = true;
        std::cout << "Lamp is turn on now. Yes we have light in the fridge" << std::endl;
    }
    else {
        isLampOn = false;
        std::cout << "Lamp is turn off now. Now, you aren`t see anything" << std::endl;
    }
}

void Fridge::Open()
{
    isOpen = true;
    std::cout << "Fridge is open" << std::endl;
    turnLamp();
}

void Fridge::Close()
{
    isOpen = false;
    std::cout << "Fridge is close" << std::endl;
    turnLamp();
}
