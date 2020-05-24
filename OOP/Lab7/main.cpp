#include "Header.h"


int main()
{
    Human human1;
    Fridge fridge1;
    human1.insertPlug(fridge1);
    human1.pushOnButton(fridge1);
    human1.open(fridge1);
    human1.close(fridge1);
    human1.pushOnButton(fridge1);
    human1.pushOnButton(fridge1);
    human1.makeJuice(fridge1.fridge_disp);
    human1.addJuice(fridge1.fridge_disp);
    human1.makeJuice(fridge1.fridge_disp);
    human1.stretchOutPlug(fridge1);
    human1.pushOnButton(fridge1);
    human1.stretchOutPlug(fridge1);
    return 0;
}
