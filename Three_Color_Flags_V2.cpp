#include <iostream>
#include <fstream>

using namespace std;

struct color{
    int blue, white, red;
};

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

color col_count(string f){
    color res = {0, 0, 0};
    for (int i = 0; i < f.length(); i++){
        switch (f[i]){
        case 'B':
            res.blue++;
            break;
        case 'W':
            res.white++;
            break;
        case 'R':
            res.red++;
            break;
        }
    }
    return res;
}

int arrange(string flag){
    int counts = 0;
    color col;
    col = col_count(flag);
    int b = 0, w = col.blue, r = flag.length() - 1, c = 0, tmpc = 0;
    while (flag[b] == 'B' && b < flag.length()){
        b++;
        c++;
    }
    while (flag[r] == 'R' && r >= 1){
        r--;
    }
    tmpc = c;

    while (w < col.blue + col.white && c < flag.length()){
        if (flag[c] == 'W' && !(c >= col.blue && c < col.blue + col.white)){
            if ( exchange(&flag, c, w) ){
                counts++;
                c++;
            }
            w++;
        }
        else {
            c++;
        }
    }
    c = tmpc;
    while (b < col.blue && c < flag.length()){
        if (flag[c] == 'B' && !(c >= 0 && c < col.blue)){
            if ( exchange(&flag, c, b) ){
                counts++;
                c++;
            }
            b++;
        }
        else {
            c++;
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
        os.open("three_flag_ans.txt", ios::app);
        os << arrange(argv[1]);
        os.close();
    }
    else {
        while (cin >> flag){
            arrange(flag);
        }
    }

    return 0;
}
