#include "stdafx.h"
#include "DataTableMgr.h"
#include "ItemTable.h"
#include "EnemyTable.h"
DataTableMgr::~DataTableMgr()
{
	Release();
}

void DataTableMgr::Init()
{
	Release();

	tables.insert({ DataTable::Types::String, new StringTable() });
	tables.insert({ DataTable::Types::Enemy, new EnemyTable() });
	tables.insert({ DataTable::Types::Item, new ItemTable() });
	for (auto t : tables)
	{
		t.second->Load();
	}
}

void DataTableMgr::Release()
{
	for (auto t : tables)
	{
		t.second->Release();
		delete t.second;
	}
	tables.clear();
}
