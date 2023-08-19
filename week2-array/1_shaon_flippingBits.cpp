// https://www.hackerrank.com/challenges/flipping-bits/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {
/*
    Convert decimal to binary string using std::bitset
*/
    // string binary = bitset<32>(n).to_string(); // 32 is the size of n (int)
    bitset<32> binary = bitset<32>(n); // 32 is the size of n (int)
    // cout << binary << '\n';
    
    // string binaryFlipped = bitset<32>(n).flip().to_string(); // 32 is the size of n (int)
    bitset<32> binaryFlipped = bitset<32>(n).flip(); // 32 is the size of n (int)
    // cout << binaryFlipped << ' ' << size(binaryFlipped) << '\n';
    
    // long flippedBits = stoi(binaryFlipped, 0, 10); // error
    long flippedBits = binaryFlipped.to_ulong();
    // cout << flippedBits << '\n';
    
    // return 0;
    return flippedBits;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);
    // cout << q_temp << endl;

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));
        // cout << n << '\n';

        long result = flippingBits(n);
        // cout << result << '\n';

        fout << result << "\n";
    }

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
