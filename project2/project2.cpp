#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int modulo(unsigned int m, unsigned int n)
{
	if (m < n)
	{
		return m;
	}

	return modulo(m - n, n);
}

int occurrences(int number, int d)
{
	if (number == 0)
	{
		return 0;
	}

	int digit = number % 10;
	int rest = number / 10;

	// Check if digit is matched.
	if (digit == d)
	{
		// If matched, add 1 and continue with the rest of number.
		return 1 + occurrences(rest, d);
	}
	else
	{
		// If matched, just continue with the rest of number.
		return occurrences(rest, d);
	}
}

string lucky7s(string s)
{
	// Return if the string length is equal or less than 1
	if (s.length() <= 1)
	{
		return s;
	}

	// Check if the first char matches the second char
	if (s[0] == s[1])
	{
		// if matched, insert "77" between two chars and continue with the rest of the string
		return s.substr(0, 1) + "77" + lucky7s(s.substr(1));
	}
	else
	{
		// If not matched, return the first char and continue with the rest of the string
		return s.substr(0, 1) + lucky7s(s.substr(1));
	}
}

bool combinations(int array[], int size, int target)
{
	// If target is reached, return true
	if (target == 0)
	{
		return true;
	}

	// If combinations don't reach the target, return false
	if (size == 0 || target < 0)
	{
		return false;
	}

	// Include the element and check if it's possible to reach the target
	bool included = combinations(array + 1, size - 1, target - array[0]);

	// Exclude the element and check if it's possible to reach the target
	bool excluded = combinations(array + 1, size - 1, target);

	// Return true if it's possible to reach the target with or without the current element
	return included || excluded;
}

int main()
{

    // test code
    assert(modulo(100, 10) == 0);
    assert(modulo(1, 13) == 1);
    assert(modulo(12, 5) == 2);
    assert(modulo(33, 6) == 3);
	assert(modulo(0, 1) == 0);

    assert(occurrences(567, 2) == 0);
    assert(occurrences(128874, 2) == 1);
    assert(occurrences(212121, 2) == 3);
	assert(occurrences(0, 0) == 0);
	assert(occurrences(10, 0) == 1);
	assert(occurrences(1, 1) == 1);
	assert(occurrences(100, 0) == 2);
	assert(occurrences(909023129, 9) == 3);

    assert(lucky7s("cs32") == "cs32");
    assert(lucky7s("Apple Baseball") == "Ap77ple Basebal77l");
    assert(lucky7s("abbba") == "ab77b77ba");
	assert(lucky7s("aa") == "a77a");
	assert(lucky7s("a") == "a");
	assert(lucky7s("") == "");


    int array[5] = { 2, 4, 6, 8, 10 };
    assert(combinations(array, 5, 10) == true);
    assert(combinations(array, 5, 18) == true);
    assert(combinations(array, 5, 15) == false);

    int other[5] = { 10, 8, 2, 6, 4 };
    assert(combinations(other, 5, 10) == true);
    assert(combinations(other, 5, 18) == true);
    assert(combinations(other, 5, 15) == false);

    cout << "all tests passed!" << endl;
    return(0);
}
