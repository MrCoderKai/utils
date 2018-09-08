#ifndef _UTILS_KMP_H_
#define _UTILS_KMP_H_
#include <vector>
#include <string>

namespace ck_utils{
    class kmp{
        public:
            kmp(){}
            kmp(std::string& m_Str, std::string& m_sPattern);
            void setStr(std::string& str);
            void setPattern(std::string& str);
            void match();
            size_t getMatchNumber();
            void printMatch();
        private:
            void getNext();
            std::string m_Str;
            std::string m_sPattern;
            // m_next中的元素表示，以第i个字符结尾的后缀与m_Str的前缀最长的相同长度的结束位置。
            // 这个位置从0开始标号。
            std::vector<int> m_next;
            // 匹配的起始位置，位置从0开始标号。
            std::vector<int> m_matchIndex;
    };
}
#endif
