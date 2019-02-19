#pragma once
#include<Jieba.hpp>
#include<string>
class TextSimilarity
{
public:
	typedef std::unordered_map<std::string, int> wordFreq;
	typedef std::unordered_set<std::string> wordSet;
	TextSimilarity(std::string dict);
	double getTextSimilariry(const char* file1, const char* file2);
private:

	void getStopWordTable(const char* stopWordFile);
	wordFreq getWordFreq(const char* file);
	std::string GBKTOUTF(std::string strGBK);
	std::string UTFTOGBK(std::string strUTF);
	std::vector<std::pair<std::string,int>> sortByValueReverse(wordFreq& wf);
	void selectAimWords(std::vector<std::pair<std::string, int>>& wfvec, wordSet& wset);
	std::vector<double> getOntHot(wordSet& wset, wordFreq& wf);

	std::string DICT;
	std::string DICT_PATH;
	std::string HMM_PATH;
	std::string USER_DICT_PATH;
	std::string IDF_PATH;
	std::string STOP_WORD_PATH;

	wordSet _stopWordSet;
	int _maxWordNumber;
};