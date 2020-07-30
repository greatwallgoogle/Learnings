#pragma once

#include <vector>

using namespace std;
 
class FindUtil
{
public:
	//���ֲ���<�ݹ�>
	static int		BinaryFindRecursive(const vector<int>& aValues, int nTarget);
	//���ֲ���<�ǵݹ�>
	static int      BinaryFind(const vector<int>& aValues,int nTarget);
private:
	static int		BinaryFindRecurveImpl(const vector<int>& aValues,  int nTarget,int nBeginIndex,int nEndIndex);
};