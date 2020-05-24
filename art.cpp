#include "art.h"

namespace AsciiArt
{
    std::string Art::getAsciiChar(char character)
    {
        if (character == '!')
            return exclamationMark;
        else if (character == '#')
            return hashtag;
        else if (character == '$')
            return dollar;
        else if (character == '%')
            return percent;
        else if (character == '&')
            return ampersand;
        else if (character == '(')
            return bracket1;
        else if (character == ')')
            return bracket2;
        else if (character == '+')
            return plus;
        else if (character == '/')
            return forwardslash;
        else if (character == ':')
            return colon;
        else if (character == '<')
            return smaller;
        else if (character == '=')
            return equals;
        else if (character == '>')
            return greater;
        else if (character == '?')
            return questionmark;
        else if (character == 'A')
            return A;
        else if (character == 'B')
            return B;
        else if (character == 'C')
            return C;
        else if (character == 'D')
            return D;
        else if (character == 'E')
            return E;
        else if (character == 'F')
            return F;
        else if (character == 'G')
            return G;
        else if (character == 'H')
            return H;
        else if (character == 'I')
            return I;
        else if (character == 'J')
            return J;
        else if (character == 'K')
            return K;
        else if (character == 'L')
            return L;
        else if (character == 'M')
            return M;
        else if (character == 'N')
            return N;
        else if (character == 'O')
            return O;
        else if (character == 'P')
            return P;
        else if (character == 'Q')
            return Q;
        else if (character == 'R')
            return R;
        else if (character == 'S')
            return S;
        else if (character == 'T')
            return T;
        else if (character == 'U')
            return U;
        else if (character == 'V')
            return V;
        else if (character == 'W')
            return W;
        else if (character == 'X')
            return X;
        else if (character == 'Y')
            return Y;
        else if (character == 'Z')
            return Z;
        else if (character == '[')
            return sqauareBracket1;
        else if (character == '\\')
            return backslash;
        else if (character == ']')
            return squareBracket2;
        else if (character == '^')
            return caret;
        else if (character == 'a')
            return a;
        else if (character == 'b')
            return b;
        else if (character == 'c')
            return c;
        else if (character == 'd')
            return d;
        else if (character == 'e')
            return e;
        else if (character == 'f')
            return f;
        else if (character == 'g')
            return g;
        else if (character == 'h')
            return h;
        else if (character == 'i')
            return i;
        else if (character == 'j')
            return j;
        else if (character == 'k')
            return k;
        else if (character == 'l')
            return l;
        else if (character == 'm')
            return m;
        else if (character == 'n')
            return n;
        else if (character == 'o')
            return o;
        else if (character == 'p')
            return p;
        else if (character == 'q')
            return q;
        else if (character == 'r')
            return r;
        else if (character == 's')
            return s;
        else if (character == 't')
            return t;
        else if (character == 'u')
            return u;
        else if (character == 'v')
            return v;
        else if (character == 'w')
            return w;
        else if (character == 'x')
            return x;
        else if (character == 'y')
            return y;
        else if (character == 'z')
            return z;
        else if (character == '~')
            return tilde;
        else
            return space;
    }
    std::string Art::getAsciiString(std::string toAscii)
    {
        std::vector<std::string> firstChar;
        std::vector<std::string> addToFirst;
        std::vector<std::string> finalAscii;

        std::istringstream input(getAsciiChar(toAscii[0]));
        std::string line;
        while (std::getline(input, line))
        {
            line.pop_back();//delete \n from the back off the ascii art
            line.pop_back();
            firstChar.push_back(line);
        }
        finalAscii = firstChar;
        std::string artString = "";
        if (toAscii.length() > 1)
        {

            for (int ii = 1; ii < static_cast<int>(toAscii.length()); ii++)
            {
                std::istringstream input2(getAsciiChar(toAscii[ii]));
                std::string line2;
                while (std::getline(input2, line2))
                {
                    addToFirst.push_back(line2);
                }
                while (addToFirst.size() > finalAscii.size())
                {
                    //if letter 2 is taller than letter 1 add spaces at letter 1 to make it the same size
                    std::string spaces = "";
                    for (int artlength = 0; artlength < static_cast<int>(finalAscii[1].length()); artlength++)
                    {
                        spaces.append(" ");
                    }
                    std::reverse( finalAscii.begin(), finalAscii.end() );
                    finalAscii.push_back(spaces);
                    std::reverse( finalAscii.begin(), finalAscii.end() );

                }
                while (addToFirst.size() < finalAscii.size())
                {
                    //if letter 1 is taller than letter 2 add spaces at letter 2 to make it the same size
                    std::string spaces = "";
                    for (int artlength = 0; artlength < static_cast<int>(addToFirst[1].length()); artlength++)
                    {
                        spaces.append(" ");
                    }
                    std::reverse( addToFirst.begin(), addToFirst.end() );
                    addToFirst.push_back(spaces);
                    std::reverse( addToFirst.begin(), addToFirst.end() );
                }

                for (int char2length = 0; char2length < static_cast<int>(finalAscii.size()); char2length++)
                {
                    //add spaces after each letter line
                    finalAscii[char2length].append(" " + addToFirst[char2length]);
                }
                addToFirst.clear();
            }
            for (int addedlength = 0; addedlength < static_cast<int>(finalAscii.size()); addedlength++)
            {
                //add new line at end of each letter line
                artString.append(finalAscii[addedlength]);
                artString.append("\n");
            }
        }

        return artString;
    }

} // namespace AsciiArt