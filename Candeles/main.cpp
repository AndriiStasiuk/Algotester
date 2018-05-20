#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int N,M;
double e = 0.000000001;

cin >> M >> N;

long array[N];

for(int i = 0; i < N; i++)
{
    cin >> array[i];
}
double  min = 0;
double max = 0;

for (int i = 0; i < N; ++i)
{
    if(array[i] > max)
    {
        max = array[i];
    }
}
int count;

while( max - min > e )
    {
        double length = (max + min)/2;
        count = 0;
        for (int i = 0; i < N; ++i)
        {
            count  = count + array[i]/length;
        }
        if (count < M)
        {
            max = length;
        }
        else if(count > M)
        {
            min = length;
        }
        else if(count == M)
        {
            min  = length;
        }
    }
        cout << setprecision(9) << min;
}
