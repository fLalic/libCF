template<int mod=1e9+7>
struct modint{
    int val;

    modint(long long v=0){
	val=v;
	if(val<0) val+=mod;
    }

    modint& operator+= (const modint& a){
	val+=a.val;
	if(val>=mod)
	    val-=mod;
	return *this;
    }

    modint& operator-= (const modint& a){
	val-=a.val;
	if(val<0)
	    val+=mod;
	return *this;
    }

    modint& operator*= (const modint& a){
	val=(1ll*val*a.val)%mod;
	return *this;
    }

    friend modint expo(modint a, long long b){
	modint res=1;

	while(b){
	    if(b&1ll)
		res*=a;
	    a*=a;
	    b>>=1ll;
	}

	return res;
    }
    friend modint inv(modint a){ return expo(a, mod-2); }

    modint& operator^= (long long e){
	long long pot=val;
	while(e){
	    if(e&1ll)
		val=(pot*val)%mod;
	    pot=(pot*pot)%mod;
	    e>>=1ll;
	}

	return *this;
    }

    modint& operator/= (const modint& a){
	return *this*=inv(a);
    }

    bool operator== (const modint& a){ return val==a.val; }
    bool operator!= (const modint& a){ return val!=a.val; }
    bool operator< (const modint& a){ return val<a.val; }
    bool operator> (const modint& a){ return val>a.val; }
    bool operator<= (const modint& a){ return val<=a.val; }
    bool operator>= (const modint& a){ return val>=a.val; }

    friend modint operator+ (modint a, modint b){ return a+=b; }
    friend modint operator- (modint a, modint b){ return a-=b; }
    friend modint operator- (modint a){ return 0-a; }
    friend modint operator* (modint a, modint b){ return a*=b; }
    friend modint operator/ (modint a, modint b){ return a/=b; }
    friend modint operator^ (modint a, long long e){ return a^=e; }
    friend istream& operator >>(istream& in, modint& a){
	ll x; in >> x;
	a=modint(x);
	return in;
    }
    friend ostream& operator <<(ostream& out, modint& a){
	return out << a.val;
    }
};
