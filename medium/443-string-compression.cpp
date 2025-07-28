// 443. String Compression
// https://leetcode.com/problems/string-compression/

#include <vector>
#include <string>

class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        int write = 0; // Position d'écriture dans le tableau
        int i = 0;     // Position de lecture

        while (i < chars.size())
        {
            char currentChar = chars[i];
            int count = 0;

            // Compter combien de fois le caractère apparaît d'affilée
            while (i < chars.size() && chars[i] == currentChar)
            {
                i++;
                count++;
            }

            // Écrire le caractère
            chars[write++] = currentChar;

            // Si le caractère apparaît plus d'une fois, écrire le nombre
            if (count > 1)
            {
                std::string countStr = std::to_string(count);
                for (char digit : countStr)
                {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};