#include <string>
#include <iostream>
#include <list>
#include <algorithm>

std::string squashParent(const std::string& filePath) {
    std::string ret = filePath;
    while (true) {
        const std::string parentSymbol = "/../";
        const std::size_t parentPosition = ret.find(parentSymbol);
        const std::size_t squashedPosition = ret.rfind("/", parentPosition - 1);
        if (parentPosition == std::string::npos) {
            return ret;
        } else {
            if (squashedPosition == std::string::npos) {
                // e.g. "aaa/../bbb.txt"
                ret.erase(0, parentPosition + parentSymbol.length());
            } else {
                // e.g. "aaa/bbb/../ccc.txt"
                ret.erase(squashedPosition + 1, parentPosition - squashedPosition + parentSymbol.length() - 1);
            }
        }
    }
}

int main(void) {
    std::list<std::pair<std::string, std::string>> ioPairs {
        {"aaa/bbb/../ccc.html", "aaa/ccc.html"},
        {"aaa/bbb/../../ccc.html", "ccc.html"},
        {"aaa/../ccc.html", "ccc.html"},
        {"../ccc.html", "../ccc.html"},
        {"a/b/../d/../ccc.html", "a/ccc.html"},
        {"a/b/../../../ccc.html", "../ccc.html"},
    };
    for (const auto& ioPair : ioPairs) {
        std::cout << ioPair.first << "," << squashParent(ioPair.first) << " : ";
        if (squashParent(ioPair.first) == ioPair.second)
            std::cout << "true" << std::endl;
        else
            std::cout << "false" << std::endl;
    }
}

