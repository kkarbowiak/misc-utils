#include "argparse.h"

#include <iostream>


auto parse_args(int argc, char * argv[])
{
    auto parser = argparse::ArgumentParser().description("Utility that returns given value (or 0) and optionally outputs given text to stdout");
    parser.add_argument("-r", "--return").help("value to return").type<int>().default_(0);
    parser.add_argument("-s", "--say").help("text to output to stdout");

    return parser.parse_args(argc, argv);
}

int main(int argc, char * argv[])
{
    auto const args = parse_args(argc, argv);

    if (auto const say = args.get("say"); say)
    {
        std::cout << say.get() << std::endl;
    }

    if (auto const ret = args.get("return"); ret)
    {
        return ret.get<int>();
    }

    return 0;
}
