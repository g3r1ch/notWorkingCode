//#include <SFML/Graphics.hpp>
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(800, 600), "test");
//	/*sf::RectangleShape shape;*/
//	/*shape.setSize({ 1,1 });
//	shape.setPosition({ 200,120 });
//	shape.setFillColor(sf::Color::Red);*/
//	sf::VertexArray triangle(sf::Lines, 2);
//	int m = 510;
//	// define the position of the triangle's points
//	triangle[0].position = sf::Vector2f(0, 0);
//	triangle[1].position = sf::Vector2f(2, 2);
//
//	// define the color of the triangle's points
//	triangle[0].color = sf::Color::Cyan;
//	triangle[1].color = sf::Color::Cyan;
//
//
//	//sf::VertexArray triangle1(sf::Triangles, 3);
//
//	//// define the position of the triangle's points
//	//triangle1[0].position = sf::Vector2f(200, 10);
//	//triangle1[1].position = sf::Vector2f(100, 10);
//	//triangle1[2].position = sf::Vector2f(100, 100);
//
//	//// define the color of the triangle's points
//	//triangle1[0].color = sf::Color::Green;
//	//triangle1[1].color = sf::Color::Yellow;
//	//triangle1[2].color = sf::Color::Green;
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (event.type == sf::Event::KeyPressed)
//			{
//				// Получаем нажатую клавишу - выполняем соответствующее действие
//				if (event.key.code == sf::Keyboard::Escape) window.close();
//			}
//		}
//		window.clear();
//		for (int i = 2, j=2; i < 100; i+=1,j+=2) {
//			triangle[0].position = sf::Vector2f(j, i);
//			triangle[1].position = sf::Vector2f(j+2, i+1);
//			window.draw(triangle);
//		}
//		/*window.clear();*/
//		//window.draw(triangle);
//		/*window.draw(triangle1);*/
//		window.display();
//	}
//
//	return 0;
//}


#include <vector>
#include <iostream>
#include <ctime>
#include "perceptron.h"
#include "Layer.h"
#include "norm.h"
#include "outputLayer.h"
#include "gui.h"
#include <cmath>
#include "windows.h"
#include "tests.h"
#include "neyralNetwork.h"
//#include <SFML/Graphics.hpp>


using namespace std;



//class Perc {
//private:
//	double sigmoid(double x) {
//		return 1. / (1. + exp(-x));
//	}
//	double dActivationFunction(double x)
//	{
//		return sigmoid(x) * (1. - sigmoid(x));
//
//	}
//	double summ;
//	double out;
//	vector <double> W;
//	vector <double> input;
//	double learningRate;
//	double mOffset;
//public:
//	Perc(int aCountOfW, double aLearningRate = 0.3) {
//		for (int i = 0; i < aCountOfW; i++) {
//			W.push_back((rand() % 1000 - 500) / 1000.);
//		}
//		mOffset = (rand() % 1000 - 500) / 1000.;
//		learningRate = aLearningRate;
//	}
//	double process(vector<double> aInput) {
//		input = aInput;
//		summ = 0;
//		for (int i = 0; i < W.size(); i++) {
//			summ += W[i] * aInput[i];
//		}
//		summ += mOffset;
//		out = sigmoid(summ);
//		return out;
//	}
//	void changeWeights(double aAnswer) {
//		double err = aAnswer - out;
//		double nechto = err * dActivationFunction(summ);
//		for (int i = 0; i < W.size(); i++) {
//			W[i] += learningRate * nechto * (input[i]);
//		}
//		mOffset += learningRate * nechto;
//	}
//	double output() {
//		return out;
//	}
//};
//
//vector <double> norm(vector<double> inp) {
//	vector <double> out;
//	for (int i = 0; i < inp.size(); i++) {
//		out.push_back(inp[i] / 1.);
//	}
//	return  out;
//}
//double norm(double inp) {
//	return inp / 1.;
//}
//
//class Norm {
//private:
//	int del;
//public:
//	Norm(int aDel) {
//		del = aDel;
//	}
//	vector <double> norm(vector <double> inp) {
//		vector <double> out(inp.size());
//		for (int i = 0; i < inp.size(); i++) {
//			out[i] = inp[i] / del;
//		}
//		return out;
//	}
//
//	double norm(double inp) {
//		return inp / del;
//	}
//};
//
//class Layer {
//private:
//	vector <Perc> neyro;
//public:
//	Layer(int aCountOfNeyrons, int aCountOfInputs) {
//		for (int i = 0; i < aCountOfNeyrons; ++i)
//		{
//			neyro.emplace_back(Perc(aCountOfInputs));
//		}
//	}
//	vector <double> process(vector <double> aInp) {
//		vector <double> res;
//		for (auto& i : neyro) {
//			res.push_back(i.process(aInp));
//		}
//		return res;
//	}
//	void correct(vector <double> ans) {
//		for (int i = 0; i < neyro.size(); i++)
//		{
//			neyro[i].changeWeights(ans[i]);
//		}
//	}
//	void correct(double ans) {
//		for (int i = 0; i < neyro.size(); i++)
//		{
//			neyro[i].changeWeights(ans);
//		}
//	}
//	int size() {
//		return neyro.size();
//	}
//};
//
//class OutputLayer {
//private:
//	int connectionsCount;
//public:
//	OutputLayer(int aConnectionsCount) {
//		connectionsCount = aConnectionsCount;
//	}
//	double process(vector <double> aInp) {
//		int num = 0;
//		for (int i = 0; i < aInp.size(); i++) {
//			/*cout << endl << "			" << i << endl;*/
//			if (aInp[i] > aInp[num])
//				num = i;
//		}
//		return num;
//	}
//	vector <double> correct(int aInp) {
//		double a = 500;
//		vector <double> res(connectionsCount);
//		double lcl = 1.;
//		for (int i = aInp - 1; i >= 0; i--) {
//			lcl -= 1 / a;
//			res[i] = lcl;
//		}
//		res[aInp] = 1.;
//		lcl = 1.;
//		for (int i = aInp + 1; i < res.size(); i++) {
//			lcl -= 1 / a;
//			res[i] = lcl;
//		}
//		return res;
//	}
//};

