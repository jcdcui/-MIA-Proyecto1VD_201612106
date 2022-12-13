#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @param causa : la causa del error
*/
void ErrorT(string causa){
    cerr << "ERROR_Debido_a: "<<causa << endl;
}