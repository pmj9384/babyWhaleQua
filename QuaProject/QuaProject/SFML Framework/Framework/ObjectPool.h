#pragma once

template<typename T>
class ObjectPool
{
private:
	std::list<T*> unused;
	std::list<T*> used;

public:
	ObjectPool(int initSize = 10)
	{
		for (int i = 0; i < initSize; ++i)
		{
			auto obj = new T();
			obj->Init();
			unused.push_back(obj);
		}
	}

	~ObjectPool()
	{
		for (auto obj : unused)
		{
			delete obj;
		}
		for (auto obj : used)
		{
			delete obj;
		}
	}

	T* Take()
	{
		if (unused.empty())
		{
			auto obj = new T();
			obj->Init();
			obj->Reset();
			used.push_back(obj);
			std::cout << "Take: »õ °´Ã¼ »ı¼º. used size = " << used.size() << ", unused size = " << unused.size() << std::endl;
			return obj;
		}

		auto obj = unused.front();
		unused.pop_front();
		used.push_back(obj);
		obj->Reset();
		obj->SetActive(true);
		std::cout << "Take: unused¿¡¼­ °´Ã¼ °¡Á®¿È. used size = " << used.size() << ", unused size = " << unused.size() << std::endl;
		//obj->Reset();
		return obj;
	}

	void Return(T* obj)
	{
		auto find = std::find(used.begin(), used.end(), obj);
		if (find == used.end())
		{
			std::cout << "Invaild Obj" << std::endl;
			return;
		}
		used.erase(find);
		obj->SetActive(false);
		obj->Reset();  //enemy reset
		unused.push_back(obj);
		std::cout << "Return: °´Ã¼ ¹İÈ¯µÊ. used size = " << used.size() << ", unused size = " << unused.size() << std::endl;
	}
};