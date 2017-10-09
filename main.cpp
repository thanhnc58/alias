#include <iostream>
#include "xorshift.h"
#include <random>
#include <algorithm>

using namespace std;

void alias_table(int a[], int n){
    int c = 1;
}

bool compare (long double i,long double j) { return (i>j); }

int main() {
    std::cout << "Hello, World!" << std::endl;

    int n = 10;
    long double a[n], b[n], c[n];
    xorshift ran;
    ran.init_seed(4);

    //Initial probability
    for (int i = 0; i < n; i++){
        a[i] = (float)(ran.get_max((n - 2)) + 1) / (n );
        cout << a[i] << " ";
    }
    cout << endl;

    sort(a,a + n);


    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;


    //Cumulative multiplication
    for (int i = 0; i < n; i++){
        if (i == 0) b[i] = a[i];
        else b[i] = a[i] * b[i-1];
        cout << b[i] << " ";
    }
    cout << endl;



    //Geometric probability
    for (int i = 0; i < n; i++){
        if (i == 0) c[i] = b[i];
        else c[i] = b[i-1] * (1- a[i]);
        if(c[i] > c[i-1]) cout << "b: " << b[i-1] <<"    a: " << a[i] << "   i: " << i<< endl;
        cout << c[i] <<", ";
    }
    cout << endl;


    long double mean = 0;
    for (int i = 0 ; i < n; i++){
        mean += c[i];
    }
    mean = mean/n;
    cout << "mean: " << mean << endl;
    return 0;
}