#pragma once
#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#define DEBUG_OUTPUT(...) debugger_details::debug_output(#__VA_ARGS__, __VA_ARGS__)

namespace debugger_details
{
    // Make value into string.
    template <typename T>
    std::string make_string(T &t)
    {
        std::stringstream buf;

        buf << t;

        return buf.str();
    }

    // Split the variable names.
    std::vector<std::string> split(std::string const &elements, char const delim)
    {
        std::vector<std::string> split_elements;

        // Like a real C++ programmer, I use iterators.
        for( auto it = elements.begin(); it != elements.end(); ++it )
        {
            std::string element;

            while( *it == delim )
            {   // Just in case there are any extra spaces; fixes formatting.
                ++it;
            }

            do
            {
                element += *it;
                ++it;

                if( it == elements.end() )
                {   // Instead of hitting the deliminator, we hit the end.
                    break;
                }

            } while( *it != delim ); // Don't include delimiter.

            split_elements.push_back(element);

            if( it == elements.end() )
            {
                break;
            }
        }

        return std::move(split_elements);
    }

    // Debug output to cout.
    template <typename ... Args>
    void debug_output(std::string const &n, Args &&... args)
    {
        std::string names = n;

        // #__VA_ARGS__ includes any commas used, so we need to remove them.
        names.erase(std::remove(names.begin(), names.end(), ','), names.end());

        // Create a vector of names.
        std::vector<std::string> variable_names = split(names, ' ');

        // Create a vector of values.
        std::vector<std::string> variable_values;

        // Push back each value after converting into a string.
        (variable_values.push_back(make_string(args)), ...); // Fold expression

        if( variable_names.size() != variable_values.size() )
        {   // This shouldn't happen, but it did actually catch a bug.
            std::cout << "WTF?\n";
        }
        else
        {
            // Same size, so do a regular for-loop.
            for( auto i = 0u; i < variable_names.size(); ++i )
            {
                std::cout << variable_names[i] << " = " << variable_values[i];

                if( i + 1 != variable_names.size() )
                {
                    std::cout << ", ";
                }
            }

            std::cout << '\n';
        }
    }
}

#endif