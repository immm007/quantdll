#include "stdafx.h"
#include "ADL.h"
#include <fstream>

using namespace std;

ADL::ADL(const char* path)
{
	ifstream ifs(path);
	const int max_len = 63;
	char tmp[max_len+1];
	ifs.getline(tmp, max_len);
	while (!ifs.eof())
	{
		ifs.getline(tmp, max_len);
		int year, month, day;
		Diff diff;
		sscanf(tmp, "%d-%d-%d,%f,%f,%f,%f", &year, &month, &day, &diff.szzs, &diff.szcz, &diff.zxbz, &diff.cybz);
		int date = year * 10000 + month*100 + day;
		_dict[date] = diff;
	}
}

float ADL::value(int code, int date)
{
	switch (code)
	{
	case 999999:
		return _dict[date].szzs;
	case 399001:
		return _dict[date].szcz;
	case 399005:
		return _dict[date].zxbz;
	case 399006:
		return _dict[date].cybz;
	default:
		return 0.5;
	}
}

bool ADL::valid(int code) const
{
	if ((code == 999999) | (code == 399001) | (code == 399005) | (code == 399006))
	{
		return true;
	}
	return false;
}
