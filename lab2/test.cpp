#define _CRT_SECURE_NO_DEPRECATE


#include <iostream>

#include <sstream>

#include <unordered_map>

#include <string>
#include <vector>

#include <cstdint>

#include <fstream>

using namespace std;

#define ASSERT_MSG(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << "." << std::endl; \
            std::cerr << "Error in test: " << message << std::endl; \
            std::abort(); \
        } \
    } while (false)

void solve(std::istream & in = std::cin, std::ostream & out = std::cout) {
    vector<string>names;
    string input;

    while (in >> input) {
        names.push_back(input);
    }

    unordered_map<string, int>reId;

    int8_t lastId = 1;

    for (int i = 0; i < names.size(); i++) {
        if (reId.find(names[i]) == reId.end()) {
            reId[names[i]] = lastId;
            lastId++;
        }

        out << reId[names[i]] << ' ';

    }

    //in >> t;
    //out << t;
}

string run(const std::string & input) {

    stringstream in(input);
    stringstream out;

    solve(in, out);

    return out.str();
}


void test() {

    ifstream file("strings_output.txt");
    ifstream file2("ids_output.txt");

    ifstream file3("strings_output2.txt");
    ifstream file4("ids_output2.txt");

    string big_in((istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>());

    string big_out((istreambuf_iterator<char>(file2)),
        istreambuf_iterator<char>());

    string mini_big_in((istreambuf_iterator<char>(file3)),
        istreambuf_iterator<char>());

    string mini_big_out((istreambuf_iterator<char>(file4)),
        istreambuf_iterator<char>());

    file.close();
    file2.close();
    file3.close();
    file4.close();

    struct {
        string input;
        string expected_return;
    } tests[] = {
        {"grapefruit banana alchohol alchohol banana", "1 2 3 3 2 "},
        {mini_big_in, mini_big_out},
        {big_in, big_out}
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {

        auto t = tests[i];

        string result = run(t.input);

        //cout << result << endl;
        //cout << t.expected_return << endl;

        //cout << (result == t.expected_return) << endl;

        ASSERT_MSG(result == t.expected_return, i + 1);
    }

    cout << "All tests Passed!";

}

int main() {

    test();

    return 0;
}

//