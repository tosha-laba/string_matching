#include "string_matching/kmp.hpp"
#include "string_matching/naive.hpp"
#include "string_matching/rabin_karp.hpp"
#include <iostream>
#include <list>

// TODO: Поиск в тексте образца, все символы которого различны.
int main(int, char **)
{
    std::cout << (string_matching::naive_matcher("abcdbcdbcd", "bcd").size()) << std::endl;
    std::cout << (string_matching::rabin_karp_matching("abcdbcdbcd", "bcd").size()) << std::endl;
    std::cout << (string_matching::kmp_matching("abcdbcdbcd", "bcd").size()) << std::endl;
}
