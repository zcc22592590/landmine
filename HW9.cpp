#include <iostream>
using namespace std;

int main()
{
	//////////input range//////////
	int r = 0, c = 0;
	while(cin >> r >> c)
	{
		//////////input value//////////
		int place[r][c];
		int all_landmine = 0;//the number of landmine
		int all_detector = 0;//the number of detector
		int i, j;
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cin >> place[i][j];
				if(place[i][j] == 1) all_landmine++;//the number of landmine
				if(place[i][j] == 5) all_detector++;//the number of detector
			}
		}
		//cout << "all_landmine: " << all_landmine << endl << "all_detector: " << all_detector << endl;
		
		//////////if detectors are too close then disable//////////
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				if(place[i][j] == 5 && all_detector > 1)
				{
					//cout << "inside" << endl;
					if(((j+1)<c) && (place[i][j+1] == 5 || place[i][j+1] == 3))		{place[i][j] = 3; place[i][j+1] = 3;}//右
					if(((i+1)<r) && (place[i+1][j] == 5 || place[i+1][j] == 3))		{place[i][j] = 3; place[i+1][j] = 3;}//下
					if(((j-1)>=0) && (place[i][j-1] == 5 || place[i][j-1] == 3))	{place[i][j] = 3; place[i][j-1] = 3;}//左
					if(((i-1)>=0) && (place[i-1][j] == 5 || place[i-1][j] == 3))	{place[i][j] = 3; place[i-1][j] = 3;}//上
					if(((j+1)<c) && ((i+1)<r) && (place[i+1][j+1] == 5 || place[i+1][j+1] == 3))		{place[i][j] = 3; place[i+1][j+1] = 3;}//右下
					if(((j-1)>=0) && ((i-1)>=0) && (place[i-1][j-1] == 5 || place[i-1][j-1] == 3))		{place[i][j] = 3; place[i-1][j-1] = 3;}//左上
					if(((i+1)<r) && ((j-1)>=0) && (place[i+1][j-1] == 5 || place[i+1][j-1] == 3)) 		{place[i][j] = 3; place[i+1][j-1] = 3;}//左下
					if(((i-1)>=0) && ((j+1)<c) && (place[i-1][j+1] == 5 || place[i-1][j+1] == 3)) 		{place[i][j] = 3; place[i-1][j+1] = 3;}//右上
		
				}
			}
		}
		//////////this is to test//////////
		/*
		cout << "first try" << endl;
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cout << place[i][j] << " ";
			}
			cout << endl;
		}*/
		
		//cout << "all_landmine: " << all_landmine << endl << "all_detector: " << all_detector << endl;
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				if(place[i][j] == 3) place[i][j] = 0;
			}
		}
		
		//////////this is to test//////////
		/*
		cout << "second try" << endl;
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cout << place[i][j] << " ";
			}
			cout << endl;
		}*/
		
		
		//////////let detectors dectect landmine//////////
		int count = 0;
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				if(place[i][j] == 5 && all_landmine >= 1)
				{
					if(((j+1)<c) && place[i][j+1] == 1)		{all_landmine--; count++; place[i][j+1] = 0;}
					if(((i+1)<r) && place[i+1][j] == 1)		{all_landmine--; count++; place[i+1][j] = 0;}
					if(((j-1)>=0) && place[i][j-1] == 1)	{all_landmine--; count++; place[i][j-1] = 0;}
					if(((i-1)>=0) && place[i-1][j] == 1)	{all_landmine--; count++; place[i-1][j] = 0;}
					if(((j+1)<c) && ((i+1)<r) && place[i+1][j+1] == 1)		{all_landmine--; count++; place[i+1][j+1] = 0;}
					if(((j-1)>=0) && ((i-1)>=0) && place[i-1][j-1] == 1)	{all_landmine--; count++; place[i-1][j-1] = 0;}
					if(((i+1)<r) && ((j-1)>=0) && place[i+1][j-1] == 1) 	{all_landmine--; count++; place[i+1][j-1] = 0;}
					if(((i-1)>=0) && ((j+1)<c) && place[i-1][j+1] == 1) 	{all_landmine--; count++; place[i-1][j+1] = 0;}
				}
			}
		}
		//cout << "count: " << count << "  all_landmine: " << all_landmine << "  all_detector" << all_detector << endl;
		
		//////////count and output//////////
		cout << count << "  " << all_landmine << endl;
		c = 0;
		r = 0;
	}
}
