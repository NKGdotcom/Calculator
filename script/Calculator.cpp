
#include <iostream>
#include <string>
#include <regex>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979;// 円周率：定数
const double E = 2.71828182845904;// 自然対数の底：定数

//足し算の関数
double Addition(double a, double b)
{
	return a + b;
}

//引き算の関数
double Subtraction(double a, double b)
{
	return a - b;
}

//掛け算の関数
double Multiplication(double a, double b)
{
	return a * b;
}

//割り算の関数
double Division(double a, double b)
{
	double _a = a * 1.0;// 実数に変換
	double _b = b * 1.0;// 実数に変換
	return _a / _b;
}

//余剰の関数
int Modulo(double a, double b)
{
	int _a = (int)a;
	int _b = (int)b;
	return _a % _b;
}

//サインの関数
double Sin(double val)
{
	return sin(val);
}

//コサインの関数
double Cos(double val)
{
	return cos(val);
}

//タンジェントの関数
double Tan(double val)
{
	return tan(val);
}

//自然対数の関数
double Log(double val)
{
	return log(val);
}

//ルートの関数
double Sqrt(double val)
{
	return sqrt(val);
}

//割合の関数
double Percentage(double val)
{
	return (val / 100);
}

//階乗の関数
int Factorial(int val)
{
	int sum = 1;

	for(int i = 0; i < val; i++)
	{
		sum *= (i + 1);
	}

	return sum;
}

double result;// 計算結果

// 文字列置換の関数(入力文字, 文字が一致するか判断, 受け取ったdoubleを文字列に変換する)
void StringConversion(string& input, smatch& match, double res)
{
	string res_str = to_string(res);

	input.replace(match.position(0), match.length(0), res_str);// 文字を入れ替えるmatchした長さ文
}

enum class CalculateType {
	TwoASType,// 加法と減法
	TwoMDType,// 乗法と除法
	ModuloType,//剰余
	ElementaryFunctionType,// 初等関数
	ConstType,// 定数
	ExponetiationType,// べき乗
	PercentAndFactorialType,//割合と階乗
};

regex fourASMD_regex;// 四則演算A(dd)S(ubtract)M(ultiply)D(ivide)チェック
regex modulo_regex;//余り
regex elementaryFunction_regex;// 初等関数をチェック
regex const_regex;// 定数チェック
regex exponentiation_regex;// べき乗をチェック
regex percent_factorial_regex;//割合と階乗をチェック

//割合と階乗計算
void PercentFactorialCalculate(string& _input, smatch _match)
{
	while (regex_search(_input, _match, percent_factorial_regex)) 
	{
		double num = stod(_match[1]);
		string percent = _match[2];

		if (regex_match(percent, regex("%", regex_constants::icase))) {// %ならば割合
			result = Percentage(num);
		}
		else if (regex_match(percent, regex("!", regex_constants::icase))) {// !ならば階乗
			result = Factorial(num);
		}

		StringConversion(_input, _match, result);// matchする部分とresultに代入された部分の文字を変更
	}
}

//初等関数計算
void ElementaryFunctionCalculate(string& _input, smatch _match)
{
	while (regex_search(_input, _match, elementaryFunction_regex)) {
		//cout << "初等関数です" << endl;
		string functionName = _match[1];// ここでsinやcosなどを取得

		double num = stod(_match[2]);// 中身の数字を取得(()などは無視され、sin10から取得するためmatch[2]で通る

		if (regex_match(functionName, regex("sin", regex_constants::icase))) {// sinならばSinの結果
			result = Sin(num);
		}

		else if (regex_match(functionName, regex("cos", regex_constants::icase))) {// cosならCosの結果
			result = Cos(num);
		}

		else if (regex_match(functionName, regex("tan", regex_constants::icase))) {// tanならTanの結果
			result = Tan(num);
		}

		else if (regex_match(functionName, regex("log", regex_constants::icase))) {// logならLogの結果
			result = Log(num);
		}
		else if (regex_match(functionName, regex("r", regex_constants::icase))) {// ルート
			result = sqrt(num);
		}

		StringConversion(_input, _match, result);// matchする部分とresultに代入された部分の文字を変更
	}
}

//定数計算
void ConstCalculate(string& _input, smatch _match)
{
	while (regex_search(_input, _match, const_regex)) {// PIとEの定数
		//cout << "定数です" << endl;

		string _const = _match[0];//PIやEは一文字分のみ返ってくるためmatch[0]

		if (regex_match(_const, regex("pi", regex_constants::icase))) {// piならばPI
			result = PI;
		}

		else if (regex_match(_const, regex("e", regex_constants::icase))) {// eならばE
			result = E;
		}

		StringConversion(_input, _match, result);// matchする部分とresultに代入された部分の文字を変更
	}
}

