#pragma once
#include "DataTable.h"
#include "Item.h"
struct DataItem
{
	Item::Types id;

	std::string textureId;

};

class ItemTable : public DataTable
{
public:
	static DataItem Undefined;

protected:
	std::unordered_map<Item::Types, DataItem> table;
	std::string filePath = "tables/item_table.csv";
public:
	ItemTable() : DataTable(DataTable::Types::Item) { };
	~ItemTable() = default;
	bool Load() override;
	void Release() override;

	const DataItem& Get(Item::Types id);
};

