#pragma once
#include <unordered_map>

struct Diff
{
	float szzs;
	float szcz;
	float zxbz;
	float cybz;
};

class ADL
{
public:
	ADL(const char* path);
	float value(int code, int date);
	bool valid(int code) const;
private:
	std::unordered_map<int, Diff> _dict;
};

