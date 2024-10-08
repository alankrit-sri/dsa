#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'longestCommonSubsequence' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    vector<int> lcs;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for(int row = 1; row <= a.size(); ++row)
    {
        for(int col = 1; col <= b.size(); ++col)
        {
            if(a[row - 1] == b[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }
            else {
                dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
            }
        }
    }

    int row = a.size();
    int col = b.size();

    while(row > 0 && col > 0)
    {
        if((dp[row][col] == dp[row - 1][col - 1] + 1) && (a.at(row - 1) == b.
at(col - 1)))
        {
            lcs.push_back(a.at(row - 1));
            --row;
            --col;
        }
        else if(dp[row][col] == dp[row][col - 1])
            --col;
        else if(dp[row][col] == dp[row - 1][col])
            --row;
    }
    
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(
first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
