#include <iostream>
#include <optional>
#include <vector>
#include <array>

class FirstNRepeatingStream {
public:
    FirstNRepeatingStream(int N) {
        if (N > 0)
            this->m_N = N;
        else {
            std::cout << "Inappropriate N" << std::endl;
            std::abort();
        }
    }
    std::optional<char> next(char c) {
        // Put
        bool incremented {false};
        for(auto& [ch,count] : tracker) {
            if (ch == c) {
                count++;
                incremented = true;
                break;
            }
        }
        if (!incremented)
            tracker.emplace_back(c, 1);

        // Lookup
        for(auto& [ch,count] : tracker) {
            if (count <= m_N)
                return ch;
        }

        return std::nullopt;
    }
private:
    int m_N;
    std::vector<std::pair<char,int>> tracker;
};

bool Test() {
    const std::array<char, 8> N1_inputs {'a', 'b', 'b', 'c', 'a', 'c', 'f', 'g'};
    const std::array<char, 14> N2_inputs {'b', 'c', 'f', 'b', 'f', 'c', 'b', 'c', 'c', 'f', 'c', 'c', 'b', 'b'};

    const std::array<std::optional<char>, 8> N1_outputs {'a', 'a', 'a', 'a', 'c', std::nullopt, 'f', 'f'};
    const std::array<std::optional<char>, 14> N2_outputs {'b', 'b', 'b', 'b', 'b', 'b', 'c', 'f', 'f',
                    std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt};

    FirstNRepeatingStream t1(1);
    for(size_t i(0); i < N1_inputs.size(); i++) {
        if (t1.next(N1_inputs[i]) != N1_outputs[i])
            return false;
    }

    FirstNRepeatingStream t2(2);
    for(size_t i(0); i < N2_inputs.size(); i++) {
        if (t2.next(N2_inputs[i]) != N2_outputs[i])
            return false;
    }

    return true;
}


int main() {

    std::cout << std::boolalpha << "Result: " << Test() << std::endl;

    std::optional<char> op1{'a'};
    std::cout << *op1 << std::endl;
    std::cout << *std::optional<int>(op1) << std::endl;     // Convert copy constructable

    return 0;
}