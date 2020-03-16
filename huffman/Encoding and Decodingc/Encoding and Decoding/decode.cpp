#include <bits/stdc++.h>
using namespace std;
map<char,int> freq;
map<char,string>codes;



struct MinHeapNode
{
	char data;			 // One of the input characters
	int freq;			 // Frequency of the character
	MinHeapNode *left, *right; // Left and right child

	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// utility function for the priority queue
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};


// utility function to store characters along with
// there huffman value in a hash table, here we
// have C++ STL map
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

// function to build the Huffman tree and store it
// in minHeap
void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}


string decode_file(struct MinHeapNode* root, string s)
{
	string ans = "";
	struct MinHeapNode* curr = root;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] == '0')
		curr = curr->left;
		else
		curr = curr->right;

		// reached leaf node
		if (curr->left==NULL and curr->right==NULL)
		{
			ans += curr->data;
			curr = root;
		}
	}
	// cout<<ans<<endl;
	return ans+'\0';
}

int decodefinal () {
  ifstream myfile;
  string line,encoded;
  string temp;
  myfile.open ("server_inp.txt");
  getline(myfile,line);
  //cout<<line;
  encoded=line;

  while(getline(myfile,line))
    {
       freq.insert({ line[0],1});
       getline(myfile,temp);
       stringstream frequency(temp);
       frequency >> freq[line[0]];
    }
  myfile.close();
  /*
  for(auto v=codes.begin() ; v!=codes.end();v++)
  {
    cout << v->first <<' ' << v->second<< endl;
  }
  */
  HuffmanCodes(15);
  string dec = decode_file(minHeap.top(),encoded);
  cout<<dec;






}
