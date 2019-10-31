#pragma once
#include <cstring>
#include <list>

namespace string_matching
{
    std::list<int> naive_matcher(char *text, char *pattern)
    {
        std::list<int> shifts;

        int text_length = std::strlen(text);
        int pattern_length = std::strlen(pattern);

        // ?
        for (int i = 0; i <= text_length - pattern_length; ++i) {
            bool is_valid_shift = true;

            for (int j = 0; j < pattern_length; ++j) {
                if (text[i + j] != pattern[j]) {
                    is_valid_shift = false;
                    break;
                }
            }

            if (is_valid_shift) {
                shifts.push_back(i);
            }
        }

        return shifts;
    }
} // namespace string_matching
