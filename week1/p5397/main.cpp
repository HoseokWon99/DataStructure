#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <list>

using namespace std;

string extractPassword(const string&);

int main() {
    ios::sync_with_stdio(false);

    vector<string> passwords;

    passwords.reserve([](istream& in){
        vector<string>::size_type n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

    string tmp;

    for (vector<string>::size_type i = 0; i != passwords.capacity(); ++i) {
        cin >> tmp;
        passwords.emplace_back(std::move(extractPassword(tmp)));
        cin.ignore();
    }

    for (const auto& password : passwords) {
        cout << password << '\n';
    }

    cout << endl;
    return 0;
}

string extractPassword(const string& sin) {
    list<char> line;
    line.push_back('\0');

    auto end = line.begin();
    auto cursor = end;

    for (char c : sin) {

        if (c == '<') {
            if (cursor != line.begin())
                --cursor;
        }
        else if (c == '>') {
            if (cursor != end)
                ++cursor;
        }
        else if (c == '-') {
            if (cursor != line.begin())
                cursor = line.erase(--cursor);
        }
        else {
            if (cursor == line.begin())
                line.push_front(c);
            else
                line.insert(cursor, c);
        }

    }

    return string(line.begin(), end);
}
