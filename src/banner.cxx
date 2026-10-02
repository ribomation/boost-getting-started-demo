// Compiled Boost library: command-line parsing via Boost.Program_options.
#include <boost/program_options.hpp>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    auto options = po::options_description("Usage: banner [options] <message>");
    options.add_options()
        ("help,h",                                       "show this help")
        ("count,n", po::value<int>()->default_value(1),  "number of repetitions")
        ("upper,u",                                      "print in upper case")
        ("message", po::value<std::string>()->required(), "the text to print");

    auto positional = po::positional_options_description();
    positional.add("message", 1);

    auto args = po::variables_map();
    try {
        po::store(po::command_line_parser(argc, argv)
                      .options(options).positional(positional).run(), args);
        if (args.contains("help")) {
            std::cout << options << "\n";
            return 0;
        }
        po::notify(args);  // throws if a required option is missing
    } catch (po::error const& err) {
        std::cerr << "error: " << err.what() << "\n" << options << "\n";
        return 1;
    }

    auto message = args["message"].as<std::string>();
    if (args.contains("upper"))
        std::ranges::transform(message, message.begin(),
                               [](unsigned char ch) { return std::toupper(ch); });

    for (auto k = 0; k < args["count"].as<int>(); ++k)
        std::cout << message << "\n";
}
