#pragma once

#include <iostream>
#include <string>

using namespace std;

enum ObjectType {
	rectangle2D,
	ellipse2D,
	star2D,
	polygon2D,
	text2D,
	vector2D,
	list2D
};

// I

class Object2D {
protected:
	ObjectType object;

public:
	Object2D() {}
	~Object2D() {}

	virtual void Print(ostream& out = cout) = 0;

	virtual void GetInformation(ostream& out = cout) = 0;

	ObjectType GetObjectType() {
		return object;
	}

	friend ostream& operator << (ostream& out, Object2D& ob) {
		ob.Print(out);
		return out;
	}
};

// II

class Coordinates : virtual public Object2D {
protected:
	double X;
	double Y;

	Coordinates(double x, double y) {
		if (x < 0)
			X = 0;
		else
			X = x;

		if (y < 0)
			Y = 0;
		else
			Y = y;
	}
	~Coordinates() {}

public:
	double GetXcoordinate() {
		return X;
	}

	double GetYcoordinate() {
		return Y;
	}

	void SetCoordinates(double x = 0, double y = 0) {
		if (x < 0)
			X = 0;
		else
			X = x;

		if (y < 0)
			Y = 0;
		else
			Y = y;
	}

	void PrintCoordinates(ostream& out = cout) {
		out << "Coordinates -- (" << X << "; " << Y << "). ";
	}
};

class Color : virtual public Object2D {
protected:
	string color;

	Color(string col) {
		if (col == "")
			col = "black";
		else
			color = col;
	}
	~Color() {}

public:
	string GetColor() {
		return color;
	}

	void SetColor(string col = "black") {
		if (col == "")
			col = "black";
		else
			color = col;
	}

	void PrintColor(ostream& out = cout) {
		out << "Color is " << color << ". ";
	}
};

// III

class FigureSize : public Coordinates, public Color {
protected:
	double width;
	double height;

	FigureSize(double x, double y, double w, double h, string col) : Coordinates(x, y), Color(col) {
		if (w < 0)
			width = 1;
		else
			width = w;

		if (h < 0)
			height = 1;
		else
			height = h;
	}
	~FigureSize() {}

public:
	double GetWidth() {
		return width;
	}

	double GetHeight() {
		return height;
	}

	void SetSize(double w = 1, double h = 1) {
		if (w < 0)
			width = 1;
		else
			width = w;

		if (h < 0)
			height = 1;
		else
			height = h;
	}

	void PrintSize(ostream& out = cout) {
		out << "Width: " << width << ", height: " << height << ". ";
	}
};

class FontSize : public Coordinates, public Color {
protected:
	float fontSize;

	FontSize(double x, double y, float fs, string col) : Coordinates(x, y), Color(col) {
		if (fs < 0)
			fs = 1;
		else
			fontSize = fs;
	}
	~FontSize() {}

public:
	float GetFontSize() {
		return fontSize;
	}

	void SetFontSize(float fs = 1) {
		if (fs < 0)
			fs = 1;
		else
			fontSize = fs;
	}

	void PrintFontSize(ostream& out = cout) {
		out << "Font size: " << fontSize << ". ";
	}
};

// IV

class Tops : public FigureSize {
protected:
	int number_of_tops;

	Tops(double x, double y, double xs, double ys, string col, int nt) : FigureSize(x, y, xs, ys, col) {
		if (nt < 3)
			nt = 3;
		else
			number_of_tops = nt;
	}
	~Tops() {}

public:
	int GetNumberOfTops() {
		return number_of_tops;
	}

	void SetNumberOfTops(int nt = 3) {
		if (nt < 3)
			nt = 3;
		else
			number_of_tops = nt;
	}

	void PrintNumberOfTops(ostream& out = cout) {
		out << "Number of tops: " << number_of_tops << ". ";
	}
};

// V

//1
class Rectangle : public FigureSize {
public:
	Rectangle(double x_coordinat, double y_coordinat, double wdth, double hght, string colr) : FigureSize(x_coordinat, y_coordinat, wdth, hght, colr) {
		object = rectangle2D;
	}
	~Rectangle() {}

	void Print(ostream& out = cout) {
		out << "Rectangle --> ";
		PrintCoordinates(out);
		PrintSize(out);
		PrintColor(out);
		out << '\n';
	}

	void GetInformation(ostream& out = cout) {
		out << "rectangle " << X << ' ' << Y << ' ' << width << ' ' << height << ' ' << color << '\n';
	}
};

//2
class Ellipse : public FigureSize {
public:
	Ellipse(double x_coordinat, double y_coordinat, double wdth, double hght, string colr) : FigureSize(x_coordinat, y_coordinat, wdth, hght, colr) {
		object = ellipse2D;
	}
	~Ellipse() {}

	void Print(ostream& out = cout) {
		out << "Ellipse --> ";
		PrintCoordinates(out);
		PrintSize(out);
		PrintColor(out);
		out << '\n';
	}

	void GetInformation(ostream& out = cout) {
		out << "ellipse " << X << ' ' << Y << ' ' << width << ' ' << height << ' ' << color << '\n';
	}
};

//3
class Star : public Tops {
public:
	Star(double x_coordinat, double y_coordinat, double wdth, double hght, string colr, int tops_number) : Tops(x_coordinat, y_coordinat, wdth, hght, colr, tops_number) {
		object = star2D;
	}
	~Star() {}

	void Print(ostream& out = cout) {
		out << "Star --> ";
		PrintCoordinates(out);
		PrintSize(out);
		PrintColor(out);
		PrintNumberOfTops(out);
		out << '\n';
	}

	void GetInformation(ostream& out = cout) {
		out << "star " << X << ' ' << Y << ' ' << width << ' ' << height << ' ' << color << ' ' << number_of_tops << '\n';
	}
};

//4
class Polygon : public Tops {
public:
	Polygon(double x_coordinat, double y_coordinat, double wdth, double hght, string colr, int tops_number) : Tops(x_coordinat, y_coordinat, wdth, hght, colr, tops_number) {
		object = polygon2D;
	}
	~Polygon() {}

	void Print(ostream& out = cout) {
		out << "Polygon --> ";
		PrintCoordinates(out);
		PrintSize(out);
		PrintColor(out);
		PrintNumberOfTops(out);
		out << '\n';
	}

	void GetInformation(ostream& out = cout) {
		out << "polygon " << X << ' ' << Y << ' ' << width << ' ' << height << ' ' << color << ' ' << number_of_tops << '\n';
	}
};

//5
class Text : public FontSize {
protected:
	string text;
public:
	Text(double x_coordinat, double y_coordinat, float font_size, string txt, string colr) : FontSize(x_coordinat, y_coordinat, font_size, colr) {
		object = text2D;
		if (txt == "")
			text = "Text";
		else
			text = txt;
	}
	~Text() {}

	string GetText() {
		return text;
	}

	void SetText(string txt = "Text") {
		if (txt == "")
			text = "Text";
		else
			text = txt;
	}

	void Print(ostream& out = cout) {
		out << "Text: " << text << " --> ";
		PrintCoordinates(out);
		PrintFontSize(out);
		PrintColor(out);
		out << '\n';
	}

	void GetInformation(ostream& out = cout) {
		out << "text " << X << ' ' << Y << ' ' << fontSize << ' ' << text << ' ' << color << '\n';
	}
};

