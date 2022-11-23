#include "ElemContainer.h"

ElemContainer::ElemContainer(int Width, int Height) : BoxWidth__(Width), BoxHeight__(Height)
{
    BoxBuffer = std::shared_ptr<std::vector<std::vector<char>>>(new std::vector<std::vector<char>>(BoxHeight__, std::vector<char>(BoxWidth__, ' ')));
}

void ElemContainer::RemoveBorder()
{
    BoxBorderSize = 0;
}


void ElemContainer::SetBorder(char c)
{
    if (sizeof(c) > 0)
    {
        BoxBorder = c;
    }
}

void ElemContainer::SetBackGround(bool flag)
{
    ActiveBackGround = flag;
}

bool ElemContainer::CheckBackGround(char c)
{
    if (!ActiveBackGround)
    {
        if (c == ' ')
        {
            return false;
        }
    }
    return true;
}
const int ElemContainer::width(){return BoxWidth__;}
const int ElemContainer::Height(){return BoxHeight__;}
shared_ptr<vector<vector<char>>> ElemContainer::buffer(){return BoxBuffer;}


void ElemContainer::SetTableChar(int PositionX, int PositionY, char c = ' ')
{
    if (!IsCharOverEdge(PositionX, PositionY) && CheckBackGround(c))
    {
        (*BoxBuffer)[PositionY][PositionX] = c;
    }
}

void ElemContainer::SetTableString(int PositionX, int PositionY, string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        SetTableChar(PositionX + i, PositionY, str[i]);
    }
}

void ElemContainer::SetTableElem(int PositionX, int PositionY, ElemContainer elem)
{
    for (size_t i = 0; i < elem.Height(); i++)
    {
        for (size_t j = 0; j < elem.width(); j++)
        {
            SetTableChar(PositionX + j, PositionY + i, (*elem.buffer())[i][j]);
        }
    }

}


bool ElemContainer::IsCharOverEdge(int PositionX, int PositionY)
{
    if (PositionX - BoxBorderSize >= 0 && PositionX + BoxBorderSize < BoxWidth__)
    {
        if (PositionY - BoxBorderSize >= 0 && PositionY + BoxBorderSize < BoxHeight__)
        {
            return false;
        }
    }
    return true;
}

void ElemContainer::DrawBorder()
{
    if(BoxBorderSize){
        for (size_t i = 1; i < BoxWidth__; i++)
        {
            (*BoxBuffer)[BoxHeight__ - 1][i] = BoxBorder;
            (*BoxBuffer)[0][i] = BoxBorder;
        }
        for (size_t i = 0; i < BoxHeight__; i++)
        {
            (*BoxBuffer)[i][BoxWidth__ - 1] = BoxBorder;
            (*BoxBuffer)[i][0] = BoxBorder;
        }
    }

}

void ElemContainer::Finish()
{
    DrawBorder();
}
