#include<bits/stdc++.h>
using namespace std;


int N  = 20;
int lx[] = {-2,2,-1, 1, -2, 2,-1, 1};
int ly[] = {1 ,1, 2, 2, -1,-1,-2,-2};
void ans(){
	vector<set<pair<int, int>>> k(N+1);
	vector<set<pair<int, int>>> c(N+1);
	vector<set<pair<int, int>>> q(N+1);
	set<pair<int, int>> initial_pt;
	initial_pt.insert(make_pair(0,0));
	k[0] = initial_pt;
	c[0] = initial_pt;
	q[0] = initial_pt;
	
	for(int i=1;i<N+1;i++){
	   	set<pair<int, int>> new_set;
	   	 set<pair<int, int>>::iterator itr;
	   	c[i]=c[i-1];
		for(itr = k[i-1].begin();itr!=k[i-1].end();++itr){
			pair<int, int> pt = *itr;
			int x = pt.first;
			int y = pt.second;
			for(int j=0;j<8;j++){
				new_set.insert(make_pair(x+lx[j], y+ly[j]));
				c[i].insert(make_pair(x+lx[j], y+ly[j]));
			}
		}
		k[i]=new_set;
		set_difference(k[i].begin(), k[i].end(), c[i-1].begin(), c[i-1].end(),
    inserter(q[i], q[i].end()));
	}
	int i=0;
	while(i<=N){
		cout<<"K "<<i<<" & Size="<<k[i].size()<<endl;
		cout<<"-----------------------\n ";
		for(auto pt: k[i]){
			cout<<"{"<<pt.first<<" "<<pt.second<<"} ";
		}
		cout<<"}\n------------------------\n";
		cout<<"C "<<i<<"& Size="<<c[i].size()<<endl;
		for(auto pt: c[i]){
			cout<<"{"<<pt.first<<" "<<pt.second<<"} ";
		}
		cout<<"\n---------------------------\n";

		cout<<"Q "<<i<<"| size="<<q[i].size()<<endl;
		for(auto pt: q[i]){
			cout<<"{"<<pt.first<<" "<<pt.second<<"}";
		}
		cout<<"\n\n********\n\n";
		i++;
	}
	
	return;
}


int main(){
ans();
	 
return 0;
}