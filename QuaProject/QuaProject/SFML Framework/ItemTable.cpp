#include "stdafx.h"
#include "ItemTable.h"
#include "rapidcsv.h"

DataItem ItemTable::Undefined;


bool ItemTable::Load()
{
	Release();

	rapidcsv::Document doc(filePath, rapidcsv::LabelParams(0, -1));
	for (int i = 0; i < doc.GetRowCount(); ++i)
	{
		auto row = doc.GetRow<std::string>(i);
		Item::Types id = (Item::Types)std::stoi(row[0]);
		if (table.find(id) != table.end())
		{
			return false;
		}

		table[id].id = id;
		table[id].textureId = row[1];
	}
	return true;
}

void ItemTable::Release()
{
	table.clear();
}

const DataItem& ItemTable::Get(Item::Types id)
{
	auto find = table.find(id);
	if (find == table.end())
	{
		return Undefined;
	}
	return find->second;
}
