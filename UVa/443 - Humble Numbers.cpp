#include <bits/stdc++.h>

using namespace std;

int main()
{
	//~ freopen("out","w",stdout);
	int num2;
	unsigned long long num,cont = 0;
	set<unsigned long long>nums;
	set<unsigned long long>::iterator it;
	vector<unsigned long long>resp;
	
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			for (int k = 0; k < 31; k++)
			{
				for (int l = 0; l < 31; l++)
				{
					num = pow(7,i) * pow(5,j) * pow(3,k) * pow(2,l);
					nums.insert(num);
				}		
			}	
		}	
	}
	
	for (it = nums.begin(); it!= nums.end() && cont <= 5843; it++, cont++)
	{
		resp.push_back(*it);
		//~ cout<<*it<<endl;
	}
	string parte;
	while (scanf("%d",&num2), num2)
	{
		if(num2%10 == 1 && num2%100 != 11)
			parte = "st";
		else if(num2%10 == 2 && num2%100 != 12)
			parte = "nd";
		else if(num2%10 == 3 && num2%100 != 13)
			parte = "rd";
		else
			parte = "th";
		
		cout<<"The "<<num2<<parte<<" humble number is "<<resp[num2]<<".\n";
	}
}
