#include <iostream>
#include <vector>

using namespace std;

bool isOneBitCharacter(std::vector<int>& bits) {
    int n = bits.size();
    int i = 0;
    while(i < n-1)
    {
        i += bits[i] + 1;
    }
    return i == n - 1;
}

bool isOneBitCharacter2(std::vector<int>& bits)
{
    if (bits.empty()) return false;
    int right = bits.back();
    bits.pop_back();
    while (!bits.empty() && bits.back())
    {
        right ^= 1;
        bits.pop_back();

    }
    return right == 0;
}

int main(int argc, char* argv[])
{
    std::vector<int> bits = { 1, 1, 0 };
    bool ret = isOneBitCharacter2(bits);

    system("pause");

    return 0;
}
