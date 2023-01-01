#include<iostream>
using namespace std;
int num[26];
int main()
{
    int i, j;
    string str; int max = 0;
    cin >> str; char x;
    for (i = 0; i < str.length(); i++)
    {
        num[str[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
            x = i + 97;
        }
    }
    cout << x << endl << max << endl;
    return 0;
}
