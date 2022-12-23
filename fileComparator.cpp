/*
 * This little app-ling is developed by ulasdilek on a fine (by fine I mean freezing cold) Friday afternoon on December 23rd, 2022
 * Stealing it is by no means prohibited, actually encouraged. But you have to pay the price with your soul ^^
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {

    ifstream file1, file2;
    string path1, path2;
    path1 = argv[1];
    path2 = argv[2];

    file1.open(path1, ios_base::in);
    file2.open(path2, ios_base::in);
    if (file1 && file2) {
        vector<pair<int, pair<string, string>>> mismatches;
        int line = 0;
        bool eof1, eof2;
        while (!file1.eof() && !file2.eof()) {
            line++;
            string str1, str2;
            getline(file1, str1);
            getline(file2, str2);
            if (str1 != str2) {
                mismatches.push_back(pair<int, pair<string, string>>(line, pair<string, string>(str1, str2)));
            }
        }
        eof1 = file1.eof();
        eof2 = file2.eof();
        if (eof1 && eof2) {
            cout << line << " lines were compared. There are a total of " << (line - mismatches.size()) << " correct lines and " << mismatches.size() << " mismatches:" << endl << endl;
            int count = 0;
            for (const auto &mismatch: mismatches) {
                count++;
                cout << "Mismatch #" << count << " on line " << mismatch.first << ":" << endl;
                cout << path1 << " - " << mismatch.second.first << endl;
                cout << path2 << " - " << mismatch.second.second << endl;
                cout << endl;
            }
        }
        else if (eof1) {
            cout << "End of " << path1 << " reached but did not finish reading " << path2 << endl;
        }
        else if (eof2) {
            cout << "End of " << path2 << " reached but did not finish reading " << path1 << endl;
        }
        else {
            cout << "None of the files were read completely. What?" << endl;
        }
    }
    else if (file1) {
        cout << "check if " << path2 << " exists and try again" << endl;
    }
    else if (file2) {
        cout << "check if " << path1 << " exists and try again" << endl;
    }
    else {
        cout << "check if both files exist and try again" << endl;
        cout << "file 1: " << path1 << endl;
        cout << "file 2: " << path2 << endl;

    }

    return 0;
}
