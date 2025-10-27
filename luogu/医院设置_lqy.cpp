#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int num;
	int left;
	int right;
	int s_num;
} Node;

vector<Node> tree(101);

int result[101]={0,0};

int returns=0;

int get_son(int pos,int deep){
	int a=0;
	int b=0;
	Node& node=tree[pos];
	if(node.left!=0){
		a=get_son(node.left,deep+1);
	}
	if(node.right!=0){
		b=get_son(node.right,deep+1);
	}
	node.s_num=a+b+node.num;
	result[1]+=deep*node.num;
	return node.s_num;
}

void get_result(int last,int pos){
	Node& node=tree[pos];
	result[pos] = result[last]-node.s_num+tree[1].s_num-node.s_num;			//last = 父节点，1 = 根节点，    
	//			3,21			
	//		1,10		2,8
	//	4		5			6
	//
	//
	returns = min(returns,result[pos]);
	if(node.left!=0){
		get_result(pos,node.left);
	}
	if(node.right!=0){
		get_result(pos,node.right);
	}
}


int main(){
	int n;
	cin>>n;
	int w,u,v;
	Node node;
	node.s_num=0;
	for(int i=1;i<=n;i++){
		cin>>w>>u>>v;
		
		node.num = w;
		node.left= u;
		node.right = v;
		
		if(u==1){
			int temp = tree[1].left;
			tree[1].left = i;
			node.left = temp;
		}
		if(v==1){
			int temp = tree[1].left;
			tree[1].right = i;
			node.left = temp;
		}
		tree[i] = node;
	}
	
	get_son(1,0);
	returns = result[1];
	node = tree[1];
	if(node.left!=0){
		get_result(1,node.left);
	}
	if(node.right!=0){
		get_result(1,node.right);
	}
	
	cout<<returns;
	
	
	
	return 0;
}

