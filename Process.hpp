//
//  Process.hpp
//  
//
//  Created by Emma on 12/09/2016.
//
//

#ifndef Process_hpp
#define Process_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <algorithm>

//#define USERNUM 4
#define USERNUM 100100
//#define ITEMNUM 2
#define ITEMNUM 100000
#define DEBUG 0

using namespace std;

typedef struct FriendNode{
	long long uid;
	struct FriendNode *next;
}Friend;

static long long user[USERNUM] = {0};
static Friend fri[USERNUM];

class ProcData{
private:
	vector<long long> split(const string &s, char delim);

public:
	ProcData() {
		for (long long i=0; i<USERNUM; ++i) {
			fri[i].uid = i;
			fri[i].next = NULL;
		}
	}

	void calDeal();
	void calFriend();
	void calCycle();
};



#endif /* Process_hpp */
