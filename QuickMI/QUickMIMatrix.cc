






struct Matrix {
    int n, m;
    Matrix(int n = 0, int m = 0, const vector<vector<int> >& vec_ = vector<vector<int> >()) : vec(vec_) {}
    vector<vector<int> > vec;
};

//vector<vector<int> > vec(n, vector<int>(m, 0));

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    //if (lhs.m != rhs.n) { cuo la };
    int n = lhs.n, m = rhs.m, r = lhs.m;
    vector<vector<int> > result(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++ j) {
            for (int k = 0; k < r; ++k) {
                result[i][j] += lhs.vec[i][r] * rhs.vec[r][j]; // % MOD;
            }
        }
    }
    return Matrix(n, m, result);
}


int main() {
    Matrix a = b;
    
}