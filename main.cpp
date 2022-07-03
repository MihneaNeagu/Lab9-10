#include <iostream>
#include <cstring>
#include "Tests.h"
#include "RepoStl.h"
#include "Service.h"
#include "UI.h"
#include "RepositoryFile.h"

int main() {
    Tests();

    char *nume = new char[20];
    strcpy(nume, "f.txt");

    RepositoryFile  r(nume);

    ProdusValidator pv;

    Service s(r, pv);

    UI ui(s);
    ui.showMenu();
    return 0;
}
