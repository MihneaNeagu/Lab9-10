#pragma once
#include "RepoStl.h"
#include "RepositoryFile.h"
#include "ProdusValidator.h"

class Service{
private:
    RepositoryFile repo;
    ProdusValidator validator;
public:
    Service();
    Service(RepositoryFile&, ProdusValidator pv);
    Service(const Service & s);
    void add(int, const string&, int);
    void dell(int, const string&, int);
    void update(int, const string&, int,int, const string&, int);
    bool codExists(int cod);
    vector<Produs> getAll();
    int getMoneda(int poz);
    void setMoneda(int poz, int value);
    Produs getItemCod(int cod);
    vector<Produs> get_products_cheaper_than(int sum);
    vector<int> give_change(int sum, int price);
    vector<int> get_coins_from_service();
    int getSumaProduseNume(vector<Produs> ,const string&);
    int getNoOfProduse();
    ~Service();
};

