// Header-only Boost: a sliding window over the input, via Boost.Circular_buffer.
#include <boost/circular_buffer.hpp>
#include <iostream>
#include <numeric>
#include <string>

auto average(boost::circular_buffer<double> const& window) -> double {
    return std::accumulate(window.begin(), window.end(), 0.0) / window.size();
}

int main(int argc, char* argv[]) {
    auto const capacity = argc > 1 ? std::stoul(argv[1]) : 3UL;
    auto window = boost::circular_buffer<double>(capacity);

    auto value = 0.0;
    while (std::cin >> value) {
        window.push_back(value);  // when full, the oldest value is dropped
        std::cout << "[";
        for (auto x : window) std::cout << " " << x;
        std::cout << " ] avg=" << average(window) << "\n";
    }
}
