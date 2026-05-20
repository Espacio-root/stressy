#pragma once

#include <iostream>
#include <chrono>
#include <random>
#include <sstream>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace Gen {
    long long rand_int(long long l, long long r) {
        return uniform_int_distribution<long long>(l,r)(rng);
    }

    vector<long long> gen_array(int min_n, int max_n, long long min_val, long long max_val) {
        int n=(min_n==max_n?min_n:rand_int(min_n,max_n));
        vector<long long> a(n);
        for (int i=0; i<n; i++) {
            a[i]=rand_int(min_val,max_val);
        }
        return a;
    }

    string gen_string(int min_n, int max_n, const string& alphabet = "abcdefghijklmnopqrstuvwxyz") {
        int n=(min_n==max_n?min_n:rand_int(min_n,max_n));
        string s="";
        for (int i=0; i<n; i++) s+=alphabet[rand_int(0,alphabet.length()-1)];
        return s;
    }
}

namespace GenGraph {
    string random_tree(int n) {
        stringstream ss;
        ss<<n<<'\n';
        for (int u=2; u<=n; u++) {
            int v=Gen::rand_int(1, u-1);
            if (Gen::rand_int(0, 1)) swap(u, v);
            ss<<u<<' '<<v<<'\n';
        }
        return ss.str();
    }
}

namespace Gen {
    void generate() {
        int n=Gen::rand_int(1,1000);
        cout<<n<<'\n';
    }
}

int main() {
    return 0;
}
