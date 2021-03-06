#pragma once
#include "utils.hpp"
#include <list>

namespace string_matching
{
    std::list<int> kmp_matching(char *text, char *pattern)
    {
        std::list<int> shifts;

        int text_length = std::strlen(text);
        int pattern_length = std::strlen(pattern);

        std::string preproduce = std::string(pattern) + "\a" + text;

        std::vector<int> max_borders = prefix_function(preproduce, preproduce.length());

        for (int i = 0; i < text_length; ++i) {
            if (max_borders[pattern_length + i + 1] == pattern_length) {
                shifts.push_back(i - pattern_length + 1);
            }
        }

        return shifts;
    }

} // namespace string_matching
