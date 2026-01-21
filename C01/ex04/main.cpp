#include <iostream>
#include <fstream>
#include <string>

void    substitute(std::string &line, const std::string &s1, const std::string &s2)
{
    std::size_t s1_len;
    std::size_t i;

    if (line.empty() || s1.empty() || s1 == s2)
        return ;
    s1_len = s1.size();
    i = 0;
    while (1)
    {
        i = line.find(s1);
        if (i == std::string::npos)
            break ;
        line.erase(i, s1_len);
        line.insert(i, s2);
        i += s2.size();
    }
}

int    copy_to_file(const std::string &file_name, const std::string &s1, const std::string &s2)
{
    std::string contents;

    std::ifstream infile(file_name.c_str());
    if (!infile)
    {
        std::cerr << "Error: could not open " << file_name << std::endl;
        return (-1);
    }
    std::ofstream outfile((file_name + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error: could not create " << file_name << ".replace" << std::endl;
        return (-1);
    }
    while (std::getline(infile, contents))
    {
        substitute(contents, s1, s2);
        outfile << contents << '\n';
    }
    std::cout << "Copy completed" << std::endl;
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "expecting 3 args: infile, s1, s2" << std::endl;
        return (0);
    }
	const std::string file_name = argv[1];
    const std::string s1 = argv[2];
	const std::string s2 = argv[3];
    copy_to_file(file_name, s1, s2);
}