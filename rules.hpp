#ifndef RULES_HPP
#define RULES_HPP

class Rules {
    public:
        bool horizontalCheck(int[20][20]);
        bool verticalCheck(int[20][20]);
        bool diagonalCheck1(int[20][20]);
        bool diagonalCheck2(int[20][20]);
        bool fullCheck(int[20][20]);
};
#endif // RULES_HPP
