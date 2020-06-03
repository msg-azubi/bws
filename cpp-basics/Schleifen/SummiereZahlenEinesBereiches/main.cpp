#include <iostream>

using namespace std;



int main()
{

    int summegrenzenZahl1;
    int summegrenzenZahl2;
    int summeBerechnen;
    int x;


    cout << " summeBerechnen " <<endl;
    cout << " von " <<endl;
    cin >> summegrenzenZahl1;
    cout << " bis " <<endl;
    cin >>summegrenzenZahl2;

    summeBerechnen=summegrenzenZahl1;


    for (int i=summegrenzenZahl1+1; i<=summegrenzenZahl1 ; i++) {

        summeBerechnen += i;

    }

    cout << " =  " << summeBerechnen << endl;

    //teil2

    summeBerechnen=summegrenzenZahl1;

    cout << summegrenzenZahl1;

    for (x=summegrenzenZahl1+1; x<=summegrenzenZahl2; x++) {
        cout << " + " << x;
        summeBerechnen += x;
    }
    cout << " = " << summeBerechnen << endl << endl;

    return 0;
    }