//class Gui {
//private:
//	sf::RenderWindow window;
//public:
//	Gui(int x = 800,int y = 600,string name = "default") {
//		window.create(sf::VideoMode(x, y), name);
//	}
//
//	void matrix_from_double_vec(vector<double> aInp) {
//		sf::VertexArray quad(sf::Quads, 4);
//		window.clear();
//		int gen = 0;
//		for (int x = 0; x < 200; x += 10) {
//			for (int z = 0; z < 250; z += 10, gen++) {
//				//cout << weights[18]<<endl;
//				if (aInp[gen] < 0) {
//					quad[0].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//					quad[1].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//					quad[2].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//					quad[3].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//				}
//				else if (aInp[gen] > 0) {
//					quad[0].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//					quad[1].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//					quad[2].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//					quad[3].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//				}
//				else {
//					quad[0].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//					quad[1].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//					quad[2].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//					quad[3].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//				}
//				/*quad[0].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);
//				quad[1].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);
//				quad[2].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);
//				quad[3].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);*/
//				/*quad[0].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//				quad[1].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//				quad[2].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//				quad[3].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);*/
//				//quad[0].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//				//quad[1].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//				//quad[2].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//				//quad[3].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//				//quad[3].color = sf::Color::Color(round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100));
//				//if (gen == round(f + u)) {
//				//	quad[0].color = sf::Color::Red;
//				//	quad[1].color = sf::Color::Red;
//				//	quad[2].color = sf::Color::Red;
//				//	quad[3].color = sf::Color::Red;
//				//}
//				//if (gen == ol.process(ans)) {
//				//	quad[0].color = sf::Color::Green;
//				//	quad[1].color = sf::Color::Green;
//				//	quad[2].color = sf::Color::Green;
//				//	quad[3].color = sf::Color::Green;
//				//}
//				//cout << x * 2 + z / 10 << endl;
//
//				//(x + z) / 10
//				quad[0].position = sf::Vector2f(x, z);
//				quad[1].position = sf::Vector2f(x, z + 8);
//				quad[2].position = sf::Vector2f(x + 8, z + 8);
//				quad[3].position = sf::Vector2f(x + 8, z);
//
//				window.draw(quad);
//			}
//		}
//		window.display();
//	}
//
//	int check_close() {
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed) {
//				window.close();
//				return 0;
//			}
//			if (event.type == sf::Event::KeyPressed)
//			{
//				// Получаем нажатую клавишу - выполняем соответствующее действие
//				if (event.key.code == sf::Keyboard::Escape) {
//					window.close();
//					return 0;
//				}
//			}
//		}
//	}
//
//	int isOpen() {
//		if(window.isOpen())
//			return 1;
//
//		return 0;
//	}
//};



//a+b

//int main() {
//
//	//sf::RenderWindow window(sf::VideoMode(800, 600), "test");
//	//sf::VertexArray line(sf::Lines, 2);
//	//line[0].color = sf::Color::White;
//	//line[1].color = sf::Color::White;
//	//sf::VertexArray quad(sf::Quads, 4);
//
//	/*vector <vector<double>> samples = { {0.0, 0.0},{1, 0.0},{0.0, 1},{1, 1} };
//	vector <double> ans = { 0.0, 1, 1, 1 };*/
//	/*vector<int> last = { 0,0 };*/
//	Gui gui(1600, 1000, "name");
//	Layer l(500, 2, 1);
//	srand(time(0));
//	OutputLayer ol(500);
//	Norm n(250);
//	int abvgd = 0;
//	int fd = 0;
//	while (gui.isOpen()) {
//		for (int i = 0; i < 250; i++) {
//			if (i == 0) {
//				for (int bn = 3; bn < 250; bn++) {
//					if (bn % 10 == 0)
//						cout << bn << endl;
//					for (int hr = 1, rh = bn - 1; hr < bn; hr++, rh--) {
//						//cout << hr << "		" << rh << "		" << hr + rh<<endl;
//						vector <double> in = { hr * 1., rh * 1. };
//						vector<double> ans = l.process(n.norm(in));
//
//
//						vector<double> weights = l.w_of_perc(1, 1);
//						gui.matrix_from_double_vec(weights, 20, 25);
//
//						if (gui.render())
//							return 0;
//						cout << abs(hr + rh - ol.process(ans)) << endl;
//						l.correct(ol.correct(rh + hr));
//					}
//				}
//			}
//			else {
//				//cout << "i: " << i << endl;
//				for (int j = 1; j <= 250; j++) {
//					//	cout << "     j: " << j << endl;
//					//	sf::Event event;
//					//	while (window.pollEvent(event))
//					//	{
//					//		if (event.type == sf::Event::Closed) window.close();
//					//		if (event.type == sf::Event::KeyPressed)
//					//		{
//					//			// Получаем нажатую клавишу - выполняем соответствующее действие
//					//			if (event.key.code == sf::Keyboard::Escape) window.close();
//					//		}
//					//	}
//					//cout << "------------------------------------------------------------------" << endl;
//					for (int y = 0; y <= 250; y++) {
//						//double f = (rand() % 250) * 1.;
//						//double u = (rand() % 250) * 1.;
//						vector <double> in = { j * 1., y * 1. };
//						vector<double> ans = l.process(n.norm(in));//ol.process(l.process(n.norm(in)));
//						//cout << n.norm(in)[0] << "		" << n.norm(in)[1]<<endl;
//
//						vector<double> weights = l.w_of_perc(1, 1);
//						//cout << weights.size()<<endl;
//						//window.clear();
//						//cout << ans[0] << endl;
//						//cout << (1. / (1. + exp(-(weights[0])))) * 255<<endl;
//						//int gen = 0;
//						//for (int x = 0; x < 200; x+=10) {
//						//	for (int z = 0; z < 250; z += 10,gen++) {
//						//		if (abvgd == 20) {
//						//			cout << weights[0] << endl;
//						//		}
//						//		//cout << weights[18]<<endl;
//						//		if (weights[gen] < 0) {
//						//			quad[0].color = sf::Color::Color((255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10));
//						//			quad[1].color = sf::Color::Color((255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10));
//						//			quad[2].color = sf::Color::Color((255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10));
//						//			quad[3].color = sf::Color::Color((255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10), (255 / 2) * (1 + (weights[gen]) / 10));
//						//		}
//						//		else if (weights[gen] > 0) {
//						//			quad[0].color = sf::Color::Color((255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10));
//						//			quad[1].color = sf::Color::Color((255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10));
//						//			quad[2].color = sf::Color::Color((255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10));
//						//			quad[3].color = sf::Color::Color((255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10), (255 / 2) * ((weights[gen]) / 10));
//						//		}
//						//		else {
//						//			quad[0].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//						//			quad[1].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//						//			quad[2].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//						//			quad[3].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//						//		}
//						//		/*quad[0].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);
//						//		quad[1].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);
//						//		quad[2].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);
//						//		quad[3].color = sf::Color::Color((1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255, (1. / (1. + exp(-(weights[gen])))) * 255);*/
//						//		/*quad[0].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//						//		quad[1].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//						//		quad[2].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//						//		quad[3].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);*/
//						//		//quad[0].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//						//		//quad[1].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//						//		//quad[2].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//						//		//quad[3].color = sf::Color::Color(round(ans[gen] * 100), round(ans[gen] * 100), round(ans[gen] * 100));
//						//		//quad[3].color = sf::Color::Color(round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100));
//						//		//if (gen == round(f + u)) {
//						//		//	quad[0].color = sf::Color::Red;
//						//		//	quad[1].color = sf::Color::Red;
//						//		//	quad[2].color = sf::Color::Red;
//						//		//	quad[3].color = sf::Color::Red;
//						//		//}
//						//		//if (gen == ol.process(ans)) {
//						//		//	quad[0].color = sf::Color::Green;
//						//		//	quad[1].color = sf::Color::Green;
//						//		//	quad[2].color = sf::Color::Green;
//						//		//	quad[3].color = sf::Color::Green;
//						//		//}			
//						//		//cout << x * 2 + z / 10 << endl;
//						//		
//						//		//(x + z) / 10
//						//		quad[0].position = sf::Vector2f(x, z);
//						//		quad[1].position = sf::Vector2f(x, z+8);
//						//		quad[2].position = sf::Vector2f(x+8, z+8);
//						//		quad[3].position = sf::Vector2f(x+8, z);
//						//		window.draw(quad);
//						//	}
//						//}
//						//window.display();
//						//if (gui.graphik(weights))
//						//	return -1;
//
//						gui.matrix_from_double_vec(weights, 20, 25);
//
//						//	//sf::Event event;
//						//	//while (window.pollEvent(event))
//						//	//{
//						//	//	if (event.type == sf::Event::Closed) {
//						//	//		window.close();
//						//	//		return 0;
//						//	//	}
//						//	//	if (event.type == sf::Event::KeyPressed)
//						//	//	{
//						//	//		// Получаем нажатую клавишу - выполняем соответствующее действие
//						//	//		if (event.key.code == sf::Keyboard::Escape) {
//						//	//			window.close();
//						//	//			return 0;
//						//	//		}
//						//	//	}
//						//	//}
//
//						//	/*if (last[0] >= 700) {
//						//		last[0] = 0;
//						//	}
//						//	line[0].position = sf::Vector2f(last[0], last[1]);
//						//	line[1].position = sf::Vector2f(last[0]+5, abs(ans-(f+u)));*/
//
//						if (gui.render())
//							return 0;
//
//						//gui.check_close();
//						if (i >= 0) {
//							if (ol.process(ans) == j + y) {
//								abvgd++;
//								//cout << abvgd << endl;
//							}
//							if (fd % 250 == 0) {
//								cout << abvgd;
//								abvgd = 0;
//								cout << endl << ' ' << endl;
//							}
//							fd++;
//							/*abvgd += abs(j + y - ol.process(ans));
//							if (fd % 2000 == 0) {
//								cout << abvgd/5000. <<endl;
//								abvgd = 0;
//							}*/
//						}
//						//cout << ans << "    	" << j + y << endl;
//						/*if (i == 1) {
//							cout << ans << "	" << j + y << endl;
//							for (int o = 0; o < l.process(in).size(); o++) {
//								cout << l.process(in)[o];
//							}
//							cout << endl << l.process(in)[ans] << endl;
//						}
//						if (y == 0) {
//							cout <<endl<<endl<< j<<endl<<endl;
//						}*/
//						/*else {
//							cout << "wrong"<<endl;
//						}*/
//						/*vector <double> s = ol.correct(j + y);
//						for (int z = 0; z < s.size(); z++) {
//							cout << s[z];
//						}
//						cout <<endl<< s.size()<<endl;*/
//						l.correct(ol.correct(j + y));
//						//Sleep(1);
//					}
//				}
//			}
//		}
//		//cout << "--------------------------------------------ALL------------------------------------------" << "==========================================" << endl;
//	}
//	/*for (int i = 0; i < ol.correct(250).size(); i++) {
//		cout << ol.correct(250)[i] << endl;
//	}*/
//	/*Layer l(1, 2);
//	OutputLayer ol(2);
//	Norm n(500);
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; j < 4; j++) {
//			l.process(samples[j);
//			cout << l.process(n.norm(samples[j]))[0] << "		" << ans[j] << endl;
//			l.correct(ans[j]);
//		}
//	}*/
//	return 0;
//}


//3x3

//int main() {
//	vector<vector<double>> test = { {1, 1, 1, 0, 0, 0, 0, 0, 0},{0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 0, 0, 1, 1, 1},{1, 0, 0, 1, 0, 0, 1, 0, 0},{0, 1, 0, 0, 1, 0, 0, 1, 0},{0, 0, 1, 0, 0, 1, 0, 0, 1},{1, 1, 1, 1, 0, 0, 1, 0, 0},{1, 1, 1, 0, 1, 0, 0, 1, 0},{1, 1, 1, 0, 0, 1, 0, 0, 1},{1, 0, 0, 1, 1, 1, 1, 0, 0},{0, 1, 0, 1, 1, 1, 0, 1, 0},{0, 0, 1, 1, 1, 1, 0, 0, 1},{1, 0, 0, 1, 0, 0, 1, 1, 1},{0, 1, 0, 0, 1, 0, 1, 1, 1},{0, 0, 1, 0, 0, 1, 1, 1, 1},{0, 0, 0, 0, 0, 0, 0, 0, 0} };
//	vector<vector<double>> right = {{0.8, 0.2}, {0.8, 0.2}, {0.8, 0.2}, {0.2, 0.8}, {0.2, 0.8}, {0.2, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.8, 0.8}, {0.2, 0.2}};
//	Gui gui(800, 600, "name");
//	Layer lay(2,9,0.3);
//	Norm n(1);
//	while(gui.isOpen()) {
//		for (int j = 0; j < right.size(); j++) {
//			vector<double> ans = lay.process(n.norm(test[j]));
//			vector<double> weights = lay.w_of_perc(0,0);
//			//cout << weights.size() << endl;
//			gui.matrix_from_double_vec(weights,3,3);
//			gui.check_close();
//			/*if (right[j][0] < 0.5 && ans[0] <= right[j][0]) {
//				cout << "1";
//			}
//			else if (right[j][0] > 0.5 && ans[0] >= right[j][0]) {
//				cout << "1";
//			}
//
//			if (right[j][1] < 0.5 && ans[1] <= right[j][1]) {
//				cout<<"		 " << "1";
//			}
//			else if (right[j][1] > 0.5 && ans[1] >= right[j][1]) {
//				cout << "		" << "1";
//			}
//			cout << endl;*/
//			lay.correct(right[j]);
//			Sleep(0.1);
//		}
//	}
//
//	return 0;
//}

//TESTS

//test layer && perceptron | + network

//int main() {
//	vector <vector<double>> samples = { {0.0, 0.0},{1, 0.0},{0.0, 1},{1, 1} };
//	vector <double> ans = { 0.0, 1, 1, 1 };
//
//	vector<Network::LayerType> arg = { Network::LayerType::NORM, Network::LayerType::PERC };
//	Network net(arg,2,1,1);
//	//Layer l(1, 2, 1);
//	for (int i = 0; i < 1000; i++) {
//		for (int j = 0; j < 4; j++) {
//			cout << net.process(samples[j]);
//			net.correct(ans[j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}
//+

//test norm layer

//int main() {
//	Norm n(250);
//	vector <double> a(0);
//	//srand(time(0));
//	for (int i = 0; i < 250; i++) {
//		a.push_back(i);
//	}
//	a = n.norm(a);
//	for (int i = 0; i < 250; i++) {
//		cout << a[i] << endl;
//	}
//	return 0;
//}
//+

//test output layer

//int main() {
//	OutputLayer ol(500);
//	vector <double> var(500);
//	for (int i = 1; i <= 500; i++) {
//		var = ol.correct(i);
//		cout << ol.process(var)<<"    "<<i << endl;
//		/*if (ol.process(var) != i) {
//			cout << "NOOOOOOO..."<<endl;
//		}*/
//		
//	}
//	return 0;
//}
//+

//test GUI render && graphik(double vector)

//int main() {
//	Gui gui(1090, 600, "name");
//	OutputLayer ol(500);
//
//	vector<double> temp = {0.5, 0.55, 0.57, 0.01, 0, 0.4, 0.3333, 0.9, 0.7, 0.2, 0.23, 0.452};
//	cout << ol.process(temp);
//	while (gui.isOpen()) {
//		
//		gui.graphik(temp);
//		//gui.graphik(temp);
//		if (gui.render())
//			return 0;
//	}
//
//	return 0;
//}
//+//8

//END TESTS

//int main() {
//	OutputLayer ol(2);
//	vector<double> in = ol.correct(1);
//	for (int i = 0; i < in.size(); i++) {
//		cout << in[i] << endl;
//	}
//	return 0;
//}

// test test

//int main() {
//	//OutputLayer ol(500);
//	////ol.process(vector<double>{});
//	//vector<double> n = ol.correct(vector<double>{50});
//	//for (int i = 0; i < n.size(); i++) {
//	//	cout << i << "		" << n[i] << endl;
//	//}
//	Test tes(250, 250, 1);
//	vector<double> n = tes.generate();
//	//cout << n[0] << "		" << n[1] << endl;
//	while (!tes.is_end()) {
//		
//		cout << n[0] << "		" << n[1] << endl;
//		n = tes.generate();
//	}
//	return 0;
//}

int main() {
	//vector<Network::LayerType> arg;
	Network net({ Network::LayerType::NORM, Network::LayerType::PERC, Network::LayerType::OUTPUTLAYER }, 2, 499);
	Test learnTest(249, 249, 10);
	Test testTest(249, 249, 1);
	Gui gui(800, 600, "work, please!");
	bool print = false;
	vector<double> test;
	double ans;
	while (gui.isOpen()) {
		cout << "learn(l) or test(t):";
		string tmp;
		cin >> tmp;
		if (tmp[0] == 'l') {
			learnTest.null_cicle();
			while (!learnTest.is_end()) {
				test = learnTest.generate();
				ans = net.process(test);
				gui.matrix_from_double_vec(net.get_w(1, 0), 20, 25);
				gui.render();
				Gui::EventType n = gui.evnt();
				if (n == Gui::EventType::CLOSE) {
					return 0;
				}
				else if (n == Gui::EventType::PAUSE) {
					cout << "___________PAUSE___________" << endl;
					n = Gui::EventType::NON;
					while (n != Gui::EventType::PAUSE) {
						n = gui.evnt();
						Sleep(1);
					}
					n = Gui::EventType::NON;
					cout << "___________!PAUSE___________" << endl;
				}
				else if (n == Gui::EventType::PRINT) {
					print = !print;
				}
				double res = learnTest.get_generated(1)[0];
				net.correct(res);
				if (print)
					cout << '#' << learnTest.get_cicle() << " fir: " << int(test[0]) << " sec: " << int(test[1]) << " ans: " << int(res) << " res: " << int(ans) << " corr: " << ((ans == res) ? "YES" : "NO ") << endl;
			}
		}
		else if (tmp[0] == 't') {
			testTest.null_cicle();
			while (!testTest.is_end()) {
				test = testTest.generate();
				ans = net.process(test);
				gui.matrix_from_double_vec(net.get_w(1, 0), 20, 25);
				gui.render();
				Gui::EventType n = gui.evnt();
				if (n == Gui::EventType::CLOSE) {
					return 0;
				}
				else if (n == Gui::EventType::PAUSE) {
					cout << "___________PAUSE___________" << endl;
					n = Gui::EventType::NON;
					while (n != Gui::EventType::PAUSE) {
						gui.evnt();
						Sleep(1);
					}
					n = Gui::EventType::NON;
					cout << "___________!PAUSE___________" << endl;
				}
				else if (n == Gui::EventType::PRINT) {
					print = !print;
				}
				double res = testTest.get_generated(1)[0];
				net.correct(res);
				if (print)
					cout << '#' << testTest.get_cicle() << " fir: " << int(test[0]) << " sec: " << int(test[1]) << " ans: " << int(res) << " res: " << int(ans) << " corr: " << ((ans == res) ? "YES" : "NO ") << endl;
				n = Gui::EventType::NON;
			}
		}
		else {
			cout << "try again, please" << endl;
		}
	}
	return 0;
}