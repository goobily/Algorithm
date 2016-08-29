#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool canConstruct_v0(string ransomNote, string magazine) {
	if (ransomNote.empty()) {
		return true;
	}
	if (magazine.empty()) {
		return false;
	}
	int len_ransomNote = ransomNote.length();
	int len_magazine = magazine.length();
	bool *flag = new bool[len_magazine];
	for (int i = 0; i < len_magazine; ++i) {
		flag[i] = 0;
	}

	for (int i = 0; i < len_ransomNote; ++i) {
		bool bFound = false;
		for (int j = 0; j < len_magazine; ++j) {
			if (!flag[j] && ransomNote[i]==magazine[j]) {
				flag[j] = true;
				bFound = true;
				break;
			}
		}
		if (!bFound) {
			return false;
		}
	}
	return true;
}

bool canConstruct_v1(string ransomNote, string magazine) {
	char *pRansom = (char *)ransomNote.c_str();
	char *pMagaze = (char *)magazine.c_str();
	int lenRansom = strlen(pRansom);
	int lenMagaze = strlen(pMagaze);
	for (int i = 0; i < lenRansom; i++)
	{
		bool flag = false;
		for (int j = i; j < lenMagaze; j++)
		{
			if (pMagaze[j] == pRansom[i])
			{
				// 将magazine中和ransomNote中相等的元素交换到前面，保证所有元素只遍历一次。
				char tempChar = pMagaze[i];
				pMagaze[i] = pMagaze[j];
				pMagaze[j] = tempChar;
				flag = true;
				break;
			}
		}
		if (flag == true)
			continue;
		else
			return false;

	}
	return true;
}

bool canConstruct_v1_1(string ransomNote, string magazine) {
	vector<int> magazLetters(128, 0);
	for (char m : magazine)
		magazLetters[m]++;
	for (char r : ransomNote)
		if (--magazLetters[r] < 0) return false;
	return true;
}


/* 空间换取时间 */
bool canConstruct_v2(std::string ransomNote, std::string magazine)
{
	int noteLen = ransomNote.length();
	int magLen = magazine.length();
	//Some special cases to return immediately
	if (magLen < noteLen) return false;
	if (magLen == noteLen && ransomNote == magazine) return true;
	//Since we are only dealing with lowercase letters
	int noteContents[26] = { 0 };
	int magContents[26] = { 0 };
	//Each characters count for both strings
	for (int i = 0; i < noteLen; i++) noteContents[ransomNote[i] - 'a']++;
	for (int i = 0; i < magLen; i++)  magContents[magazine[i] - 'a']++;
	//If ransom string had any character count more than magazine, we can return false
	for (int i = 0; i < 26; i++) if (noteContents[i] > magContents[i]) return false;
	//If nothing has been returned yet, result must be true because we have checked for all false cases
	return true;
}

/* NICE Solution */
bool canConstruct_v3(string ransomNote, string magazine) {
	int hist[26] = { 0 };
	int nUnique = 0;  // # of unique chars in ransomNote
	for (auto c : ransomNote) {
		// when the number first appears
		if (++hist[c - 'a'] == 1) ++nUnique;
	}
	for (auto c : magazine) {
		// when all instances of c is addressed
		if (--hist[c - 'a'] == 0) --nUnique;
		if (nUnique == 0) return true; // An optimization
	}
	return nUnique == 0;
}

/* a simple way, but will change magazine string*/

bool canConstruct_v4(string ransomNote, string magazine) {
	for (auto i : ransomNote) {
		auto pos = magazine.find(i);
		if (pos == string::npos) {
			return false;
		}
		magazine.erase(pos, 1);
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "argumnets should be TWO strings\n";
		return 0;
	}

	cout << argv[0] << ", " << argv[1] << ", " << argv[2] << endl;
	if (canConstruct_v3(argv[1], argv[2])) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}