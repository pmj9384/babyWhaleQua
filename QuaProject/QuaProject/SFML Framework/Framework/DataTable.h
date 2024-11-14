#pragma once
class DataTable
{
public:
	enum class Types
	{
		String,
		Item,
		Enemy,
	};
	static const int TotalTypes = 3;

protected:
	Types type;

public:
	DataTable(Types t) : type(t) {}
	~DataTable() = default;

	virtual bool Load() = 0;
	virtual void Release() = 0;
};

