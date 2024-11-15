#pragma once
#include "DataTable.h"
#include "Enemy.h"



struct DataEnemy
{
	Enemy::Types id;

	std::string textureId;
	int speed = 0;
	int damage = 0;
};

class EnemyTable : public DataTable
{
public:
	static DataEnemy Undefined;

protected:
	std::unordered_map<Enemy::Types, DataEnemy> table;
	std::string filePath = "tables/enemy_table.csv";
public:
	EnemyTable() : DataTable(DataTable::Types::Enemy) { };
	~EnemyTable() = default;

	bool Load() override;
	void Release() override;

	const DataEnemy& Get(Enemy::Types id);
};

