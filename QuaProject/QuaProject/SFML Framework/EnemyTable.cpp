#include "stdafx.h"
#include "EnemyTable.h"
#include "rapidcsv.h"

DataEnemy EnemyTable::Undefined;

bool EnemyTable::Load()
{
	Release();

	rapidcsv::Document doc(filePath, rapidcsv::LabelParams(0, -1));
	for (int i = 0; i < doc.GetRowCount(); ++i)
	{
		auto row = doc.GetRow<std::string>(i);
		Enemy::Types id = (Enemy::Types)std::stoi(row[0]);
		if (table.find(id) != table.end())
		{
			//
			return false;
		}

		table[id].id = id;
		table[id].textureId = row[1];
		table[id].min_speed = std::stof(row[2]);
		table[id].max_speed = std::stof(row[3]);
		table[id].damage = std::stof(row[4]);

	}

	return true;
}

void EnemyTable::Release()
{
	table.clear();
}

const DataEnemy& EnemyTable::Get(Enemy::Types id)
{
	auto find = table.find(id);
	if (find == table.end())
	{
		return Undefined;
	}
	return find->second;
}
