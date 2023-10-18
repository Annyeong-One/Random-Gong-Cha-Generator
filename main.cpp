#include<bits/stdc++.h>
//#pragma GCC optimize("O3") // optimization
//#pragma GCC optimize("Ofast") // optimization
//#pragma GCC optimize("unroll-loops") // optimization
using namespace std;
#define i32 signed
#define int long long // CP
#define i64 long long
#define endl '\n'
#define elif else if
#define fi first
#define se second
#define pb push_back
#define p32 pair<i32,i32>
#define p64 pair<i64,i64>
#define f2(i,x) for((i)=0;(i)<(x);(i)++)
#define f2b(i,x) for((i)=(x)-1;(i)>=0;(i)--)
#define f3(i,f,t) for((i)=(f);(i)<(t);(i)++)
#define fall(x) (x).begin(), (x).end()
#define sort1(x) sort(fall(x))
#define rev(x) reverse(fall(x))
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fl fflush(stdout)
#define nl cout<<endl;fflush(stdout)
i64 gcd(i64 a, i64 b){if(a<b){a=a^b;b=a^b;a=a^b;} return b==0?a:gcd(b,a%b);}
i64 lcm(i64 a, i64 b){return a/gcd(a,b)*b;}
i64 expm(i64 a, i64 b, i64 m){i64 r=1;while(b){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r%m;}
i64 minv(i64 a, i64 m){return expm(a,m-2,m);}
string topping[10]={"foam","pearl","coco","aloe","wpearl","cheese"};
struct gongcha{
    string name;
    int type; // 1 is tea, 2 is milktea, 3 is fruittea
    // 4 is smoothie, 5 is coffee, 0 is unrestricted
    bool top_ban[10];
};
vector<gongcha> drink;
void exprt(){
    cout<<"drink export mode\n";
    cout<<drink.size()<<endl;
    int i; f2(i,drink.size()){
        cout<<drink[i].name<<' '<<drink[i].type<<' ';
        int j; f2(j,6) cout<<drink[i].top_ban[j]<<' ';
        nl;
    }
}
i32 main(){
    int hash;
    cout<<"Welcome to RGG, please enter hash:\n";fl; cin>>hash;
    if(hash==-1){
        cout<<"New Drink Insertion Mode\ninsert name and type\n";fl;
        while(1){
            gongcha t;
            cin>>t.name;
            if(t.name=="break"){
                exprt();
                return 0;
            }
            cin>>t.type;
            t.top_ban[0]=0;
            t.top_ban[1]=0;
            t.top_ban[2]=0;
            t.top_ban[3]=0;
            t.top_ban[4]=0;
            t.top_ban[5]=0;
            drink.pb(t);
        }
    }
    elif(hash==-2) exprt();
    elif(hash==-3){
        cout<<"drink import mode\n";fl;
        drink.clear();
        int n; cin>>n;
        int i; f2(i,n){
            gongcha t; cin>>t.name>>t.type;
            int j; f2(j,6) cin>>t.top_ban[j];
            drink.pb(t);
        }
    }
    mt19937_64 rng(hash);
    while(1){
        int x=rng()%drink.size();
        cout<<drink[x].name<<' ';
        cout<<"random topping?\n";fl;
        int y; cin>>y;
        int topban=0;
        if(y==0) cout<<"no topping\n",fl;
        else{
            while(1){
                int top=rng()%6;
                if(drink[x].top_ban[top]==0){
                    cout<<topping[top]<<endl;
                    topban=top;
                    break;
                }
            }
        } cout<<"1 for export and end, 0 for again, -1 for ban drink and again\n";fl;
        int z; cin>>z;
        if(z==1){
            exprt();
            break;
        } elif(z==-1){
            drink[x].top_ban[topban]=1;
        }
    }
}