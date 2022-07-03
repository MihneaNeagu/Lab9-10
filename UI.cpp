#include <iostream>
#include "UI.h"
using namespace std;

UI::UI() = default;

UI::~UI() = default;

void UI::showMenu() {
    try {
        int sum = 0;
        while (true) {
            cout << "1.Tonomat: " << endl;
            cout << "2.Client: " << endl;
            cout << "x.Exit: " << endl;
            cout << "Dati optiunea: " << endl;
            string opt;
            cin >> opt;
            if (opt == "1")
                while (true) {
                    cout << "1.Adaugare produs" << endl;
                    cout << "2.Stergere produs" << endl;
                    cout << "3.Modificare produs" << endl;
                    cout << "a.Afisare produse din tonomat" << endl;
                    cout << "x.Iesire " << endl;
                    cout << "Dati optiunea: " << endl;
                    cin >> opt;
                    if (opt == "1")
                        adaugaProdus();
                    else if (opt == "2")
                        stergeProdus();
                    else if (opt == "3")
                        modificaProdus();
                    else if (opt == "a")
                        showAll();
                    else if (opt == "x")
                        break;
                    else cout << "Optiune gresita! Reincercati! " << endl;
                }
            else if (opt == "2")
                while (true) {
                    cout << "1.Cumpara produse din tonomat" << endl;
                    cout << "a.Afisare produse din tonomat" << endl;
                    cout << "x.Iesire " << endl;
                    cout << "Dati optiunea: " << endl;
                    cin >> opt;
                    if (opt == "1")
                        cumparaProdus();
                    else if (opt == "a")
                        showAll();
                    else if (opt == "x")
                        break;
                }
            else if (opt == "x")
                break;
            else cout << "Optiunea e gresita! Reinceracti! " << endl;
        }
    }
    catch (...){
        cout << endl << "Eroare!" << endl;
    }
}

void UI::adaugaProdus() {
    try{
        cout << "Dati cod: " << endl;
        int cod;
        cin >> cod;
        cout << "Dati nume: " << endl;
        char* nume = new char[10];
        cin >> nume;
        cout << "Dati pret: " << endl;
        int pret;
        cin >> pret;
        serv.add(cod, nume, pret);
        delete [] nume;
        }
    catch (DublicateCodeError& dce){
        cout << endl << "Code Error: " << dce.what();
    }
    catch (ProdusValidationError& pve){
        cout << endl << "Eroare de validare: " << pve.what();
    }
    catch (...){
        cout << endl << "Eroare! ";
    }
    cout << endl;
}

void UI::showAll() {
    vector<Produs> elem;
    elem = this->serv.getAll();
    for (auto & i : elem)
        cout << i << endl;}

void UI::stergeProdus() {
    try {
        cout << "Dati cod: " << endl;
        int cod;
        cin >> cod;
        cout << "Dati nume: " << endl;
        char *nume = new char[10];
        cin >> nume;
        cout << "Dati pret: " << endl;
        int pret;
        cin >> pret;
        serv.dell(cod, nume, pret);
        delete[] nume;
    }
    catch (NonExistentCodeError& nece){
        cout << endl << "CodeError: " << nece.what();
    }
    catch (...){
        cout << endl << "Eroare! ";
    }
    cout << endl;

}

void UI::modificaProdus() {
    try{
        cout << "Dati cod de modificat: " << endl;
        int codV;
        cin >> codV;
        cout << "Dati nume de modificat: " << endl;
        char* numeV = new char[10];
        cin >> numeV;
        cout << "Dati pret de modificat: " << endl;
        int pretV;
        cin >> pretV;

        cout << "Dati cod nou: " << endl;
        int codN;
        cin >> codN;
        cout << "Dati nume nou: " << endl;
        char* numeN = new char[10];
        cin >> numeN;
        cout << "Dati pret nou: " << endl;
        int pretN;
        cin >> pretN;

        serv.update(codV, numeV, pretV, codN, numeN, pretN);
        delete [] numeV;
        delete [] numeN;
    }

    catch (DublicateCodeError& dce){
        cout << endl << "Code Error: " << dce.what();
    }
    catch (NonExistentCodeError& nece){
        cout << endl << "CodeError: " << nece.what();
    }
    catch (ProdusValidationError& pve){
        cout << endl << "Eroare de validare: " << pve.what();
    }
    catch (...){
        cout << endl << "Eroare! ";
    }
    cout << endl;
}

UI::UI(Service & s) {
    this->serv = s;
}

void UI::afisareSumaDupaNume() {
    cout << "Dati numele pentru care va fi facuta suma: " << endl;
    char* nume = new char[10];
    cin >> nume;
    cout << "Suma produselor cu numele "<< nume << " este: " << serv.getSumaProduseNume(serv.getAll(), nume) << endl;
    delete [] nume;
}


void UI::cumparaProdus() {
    try {
        int s = 0;
        int contorMoneda;
        cout << "Introduceti monezi! " << endl;
        cout << "Cate monezi de 1 ban: " << endl;
        cin >> contorMoneda;
        s = s + contorMoneda * 1;
        this->serv.setMoneda(0, this->serv.getMoneda(0));

        cout << "Cate monezi de 5 bani: " << endl;
        cin >> contorMoneda;
        s = s + contorMoneda * 5;
        this->serv.setMoneda(1, this->serv.getMoneda(1));

        cout << "Cate monezi de 10 bani: " << endl;
        cin >> contorMoneda;
        s = s + contorMoneda * 10;
        this->serv.setMoneda(2, this->serv.getMoneda(2));

        cout << "Cate monezi de 50 bani: " << endl;
        cin >> contorMoneda;
        s = s + contorMoneda * 50;
        this->serv.setMoneda(3, this->serv.getMoneda(3));

        cout << "Cate monezi de 100 bani: " << endl;
        cin >> contorMoneda;
        s = s + contorMoneda * 100;
        this->serv.setMoneda(4, this->serv.getMoneda(4));

        cout << "Dati codul produsului pe care doriti sa il achizitionati: " << endl;
        int codProdus;
        cin >> codProdus;
        Produs p1 = this->serv.getItemCod(codProdus);

        vector<Produs> produse = this->serv.getAll();

        vector<int> result = this->serv.give_change(s, p1.getPret());
        if (result.empty())
            cout << "Produsul a fost achizitionat! Restul este 0 : " << endl;
        else if (result[0] == -1)
            cout << "Credit insuficient! " << endl;
        else {
            int rest = 0;
            cout << "Restul este: ";
            for (int i = 0; i < result.size(); i++)
                if (i == result.size() - 1) {
                    cout << result[i];
                    rest = rest + result[i];
                } else {
                    rest = rest + result[i];
                    cout << result[i] << "+";
                }
            cout << " lei = " << rest << endl;
        }
    }
    catch (...){
        cout << endl << "Eroare!" << endl;
    }
}

