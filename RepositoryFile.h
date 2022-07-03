#pragma once
#include <vector>
#include "RepoStl.h"
#include "map"

class RepositoryFile: public Repository{
private:
    vector<int> coins;
    char *filename;
public:
    RepositoryFile();
    RepositoryFile(const char *filename);
    RepositoryFile& operator = (const RepositoryFile& r);
    ~RepositoryFile();
    void addItem(Produs & p);
    Produs getItem(int cod);
    void updateItem(int poz, Produs& p);
    void delItem(int p);
    float sumMonede();
    void setMonede(int poz, int value);
    int getMoneda(int poz);
    vector <int> getMonede();

    void loadFromFile();

private:
    void saveToFile();
};
