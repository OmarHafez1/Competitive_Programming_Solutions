
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono; 
using namespace __gnu_pbds;
 
template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using indexed_mset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
#define int long long
 
const double PI = 3.141592653589793;
const int MOD = 1e9+7; 
const int INF = 1e9;
 
//
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double; 
 
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pull = pair<ull, ull>;
using pdb = pair<db,db>;
 
using vi = vector<int>;
using vl = vector<long>;
using vb = vector<bool>;
using vll = vector<ll>;
using vull = vector<ull>;
using vld = vector<ld>;
using vdb = vector<db>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpll = vector<pll>; 
using vpull = vector<pull>;
using vpdp = vector<pdb>;
 
#define vec vector
#define lb lower_bound
#define ub upper_bound
#define pushb(a) push_back(a)
#define pushf(a) push_front(a)
#define popb pop_back()
#define popf pop_front()
 
// pairs & tuples
#define fir first
#define sec second
#define tsize(t) tuple_size<decltype(t)>::value
#define tcat tuple_cat
 
// vectors
#define all(x) begin(x), end(x)
#define alll(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()  //C++17 
#define sor(x) sort(all(x)) 
#define sorr(x) sort(alll(x)) 
#define rsor(x) sort(all(x), greater<>()) 
#define rsorr(x) sort(alll(x), greater<>()) 
#define rsz(a, b) resize(distance(a, b))
#define eb emplace_back
#define shuffle(v) random_shuffle(all(v))
#define vmax(x) max_element(all(x))
#define vcnt(x, i) count(all(x), i)
#define uniq(x) x.resize(unique(all(x)) - x.begin())
 
// sets
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define ins insert
#define ers erase
 
#define key find_by_order
#define order order_of_key
 
// queue
#define qu queue
#define dqu deque
#define pqu priority_queue
template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;
 
// maps
#define umap unordered_map
 
// loops
#define f0r(i,a) for(int i = 0; i < (a); ++i)
#define f1r(i,a) for(int i = 1; i < (a); ++i)
#define foor(i,a,b) for(int i = (a); i < (b); ++i)
#define r0f(i,a) for(int i = (a)-1; i >= 0; --i)
#define rof(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define fe(a,x) for(auto& a: x)
 
// some hacks
#define endl '\n'
#define newl cout<<endl;
 
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define y0 this_fix_bug_with_y0_2022
#define y1 this_fix_bug_with_y1_2022
#define y2 this_fix_bug_with_y2_2022
#define y3 this_fix_bug_with_y3_2022
#define y4 this_fix_bug_with_y4_2022
 
// some math
#define point complex<ld>
#define degree(x) (x) * 180.0 / PI
#define radian(x) (x) * PI / 180.0
#define sinDegrees(x) sin(radian(x))
#define cosDegrees(x) cos(radian(x))
#define tanDegrees(x) tan(radian(x))
#define asinDegrees(x) dgeree(asin(x))
#define acosDegrees(x) degree(acos(x))
#define atanDegrees(x) degree(atan(x))
#define EPS 1e-8
#define is_same(a, b) (fabs(a-b) <= EPS)
 
// some complex
#define point complex<ld>
#define c_angle(a) (atan2((a).imag(), (a).real()))
#define c_vec(a,b) (b)-(a)
#define c_dp(a,b) (conj(a)*(b)).real() // a*b cos(T), if zero -> prep
#define c_cp(a,b) (conj(a)*(b)).imag()  // a*b sin(T), if zero -> parllel
#define c_same(p1,p2) (c_dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define c_length(a) (hypot((a).imag(), (a).real()))
#define c_distance(a, b, c) fabs(c_cp(a-b, a-c)/c_length(a-b))
#define c_normalize(a) (a)/c_length(a)
#define c_rotateO(p,ang) ((p)*exp(point(0,ang)))
#define c_rotateA(p,ang,about) (c_rotateO(vec(about,p),ang)+about)
#define c_reflectO(v,m) (conj((v)/(m))*(m))
 
// bits
#define cnt_1s(b) __builtin_popcountll(b)
#define begin_0s(b) __builtin_clzll(b) 
#define end_0s(b) __builtin_ctzll(b) 
#define ffno(b) find_first_not_ofll(b) 
 
// permutation 
#define n_perm next_permutation
#define p_perm prev_permutation 
#define vn_perm(x) next_permutation(all(x))
#define vp_perm(x) prev_permutation(all(x))
 

// fflush(stdout);
// cout << fixed << setprecision(10);

namespace NT{
    template<typename T>
    struct bigger_type{};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<> struct bigger_type<int>{using type = long long;};
    template<> struct bigger_type<unsigned int>{using type = unsigned long long;};
    //template<> struct bigger_type<int64_t>{using type = __int128;};
    //template<> struct bigger_type<uint64_t>{using type = unsigned __int128;};
 
