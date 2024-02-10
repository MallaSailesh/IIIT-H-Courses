#include<bits/stdc++.h>
using namespace std;

char dominion(char state){
    if(state == 'R') return 'P';
    else if(state == 'P') return 'S';
    return 'R';
}

int main(){
    int n ; cin>>n;
    char input_1[n];
    vector<int> input[n];
    vector<int> output[n] ;
    char arr[3] = {'R','P','S'};
    set<int> s ;
    vector<char> output_ch;
    vector<int> output_r ;
    vector<int> output_p ;
    vector<int> output_s ;
    
    int rk = 0, pr = 0 , sc = 0;

    // input reading 
    for(int i=0;i<n;++i){
        char state;cin>>state;
        int on_r,on_p,on_s; cin>>on_r>>on_p>>on_s;
        input_1[i] = state ;
        input[i].push_back(on_r);
        input[i].push_back(on_p);
        input[i].push_back(on_s);
        s.insert(i);
        if(state == 'R') rk++;
        else if(state == 'P') pr++;
        else sc++;
    }

    int cnt = 1;
    int equalise = 0,equalise2 = 0;
    // reducing the number of states 
    set<int> s2;
    set<set<int>> main_set;
    while(cnt < 180){
        // cout<<endl<<endl<<cnt<<endl;
        if(s.size() == 1) break;
        set<int> s1;
        output_r.push_back(cnt+1);
        output_p.push_back(cnt+1);
        output_s.push_back(cnt+1);
        if(cnt < 30 && rk >= pr && rk >= sc)
        {
            output_ch.push_back('P');
            for(auto x : s){
                s1.insert(input[x][1]);
            }
        }
        else if(cnt < 30 && pr >= rk && pr >= sc ){
            output_ch.push_back('S');
            for(auto x : s){
                s1.insert(input[x][2]);
            }
        }
        else if(cnt < 30 && sc >= rk && sc >= pr){
            output_ch.push_back('R');
            for(auto x : s){
                s1.insert(input[x][0]);
            }
        }
        else if(cnt < 60 && pr >= rk && pr >= sc ){
            output_ch.push_back('S');
            for(auto x : s){
                s1.insert(input[x][2]);
            }
        }
        else if(cnt < 60 && rk >= pr && rk >= sc)
        {
            output_ch.push_back('P');
            for(auto x : s){
                s1.insert(input[x][1]);
            }
        }
        else if(cnt < 60 && sc >= rk && sc >= pr){
            output_ch.push_back('R');
            for(auto x : s){
                s1.insert(input[x][0]);
            }
        }
        else if(cnt < 90 && sc >= rk && sc >= pr){
            output_ch.push_back('R');
            for(auto x : s){
                s1.insert(input[x][0]);
            }
        }
        else if(cnt < 90 && rk >= pr && rk >= sc)
        {
            output_ch.push_back('P');
            for(auto x : s){
                s1.insert(input[x][1]);
            }
        }
        else if(cnt < 90 && pr >= rk && pr >= sc ){
            output_ch.push_back('S');
            for(auto x : s){
                s1.insert(input[x][2]);
            }
        }
        else if(cnt < 120 && pr >= rk && pr >= sc ){
            output_ch.push_back('S');
            for(auto x : s){
                s1.insert(input[x][2]);
            }
        }
        else if(cnt < 120 && sc >= rk && sc >= pr){
            output_ch.push_back('R');
            for(auto x : s){
                s1.insert(input[x][0]);
            }
        }
        else if(cnt < 120 && rk >= pr && rk >= sc)
        {
            output_ch.push_back('P');
            for(auto x : s){
                s1.insert(input[x][1]);
            }
        }
        else if(cnt < 150 && sc >= rk && sc >= pr){
            output_ch.push_back('R');
            for(auto x : s){
                s1.insert(input[x][0]);
            }
        }
        else if(cnt < 150 && pr >= rk && pr >= sc ){
            output_ch.push_back('S');
            for(auto x : s){
                s1.insert(input[x][2]);
            }
        }
        else if(cnt < 150 && rk >= pr && rk >= sc)
        {
            output_ch.push_back('P');
            for(auto x : s){
                s1.insert(input[x][1]);
            }
        }
        else if(cnt < 180 && rk >= pr && rk >= sc)
        {
            output_ch.push_back('P');
            for(auto x : s){
                s1.insert(input[x][1]);
            }
        }
        else if(cnt < 180 && sc >= rk && sc >= pr){
            output_ch.push_back('R');
            for(auto x : s){
                s1.insert(input[x][0]);
            }
        }
        else if(cnt < 180 && pr >= rk && pr >= sc ){
            output_ch.push_back('S');
            for(auto x : s){
                s1.insert(input[x][2]);
            }
        }
        s.clear();
        cnt++;
        rk = 0, pr = 0 , sc = 0;
        if(main_set.find(s1) != main_set.end()){
            int calc1 = s1.size();
            char char1 = dominion(output_ch[output_ch.size()-1]);
            char char2 = dominion(char1);
            char char3 = dominion(char2);
            set<int> s3,s4;
            s3.clear();
            s4.clear();
            // s5.clear();
            for(auto x : s1){
                if(char1 == 'R')
                s3.insert(input[x-1][0]);
                else if(char1 == 'P')
                s3.insert(input[x-1][1]);
                else 
                s3.insert(input[x-1][2]);
                if(char2 == 'R')
                s4.insert(input[x-1][0]);
                else if(char2 == 'P')
                s4.insert(input[x-1][1]);
                else 
                s4.insert(input[x-1][2]);
                // if(char3 == 'R')
                // s5.insert(input[x-1][0]);
                // else if(char3 == 'P')
                // s5.insert(input[x-1][1]);
                // else 
                // s5.insert(input[x-1][2]);
            }
            int calc2 = s3.size();
            int calc3 = s4.size();
            // int calc4 = s5.size();
            // if(calc4 < calc2 && calc4 < calc3){
            //     output_ch.push_back(char3);
            //     output_p.push_back(cnt+1);
            //     output_r.push_back(cnt+1);
            //     output_s.push_back(cnt+1);
            //     for(auto x : s3){
            //         s1.insert(x);
            //     } 
            // }
            if(min(calc2,calc3) <= calc1){
                s1.clear();
                if(calc2 == calc3){
                    equalise++;
                    if(equalise%2){
                        output_ch.push_back(char1);
                        output_p.push_back(cnt+1);
                        output_r.push_back(cnt+1);
                        output_s.push_back(cnt+1);
                        for(auto x : s3){
                            s1.insert(x);
                        } 
                    }
                    else{
                        output_ch.push_back(char2);
                        output_p.push_back(cnt+1);
                        output_r.push_back(cnt+1);
                        output_s.push_back(cnt+1);
                        for(auto x : s4){
                            s1.insert(x);
                        }
                    }
                }
                else if(calc2 < calc3){
                    output_ch.push_back(char1);
                    output_p.push_back(cnt+1);
                    output_r.push_back(cnt+1);
                    output_s.push_back(cnt+1);
                    for(auto x : s3){
                        s1.insert(x);
                    }
                }
                else{
                    output_ch.push_back(char2);
                    output_p.push_back(cnt+1);
                    output_r.push_back(cnt+1);
                    output_s.push_back(cnt+1);
                    for(auto x : s4){
                        s1.insert(x);
                    }
                }
                cnt++;
            } 
            // for(auto x : s1)  {
            //     // state = x+1;
            //     cout<<x<<" a ";
            // }
            // cout<<endl;
        }
        s2.clear();
        for(auto x : s1) {
            if(input_1[x-1] == 'R') rk++;
            else if(input_1[x-1] == 'S') sc++;
            else pr++;
            s.insert(x-1);
            s2.insert(x);
            main_set.insert(s2);
        }
        // for(auto x : s)  {
        //     // state = x+1;
        //     cout<<x+1<<" ";
        // }
        // cout<<endl;
    }
    int state  = 0;
    for(auto x : s) state = x+1;
    s.clear();
    for(int i=0;i<800;++i){
        output_ch.push_back(dominion(input_1[state-1]));
        output_r.push_back(cnt+1);
        output_p.push_back(cnt+1);
        output_s.push_back(cnt+1);
        cnt++;
        char p_char = dominion(input_1[state-1]);
        if(p_char == 'R')
        state = input[state-1][0];
        else if(p_char == 'P')
        state = input[state-1][1];
        else 
        state = input[state-1][2];
    }
    output_ch.push_back('P'); 
    output_r.push_back(1);
    output_p.push_back(1);
    output_s.push_back(1);
    cout<<output_r.size()<<endl;
    for(int i=0;i<output_r.size();++i){
        cout<<output_ch[i]<<" "<<output_r[i]<<" "<<output_p[i]<<" "<<output_s[i]<<endl;
    }
    return 0;
}