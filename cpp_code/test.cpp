#include <iostream>
using namespace std;

int main()
{
    int start = 0,end = 0;
    cout << "enter start and end values: ";
    cin >> start >> end;
    while(start <= end)
    {
        cout << start << endl;
        start++;
    }
    return 0;
}