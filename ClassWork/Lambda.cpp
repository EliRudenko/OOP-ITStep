#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Lambda
{
private:
    int m_lowerBound;
    int m_upperBound;

public:
    Lambda(int lowerBound, int upperBound) : m_lowerBound(lowerBound), m_upperBound(upperBound)
    {}

    bool operator ()(int n) const
    {
        return m_lowerBound <= n && n <= m_upperBound;
    }
};

bool Test(int n)
{
    return n % 2 == 0;
}

int main()
{
    vector<int> srcVec;

    for (int val = 0; val < 10; val++)
    {
        srcVec.push_back(val);
    }

    for (auto in : srcVec)
    {
        cout << in << "\t";
    }
    int lowerBound = 0;
    int upperBound = 0;
    cout << "Enter the value range: ";
    cin >> lowerBound >> upperBound;

    int result = count_if(srcVec.begin(), srcVec.end(), [lowerBound, upperBound](int n)
    {
        return lowerBound <= n && n <= upperBound;
    });

    cout << "Number of elements in the range: " << result << endl;

    int evenCount = count_if(srcVec.begin(), srcVec.end(), [](int x) { return x % 2 == 0; });
    cout << "Number of even elements: " << evenCount << endl;

    vector<int> negVec = {1, -2, 3, -4, 5, -6, 7, -8};
    negVec.erase(remove_if(negVec.begin(), negVec.end(), [](int x) { return x < 0; }), negVec.end());

    cout << "Vector after removing negative elements: ";
    for (int num : negVec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
