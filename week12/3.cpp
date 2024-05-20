#include <iostream>
#include <algorithm>
class Deal {
public:
    long long int n[3][1000001];
    long long int df[3][1000001];
    long long int N;

    Deal(long long int _N) {
        N = _N;
        for (long long int i = 0; i < 3; i++) {
            for (long long int j = 0; j < N; j++) {
                scanf("%lld", &(n[i][j]));
            }
        }
    }

    void solve() {
        df[0][0] = 0;
        df[1][0] = 0;
        df[2][0] = 0;
        for (long long int i = 1; i < N; i++) {
            for (long long int j = 0; j < 3; j++) {
                df[j][i] = std::min({df[0][i - 1] + abs(n[j][i] - n[0][i - 1]),
                                df[1][i - 1] + abs(n[j][i] - n[1][i - 1]),
                                df[2][i - 1] + abs(n[j][i] - n[2][i - 1])});
            }
        }

        long long int result = std::min({df[0][N - 1], df[1][N - 1], df[2][N - 1]});
        printf("%lld\n", result);
    }
};

int main() {
    long long int N;
    scanf("%lld", &N);
    Deal solver(N);
    solver.solve();

    return 0;
}