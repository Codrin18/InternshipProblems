#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
int compute(std::vector<int> &A)
{
int sum[A.size()][A.size()+1];
for (int i = 0; i < A.size(); i++)
{
    for(int j =0; j < A.size(); j++)
    {
        sum[i][j]=2;
    }
}

for (int k = 0; k < A.size();k++)
{
    sum[k][A.size()]=0;
}

for (int i = 0; i < A.size(); i++)
{
    for(int j = 0; j < A.size(); j++)
    {
        if (i!=j)
        {
            if (sum[i][i] != 7)
            {
                int temp = abs(A[j]-A[i]);
                if (temp<7 && abs(j-i)>=3)
                {   
                    sum[i][i]=7;
                    sum[i][j]=7;
                    if (i>j)
                    {
                        for(int k = j;k < i;k++)
                            sum[i][k]=7;
                    }
                    else
                    {
                        for(int k = i;k < j;k++)
                            sum[i][k]=7;
                    } 
                }
            }
        }
    }
}

for (int i = 0; i < A.size(); ++i)
{
    for(int j = 0; j < A.size(); ++j)
    {
        if (sum[i][j]==7)
        {
            sum[i][A.size()]+=1;
        }
    }
}

for (int i = 0; i < A.size(); ++i)
{
    for (int j = 0; j < A.size()+1; ++j)
        std::cout<<sum[i][j]<<" ";
    std::cout<<std::endl;
}


int result = 0;
int row = A.size()-1;
int column = A.size()-1;
while(1)
{
    int value = sum[row][A.size()];
    if (value == 0)
        value=1;
    int temp = sum[row][column];
    result += temp;
    row = row-value;
    column = column-value;
    while (sum[row][column+1]==7 && row>=0)
    {
        row-=1;
        column-=1;
        result+=2;
    }
    if (row < 0)
        break;
}

return result;
}

int solution(std::vector<int> &A) {
if (A.size() > 24)
    return 25;
if (A.size() <= 3)
    return A.size() * 2;

return std::min(25,compute(A));
}

int main()
{
	std::vector<int> arr = {1,3,5,6,13,15,25,26,28,30};
	std::cout << solution(arr);
	return 0;
}