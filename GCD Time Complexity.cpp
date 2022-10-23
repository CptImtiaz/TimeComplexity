#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == b)
    {
        return b;
    }
    else
    {
        if (a > b)
        {
            return gcd(a - b, b);
        }
        else
        {
            return gcd(a, b - a);
        }
    }
}
int main()
{
    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    gcd(2000000,5000000);
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        time_taken1 *= 1e-9;
    cout << "Time taken by this gcd is :" << fixed << time_taken1 << " s" << setprecision(9) << endl;
    return 0;
}
