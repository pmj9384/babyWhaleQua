#include "stdafx.h"
#include "StringTable.h"
#include "rapidcsv.h"

std::wstring StringTable::Undefined = L"Press Enter to Start!";

bool StringTable::Load()
{
	Release();

	std::wstring wstr;

	rapidcsv::Document doc(filePath, rapidcsv::LabelParams(0, -1));
	for (int i = 0; i < doc.GetRowCount(); ++i)
	{
		std::vector<std::string> strings = doc.GetRow<std::string>(i); 
		auto it = table.find(strings[0]);
		if (it != table.end())
		{
			std::cout << "파일생성 실패!" << std::endl;
			continue;
		}

		for (int j = 0; j < (int)Languages::Count; ++j)
		{
			auto& vec = table[strings[0]];
			Utils::Convert_utf8_to_unicode_string(wstr, strings[j + 1].c_str(), strings[j + 1].size());
			vec.push_back(wstr);
		}
	}

	for (auto& pair : table)
	{
		std::cout << pair.first << ": ";
		for (auto& s : pair.second)
		{
			std::wcout << s << " ";
		}
		std::cout << std::endl;
	}

	return false;
}

void StringTable::Release()
{
	table.clear();
}

const std::wstring& StringTable::Get(const std::string& id)
{
	return Get(id, Variables::currentLang);
}

const std::wstring& StringTable::Get(const std::string& id, Languages lang)
{
	auto find = table.find(id);
	if (find == table.end())
	{
		return Undefined;
	}
	return (find->second)[(int)lang];
}
