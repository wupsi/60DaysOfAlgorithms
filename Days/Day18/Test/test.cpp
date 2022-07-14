#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(){
    ofstream out;
    out.open("output.txt");

    int n = 100000, k = 99999;
    out << n << " " << k << endl;
    for(int i = 0; i < n; i++){
        out << rand() % 1000000000 << " " << rand() % 1000000000 << " ";
        out << rand() % 1000000000 << " " << rand() % 1000000000 << endl;
    }   
}