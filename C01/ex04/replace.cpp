/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:06:49 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 17:13:46 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
//istream& getline (char* s, streamsize n, char delim );
//find(const basic_string& __str, size_type __pos = 0) const
//std::string& erase(size_t pos = 0, size_t count = npos);
//std::string& insert(size_t pos, const std::string& str);

Replace::Replace (std::string filename)
{
    this->_infile = filename;
    this->_outfile = filename + ".replace";
};

Replace::~Replace (void)
{
};

void Replace::ft_replace(std::string s1, std::string s2)
{
    std::string input = "";
    std::ifstream ifs(this->_infile.c_str());
    size_t pos;
    if (ifs.is_open())
    {
        if (ifs.good())
        {
            std::getline(ifs, input);
            std::ofstream ofs(this->_outfile.c_str());
            pos = input.find(s1);
            while (pos != std::string::npos)
            {
                input.erase(pos, s1.size());
                input.insert(pos, s2);
                pos = input.find(s1);
            }
            ofs << input;
            ofs.close();
        }
        else
            std::cerr << "empty file!" << std::endl;
        ifs.close();
    }
    else
    {
        std::cerr << "can not open the file!" << std::endl;
        exit (1);
    }
}