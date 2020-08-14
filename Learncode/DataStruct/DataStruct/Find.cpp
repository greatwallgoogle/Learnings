#include "Find.h"

int FindUtil::BinaryFindRecursive(const vector<int>& aValues, int nTarget)
{
	int nBegintIndex = 0;
	int nEndIndex = aValues.size() - 1;
	return BinaryFindRecurveImpl(aValues, nTarget, nBegintIndex, nEndIndex);
}

int FindUtil::BinaryFind(const vector<int>& aValues, int nTarget)
{
	int nBeginIndex = 0;
	int nEndIndex = aValues.size() - 1;
	while (nBeginIndex <= nEndIndex)
	{
		int nMiddleIndex = (nBeginIndex + nEndIndex) / 2;
		if (aValues[nMiddleIndex] == nTarget)
		{
			return nMiddleIndex;
		}

		if (aValues[nMiddleIndex] > nTarget)
		{
			nEndIndex = nMiddleIndex - 1;
		}
		else
		{
			nBeginIndex = nMiddleIndex + 1;
		}
	}
	return -1;
}

int FindUtil::BinaryFindRecurveImpl(const vector<int>& aValues, int nTarget, int nBeginIndex, int nEndIndex)
{
	if (nBeginIndex > nEndIndex)
	{
		return -1;
	}

	int nMiddleIndex = (nBeginIndex + nEndIndex) / 2;
	if (aValues[nMiddleIndex] == nTarget)
	{
		return nMiddleIndex;
	}

	if (aValues[nMiddleIndex] < nTarget)
	{
		return BinaryFindRecurveImpl(aValues, nTarget, nMiddleIndex + 1, nEndIndex);
	}
	
	return BinaryFindRecurveImpl(aValues, nTarget, nBeginIndex, nMiddleIndex - 1);
}
