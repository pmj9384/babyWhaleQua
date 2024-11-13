#pragma once

class StringTable : public DataTable
{
public:
	static std::wstring Undefined;

protected:
	// <T1, T2>
	// T1: 스트링 아이디
	// T2: 언어별 스트링 ([0] 한국어 [1] 영어...)
	std::unordered_map<std::string, std::vector<std::wstring>> table;
	std::string filePath = "tables/string_table.csv";

public:
	StringTable() : DataTable(DataTable::Types::String) { };
	~StringTable() = default;

	bool Load() override;
	void Release() override;

	const std::wstring& Get(const std::string& id);
	const std::wstring& Get(const std::string& id, Languages lang);
};

