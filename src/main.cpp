#include <iostream>
#include "ImageFlush.h"
#include "ElemContainer.h"

using namespace std;
namespace TimeTools{
    void FlushRate(const int& delaytime)
    {
        usleep(1000000/delaytime);
    }
}


int main(int argc, char **argv)
{
    int i = 0;
    while (1)
    {
        ElemContainer b(15, 5);
        // b.RemoveBorder();
        b.SetTableString(2,2, "---eat---->");
        b.Finish();


        ElemContainer a(90, 30);
        a.SetBackGround(false);
        a.SetTableElem((3+i)%90, 3, b);
        a.SetTableElem((9+i)%90, 9, b);
        a.SetTableElem((2+i)%90, 15, b);
        a.SetTableElem(11, (2+i)%30, b);
        // a.RemoveBorder();
        // a.SetBorder('+');
        a.Finish();
        ImageFlush<ElemContainer> Gen(a);
        Gen.Flush();
        TimeTools::FlushRate(10);
        i++;
    }

    return 0;
}
