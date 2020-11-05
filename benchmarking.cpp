#include<iostream>
#include<queue>
#include<string>
#include<bits/stdc++.h>

using namespace std;

//RANDOM STRING
const int MAX = 26; 
  
// Returns a string of random alphabets of 
// length n. 
string printRandomString(int n) 
{ 
    char alphabet[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',  
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
                          'V', 'W', 'X', 'Y', 'Z' }; 
  
    string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % MAX]; 
      
    return res; 
} 
  



//HUFFMAN CODE
struct node{
   int freq;
   char data;
   const node *child0, *child1;
   node(char d, int f = -1){ //assign values in the node
      data = d;
      freq = f;
      child0 = NULL;
      child1 = NULL;
   }
   node(const node *c0, const node *c1){
      data = 0;
      freq = c0->freq + c1->freq;
      child0=c0;
      child1=c1;
   }
   bool operator<( const node &a ) const { //< operator performs to find priority in queue
      return freq >a.freq;
   }
   void traverse(string code = "")const{
      if(child0!=NULL){
         child0->traverse(code+'0'); //add 0 with the code as left child
         child1->traverse(code+'1'); //add 1 with the code as right child
      }else{
         cout << "Data: " << data<< ", Frequency: "<<freq << ", Code: " << code<<endl;
      }
   }
};
void huffmanCoding(string str){
   priority_queue<node> qu;
   int frequency[256];
   for(int i = 0; i<256; i++)
      frequency[i] = 0; //clear all frequency
   for(int i = 0; i<str.size(); i++){
      frequency[int(str[i])]++; //increase frequency
   }
   for(int i = 0; i<256; i++){
      if(frequency[i]){
         qu.push(node(i, frequency[i]));
      }
   }
   while(qu.size() >1){
      node *c0 = new node(qu.top()); //get left child and remove from queue
      qu.pop();
      node *c1 = new node(qu.top()); //get right child and remove from queue
      qu.pop();
      qu.push(node(c0, c1)); //add freq of two child and add again in the queue
   }
   cout << "The Huffman Code: "<<endl;
   qu.top().traverse(); //traverse the tree to get code
}




//RLE
void printRLE(string str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n; i++) { 
  
        // Count occurrences of current character 
        int count = 1; 
        while (i < n - 1 && str[i] == str[i + 1]) { 
            count++; 
            i++; 
        } 
  
        // Print character and its count 
        cout << str[i] << count; 
    } 
} 




//RLE 2
string rle2(const string & str){
    int i = str.size();
    string letters;
    letters[0] = str[0];
    for (int j = 0; j < i; ++j){
        int count = 1;
        while (str[j] == str[j+1]){
            count++;
            j++;
        }
        letters.push_back('0' + count);
        letters.push_back(str[j]);
    }
    return letters;
}



//ROT13
// Map to lookup the index of alphabets 
map <char,int> dict1; 

// Map to lookup alphabets corresponding 
// to the index after shift 
map <int,char> dict2; 

void create_dict() 
{ 
	for(int i = 1; i < 27; i++) 
		dict1[char(64 + i)] = i; 
	
	dict2[0] = 'Z'; 
	
	for(int i = 1; i < 26; i++) 
		dict2[i] = char(64 + i); 
		
	return; 
} 

// Function to encrypt the string 
// according to the shift provided 
string encrypt(string message, int shift) 
{ 
	string cipher = ""; 
	for(int i = 0; i < message.size(); i++) 
	{ 
		// Checking for namespace 
		if(message[i] != ' ') 
		{ 
			// loooks up the map and 
			// adds the shift to the index 
			int num = (dict1[message[i]] + shift) % 26; 
			
			// looks up the second map for the 
			// shifted alphabets and adds them 
			cipher += dict2[num]; 
		} 
		else
		{ 
			// adds space 
			cipher += " "; 
		} 
	} 
	return cipher; 
} 






//===================================================


main(){
	clock_t start, end, startrle, endrle, start13, end13, startrle2, endrle2;
	
	/*TEST STRINGS
   //string str = "ACCEBFFFFAAXXBLKE";
	string str;
	cout<< "Enter your string in :" <<endl;
	cin >> str;*/ 
	
	int n;
	cout<< "Enter your Total Final String Length :" <<endl;
	cin >> n;
	//initialization for rot13
	create_dict(); 
	int shift = 13;
	 
   //HUFFMAN
   
	/* TEST CODE TO SEE IF HUFFMAN CODING WORKS
	start = clock();
	huffmanCoding(str);
	end = clock(); 
   
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	cout << "Time taken by program is : " << fixed  << time_taken << setprecision(10); 
	cout << " sec " << endl;
    
	srand(time(NULL)); 
	int n = 30;
    cout << "Random String";
	cout << printRandomString(n) << endl;
	cout << " " << endl;*/
	//FILE WRITING
	fstream fout; 
	fout.open("C:/Users/kabii/Desktop/itc_1000.csv", ios::out | ios::app);
	fout << "mssg_size" << ", "
             << "time" << ", "
             << "time_rle"<<","
             << "time_rot13"<<","
             << "time_rle2"<<","
             << "\n";
	
	int string_size[n];
    double time[n];
    double timeRLE[n];
    double time13[n];
    double timerle2[n];

    
	for(int i = 1; i<=n; i++)
	{
		string str = printRandomString(i);
		cout << i << ". " <<"Random input String : "<< str  << endl;
		cout << " " << endl;
		
		start = clock();
		huffmanCoding(str);
		end = clock();
		
		startrle = clock();
		printRLE(str);
		endrle = clock();
		
		start13 = clock();
		cout << encrypt(str, shift) << "\n";
		end13 = clock();
		
		startrle2 = clock();
		cout << rle2(str) << "\n";
		endrle2 = clock();
		
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    	cout << "Time taken by huffman is : " << fixed  << time_taken << setprecision(10); 
    	cout << " sec " << endl;
    	cout << " " << endl;

		double time_takenrle = double(endrle - startrle) / double(CLOCKS_PER_SEC); 
    	cout << "Time taken by RLE is : " << fixed  << time_takenrle << setprecision(10); 
    	cout << " sec " << endl;
    	cout << " " << endl;
    	
    	double time_taken13 = double(end13 - start13) / double(CLOCKS_PER_SEC); 
    	cout << "Time taken by Rot13 is : " << fixed  << time_taken13 << setprecision(10); 
    	cout << " sec " << endl;
    	cout << " " << endl;
    	
    	double time_takenrle2 = double(endrle2 - startrle2) / double(CLOCKS_PER_SEC); 
    	cout << "Time taken by RLE2 is : " << fixed  << time_takenrle2 << setprecision(10); 
    	cout << " sec " << endl;
    	cout << " " << endl;
    	
    	
		string_size[i] = i;
		time[i] = time_taken;
		timeRLE[i] = time_takenrle;
		time13[i] = time_taken13;
		timerle2[i] = time_takenrle2;
		
        //Writing Data into the file
		fout << string_size[i] << ", "
             << time[i] << ", "
             << timeRLE[i]<<","
             << time13[i]<<","
             << timerle2[i]<<","
             << "\n";	
	}

   return 0;

}
