// Copyright 2015, Alessandro Fabbri
// for any question, please mail rommacc@yahoo.it

/************************************************************************
* This program is free software: you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program.  If not, see <http://www.gnu.org/licenses/>. *
************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

typedef std::pair<int,int> int_pair;

bool titled_print(std::string s, std::vector<int_pair> v){
	std::cout << s << std::endl;
  	for(size_t i=0; i<v.size(); i++){
  		std::cout << "( " << v[i].first << " , " << v[i].second << " ) ";
  	}
  	std::cout << std::endl << std::endl;
}

bool compare_first(int_pair p1, int_pair p2) { 
	return (p1.first < p2.first); 
}

bool compare_second(int_pair p1, int_pair p2) { 
	return (p1.second < p2.second); 
}

int main () {
  int size = 10;
  std::vector<int_pair> myvec;

  for(int i=0; i<size; i++){
  	myvec.push_back( std::make_pair( 10-i, i+1 ) );
  }

  titled_print("Pre sort", myvec);

  // sorting on first component
  std::sort (myvec.begin(), myvec.end(), compare_first); 
  // or using lambdas
  //std::sort (myvec.begin(), myvec.end(), [] (int_pair a, int_pair b) {
  //  return a.first < b.first;
  //} ); 
  titled_print("Sorting on first component", myvec);

  // sorting on second component
  std::sort (myvec.begin(), myvec.end(), compare_second); 
  titled_print("Sorting on second component", myvec);

  return 0;
}