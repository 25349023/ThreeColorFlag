#include <iostream>
#include <fstream>
#include <cstdlib>

#define Swap(x, y){ \
                char temp; \
                temp = flag[x]; \
                flag[x] = flag[y]; \
                flag[y] = temp; }

using namespace std;

inline bool exchange(string *flag, int x, int y){
        char temp;
        bool change = true;
        if ( (*flag)[x] != (*flag)[y] ){
            temp = (*flag)[x];
            (*flag)[x] = (*flag)[y];
            (*flag)[y] = temp;
        }
        else {
            change = false;
        }
        return change;
}

int arrange(string flag){
    int b = 0,
    w = 0,
    r = flag.length() - 1;

    while (flag[b] == 'B' && b < flag.length()){
        b++;
        w++;
    }
    while (flag[r] == 'R' && r >= 1){
        r--;
    }
    int counts = 0;
    while (w <= r){
        switch (flag[w]){
        case 'B':
            if (exchange(&flag, b, w)){
                counts++;
            }
            b++;
            w++;
            break;
        case 'W':
            w++;
            break;
        case 'R':
            if (exchange(&flag, w, r)){
                counts++;
            }
            r--;
            break;
        }
    }

    for (int i = 0; i < flag.length(); i++){
        cout << flag[i] << " ";
    } cout << endl << "counts : " << counts << endl;

    return counts;
}

int main(int argc, char *argv[]){
    string flag;
    if (argc > 1){
        ofstream os;
        os.open("three_flag_ans.txt", ios::out);
        os << arrange(argv[1]) << endl;
        os.close();
    }
    else {
        while (cin >> flag){
            arrange(flag);
        }
    }

    return 0;
}
