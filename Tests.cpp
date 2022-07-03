#include "Tests.h"
#include "Produs.h"
#include "RepoStl.h"
#include "Service.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;


void setRepoGetSetLab9(){
    Repository repo;
    Produs p5(100, "suc", 20);
    assert(p5.getCod() == 100);
    assert(p5.getNume() == "suc");
    assert(p5.getPret() == 20);

    p5.setCod(300);
    p5.setNume("ciocolata");
    p5.setPret(60);

    assert(p5.getCod() == 300);
    assert(p5.getNume() == "ciocolata");
    assert(p5.getPret() == 60);


    assert(repo.size() == 0);
    Produs p1(100, "corn", 10);
    repo.add(p1);
    assert(repo.size() == 1);

    Produs p2(50, "ciocolata", 20);
    repo.add(p2);
    assert(repo.size() == 2);
}

void testService(){
    RepositoryFile repo;
    ProdusValidator pv;
    Service serv(repo, pv);
    assert(serv.getAll().size() == 0);
    serv.add(1, "a", 1);
    assert(serv.getSumaProduseNume(serv.getAll(), "a") == 1);
    assert(serv.getAll().size() == 1);
    serv.dell(1, "a", 2);
    assert(serv.getAll().size() == 1);
    serv.dell(1, "a", 1);
    assert(serv.getAll().size() == 0);


    Produs p2(50, "ciocolata", 20);
    Produs p3(10, "c", 10);
    p2 = p3;
}

void testRepoFile(){
    ifstream f("testProduse.txt");
    ofstream g("testProduse.txt");
    RepositoryFile repoFile("testProduse.txt");
    Produs p1(1, "1", 1);
    Produs p2(2, "3", 1);
    repoFile.addItem(p1);
    assert(repoFile.size() == 1);
    repoFile.addItem(p2);
    assert(repoFile.size() == 2);
}

void testFunctionalitati(){
    char *nume = new char[20];
    strcpy(nume, "testProduse.txt");
    ProdusValidator pv;
    RepositoryFile repo(nume);
    Service serv(repo, pv);

    assert(serv.give_change(2, 1)[0] == 1);
    assert(serv.give_change(10, 3)[1] == 1);
    assert(serv.give_change(105, 3)[2] == 1);
    assert(serv.give_change(10, 1)[0] == 5);
}


void Tests(){
    setRepoGetSetLab9();
    testService();
    testRepoFile();
    testFunctionalitati();
};