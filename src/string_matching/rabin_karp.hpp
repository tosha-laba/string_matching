#pragma once
#include "utils.hpp"
#include <list>
#include <vector>

namespace string_matching
{
    std::list<int> rabin_karp_matching(char *text, char *pattern)
    {
        std::list<int> shifts;

        int text_length = std::strlen(text);
        int pattern_length = std::strlen(pattern);

        if (text_length < pattern_length)
            return shifts;

        std::vector<long long> p_pows = generate_p_pows(text_length);

        long long text_hash = calculate_hash(text, pattern_length, p_pows);
        long long pattern_hash = calculate_hash(pattern, pattern_length, p_pows);

        for (int i = 0; i <= text_length - pattern_length; ++i) {
            if (text_hash == pattern_hash) {
                shifts.push_back(i);
            }

            long long decreasing_prefix = text[i];
            long long increasing_suffix = (p_pows[pattern_length - 1] * text[i + pattern_length]) % HASH_CONSTRAINT;

            text_hash = ((text_hash - decreasing_prefix) / DEFAULT_P + increasing_suffix) % HASH_CONSTRAINT;
        }

        return shifts;
    }
} // namespace string_matching
