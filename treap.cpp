mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Treap{
    struct tNode{
	int val, pri;
	tNode *c[2];

	tNode(int v){
	    val = v; pri = rng();
	    c[0] = c[1] = NULL;
	}
    }*root = NULL;

    pair<tNode*, tNode*> split(tNode* t, int x){
	if(!t)
	    return {t, t};

	if(t->val >= x){
	    auto a = split(t->c[0], x);
	    t->c[0] = a.second;
	    return {a.first, t};
	}
	else{
	    auto a = split(t->c[1], x);
	    t->c[1] = a.first;
	    return {t, a.second};
	}
    }

    tNode* merge(tNode* a, tNode* b){
	if(!a)
	    return b;
	else if(!b)
	    return a;

	if(a->pri > b->pri){
	    a->c[1] = merge(a->c[1], b);
	    return a;
	}
	else{
	    b->c[0] = merge(a, b->c[0]);
	    return b;
	}
    }

    void insert(int val){
	auto a = split(root, val);
	root = merge(merge(a.first, new tNode(val)), a.second);
    }

    void erase(int val){
	auto a = split(root, val);
	auto b = split(a.second, val + 1);
	root = merge(a.first, b.second);
    }
};
