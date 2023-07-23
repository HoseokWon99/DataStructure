#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class CStack {

public:
    CStack() : m_data{ nullptr }, m_size{ 0 }, m_capacity{ 2000 } {
        m_data = m_alloc.allocate(m_capacity);
    }

    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    int top() {
        return  empty() ? -1 : m_data[m_size-1];
    }

    void push(int x) {

        if (m_size < m_capacity) {
            m_alloc.construct(m_data + m_size++, x);
        }
        else {
            auto new_data = m_alloc.allocate(2*m_size);

            uninitialized_copy(m_data, m_data+m_size, new_data);
            m_alloc.deallocate(m_data, m_size);

            m_data = new_data;
            m_capacity = 2*m_size;
            m_alloc.construct(m_data + m_size++, x);
        }

    }

    int pop() {

        if (!empty()) {
            int ret = top();
            m_alloc.destroy(m_data + --m_size);
            return ret;
        }

        return -1;
    }

private:
    int* m_data;
    size_t m_size, m_capacity;
    allocator<int> m_alloc;


};


int main() {
    CStack stack;
    vector<int> output;

    int n_commands;
    cin >> n_commands;
    cin.ignore();

    string command;

    for (int i = 0; i != n_commands; ++i) {
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (command == "pop") {
            output.push_back(stack.pop());
        }
        else if (command == "size") {
            output.push_back((int)stack.size());
        }
        else if (command == "empty") {
            output.push_back((int)stack.empty());
        }
        else {
            output.push_back(stack.top());
        }

        cin.ignore();
    }

    for (auto x : output)
        cout << x << '\n';

    cout.flush();
    return 0;
}
