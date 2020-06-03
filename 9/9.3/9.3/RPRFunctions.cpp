
#include "ReversePolishRecord.h"

void ReversePolishRecord(string &exp) {
	int l = exp.length();
	bool is_sign = true;
	stack <string> X;
	stack <string> Y;
	
	for (int i = 0; i < l; i++) {
		if ('0' <= exp[i] && exp[i] <= '9' || exp[i] == '-' && is_sign) {
			string numb("");
			if (exp[i] == '-') {
				numb += '-';
				i++;
			}
			while (true) {
				numb += exp[i];
				if (i < l && ('0' <= exp[i + 1] && exp[i + 1] <= '9' || exp[i + 1] == '.'))
					i++;
				else
					break;
			}
			X.push(numb);
			is_sign = false;
		}
		else if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-' || exp[i] == '(' || exp[i] == ')') {
			string sign("");
			sign += exp[i];
			switch (exp[i])
			{
			case '*':
			case '/':
			case '(':
			{
				Y.push(sign);
				break;
			}
			case '+':
			case '-':
			{
				if (!Y.empty() && (Y.top() == "*" || Y.top() == "/"))
					while (!Y.empty() && Y.top() != "(") {
						X.push(Y.top());
						Y.pop();
					}
				Y.push(sign);
				break;
			}
			case ')':
			{
				while (Y.top() != "(") {
					X.push(Y.top());
					Y.pop();
				}
				Y.pop();
				break;
			}
			}
			is_sign = true;
		}
		if (i >= l - 1)
			while (!Y.empty()) {
				X.push(Y.top());
				Y.pop();
			}
	}
	
	
	list <string> expPol;
	while (!X.empty()) {
		expPol.push_front(X.top());
		X.pop();
	}
	
	list<string>::iterator p = expPol.begin();
	double d1, d2;
	while (true) {
		if (*p == "+" || *p == "-" || *p == "*" || *p == "/") {
			p--;
			p--;
			d1 = ToDouble(*p);
			p = expPol.erase(p);
			d2 = ToDouble(*p);
			p = expPol.erase(p);

			if (*p == "+")
				d1 += d2;
			else if (*p == "-")
				d1 -= d2;
			else if (*p == "*")
				d1 *= d2;
			else if (*p == "/")
				d1 /= d2;

			*p = ToString(d1);
		}
		p++;
		if (p == expPol.end())
			break;
	}
	p--;
	exp = *p;
}

double ToDouble(string &s) {
	double d = 0;
	bool dot = false;
	bool neg = false;
	double mult = 0.1;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		if (s[i] == '-')
			neg = true;
		else if (s[i] == '.')
			dot = true;
		else if (dot) {
			d = d + int(s[i] - '0') * mult;
			mult *= 0.1;
		}
		else
			d = d * 10 + int(s[i] - '0');
	}
	if (neg)
		d *= -1;
	return d;
}

string ToString(double d) {
	string s("");

	if (d < 0) {
		s += '-';
		d *= -1;
	}

	int n = d + E * 0.1;
	d -= n;
	string real("");
	if (!n)
		real += '0';
	while (n) {
		real += char(n % 10 + '0');
		n /= 10;
	}
	reverse(real.begin(), real.end());
	s += real;

	string mant("");
	if (d >= E) {
		s += '.';
		n = d * 1000000;
		bool is_null = true;
		for (int i = 0; i < 6; i++) {
			if (n % 10 != 0)
				is_null = false;
			if (!is_null)
				mant = char(n % 10 + '0') + mant;
			n /= 10;
		}
	}
	s += mant;
	return s;
}
