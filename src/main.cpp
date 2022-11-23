#include <iostream>
#include "ImageFlush.h"
#include "ElemContainer.h"

using namespace std;

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
        ImageFlush Gen(a);
        Gen.Flush();
        usleep(1000000/1);
        i++;
    }

    return 0;
}
