#pragma once

#include <vector>

using namespace std;
 
class FindUtil
{
public:
	//二分查找<递归>
	static int		BinaryFindRecursive(const vector<int>& aValues, int nTarget);
	//二分查找<非递归>
	static int      BinaryFind(const vector<int>& aValues,int nTarget);
private:
	static int		BinaryFindRecurveImpl(const vector<int>& aValues,  int nTarget,int nBeginIndex,int nEndIndex);
};