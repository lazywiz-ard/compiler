
#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string &str) {
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

int main() {
    string statement;
    cout << "Enter the statement: ";
    getline(cin, statement);

    cout << "The entered statement was: " << statement << endl;

    vector<string> tokens;
    string temp = "";

    for (int i = 0; i < statement.size(); ++i) {
        if (statement[i] == ' ') {
            continue;
        }
        
        if (statement[i] == '=' || statement[i] == '*' || statement[i] == '/' || 
            statement[i] == '+' || statement[i] == '-' || statement[i] == ';') {
            if (!temp.empty()) {
                tokens.push_back(temp);
                temp = "";
            }
            tokens.push_back(string(1, statement[i]));
        } else {
            temp += statement[i];
        }
    }
    
    if (!temp.empty()) {
        tokens.push_back(temp);
    }

    cout << "Tokens: ";
    for (const auto& token : tokens) {
        cout << token << " ";
    }
    cout << endl;

    for (const auto& token : tokens) {
        if (!isdigit(token[0])) {
            cout << token << " is a valid variable (first letter is not a digit)." << endl;
        } else {
            cout << token << " is invalid (starts with a digit)." << endl;
        }
    }

    return 0;
}
