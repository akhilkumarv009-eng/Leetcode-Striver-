#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:

    // expr = term (',' term)*
    set<string> parseExpression(string &s, int &i) {
        set<string> result = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','

            set<string> next = parseTerm(s, i);

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    // term = factor factor factor ...
    set<string> parseTerm(string &s, int &i) {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> factor = parseFactor(s, i);

            set<string> temp;

            // Cartesian product = concatenation
            for (string a : result) {
                for (string b : factor) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    // factor = letter OR {expression}
    set<string> parseFactor(string &s, int &i) {

        set<string> result;

        if (s[i] == '{') {
            i++; // skip '{'

            result = parseExpression(s, i);

            i++; // skip '}'
        }
        else {
            result.insert(string(1, s[i]));
            i++;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parseExpression(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};