    template<typename int_t = unsigned long long>
    struct Mod_Int{
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = a+b;
            if(ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
            uint64_t ret = a * (uint64_t)b - (uint64_t)((long double)a * b / mod - 1.1) * mod;
            if(-ret < ret){
                ret = mod-1-(-ret-1)%mod;
            } else {
                ret%=mod;
            }
                
            //ret = min(ret, ret+mod);
            int64_t out = ret;
            /*if(out != a*(__int128) b % mod){
                cerr << (long double)a * b / mod << " " << (uint64_t)((long double)a * b / mod - 0.1) << "\n";
                cerr << mod << " " << ret << " " << ret+mod << " " << out << " " << (int64_t)(a*(__int128) b % mod) << "\n";
                assert(0);
            }*/
            return out;
            //return a*static_cast<bigger_type_t<int_t>>(b)%mod;
        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = 1;
            int_t base = a;
            for(int i=0;b>>i;++i){
                if((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type is_prime(T x){
        if(x<T(4)) return x>T(1);
        for(T i=2;i*i<=x;++i){
            if(x%i == 0) return false;
        }
        return true;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_single(T const&x, T base){
        if(x<T(4)) return x>T(1);
        if(x%2 == 0) return false;
        base%=x;
        if(base == 0) return true;
 
        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0){ // could use __builtin_ctz
            d/=2;
            ++j;
        }
        T t = Mod_Int<T>::pow(base, d, x);
        if(t==T(1) || t==T(xm1)) return true;
        for(int k=1;k<j;++k){
            t = Mod_Int<T>::mul(t, t, x);
            if(t == xm1) return true;
            if(t<=1) break;
        }
        return false;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&){return true;}
    template<typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&x, T const&base, S const&...bases){
        if(!miller_rabin_single(x, base)) return false;
        return miller_rabin_multi(x, bases...);
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin(T const&x){
        if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type isqrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type icbrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    /*uint64_t isqrt(unsigned __int128 const&x){
        unsigned __int128 ret = sqrtl(x);
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }*/
    vector<uint16_t> saved;
    // fast prime factorization from
    // https://github.com/radii/msieve
    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        //cerr << "try: " << x << " " << k << "\n";
        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn-p1*p1;
 
        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }
 
        uint32_t multiplier = 2*k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        //cerr << "at: " << multiplier << "\n";
 
        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;
 
        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;
 
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (q1 < coarse_cutoff) {
                tmp = q1 / __gcd(q1, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }
 
            bits = 0;
            tmp = q0;
            while(!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {
 
                sqrtq = (uint32_t)isqrt(q0);
 
                if (sqrtq * sqrtq == q0) {
                    for(j=0;j<saved.size();++j){
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    //else cerr << "skip " << i << "\n";;
                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (q0 < coarse_cutoff) {
                tmp = q0 / __gcd(q0, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }
 
        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}
 
        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
 
        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;
 
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (p0 == p1) {
                q0 = q1;
                break;
            }
 
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (p0 == p1)
                break;
        }
        if(j==it_max) {cerr << "RNG\n"; return 1;} // random fail
 
        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t squfof(uint64_t const&x){
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
 
        uint64_t cbrt_x = icbrt(x);
        if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;
 
        //uint32_t iter_lim = isqrt(isqrt(x))+10;
        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; //would overflow
                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        assert(0);
        return 1;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize_brute(T x){
        vector<T> ret;
        while(x%2 == 0){
            x/=2;
            ret.push_back(2);
        }
        for(uint32_t i=3;i*(T)i <= x;i+=2){
            while(x%i == 0){
                x/=i;
                ret.push_back(i);
            }
        }
        if(x>1) ret.push_back(x);
        return ret;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize(T x){
        //cerr << "factor: " << x << "\n";
        vector<T> ret;
        const uint32_t trial_limit = 5000;
        auto trial = [&](uint32_t const&i){
            while(x%i == 0){
                x/=i;
                ret.push_back(i);
            }
        };
        trial(2);
        trial(3);
        for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
            trial(i);
        }
        if(x>1){
            static stack<T> s;
            s.push(x);
            while(!s.empty()){
                x = s.top(); s.pop();
                if(!miller_rabin(x)){
                    T factor = squfof(x);
                    if(factor == 1 || factor == x){assert(0); return ret;}
                    //cerr << x << " -> " << factor << "\n";
                    s.push(factor);
                    s.push(x/factor);
                } else {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
}

int sum(int n) {
    int sm = 0;
    for(auto &x : NT::factorize(n)) {
        sm += x;
    }
    return sm;
}

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    
    int ans = 0;
    
    for(int i = 15000001; i <= 20000000; i++) {
        ans += sum(i);
    }
    for(int i = 1; i <= 5000000; i++) {
        ans -= sum(i);
    }
    cout << ans;
}
 