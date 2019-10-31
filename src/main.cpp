#include "string_matching/kmp.hpp"
#include "string_matching/rabin_karp.hpp"
#include "string_matching/utils.hpp"
#include <fstream>
#include <iostream>
#include <list>
#include <string>

int main(int, char **)
{
    std::ifstream in("input.dat");
    std::ofstream out("output.dat");

    int n_test = 1;

    INIT_PERF;

    in.peek();

    while (!in.eof()) {
        std::string text;
        std::string pattern;

        in >> text;
        in >> pattern;

        std::cout << "Test no. " << n_test << '\n';
        std::cout << "Text: \"" << text << "\"\n"
                  << "Pattern: \"" << pattern << "\"\n";

        out << "Test no. " << n_test << '\n';
        out << "Text: \"" << text << "\"\n"
            << "Pattern: \"" << pattern << "\"\n";

        ++n_test;

        if (!string_matching::is_unique_characters(pattern, pattern.length())) {
            std::cout << "Test error: string \"" << pattern << "\" contains non-unique characters.\n\n";
            out << "Test error: string \"" << pattern << "\" contains non-unique characters.\n\n";
            continue;
        }

        std::list<int> rk_shifts;
        std::list<int> kmp_shifts;

        PERF(rk_shifts = string_matching::rabin_karp_matching((char *)text.c_str(), (char *)pattern.c_str()), "Rabin-Karp matching");
        out << "Rabin-Karp matching running time:\t" << 1000.0 * c_end / CLOCKS_PER_SEC << " ms\n\n";
        PERF(kmp_shifts = string_matching::kmp_matching((char *)text.c_str(), (char *)pattern.c_str()), "KMP matching");
        out << "KMP matching running time:\t" << 1000.0 * c_end / CLOCKS_PER_SEC << " ms\n\n";

        std::cout << "Rabin-Karp shifts:\n";
        out << "Rabin-Karp shifts:\n";

        for (auto it : rk_shifts) {
            std::cout << it << ' ';
            out << it << ' ';
        }

        std::cout << "\n\n";
        out << "\n\n";

        std::cout << "KMP shifts:\n";
        out << "KMP shifts:\n";

        for (auto it : kmp_shifts) {
            std::cout << it << ' ';
            out << it << ' ';
        }

        std::cout << "\n\n";
        out << "\n\n";

        if (rk_shifts == kmp_shifts) {
            std::cout << "Shifts are equal!\n\n";
            out << "Shifts are equal!\n\n";
        } else {
            std::cout << "Shifts are not equal!\n\n";
            out << "Shifts are not equal!\n\n";
        }
    }
}
