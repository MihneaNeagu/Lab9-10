#include "RepositoryFile.h"
#include "cstring"
#include <iostream>
#include <fstream>
using namespace std;

RepositoryFile::RepositoryFile() {
    coins.push_back(0);
    coins.push_back(0);
    coins.push_back(0);
    coins.push_back(0);
    coins.push_back(0);
    this->filename=nullptr;
}

int RepositoryFile::getMoneda(int poz) {
    return coins[poz];
}

void RepositoryFile::setMonede(int poz, int value) {
    coins[poz] = value;
}

float RepositoryFile::sumMonede() {
    int s = 0;
    for (int i = 0; i< coins.size(); i++)
        s += coins[i];
    return s;
}

vector <int> RepositoryFile::getMonede() {
    return coins;
}

RepositoryFile::RepositoryFile(const char *filename)  {
    coins.push_back(5);
    coins.push_back(5);
    coins.push_back(5);
    coins.push_back(5);
    coins.push_back(5);
    if (filename != NULL) {
        this->filename = new char[strlen(filename) + 1];
        strcpy(this->filename, filename);
    }
    else
        {
        this->filename = nullptr;
        }
    this->loadFromFile();
}

RepositoryFile::~RepositoryFile() {
    if (filename != NULL)
    {
        delete [] filename;
        filename = nullptr;
    }
}

void RepositoryFile::addItem(Produs &p) {
    this->add(p);
    this->saveToFile();
}

RepositoryFile &RepositoryFile::operator=(const RepositoryFile &r) {
    coins = r.coins;
    if (r.filename != NULL)
    {
        this->filename = new char [strlen(r.filename)+1];
        strcpy(this->filename, r.filename);
    }
    elements = r.elements;
    return *this;
}

void RepositoryFile::delItem(int poz) {
    this->delPoz(poz);
    this->saveToFile();
}

void RepositoryFile::loadFromFile() {
    if(this->filename)
    {
        ifstream f(this->filename);
        if (!f.is_open())
            return;
        Produs element;
        while (!f.eof()) {
            f >> element;
            if (f.fail())
                break;
            this->addItem(element);
        }
        f.close();
    }
}

void RepositoryFile::saveToFile() {
    if (this->filename)
    {
        ofstream f(this->filename);
        for (int i = 0; i < this->elements.size();i++)
            f << this->elements[i] << endl;
    }
}

void RepositoryFile::updateItem(int poz, Produs &p) {
    this->set_on_pos(poz,p);
    this->saveToFile();
}

Produs RepositoryFile::getItem(int cod) {
    for(int i = 0; i<this->elements.size(); i++)
        if(this->elements[i].getCod() == cod)
            return elements[i];
}






