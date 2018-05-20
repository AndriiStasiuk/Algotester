#include <iostream>

using namespace std;

int main()
{
    long long int a,b,c;
    cin >> a >> b >>c;

    if ((a < b) && (a < c)){
        cout<<"YES";
    }

    else if((a == 0) && ((b > 0)||(c>0))){
        cout << "YES";
    }
    else if((a == b) && (a == c)){
        cout <<"NO";
    }
    else{
        cout << "NO";
    }

    return 0;
}
