#pragma once
#include <exception>
#include <set>
#include <vector>
#include <ctime>

#define INIT_PERF clock_t c_start, c_end;

#define PERF(statement, message)    \
    c_start = std::clock();         \
    statement;                      \
    c_end = std::clock() - c_start; \
    std::cout << message << " running time:\t\t" << 1000.0 * c_end / CLOCKS_PER_SEC << " ms\n";

namespace string_matching
{
    const long long HASH_CONSTRAINT = 9223372036854775807;
    const int DEFAULT_P = 257;
    const int ALPHABET_CAPACITY = 256;

    std::vector<long long> generate_p_pows(int count, int p = DEFAULT_P)
    {
        std::vector<long long> p_pows(count);

        if (count == 0)
            return p_pows;

        p_pows[0] = 1;

        for (int i = 1; i < count; ++i) {
            p_pows[i] = p_pows[i - 1] * p;
        }

        return p_pows;
    }

    template <typename T>
    long long calculate_hash(T item, size_t length, std::vector<long long> &p_pows)
    {
        if (p_pows.size() < length) {
            throw std::out_of_range("p_pows");
        }

        long long acc = 0;

        for (size_t i = 0; i < length; ++i) {
            acc += (p_pows[i] * item[i]) % HASH_CONSTRAINT;
        }

        return acc;
    }

    template <typename T>
    std::vector<int> prefix_function(T item, int length)
    {
        if (length <= 0) {
            throw std::invalid_argument("length");
        }

        std::vector<int> p(length);
        p[0] = 0;

        for (int i = 1; i < length; ++i) {
            int k = p[i - 1];

            while (k > 0 && item[i] != item[k]) {
                k = p[k - 1];
            }

            if (item[i] == item[k]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    bool is_unique_characters(const char *text, int length)
    {
        if (length > ALPHABET_CAPACITY) {
            return false;
        }

        std::set<char> entries;

        for (int i = 0; i < length; ++i) {
            if (entries.find(text[i]) != entries.end())  {
                return false;
            }

            entries.insert(text[i]);
        }

        return true;
    }

    bool is_unique_characters(std::string &text, int length)
    {
        return is_unique_characters(text.c_str(), length);
    }

} // namespace string_matching
