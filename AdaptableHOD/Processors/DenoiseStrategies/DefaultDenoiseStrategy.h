#pragma once
#include "../DenoiseStrategy.h"

//����ģʽ
class DefaultDenosieStrategy : public DenoiseStrategy
{
public:

	~DefaultDenosieStrategy(void) {}

	static DefaultDenosieStrategy* getInstance()
	{
		if (mSingleton == NULL)
		{
			mSingleton = new DefaultDenosieStrategy();
		}
		return mSingleton;
	}

	void denoise(const Mat& srcImg, Mat& desImg);
private:
		DefaultDenosieStrategy(void) {}
		static DefaultDenosieStrategy* mSingleton;

		class Cleaner   //��˽����Ƕ���Ψһ��������������������ɾ������
		{  
		public:  
			~Cleaner()  
			{  
				if(DefaultDenosieStrategy::mSingleton)  
					delete DefaultDenosieStrategy::mSingleton;  
			}  
		};  
		static Cleaner cleaner;  //����һ����̬��Ա�������������ʱ��ϵͳ���Զ�����������������  
};