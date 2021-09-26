#ifndef Strings_H
#define Strings_H

#include <string>
#include <vector>

namespace rap {

    std::vector<std::string> splitStr(const std::string &str, const std::string &delimiter);
    std::string toUpper(std::string str);
    std::string getExtension(const std::string &str);

    /* bool isInList(const std::string &item, std::string strings[]); */
}

#endif
