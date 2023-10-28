#include <bits/stdc++.h>
using namespace std;

// Function to delete pair of adjacent
// characters which are equal
string removeAdjacent(string s)
{
	
	// Base Case
	if (s.length() == 1)
		return s;

	// Stores the update string
	string sb = "";

	// Traverse the string s
	for(int i = 0; i < s.length() - 1; i++)
	{
		char c = s[i];
		char d = s[i + 1];

		// If two unequal pair of
		// adjacent characters are found
		if (c != d)
		{
			sb = sb + c;

			if (i == s.length() - 2)
			{
				sb = sb + d;
			}
		}

		// If two equal pair of adjacent
		// characters are found
		else
		{
			for(int j = i + 2;
					j < s.length(); j++)

				// Append the remaining string
				// after removing the pair
				sb = sb + s[j];

			return sb;
		}
	}

	// Return the final String
	return sb;
}

// Function to find the shortest string
// after repeatedly removing pairs of
// adjacent characters which are equal
void reduceString(string s)
{
	
	// Stores the resultant String
	string result = "";

	// Keeps track of previously
	// iterated string
	string pre = s;

	while (true)
	{
		
		// Update the result after
		// deleting adjacent pair of
		// characters which are similar
		result = removeAdjacent(pre);
        if(result.size()==0)
        {
            break;
        }
		// Termination Conditions
		if (result == pre)
			break;

		// Update pre variable with
		// the value of result

		pre = result;
	}

	if (result.length() != 0)
		cout << (result) << endl;

	// Case for "Empty String"
	else
		cout << "Empty String" << endl;
}

// Driver code
int main()
{
	string S = "aa";
	
	reduceString(S);
	
	return 0;
}