#pragma once
#include <iostream>
#include <string>
using namespace std;

class Produs{
protected:
    int cod;
    string nume;
    int pret;
public: Produs();
    Produs(int, string , int);
    Produs(const Produs&);
    int getCod();
    string getNume();
    int getPret();
    void setCod(int);
    void setNume(string);
    void setPret(int);
    Produs& operator = (const Produs&);
    bool operator == (const Produs&);

    friend ostream& operator << (ostream & os, Produs & p);
    friend istream& operator >> (istream& is, Produs& p);
    ~Produs();

};

