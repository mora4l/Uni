#if !defined(CONTEXT_H)
#define CONTEXT_H

#include <string>
#include <unordered_map>

class Context {

public:
	Context() = default;
	~Context() = default;

	Context(const Context& other) = delete;
	Context& operator=(const Context& other) = delete;

	int getValue(std::string const& key) const {
		return (*map.find(key)).second;
	}
	void setValue(std::string const& key, int value) {
		map[key] = value;
	}

private:
	std::unordered_map<std::string, int> map;

};

#endif
