#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible = true;

void search(int left, int right, long monstr[])
{
	bool finded = false;
	if (!possible)
		return;
	if (left < right - 1) {
		double middle = ((double)(monstr[left] + (double)monstr[right]) / 2);
		int index;
		for (int i = left + 1; i < right; i++)
		{
			if (middle == monstr[i])
			{
				finded = true;
				index = i;


			}
			if(i == right - 1 && !finded)
			{
				possible = false;
				return;
			}
		}
		search(left, index, monstr);
		if (!possible)
			return;
		search(index, right, monstr);
		if (!possible)
			return;
	}

}



void QuickSort (long Array[], long N, long L, long R)
{
    int iter = L ,
        jter = R ;

    int middle = (R+L)/2 ;

    int x = Array [middle] ;
    int w ;

    do
    {
        while (Array[iter]<x)
        { iter ++ ; }

        while (x<Array[jter])
        { jter -- ; }

        if (iter<=jter)
        {
           w = Array [iter];
           Array [iter] = Array [jter] ;
           Array [jter] = w ;

           iter ++ ;
           jter -- ;
        }
    }
    while (iter<jter) ;

    if (L<jter)
    { QuickSort (Array, N, L, jter) ; }

    if (iter<R)
    { QuickSort (Array, N, iter, R) ; }
}
int main()
{
	long n;
	cin >> n;
	long monstr [n];

	for (int i = 0; i < n; i++) {
		cin >> monstr[i];
	}

	QuickSort(monstr, n ,0,n-1);
	search(0, n - 1, monstr);
	if (possible == false)
	{
		cout <<"NO";
	}
	else
	{
		cout <<"YES";
	}

	return 0;
}
