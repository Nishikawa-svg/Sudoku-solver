#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const int MOD = 1e9+7;

bool solve(vector<vector<int>>&,int,int);
bool check_vertical(vector<vector<int>>&,int,int);
bool check_horizontal(vector<vector<int>>&,int,int);
bool check_mass(vector<vector<int>>&,int,int,int);
int change_num(vector<vector<int>>&,int,int,int);


bool solve(vector<vector<int>>& arr, int x, int y){
    if(y>8){
        return true;
    }else if(x>8){
        if(solve(arr,0,y+1)){
            return true;
        }
    }else if(arr[y][x]!=0){
        if(solve(arr,x+1,y)){
            return true;
        }
    }else{
        for(int i=1; i<=9; i++){
            int tmp = change_num(arr,x,y,i);
            if(tmp!=0){
                if(solve(arr,x+1,y)){
                    return true;
                }
            }
        }
        arr[y][x]=0;
    }
    return false;
}

bool check_vertical(vector<vector<int>>& arr, int x, int n){
    for(int i=0; i<9; i++){
        if(arr[i][x]==n){
            return false;
        }
    }
    return true;
}

bool check_horizontal(vector<vector<int>>& arr, int y, int n){
    for(int i=0; i<9; i++){
        if(arr[y][i]==n){
            return false;
        }
    }
    return true;
}


bool check_mass(vector<vector<int>>& arr, int x, int y, int n){
    int ix = x/3*3;
    int jy = y/3*3;
    for(int i=ix; i<ix+3; i++){
        for(int j=jy; j<jy+3; j++){
            if(x==i && y==j) continue;
            if(arr[j][i]==n){
                return false;
            }
        }
    }
    return true;
}

int change_num(vector<vector<int>>& arr, int x, int y, int n){
    if(check_vertical(arr,x,n) && check_horizontal(arr,y,n) && check_mass(arr,x,y,n)){
        return arr[y][x] = n;
    }else{
        return 0;
    }
}

int main(){
    vector<vector<int>> arr(9,vector<int>(9));
    rep(i,9){
        string s;
        cin >> s;
        rep(j,9){
            arr[i][j] = int(s[j]-'0');
        }
    }
    rep(i,9){
        rep(j,9){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
    chrono::system_clock::time_point start,end;
    start = chrono::system_clock::now();

    if(solve(arr,0,0)){
        cout << "solved" << endl;
        for(int i=0; i<9; i++){
            cout << '|';
            for(int j=0; j<8; j++){
                cout << arr[i][j] << ',';
            }
            cout << arr[i][8] << '|' << endl;
        }
    }else{
        cout << "couldn't solved" << endl;
    }
    
    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "time : " << elapsed << "ms" << endl;
    return 0;
}