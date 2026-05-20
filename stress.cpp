#include <iostream>
#include <sstream>

using namespace std;

namespace Gen {
    void generate() {
    }
}

int brute() {
    int n; cin>>n;
    int sm=0;
    for (int i=0; i<n; i++) {
        int v; cin>>v;
        sm+=v;
    }
    return sm;
}

int solve() {
    int n; cin>>n;
    int sm=0;
    for (int i=0; i<n; i++) {
        int v; cin>>v;
        sm+=v;
    }
    return sm;
}

void stress() {
    int test_cases=0;
    streambuf* original_cin = cin.rdbuf();
    streambuf* original_cout = cout.rdbuf();

    while (true) {
        test_cases++;

        stringstream ss_test;
        cout.rdbuf(ss_test.rdbuf());
        Gen::generate();
        string tc_string=ss_test.str();
        cout.rdbuf(original_cout);

        // void return type
        // stringstream ss_in_slow(tc_string);
        // ostringstream ss_out_slow;
        // cin.rdbuf(ss_in_slow.rdbuf());
        // cout.rdbuf(ss_out_slow.rdbuf());
        // brute();
        // auto slow_ans=ss_out_slow.str();
        //
        // stringstream ss_in_fast(tc_string);
        // ostringstream ss_out_fast;
        // cin.rdbuf(ss_in_fast.rdbuf());
        // cout.rdbuf(ss_out_fast.rdbuf());
        // solve();
        // auto fast_ans=ss_out_fast.str();

        // non-void return type
        stringstream ss_slow(tc_string);
        cin.rdbuf(ss_slow.rdbuf());
        auto slow_ans=brute();

        stringstream ss_fast(tc_string);
        cin.rdbuf(ss_fast.rdbuf());
        auto fast_ans=solve();

        if (slow_ans != fast_ans) {
            cin.rdbuf(original_cin);
            cout << "Wrong Answer found on Test " << test_cases << "!\n";
            cout << "--- Input ---\n" << tc_string;
            cout << "--- Slow Output ---\n" << slow_ans << "\n";
            cout << "--- Fast Output ---\n" << fast_ans << "\n";
            break;
        }

        if (test_cases % 1000 == 0) {
            cin.rdbuf(original_cin);
            cout << test_cases << " tests passed...\n";
        }
    }
    cin.rdbuf(original_cin);
}
