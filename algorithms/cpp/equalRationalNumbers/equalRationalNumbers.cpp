// Source: https://leetcode.com/problems/equal-rational-numbers/
// Author: Miao Zhang
// Date:   2021-03-30

/*********************************************
 * 0.5(25)
 *   n  r
 * sum = n / 10 ** len(n) + r / (10 ** len(r) - 1) / 10 ** len(n)
*********************************************/
class Fraction {
public:
    Fraction(long n = 0, long d = 1) {
        long g = __gcd(n, d);
        n_ = n / g;
        d_ = d / g;
    }
    
    Fraction operator+(const Fraction& o) const {
        return Fraction(n_ * o.d_ + d_ * o.n_, d_ * o.d_);
    }
    
    bool operator==(const Fraction& o) const {
        return this->n_ * o.d_ == this->d_ * o.n_;
    }

private:
    long n_;
    long d_;
};


class Solution {
public:
    bool isRationalEqual(string s, string t) {
        auto convert = [](string s) {
            std::regex re("(\\d+)\\.?(\\d+)?(\\((\\d+)\\))?");
            std::smatch matches;
            std::regex_match(s, matches, re);
            string int_part = matches[1].str();
            string nr_part = matches[2].str();
            string r_part = matches[4].str();
            
            Fraction f(stoi(int_part), 1);
            const int base = pow(10, nr_part.length());
            if (nr_part.length()) {
                f = f + Fraction(stoi(nr_part), base);
            }
            if (r_part.length()) {
                f = f + Fraction(stoi(r_part), (pow(10, r_part.length()) - 1) * base);
            }
            return f;
        };
        
        return convert(s) == convert(t);
    }
};
