#include "main.h"


int main()
{
    Fibonacci f;
    f.generate(9);
    cout << f << "\n";

    f.generate(13);
    cout << f << "\n";

    f.generate(20);
    cout << f << "\n";

    return 0;
}

