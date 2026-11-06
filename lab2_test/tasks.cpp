#include "tasks.h"

void task2(std::vector<int>& v, std::list<int>& l) {
    if (v.size() < 5 || l.size() < 5) return;
    l.insert(std::next(l.begin(), 5),
        std::make_reverse_iterator(v.begin() + 5),
        std::make_reverse_iterator(v.begin()));
}

void task3(std::deque<int>& d) {
    if (d.size() < 4 || d.size() % 4 != 0) return;
    std::size_t n = d.size();
    auto i = d.begin();
    for (std::size_t k = 0; k < n / 4; ++k) {
        i = d.erase(++i);
    }
}

void task4(const std::vector<double>& v) {
    if (v.size() < 2) return;
    std::size_t idx = 0;
    std::remove_copy_if(v.begin(), v.end(),
    std::ostream_iterator<double>(std::cout, " "),
    [&idx](double) { 
        return idx++ % 2 == 0;
    });
    std::cout << '\n';
}

void task5(std::list<int>& l) {
    auto itNeg = std::find_if(l.begin(), l.end(),
        [](int x) { return x < 0; });
    auto rPos = std::find_if(l.rbegin(), l.rend(),
        [](int x) { return x > 0; });
    if (itNeg == l.end() || rPos == l.rend()) return;
    l.insert(std::next(itNeg), 0);
    l.insert((++rPos).base(), 0);
}

void task6(std::vector<int>& v) {
    if (v.size() < 2 || v.size() % 2 != 0) return;
    auto mid = v.begin();
    std::advance(mid, v.size() / 2);
    std::vector<int> v0(mid, v.end());
    std::remove_copy_if(v0.begin(), v0.end(),
        std::inserter(v, v.begin()),
        [](int x) { return x <= 0; }); 
}

void task7(std::deque<std::string>& d) {
    std::sort(d.begin(), d.end(),
        [](const std::string& a, const std::string& b) {
            if (a.length() != b.length()) return a.length() > b.length();
            return a < b;
        });
}

void task8(const std::list<int>& l, std::vector<double>& v) {
    if (l.empty()) return;
    std::adjacent_difference(l.begin(), l.end(),
        std::back_inserter(v),
        [](int a, int b) { return (a + b) / 2.0; });
    if (!v.empty()) v.erase(v.begin());
}

int task9(const std::vector<int>& v0,
    const std::vector<std::vector<int>>& allV) {
    std::set<int> set0(v0.begin(), v0.end());
    int count = 0;
    for (const auto& vi : allV) {
        std::set<int> setVi(vi.begin(), vi.end());
        if (std::includes(setVi.begin(), setVi.end(),
         set0.begin(), set0.end())) {
            ++count;
        }
    }
    return count;
}

void task10(const std::vector<std::string>& v) {
    std::map<char, std::size_t> m;
    for (auto it = v.begin(); it != v.end(); ++it) {
        m[(*it)[0]] += (*it).size();
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " " << it->second << '\n';
    }
}