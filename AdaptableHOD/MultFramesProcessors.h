#pragma once

//辅助类，用以存储传入帧的索引和处理后的像素点数目
class IndexPixel
{
public:
	IndexPixel(){}
	IndexPixel(int index, int pixel)
	{
		mIndex = index;
		mPixel = pixel;
	}

	static bool comparepixel( IndexPixel& a, IndexPixel& b)
	{
		return a.getPixel() > b.getPixel();
	}

	static bool compareindex(IndexPixel& a, IndexPixel& b)
	{
		return a.getIndex() < b.getIndex();
	}

	void setIndex(int index) { mIndex = index; }
	void setPixel(int pixel) { mPixel = pixel; }
	int getIndex() { return mIndex; }
	int getPixel() { return mPixel; }

private:
	int mIndex;
	int mPixel;
};

class MultFramesProcessors
{
public:
	MultFramesProcessors(void);
	~MultFramesProcessors(void);
};

