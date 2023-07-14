#include <iostream>
#include <ios>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    auto line = std::move([](istream& in){
        string s;
        in >> s;
        in.ignore();

        list<char> ret(s.begin(), s.end());
        ret.push_back('\0');

        return ret;
    }(cin));

    auto end = line.begin();
    advance(end, line.size() - 1);

    int n_commands;
    cin >> n_commands;
    cin.ignore();

    auto cursor = end;
    char c;

    for(int i = 0; i != n_commands; ++i) {
        cin >> c;

        if (c == 'L') {
            if (cursor != line.begin())
                --cursor;
        }
        else if (c == 'D') {
            if (cursor != end)
                ++cursor;
        }
        else if (c == 'B') {
            if (cursor != line.begin())
                cursor = line.erase(--cursor);
        }
        else {
            cin >> c;

            if (cursor == line.begin()) line.push_front(c);
            else line.insert(cursor, c);
        }

        cin.ignore();
    }

    string sout(line.begin(), end);
    cout << sout << endl;
    return 0;
}
