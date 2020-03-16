#include<bits/stdc++.h>
using namespace std;


string encoder(string str);

string decoder(string str);

void printCodes(struct MinHeapNode* root, string str);

void storeCodes(struct MinHeapNode* root, string str);

void HuffmanCodes(int size);

void calcFreq(string str, int n);

string decode_file(struct MinHeapNode* root, string s);
