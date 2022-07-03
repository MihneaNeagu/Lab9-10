#pragma once
#include "Service.h"

class UI{
private:
    Service serv;
    void adaugaProdus();
    void showAll();
    void stergeProdus();
    void modificaProdus();
    void afisareSumaDupaNume();

    void cumparaProdus();

public:
    UI();
    UI(Service&);
    void showMenu();
    ~UI();
};
