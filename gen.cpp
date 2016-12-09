#include "params.h"

ll seed = 100000000000ll;

//myrand() generate platform irrelevant random number
int myrand(int l, int r)
{
	seed = (3 * seed + 5) % 1125899906842679ll;
	int m = r - l + 1;
	return (int)(seed % m + l);
}

vector<int> items;
vector< set<int> > users;

void gen_items()
{
	cout << "generate items..." << endl;
	for (int i = 0; i < ITEM_NUM; i++)
	{
		int price = myrand(1, MAX_PRICE);
		items.push_back(price);
	}
}

void gen_users()
{
	cout << "generate users..." << endl;
	for (int i = 0; i < USER_NUM; i++)
	{
		set<int> friends;
		users.push_back(friends);
	}
	for (int i = 0; i < USER_NUM; i++)
	{
		int fn;
		int p = myrand(1, 100);
		if (p <= 95)
			fn = myrand(0, 5);
		else
			fn = myrand(5, 10);
		for (int j = 0; j < fn; j++)
		{
			p = myrand(1, 100);
			int f;
			if (p <= 95)
				f = min(USER_NUM - 1, i + myrand(1, 10));
			else
				f = myrand(0, USER_NUM - 1);
			if (f == i) continue;
			users[i].insert(f);
			users[f].insert(i);
		}
	}
}

void print_items()
{
	cout << "print items..." << endl;
	const char* fname = ITEM_FILE;
	ofstream f(fname, ios::out);
	if (f.is_open() == false) 
	{
		cout << "cannot open file " << fname << endl;;
		assert(false);
	}
	
	for (int i = 0; i < ITEM_NUM; i++)
	{
		f << i << " " << items[i] << endl;
	}

	f.close();
}

void print_users()
{
	cout << "print users ..." << endl;
	const char* fname = USER_FILE;
	ofstream f(fname, ios::out);
	if (f.is_open() == false) 
	{
		cout << "cannot open file " << fname << endl;;
		assert(false);
	}

	for (int i = 0; i < USER_NUM; i++)
	{
		f << i;
		f << " " << users[i].size();
		for (set<int>::iterator j = users[i].begin(); j != users[i].end(); j++)
		{
			f << " " << *j;
		}
		f << endl;
	}

	f.close();
}

void print_deals()
{
	cout << "generate and print deals ..." << endl;
	const char* fname = DEAL_FILE;
	ofstream f(fname, ios::out);
	if (f.is_open() == false) 
	{
		cout << "cannot open file " << fname << endl;;
		assert(false);
	}

	for (int i = 0; i < DEAL_NUM; i++)
	{
		int uid;
		if (myrand(1, 100) <= 50)
			uid = myrand(0, USER_NUM / 10);
		else
			uid = myrand(USER_NUM / 10, USER_NUM - 1);
		f << uid;

		int s = myrand(1, 5);
		f << " " << s;
		set<int> items;
		for (int i = 0; i < s; i++)
		{
			int iid = myrand(0, ITEM_NUM - 1);
			if (items.find(iid) != items.end())
			{
				i --;
				continue;
			}
			items.insert(iid);
			int nums = myrand(1, 10);
			f << " " << iid << " " << nums;
		}
		
		f << endl;
	}

	f.close();
}

int main()
{
	gen_items();
	gen_users();
	
	print_items();
	print_users();
	print_deals();
	cout << "done!" << endl;
	return 0;
}
