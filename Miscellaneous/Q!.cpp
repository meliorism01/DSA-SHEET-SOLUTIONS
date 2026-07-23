#include <iostream>
using namespace std;

class EvenPositive
{
private:
    int a, b, c;

public:
    void getData()
    {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    void countEvenPositive()
    {
        int count = 0;

        if (a > 0 && a % 2 == 0)
            count++;

        if (b > 0 && b % 2 == 0)
            count++;

        if (c > 0 && c % 2 == 0)
            count++;

        cout << "Number of even positive numbers = " << count;
    }
};

int main()
{
    EvenPositive obj;

    obj.getData();
    obj.countEvenPositive();

    return 0;
}
