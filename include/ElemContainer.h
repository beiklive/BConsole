#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using std::shared_ptr;
using std::vector;
using std::string;

class ElemContainer
{
private:
    // box property
    int BoxWidth__;
    int BoxHeight__;

    char BoxBorder = '*';
    int BoxBorderSize = 1;
    bool ActiveBackGround = true;
    shared_ptr<vector<vector<char>>> BoxBuffer;

public:
    ElemContainer() = delete;
    ~ElemContainer() = default;

    ElemContainer(int Width, int Height);
    // 基础配置
    void SetBackGround(bool);    //是否开启背景，开启透明字符也会覆盖前一图层
    void SetBorder(char c);
    void RemoveBorder();

    // 对外开放数据
    const int width();
    const int Height();
    shared_ptr<vector<vector<char>>> buffer();

    // 数据写入
    void SetTableChar(int PositionX, int PositionY, char c);
    void SetTableString(int PositionX, int PositionY, string str);
    void SetTableElem(int PositionX, int PositionY, ElemContainer elem);
    void Finish();   // 该帧绘制完毕

private:
    // 边界检查
    bool IsCharOverEdge(int PositionX, int PositionY);
    bool CheckBackGround(char c);
    void DrawBorder();
};
