#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double N,K;
    cin >> N >> K;

    double a = N * K;
    double d = 1/a;
    if( a >  0){
        cout << setprecision(10) << d;
    }
    else{
      cout << "0";
    }
    return 0;
}
