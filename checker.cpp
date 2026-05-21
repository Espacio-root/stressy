#include <iostream>
#include <sstream>

using namespace std;

namespace Gen {
    void generate() {
    }
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

bool checker(string tc_string, string ans, stringstream &feedback) {
    stringstream ss_in(tc_string), ss_ans(ans);

    int res; ss_ans<<ans;

    int n; ss_in>>n;
    int sm=0;
    for (int i=0; i<n; i++) {
        int v; ss_in>>v;
        sm+=v;
    }

    return sm==res;
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
        stringstream ss_in_fast(tc_string);
        ostringstream ss_out_fast;
        cin.rdbuf(ss_in_fast.rdbuf());
        cout.rdbuf(ss_out_fast.rdbuf());
        solve();
        auto ans=ss_out_fast.str();

        // non-void return type
        // stringstream ss_in(tc_string);
        // cin.rdbuf(ss_in.rdbuf());
        //
        // stringstream ss_out;
        // ss_out<<solve();
        // string ans=ss_out.str();

        stringstream feedback;

        if (!checker(tc_string, ans, feedback)) {
            cin.rdbuf(original_cin);
            cout.rdbuf(original_cout);
            cout << "Wrong Answer found on Test " << test_cases << "!\n";
            string feedback_str=feedback.str();
            if (!feedback_str.empty()) {
                cout << "--- Feedback -- \n" << feedback_str << "\n";
            }
            cout << "--- Input ---\n" << tc_string;
            cout << "--- Output ---\n" << ans << "\n";
            break;
        }

        if (test_cases % 1000 == 0) {
            cin.rdbuf(original_cin);
            cout.rdbuf(original_cout);
            cout << test_cases << " tests passed...\n";
        }
    }
    cin.rdbuf(original_cin);
}

int main() {
    stress();
    return 0;
}
