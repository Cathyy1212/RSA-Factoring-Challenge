#include "factors.h"
#include <iostream>
#include <fstream>
#include <cmath>

std::vector<std::pair<int, int>> factorize(int num) {
    std::vector<std::pair<int, int>> factor_pairs;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
	    factor_pairs.emplace_back(i, num / i);
        }
    }
    return factor_pairs;
}

void factorize_file(const std::string& file_path) {
    std::ifstream input_file(file_path);
    if (!input_file) {
        std::cerr << "Failed to open the file: " << file_path << std::endl;
        return;
    }

    int number;
    while (input_file >> number) {
        std::vector<std::pair<int, int>> factor_pairs = factorize(number);
        for (const auto& factor : factor_pairs)
        {
            std::cout << number << " = " << factor.first << " * " << factor.second << std::endl;
        }
    }
}
