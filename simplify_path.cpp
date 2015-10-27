//
// Created by manfred on 10/27/2015.
//
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> elements;
        if(path[path.size() - 1] != '/')
            path += "/";

        string _element;
        for (int i = 0; i < path.size(); ++i) {
            char c = path[i];

            if (c == '/') {
                if (_element.size() == 0 || _element == ".") {
                    _element.clear();
                    continue;
                }

                if (_element == "..") {
                    if(elements.size() != 0)
                        elements.pop();
                    _element.clear();
                    continue;
                }

                elements.push(_element);
                cout << _element << endl;
                _element.clear();
            }
            else
                _element += c;
        }

        if(elements.size() == 0)
            return "/";

        string result;
        while (elements.size() != 0) {
            result = string("/") + elements.top() + result;
            elements.pop();
        }


        return result;
    }
};

int main() {
    Solution s;

    string path = "/.";
    string result = s.simplifyPath(path);

    cout << result << endl;
}
