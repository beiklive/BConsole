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

template<class ELE_ITEM>
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
    ImageFlush(ELE_ITEM& elem);
    // 重新绘制
    void DrawImage(ELE_ITEM& elem);
    // 刷新缓冲区
    void Flush();


};


template<class ELE_ITEM>
ImageFlush<ELE_ITEM>::ImageFlush(int Width, int Height) : ImgSizeW__(Width), ImgSizeH__(Height)
{
    FrameBuffer = std::shared_ptr<std::vector<std::vector<char>>>(new std::vector<std::vector<char>>(ImgSizeH__, std::vector<char>(ImgSizeW__, ' ')));;

}
template<class ELE_ITEM>
ImageFlush<ELE_ITEM>::ImageFlush(ELE_ITEM& elem)
{
    ImgSizeH__ = elem.Height();
    ImgSizeW__ = elem.width();
    FrameBuffer = elem.buffer();
}

template<class ELE_ITEM>
void ImageFlush<ELE_ITEM>::DrawImage(ELE_ITEM& elem)
{
    ImgSizeH__ = elem.Height();
    ImgSizeW__ = elem.width();
    FrameBuffer = elem.buffer();
}


template<class ELE_ITEM>
void ImageFlush<ELE_ITEM>::Flush()
{
    DJ::screenClear();
    for (size_t i = 0; i < ImgSizeH__; i++)
    {
        for (size_t j = 0; j < ImgSizeW__; j++)
        {
            cout << (*FrameBuffer)[i][j];
        }
        cout << "" << endl;
    }
}