//べき乗計算
void ExponetiationCalculation(string& _input, smatch _match)
{
	while (regex_search(_input, _match, exponentiation_regex)) {
		//cout << "べき乗です" << endl;

		double num = stod(_match[1]); //例:5^2のうち5の方 matchでは^を無視していたため1,2で通る
		double factiorial = stod(_match[2]); //例:階乗

		result = pow(num, factiorial);// べき乗の結果

		StringConversion(_input, _match, result);// matchする部分とresultに代入された部分の文字を変更
	}
}
//剰余の計算

void ModuloCalculation(string& _input, smatch _match)
{
	while (regex_search(_input, _match, modulo_regex)) {

		double num1 = stod(_match[1]);
		double num2 = stod(_match[3]);
		string op = _match[2];

		if (op == "%") {
			if(num2 == 0) { //0剰余のチェック
				cout << "Error: Modulo by zero." << endl;
				exit(1);
			}
			result = Modulo(num1, num2);
		}
		StringConversion(_input, _match, result);// matchする部分とresultに代入された部分の文字を変更
	}
}

//四則演算

void TwoASMDCalculation(string& _input, smatch _match)
{
	while (regex_search(_input, _match, fourASMD_regex)) {
		//cout << "四則演算です" << endl;

		double num1 = stod(_match[1]);//前
		double num2 = stod(_match[3]);//後

		string op = _match[2];//*or/

		if (op == "*") {
			result = Multiplication(num1, num2);//掛け算の結果
		}

		else if (op == "/") {
			if (num2 == 0) { //0除算のチェック
				cout << "Error: Division by zero." << endl;
				exit(1);
			}
			result = Division(num1, num2);//割り算の結果
		}

		else if (op == "+") {
			result = Addition(num1, num2);//足し算の結果
		}

		else if (op == "-") {
			result = Subtraction(num1, num2);//引き算の結果
		}
		StringConversion(_input, _match, result);// matchする部分とresultに代入された部分の文字を変更
	}
}

//実際に計算(入力文字, 何を行うか)
void Calculate(string& input, CalculateType type)
{
	string num_pattern = R"((-?\d+(?:\.\d+)?))";// 整数及び少数パターン
	//-? -が0回か1回 d+ 10進数が1回以上 (\.\d+)? .小数点と小数点の後ろにある数字が0回か1回以上(あってもなくても)　
	//?: (小数点以降.数字の部分のみが取得されないよう)

	//typeをここで仕分ける
	switch (type) {
	case CalculateType::ConstType:// π,e
		const_regex = regex(R"(pi|e)", regex_constants::icase); //(PIorE) regex_constants::icase //大文字小文字区別
		break;

	case CalculateType::ModuloType: //剰余%
		modulo_regex = regex(num_pattern + R"(\s*([\%])\s*)" + num_pattern); //数字 % 数字
		break;

	case CalculateType::PercentAndFactorialType://%と!
		percent_factorial_regex = regex(num_pattern + R"(\s*([\!\%])\s*)", regex_constants::icase); //数 !(階乗)または%(割合)
		//数 !or%の時
		break;

	case CalculateType::ElementaryFunctionType: //sin,cos,tan,log
		elementaryFunction_regex = regex(
			R"(([a-zA-Z]+)\s*\(?\s*)" + num_pattern + R"(\s*\)?)",// (sinなどの文字( + 数字 + )とルート)
			//([a-zA-Z]+) ローマ字が1個以上含まれる \s*\(?\s* 空白ありなしの( 数字 \s*\) 空白ありなしの)
			regex_constants::icase
		);
		break;

	case CalculateType::ExponetiationType: //べき乗^
		exponentiation_regex = regex(num_pattern + R"(\s*\^\s*)" + num_pattern);// (数字 + ^ + 数字)
		//数字 \^を含む 数字
		break;

	case CalculateType::TwoMDType:// 掛け算と割り算
		fourASMD_regex = regex(num_pattern + R"(\s*([\*/])\s*)" + num_pattern);// 数字(*or/)数字
		//数字 空白ありなし [\*/\%]掛け算or割り算or除算 空白ありなし
		break;

	case CalculateType::TwoASType: //足し算引き算
		fourASMD_regex = regex(num_pattern + R"(\s*([\+\-])\s*)" + num_pattern);// 数字(+or-)数字
		//数字 空白ありなし [\s+\-]足し算or引き算 空白ありなし
		break;
	}

	smatch match;

	//typeが定数であれば
	if (type == CalculateType::ConstType) {
		ConstCalculate(input, match);
	}

	if (type == CalculateType::ModuloType) {
		ModuloCalculation(input, match);
	}

	//typeが割合と階乗であれば
	if (type == CalculateType::PercentAndFactorialType) {
		PercentFactorialCalculate(input, match);
	}

	//typeが初等関数かルートであれば
	if (type == CalculateType::ElementaryFunctionType) {// 初等関数と√
		ElementaryFunctionCalculate(input, match);
	}

	//typeがべき乗であれば
	if (type == CalculateType::ExponetiationType) {
		ExponetiationCalculation(input, match);
	}

	//typeが加法、減法、乗法、除法であれば %も含む
	if (type == CalculateType::TwoMDType || type == CalculateType::TwoASType) {
		TwoASMDCalculation(input, match);
	}
}

