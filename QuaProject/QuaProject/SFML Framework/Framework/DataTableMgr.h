#pragma once

class DataTableMgr : public Singleton<DataTableMgr>
{
	friend Singleton<DataTableMgr>;

private:
	DataTableMgr() = default;
	~DataTableMgr();

	std::unordered_map<DataTable::Types, DataTable*> tables;

public:
	void Init();
	void Release();

	template<typename T>
	T* Get(DataTable::Types type);
};

template<typename T>
inline T* DataTableMgr::Get(DataTable::Types type)
{
	auto find = tables.find(type);
	if (find == tables.end())
		return nullptr;
	return dynamic_cast<T*>(find->second);
}

#define DATATABLE_MGR (DataTableMgr::Instance())
#define STRING_TABLE (DATATABLE_MGR.Get<StringTable>(DataTable::Types::String))
#define ZOMBIE_TABLE (DATATABLE_MGR.Get<ZombieTable>(DataTable::Types::Zombie))
#define ITEM_TABLE (DATATABLE_MGR.Get<ItemTable>(DataTable::Types::Item))