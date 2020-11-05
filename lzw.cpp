#include <bits/stdc++.h> 
#include <tr1/unordered_map>
#include <vector>


using namespace std::tr1;

const int MAX = 26; 
  
// Returns a string of random alphabets of 
// length n. 
std::string printRandomString(int n) 
{ 
    char alphabet[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',  
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
                          'V', 'W', 'X', 'Y', 'Z' }; 
  
    std::string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % MAX]; 
      
    return res; 
} 
  

std::vector<int> encoding(std::string s1)
{ 
	std::cout << "Encoding\n"; 
	unordered_map<std::string, int> table; 
	for (int i = 0; i <= 255; i++) { 
		std::string ch = ""; 
		ch += char(i); 
		table[ch] = i; 
	} 

	std::string p = "", c = ""; 
	p += s1[0]; 
	int code = 256; 
	std::vector<int> output_code; 
	std::cout << "String\tOutput_Code\tAddition\n"; 
	for (int i = 0; i < s1.length(); i++) { 
		if (i != s1.length() - 1) 
			c += s1[i + 1]; 
		if (table.find(p + c) != table.end()) { 
			p = p + c; 
		} 
		else { 
			std::cout << p << "\t" << table[p] << "\t\t"
				<< p + c << "\t" << code << std::endl; 
			output_code.push_back(table[p]); 
			table[p + c] = code; 
			code++; 
			p = c; 
		} 
		c = ""; 
	} 
	std::cout << p << "\t" << table[p] << std::endl; 
	output_code.push_back(table[p]); 
	return output_code; 
} 






int main() 
{ 
	clock_t start, end;
	
	int n;
	std::cout<< "Enter your Total Final String Length :" <<std::endl;
	std::cin >> n;
	
	std::fstream fout; 
	fout.open("C:/Users/kabii/Desktop/lzw_1000.csv", std::ios::out | std::ios::app);
	fout << "mssg_size" << ", "
             << "time_lzw" << ", "
             << "\n";
             
    double timelzw[n];
	
	
	for(int i = 1; i<=n; i++)
	{
		std::string str = printRandomString(i);
		std::cout << i << ". " <<"Random input String : "<< str  << std::endl;
		std::cout << " " << std::endl;
		
		std::string s = str; 
		start = clock();
		std::vector<int> output_code = encoding(s);
		end = clock();
		std::cout << "Output Codes are: "; 
		for (int j = 0; j < output_code.size(); j++) { 
			std::cout << output_code[j] << " "; 
		}
		std::cout << " " << std::endl;
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    	std::cout << "Time taken by program is : " << std::fixed  << time_taken << std::setprecision(10); 
    	std::cout << " sec " << std::endl;
    	std::cout << " " << std::endl;
    	
    	timelzw[i] = time_taken;
    	
    	fout << i << ", "
             << timelzw[i] << ", "
             << "\n";
	}
	/*
	std::string str = printRandomString(50);
	std::string s = str; 
	std::vector<int> output_code = encoding(s); 
	std::cout << "Output Codes are: "; 
	for (int i = 0; i < output_code.size(); i++) { 
		std::cout << output_code[i] << " "; 
	} 
	*/ 
} 

