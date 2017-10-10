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
    long double alias_table[n][2];
    long double nomalize[n];
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
        if (i == 0) c[i] = 1 - a[i];
        else c[i] = b[i-1] * (1- a[i]);
        if(c[i] > c[i-1]) cout << " c :  "<< c[i] <<  "b: " << b[i-1] <<"    a: " << a[i] << "   i: " << i<< endl;
        cout << c[i] <<", ";
    }
    cout << endl;


    long double mean = 0;
    for (int i = 0 ; i < n; i++){
        mean += c[i];
    }
    mean = mean/n;
    cout << "mean: " << mean << endl;

    for (int i = 0 ; i < n ; i++){
        nomalize[i] = c[i] * n;
        cout << nomalize[i] << " ";
    }
    cout << endl;

    int j = 0, check = 0;
    for (int i  = 0; i < n ; i++){
        if (nomalize[n - 1 - i] < 1){
            alias_table[i][1] = nomalize[n - 1 - i];
//            cout << alias_table[i][1] << " sdas  " << endl;
        }
        else if(i < n - 1 - check) alias_table[i][1] = 0;
        if(nomalize[j] > 1){
            alias_table[i][0] = 1 - alias_table[i][1];
            nomalize[j] = nomalize[j] - alias_table[i][0];
        }
        else {
            alias_table[n - 1 - j][1] = nomalize[j];
            check++;
            j++;
        }

        cout << alias_table[i][0] << " ";
    }
    cout << endl;

    for (int i = 0 ; i < n ; i++){
        cout << alias_table[i][1] << " ";
    }






    return 0;
}