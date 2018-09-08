#include <iostream>
#include <string>
#include "kmp.h"

ck_utils::kmp::kmp(std::string& str, std::string& pattern) : m_Str(str), m_sPattern(pattern)
{
    m_next.reserve(m_sPattern.size());
    getNext();
}


void ck_utils::kmp::setStr(std::string& str)
{
    m_Str = str;
    m_matchIndex.clear();
}

void ck_utils::kmp::setPattern(std::string& str)
{
    m_sPattern = str;
    getNext();
    m_matchIndex.clear();
}

void ck_utils::kmp::getNext()
{
    int j;
    m_next.clear();
    for(int i = 0; i < m_sPattern.size(); ++i)
        m_next.push_back(-1);
    for(int i = 1; i < m_sPattern.size(); ++i)
    {
        j = m_next[i - 1];
        while(m_sPattern[i] != m_sPattern[j + 1] && j >= 0)
        {
            j = m_next[j];
        }
        if(m_sPattern[j + 1] == m_sPattern[i])
        {
            m_next[i] = j + 1;
        }
        else
        {
            m_next[i] = -1;
        }
    }
}


void ck_utils::kmp::match()
{
    int j = 0;
    int i = 0;
    while(i < m_Str.size())
    {
        if(m_Str[i] == m_sPattern[j])
        {
            ++i;
            ++j;
            if(j == m_sPattern.size())
            {
                m_matchIndex.push_back(i - m_sPattern.size());
                j = m_next[j - 1] + 1;
            }
        }
        else
        {
            if(j == 0)
                ++i;
            else
                j = m_next[j - 1] + 1;
        }
    }
}

size_t ck_utils::kmp::getMatchNumber()
{
    return m_matchIndex.size();
}

void ck_utils::kmp::printMatch()
{
    std::cout << "str     = " << m_Str << std::endl;
    std::cout << "pattern = " << m_sPattern << std::endl;
    std::cout << "m_next  = " << std::endl;
    for(int i = 0; i < m_next.size(); ++i)
    {
        std::cout << m_next[i] << " ";
    }
    std::cout << std::endl;

    if(m_matchIndex.size() == 0)
    {
        std::cout << "No match" << std::endl;
    }
    for(int i = 0; i < m_matchIndex.size(); ++i)
    {
        std::cout << m_matchIndex[i] << " " << std::endl;
    }
}
