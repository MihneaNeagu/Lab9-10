#include <cstring>
#include<iostream>
#include "Service.h"
using namespace std;
Service::Service() = default;

void Service::add(int cod,const string& nume, int pret) {
    if (!codExists(cod)){
    Produs p(cod, nume, pret);
    ProdusValidator::validate(p);
    repo.add(p);
    }
    else throw DublicateCodeError("Codul este luat! ");
}

void Service::dell(int cod,const string& nume, int pret) {
    if (codExists(cod)){
        Produs p(cod, nume, pret);
        repo.dell(p);
    }
    else throw NonExistentCodeError("Nu exista produs cu acest cod! ");
}

void Service::update(int codVechi,const string& numeVechi, int pretVechi, int codNou,const string& numeNou, int pretNou) {
    if (codExists(codVechi)){
        if (!codExists(codNou)) {
            Produs pVechi(codVechi, numeVechi, pretVechi);
            Produs pNou(codNou, numeNou, pretNou);
            repo.update(pVechi, pNou);
        }
        else throw DublicateCodeError("Noul cod este luat! ");
    }
    else throw NonExistentCodeError("Nu exista acest produs! ");
}

Service::~Service() = default;

int Service::getNoOfProduse() {
    return repo.size();
}

vector<Produs> Service::getAll() {
    return this->repo.findAll();
}

Service::Service(RepositoryFile & rep, ProdusValidator pv) {
    this->repo = rep;
    this->validator = pv;
}

int Service::getSumaProduseNume(vector<Produs> lista, const string& nume) {
    int suma = 0;
    for (auto &i: lista)
        if (i.getNume() == nume)
            suma = suma + i.getPret();
    return suma;
}


Service::Service(const Service & s) {
    repo = s.repo;
}




vector<Produs> Service::get_products_cheaper_than(int sum) {
    vector<Produs> entities = this->repo.findAll();
    vector<Produs> result;
    for (int i = 0; i < this->repo.size(); i++)
        if (entities[i].getPret() <= sum)
            result.push_back(entities[i]);
    return result;
}

vector<int> Service::give_change(int sum, int price) {
    vector<int> result;
    vector<int> aux = this->repo.getMonede();

    int change_to_give = sum - price;
    if (change_to_give == 0)
        return {};
    else if (price > sum){
        result.push_back(-1);
        return result;}
    else {
        while (true) {
            while (aux[4] != 0 && change_to_give >= 100) {
                change_to_give -= 100;
                aux[4]--;
                result.push_back(100);
            }

            while (aux[3] != 0 && change_to_give >= 50) {
                change_to_give -= 50;
                aux[3]--;
                result.push_back(50);
            }

            while (aux[2] != 0 && change_to_give >= 10) {
                change_to_give -= 10;
                aux[2]--;
                result.push_back(10);
            }

            while (aux[1] != 0 && change_to_give >= 5) {
                change_to_give -= 5;
                aux[1]--;
                result.push_back(5);
            }

            while (aux[0] != 0 && change_to_give >= 1) {
                change_to_give -= 1;
                aux[0]--;
                result.push_back(1);
            }
            if (change_to_give != 0){
                return result;
            }
            else
            {
                this->repo.setMonede(0,aux[0]);
                this->repo.setMonede(1,aux[1]);
                this->repo.setMonede(2,aux[2]);
                this->repo.setMonede(3,aux[3]);
                this->repo.setMonede(4,aux[4]);
                return result;
            }
        }
    }
}

vector<int> Service::get_coins_from_service() {
    return this->repo.getMonede();
}

void Service::setMoneda(int poz, int value) {
    this->repo.setMonede(poz, value);
}

int Service::getMoneda(int poz) {
    return this->repo.getMoneda(poz);
}

Produs Service::getItemCod(int cod) {
    return this->repo.getItem(cod);
}

bool Service::codExists(int cod) {
    vector<Produs> entities = repo.findAll();
    for (int i=0; i<repo.size(); i++)
        if (entities[i].getCod() == cod)
            return true;
    return false;
}






