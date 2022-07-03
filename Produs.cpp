#include <cstring>
#include "Produs.h"

Produs::Produs() {
    this->cod = 0;
    this->nume = "";
    this->pret = 0;
}

Produs::Produs(int c, string n, int p) {
    this->cod = c;
    this->nume = std::move(n);
    this->pret = p;
}

Produs::Produs(const Produs & p) {
    this->cod = p.cod;
    this->nume = p.nume;
    this->pret = p.pret;
}

int Produs::getCod() {
    return this->cod;
}

string Produs::getNume() {
    return this->nume;
}

int Produs::getPret() {
    return this->pret;
}

void Produs::setCod(int c) {
    this->cod = c;
}

void Produs::setNume(string n) {
    this->nume = n;
}

void Produs::setPret(int p) {
    this->pret = p;
}

Produs &Produs::operator=(const Produs & p) {
    this->cod = p.cod;
    this->nume = p.nume;
    this->pret = p.pret;
    return *this;
}

Produs::~Produs() {
    this->cod = 0;
    this->nume = "s";
    this->pret = 0;
}

bool Produs::operator==(const Produs& c) {
    return (this->cod == c.cod) and (this->nume == c.nume) and (this->pret == c.pret);
}

istream &operator>>(istream &is, Produs &p) {
    is >> p.cod >> p.nume >> p.pret;
    return is;
}


ostream &operator<<(ostream &os, Produs &p) {
    os << p.cod << " " << p.nume << " " << p.pret << endl;
    return os;
 }







