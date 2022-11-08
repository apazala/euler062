#include <map>
#include <vector>
#include <iostream>
#include <cinttypes>
using namespace std;

int countdigs[10];
inline int64_t digitssignature(int64_t n)
{
    int d;
    while (n > 9)
    {
        d = n % 10;
        countdigs[d]++;
        n /= 10;
    }
    countdigs[n]++;

    int64_t signature = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (d = countdigs[i])
        {
            countdigs[i] = 0;
            while (d--)
            {
                signature = 10 * signature + i;
            }
        }
    }
    if (d = countdigs[0])
    {
        countdigs[0] = 0;
        while (d--)
        {
            signature = 10 * signature;
        }
    }

    return signature;
}

int main()
{
    map<int64_t, vector<int64_t>> cubesperms;
    int64_t limit = 10000; // 2^(63/3)
    int64_t v, s;
    for(int i = 1; i < limit; i++){
        v = i;
        v*=i;
        v*=i;
        s = digitssignature(v);
        cubesperms[s].push_back(v);
    }

    for(auto &it: cubesperms){
        vector<int64_t> vec = it.second;
        if(vec.size() == 5){
            for(int64_t c: vec){
                cout << c << " ";
            }
            cout << "\n";
        }
    }
}