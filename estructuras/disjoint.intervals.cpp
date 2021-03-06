// Guarda intervalos como [first, second]
// En caso de colision, los une en un solo intervalo
bool operator <(const ii &a, const ii &b){ return a.first < b.first; }
struct disjoint_intervals {
	set<ii> segs;
	void insert(ii v){ // O(lg n)
		if(v.snd - v.fst == 0.0) return; // Cuidado!
		set<ii>::iterator it, at;
		at = it = segs.lower_bound(v);
		if(at != segs.begin() && (--at)->snd >= v.fst){
			v.fst = at->fst;
      --it;
    }
		for(; it!=segs.end() && it->fst <= v.snd; segs.erase(it++))
			v.snd = max(v.snd, it->snd);
		segs.insert(v);
	}
};
