#include "ImageFlush.h"

ImageFlush::ImageFlush(int Width, int Height) : ImgSizeW__(Width), ImgSizeH__(Height)
{
    FrameBuffer = std::shared_ptr<std::vector<std::vector<char>>>(new std::vector<std::vector<char>>(ImgSizeH__, std::vector<char>(ImgSizeW__, ' ')));;

}

ImageFlush::ImageFlush(ElemContainer elem)
{
    ImgSizeH__ = elem.Height();
    ImgSizeW__ = elem.width();
    FrameBuffer = elem.buffer();
}

void ImageFlush::DrawImage(ElemContainer elem)
{
    ImgSizeH__ = elem.Height();
    ImgSizeW__ = elem.width();
    FrameBuffer = elem.buffer();
}



void ImageFlush::Flush()
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