//方程式を解く順番の関数(πやeを数に→()の中身を一つの数に→sinやcosを一つの数に→べき乗を一つの数に→掛け算、割り算→足し算、引き算)
string SolveEquation(string input)
{
	smatch match;

	Calculate(input, CalculateType::ConstType);//定数を数字に


	regex parentheses_regex{ R"(\(([^()]+)\))" }; 	// 括弧内の計算をすべて処理する


	//括弧が見つかる限りループ
	while (regex_search(input, match, parentheses_regex)) {//括弧内の式を取得し、同様のことを繰り返す

		string inner_expression = match[1];//()の中身の全体式を取得 
		string inner_result = SolveEquation(inner_expression);

		input.replace(match.position(0), match.length(0), inner_result);
	}

	//sinやcosを変換
	Calculate(input, CalculateType::ElementaryFunctionType);

	//べき乗演算
	Calculate(input, CalculateType::ExponetiationType);

	Calculate(input, CalculateType::ModuloType); //剰余計算

	//パーセント % と階乗
	Calculate(input, CalculateType::PercentAndFactorialType); //階乗や割合を数字に

	// 乗法・除法を処理する
	Calculate(input, CalculateType::TwoMDType);

	// 加法・減法を処理する
	Calculate(input, CalculateType::TwoASType);

	return input;
}

void Explanation();// 説明文

double saveNum;// 保存用変数
double getSaveNum;//

bool firstTime = true; //最初の一回だけ説明文を表示するため

int main()
{
	bool running = true;// これをfalseにすれば止まる

	string input; //文字入力用変数

	Explanation(); //まず説明文

	while (running)// キーを押して計算機の実行を終わらせたかったため
	{

		getline(cin, input); // 式の入力(空白が開いていても対応可能)

		if (input.empty()) continue;

		if (input == "finish") // 終了コマンド
		{
			running = false;// whileを終了
			break;
		}

		if (input == "save")// 保存コマンド
		{
			if (firstTime)// 一番初め
			{
				cout << "まだ保存できる数値がありません。" << endl;
			}
			else// 二回目以降
			{
				getSaveNum = saveNum;
				cout <<  getSaveNum << "を保存しました。" << endl;
			}
			continue;
		}

		if (input == "call")// 呼び出しコマンド
		{
			cout << getSaveNum;// 保存した数値を表示 例0
			getline(cin, input);// 再度入力を測る 例input + 9 +1
			string more_input = to_string(getSaveNum);// 保存した数値を式として扱う 例moreinputは0
			input = more_input + input; // 0 + 9 + 1
		}

		string solved_input = SolveEquation(input); //計算

		double final_result = stod(solved_input); //最終結果

		cout <<  final_result << endl; //結果の表示

		firstTime = false;

		saveNum = final_result;//保存用としていったん保存
	}
	
	cout << "処理が終了しました.何かのキーを押してください." << endl;
	cin.get();
	return 0;
}

//説明文の表示
void Explanation()
{
	cout << "使い方:" << endl;
	cout << "・四則演算(+,-,*,/)、括弧()の計算、初等関数、対数関数、π、e、階乗、割合、ルート(rキー)が使用可能です。" << endl;
	cout << "・saveの入力で直前の計算結果を保存、callの入力で保存した数値を呼び出せます。" << endl;
	
	cout << "・終了するにはfinishを入力してください。" << endl;
}