#pragma once
#include"Includer.h"
#include"VarSpace.h"

using namespace std;
//TEXT READ


//COPYRIGHT FOXAXU SOFTWARE TEAM
// Text command Process
// Cpp Includer

//Only Support Read 1 Char Size,Read Size A"B$C "+$ = B
bool check_file_existence(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        return true;
    } else {
        return false;
    }
}

//Read Env
string PartRead(string Info, string StartMark, string EndMark) {
	int infosize = Info.size();
	string tempInfo, ReadCheck;

	int CurrentRead = 0;

	while (ReadCheck != StartMark) {
		if (CurrentRead > infosize) {
			return "PartRead.NotFound";
		}
		ReadCheck = Info[CurrentRead];
		CurrentRead++;
	}

	int backread = Info.size();
	for (;readbuffer != EndMark;backread--){
		readbuffer = Info[backread];
	}

	if (backread - CurrentRead ==1){
		return "partread.err.emptydata";
	}

	while(true){
		ReadCheck = Info[CurrentRead];
		tempInfo = tempInfo + ReadCheck;
		if (CurrentRead == backread) {
			break;
		}
		CurrentRead++;
	}

	return tempInfo;
}

//ReadSize
// FoxaXu good work 3 = Fox
string SizeRead(string Info, int Size) {
	if (Size > Info.size()) {
		return "SizeRead.OverSize";
	}

	string TempInfo;
	for (int ReadCharSize = 0; ReadCharSize != Size; ReadCharSize++) {
		TempInfo = TempInfo + Info[ReadCharSize];
	}

	return TempInfo;
}

//Read Size from End
// This is FoxaXu 4=xaXu
string EndSizeRead(string Info, int LateSize) {
	int InfoSize = Info.size();
	int EndAddress = InfoSize - LateSize;
	if (EndAddress < 0) {
		return "EndSizeRead.LateSizeOverSmall";
	}
	string TempInfo,ReadChar;

	for (int LateRead = InfoSize; LateRead != EndAddress; LateRead--) {
		ReadChar = Info[LateRead];
		TempInfo = TempInfo + ReadChar;
	}

	return TempInfo;
}

//Get Char Address int
// ABC$DEFG$
int TextGetSizeAddress(string Info, string MarkSize, int NumBit) {
	int MaxSizeInfo = Info.size();
	int CurrentNumBit = 0;
	int StartRead = 0;
	string TempInfo, charRead;

	while (CurrentNumBit != NumBit) {
		for (int EndRead; charRead != MarkSize; StartRead++) {
			charRead = Info[StartRead];
		}
		CurrentNumBit++;
	}

	return StartRead;
}

//Char Size Read
//Example ABCDEFG S=C E=F DE
string PartReadSize(string Info, int StartSize, int EndSize) {
	StartSize--; EndSize--;
	int MaxInfoSize = Info.size();
	if (StartSize > EndSize) {
		return "PartReadSize.StartOverThanEnd";
	}
	if (StartSize == EndSize) {
		return "";
	}
	if (EndSize > MaxInfoSize) {
		return "PartReadSize.EndSizeOverMaxinfo";
	}
	int CurrentSize = StartSize;

	string TempInfo, charRead;
	while (CurrentSize <= EndSize) {
		charRead = Info[CurrentSize];
		TempInfo = TempInfo + charRead;
		CurrentSize++;
	}

	return TempInfo;
}

//API For LineReader
int CountLines(string filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename.c_str());
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}

