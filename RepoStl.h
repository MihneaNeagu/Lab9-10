#pragma once
#include <vector>
#include "Produs.h"
using namespace std;

class Repository{
protected:
    vector<Produs> elements;
    char* fname;
public:
    Repository();
    void add(Produs&);
    void dell(Produs&);
    void delPoz(int poz);
    void set_on_pos(int pos, Produs& new_entity);
//    Produs getItemCod(int cod);
    Produs getItemPoz(int poz);
    void update(Produs&, Produs&);
    int size();
    vector<Produs> findAll();
    ~Repository();
};

