#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img)
	{
		int rows = img.size();
		int cols = img[0].size();

		vector<vector<int>> result(rows, vector<int>(cols));

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int sum = 0;
				int count = 0;

				for (int di = -1; di <= 1; di++)
				{
					for (int dj = -1; dj <= 1; dj++)
					{
						int r = i + di;
						int c = j + dj;

						if (r >= 0 && r < rows &&
							c >= 0 && c < cols)
						{
							sum += img[r][c];
							count++;
						}
					}
				}
			result[i][j] = floor((double)sum / count);
			}
		}

		return result;
	}
};