//Read LineSize
//Like : 
//
//      #Calcium
//      BEFORE
//      FOXAXU
//      After
//
//Read  :
//
//      LineReader(ExampleFile,3) return FOXAXU
string LineReader(string File, int line_number) {
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(File.c_str());
	lines = CountLines(File);

	if (line_number <= 0)
	{
		return "LineError";
	}
	if (file.fail())
	{
		return "ReadFailed";
	}
	if (line_number > lines)
	{
		return "overline";
	}
	while (getline(file, temp) && i < line_number - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

int checkChar(string text,string chechchar ) {
	const char* c = chechchar.c_str();

	if (text.find(c) != string::npos) {
		return 1;
	}
	else {
		return 0;
	}
}

string cutlineblockA(string lines, string cutmark, int line) {
	string backapi;

	if (checkChar(lines, cutmark) == 0) {
		return "NUL";
	}

	char* readcut = NULL;

	char Texts[65535] = "a";
	char CUMark[65535] = "a";

	strcpy(Texts, lines.c_str());
	strcpy(CUMark, cutmark.c_str());

	int cutrecord = 1;
	char* token = strtok(Texts, CUMark);
	if (token == NULL) {
		backapi = "";
		return backapi;
	}

	if (cutrecord == line) {

		//cout << "CUTLINEBLOCK CHECK OK, RETURN :  _" << token << "_" << endl;
		backapi = token;
		return backapi;
	}

NextRollCR:
	if (cutrecord == line) {
		//cout << "CUTLINEBLOCK CHECK OK, RETURN :  _" << token << "_" << endl;
		backapi = token;
		return backapi;
	}
	if (token == NULL) {
		backapi = "";
		return backapi;
	}
	cutrecord++;
	token = strtok(NULL, CUMark);
	goto NextRollCR;
}

string HeadSpaceClean(string Info) {
	int maxCSize = Info.size();
	string readMCS, tempInfo;
	int currentFit;

	//cout << "Max C Size :  _" << maxCSize << endl;
	for (currentFit = 0; currentFit < maxCSize; currentFit++) {
		readMCS = Info[currentFit];
		//cout << "Read MCS :  _" << readMCS << endl;
		if (readMCS == " ") {}
		else {
			while (currentFit < maxCSize) {
				//cout << "Trans Add : _" << Info[currentFit] << endl;
				tempInfo = tempInfo + Info[currentFit];
				currentFit++;
			}
		}
	}
	return tempInfo;
}

int charTotal(string info,string markchar){
	int charsize = info.size();
	int totalget = 0;
	for(int readsize = 0;charsize != readsize;readsize++){
		readbuffer = info[readsize];
		if (readbuffer == markchar){
			totalget ++;
			continue;
		}
		else {
			continue;
		}
	}
	return totalget;
}

//Replace Char
string ReplaceChar(string info, string replaceword, string nword) {
	//cout << "New Replace :  _" << info << "_  _" << replaceword << "_  _" << nword << "_" << endl;
	int checkanti = checkChar(info, replaceword);
	if (checkanti == 1) {
		std::string dst_str = info;
			std::string::size_type pos = 0;
		while ((pos = dst_str.find(replaceword)) != std::string::npos)
		{
			dst_str.replace(pos, replaceword.length(), nword);
		}
		//cout << "Return Data :  _" << dst_str <<"_" << endl;
		return dst_str;
	}
	else {
		//cout << "Return Data :  _" << info << "_" << endl;
		return info;
	}
}

void coutll(){
	if (ListWARNING == 0){
		cout << "-----------------------------WARNING------------------------------" <<endl;
		ListWARNING = 1;
		return;
	}
	else {
		cout << "-------------------------------END--------------------------------" <<endl;
		cout <<endl;
		ListWARNING = 0;
		return;
	}
	return;
}

int SpawnRandomNum(int min, int max) {

	string minb, maxb;
	minb = to_string(min);
	maxb = to_string(max);

	//string chars = "Min :  " + minb + "   Max :   " + maxb + "  Bug Report";
	//MessageBox(0, chars.c_str(), "MXBug Report", MB_OK);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max); // ����i-a֮����������
	int outdata = dis(gen);
	
	//string dis_str = to_string(dis(gen));
	//MessageBox(0,dis_str.c_str(),"Bug check",MB_OK);
	
	return dis(gen);
}