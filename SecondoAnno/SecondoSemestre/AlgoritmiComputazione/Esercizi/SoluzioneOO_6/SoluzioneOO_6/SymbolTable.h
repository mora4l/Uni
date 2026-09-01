#if !defined(SYMBOL_TABLE_H)
#define SYMBOL_TABLE_H

#include <string>
#include <sstream>
#include <unordered_map>

#include "Exception.h"

class SymbolTable {

public:
	SymbolTable() = default;
	~SymbolTable() = default;

	SymbolTable(const SymbolTable& other) = delete;
	SymbolTable& operator=(const SymbolTable& other) = delete;

	int getValue(std::string const& key) const {
		auto itr = map.find(key);
		if (itr == map.end()) {
			std::stringstream temp;
			temp << "Undeclared identifier: " << key;
			throw EvaluationError{ temp.str() };
		}
		return (*map.find(key)).second;
	}
	
	void setValue(std::string const& key, int value) {
		map[key] = value;
	}

private:
	std::unordered_map<std::string, int> map;

};


#endif
