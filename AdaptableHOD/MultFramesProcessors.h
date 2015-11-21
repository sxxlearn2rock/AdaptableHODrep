#pragma once

//�����࣬���Դ洢����֡�������ʹ���������ص���Ŀ
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
