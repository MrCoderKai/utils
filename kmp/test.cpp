#include <iostream>
#include <string>
#include "kmp.h"

int main()
{
    std::string str("abaabaabbabaaabaabbabaab");
    std::string pattern("abaabbabaab");
    ck_utils::kmp m_kmp(str, pattern);
    m_kmp.match();
    m_kmp.printMatch();
    
    str = "abababababababa";
    pattern = "aba";
    m_kmp.setStr(str);
    m_kmp.setPattern(pattern);
    m_kmp.match();
    m_kmp.printMatch();
}
