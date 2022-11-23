#pragma once

#include <iostream>
#include <string>
#include "tools.hpp"
#include "ElemContainer.h"
#include <memory>
#include <vector>
using std::shared_ptr;
using std::vector;
using std::cout;
using std::endl;
using std::string;

class ImageFlush
{
private:
    int ImgSizeW__ = 80;
    int ImgSizeH__ = 60;
    shared_ptr<vector<vector<char>>> FrameBuffer;
    // shared_ptr<vector<vector<char>>> asd1;
public:
    ImageFlush() = delete;
    ~ImageFlush() = default;
    // 初始化
    ImageFlush(int Width, int Height);
    ImageFlush(ElemContainer elem);
    // 重新绘制
    void DrawImage(ElemContainer elem);
    // 刷新缓冲区
    void Flush();


};

