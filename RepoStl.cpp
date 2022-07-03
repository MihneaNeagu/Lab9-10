#include "RepoStl.h"
using namespace std;

Repository::Repository() {
}


void Repository::add(Produs & p) {
    this->elements.push_back(p);
}


int Repository::size() {
    return elements.size();
}

Repository::~Repository() {
}


void Repository::dell(Produs & p) {
    for(int i = 0; i<elements.size();i++)
        if (p==elements[i]){
            elements[i] = elements[elements.size()-1];
            elements.pop_back();}
}

vector<Produs> Repository::findAll() {
    return elements;
}

void Repository::update(Produs & vechi, Produs & nou) {
    /*for (Produs crt:elements)
        if (crt == vechi){
            crt = nou;
        }*/
    for(int i = 0; i<this->elements.size(); i++)
        if(this->elements[i] == vechi)
        {
            this->elements[i] = nou;
            i = this->elements.size()+1;
        }
}

Produs Repository::getItemPoz(int poz) {
    return elements[poz];
}

void Repository::delPoz(int poz) {
    elements.erase(elements.begin()+poz);
}

//Produs Repository::getItemCod(int cod) {
//    for(int i = 0; i<this->elements.size(); i++)
//        if(this->elements[i].getCod() == cod)
//            return elements[i];
//}

void Repository::set_on_pos(int pos, Produs& new_entity) {
    this->elements[pos] = new_entity;
}



