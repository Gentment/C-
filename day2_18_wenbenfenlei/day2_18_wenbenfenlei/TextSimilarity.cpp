#include"TextSimilarity.h"
#include<fstream>
#include<iostream>
using namespace std;

TextSimilarity::TextSimilarity(string dict)
	:DICT(dict)
	,DICT_PATH(dict + "/jieba.dict.utf8")
	,HMM_PATH(dict+"/hmm_model.utf8")
	,USER_DICT_PATH(dict+"/user.dict.utf8")
	,IDF_PATH(dict+"/idf.utf8")
	,STOP_WORD_PATH(dict+"/stop_words.utf8")
{

}

TextSimilarity::wordFreq getWordFreq(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "open file:" << filename << endl;
		return wordFreq();
	}
	string line;
	wordFreq wf;
	while (!fin.eof())
	{
		getline(fin, line);
		line = GBKTOUTF(line);
		vector<string> words;
		_jieba.Cut(line, words.true);
	}
	for (size_t i = 0; i < length; i++)
	{

	}
}

bool cmpReverse(pair<string, int> lp, pair<string, int> rp)
{
	return lp.second > rp.second;
}

vector<std::pair<std::string, int>> TextSimilarity::sortByValueReverse(TextSimilarity::wordFreq& wf)
{
	sort(wf.begin(), wf.end(), cmpReverse);

}

void TextSimilarity::selectAimWords(std::vector<std::pair<std::string, int>>& wfvec, wordSet& wset)
{
	int len = wfvec.size();
	int sz = len > _maxWordNumber ? _maxWordNumber : len;
	for (int i=0;i<sz;++i)
	{
		wset.insert(wfvec[i].first);
	}
}
