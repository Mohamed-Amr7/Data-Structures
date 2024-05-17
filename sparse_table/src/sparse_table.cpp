#include "sparse_table.h"

template<typename T>
SparseTable<T>::SparseTable(const std::vector<T> &values, std::function<T(T, T)> op) : operation(op) {
    build(values);
}

template<typename T>
void SparseTable<T>::build(const std::vector<T> &values) {
    n = values.size();
    P = std::floor(std::log2(n));
    dp.assign(P + 1, std::vector<T>(n));
    log2.assign(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        log2[i] = log2[i / 2] + 1;
    }

    for (int i = 0; i < n; ++i) {
        dp[0][i] = values[i];
    }

    for (int i = 1; i <= P; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            dp[i][j] = operation(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
        }
    }
}

template<typename T>
T SparseTable<T>::query(int l, int r) const {
    if (l < 0 || r >= n || l > r) {
        throw std::out_of_range("Invalid range for query");
    }
    int p = log2[r - l + 1];
    T result = dp[p][l];
    l += (1 << p);
    for (p = log2[r - l + 1]; l <= r; p = log2[r - l + 1]) {
        result = operation(result, dp[p][l]);
        l += (1 << p);
    }
    return result;
}