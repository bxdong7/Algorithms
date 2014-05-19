#ifndef LCS_H
#define LCS_H
#include <string>

/*
  find the longest common substring of two strings. The substring does not have to be consecutive, only need to be in the same order in both strings.
  Example: X = ACCGGTCGAGTGCGCGGAAGCCGGCCGAA, Y = GTCGTTCGGAATGCCGTTGCTCTGTAAA, LCS(X, Y) = GTCGTCGGAAGCCGGCCGAA
  complexity: O(mn), m=X.size(), n=Y.size()
*/
std::string LCS (const std::string &X, const std::string &Y);

//help output the longest common substring
std::string LCSAux (const int **c, const std::string &X, const std::string &Y);

//help form the longest common substring
void LCSStr (std::string &s, int i, int j, const int **c, const std::string &X, const std::string &Y);
#endif
