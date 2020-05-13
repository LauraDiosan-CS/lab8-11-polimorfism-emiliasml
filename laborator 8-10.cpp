// laborator 8-10.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "UI.h"
#include "Service.h"
#include "SerializerSeries.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileHTML.h"
#include "IRepository.h"
#include "Tests.h"
#include <iostream>

using namespace std;

int main(){
    cout << "--Start";
    Tests test;
    test.runTests();
    cout << endl << "--Tests are ok!";

    SerializerSeries* s = new SerializerSeries();
    RepositoryFile<Series*>repo("Tests.txt", s);
    RepositoryFileCSV<Series*>repoCSV("Series.csv", s);
    RepositoryFileHTML<Series*>repoHTML("Series.html", s);
    IRepository<User>* repoUser();
    
    //Service service(repoHTML, repoUser);
    //UI userInterface(service);
    //userInterface.showMenu();
    return 0;
}
