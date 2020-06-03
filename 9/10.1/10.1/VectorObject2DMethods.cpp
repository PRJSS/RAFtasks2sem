
#include "Hierarchy.h"
#include "VectorObject2D.h"

VectorObject2D::VectorObject2D() {
	object = vector2D;
	max_size = 10;
	vector = new Object2D*[max_size];
	for (int i = 0; i < max_size; i++)
		vector[i] = NULL;
	size = 0;
	saving_file = "";
}

VectorObject2D::VectorObject2D(const string &name) {
	object = vector2D;

	saving_file = name;
	ifstream fin(name);
	if (fin) {
		string type;
		fin >> type;
		if (!fin.eof()) {
			fin >> size >> max_size;

			vector = new Object2D*[max_size];

			string t, c;
			int tops;
			double x, y, w, h;
			float fs;
			for (int i = 0; i < size; i++) {
				fin >> type;
				if (type == "rectangle") {
					fin >> x >> y >> w >> h >> c;
					vector[i] = new Rectangle(x, y, w, h, c);
				}
				else if (type == "ellipse") {
					fin >> x >> y >> w >> h >> c;
					vector[i] = new Ellipse(x, y, w, h, c);
				}
				else if (type == "star") {
					fin >> x >> y >> w >> h >> c >> tops;
					vector[i] = new Star(x, y, w, h, c, tops);
				}
				else if (type == "polygon") {
					fin >> x >> y >> w >> h >> c >> tops;
					vector[i] = new Polygon(x, y, w, h, c, tops);
				}
				else if (type == "text") {
					fin >> x >> y >> fs >> t >> c;
					vector[i] = new Text(x, y, fs, t, c);
				}
			}
		}
		else {
			max_size = 10;
			vector = new Object2D*[max_size];
			for (int i = 0; i < max_size; i++)
				vector[i] = NULL;
			size = 0;
		}
	}
	else {
		max_size = 10;
		vector = new Object2D*[max_size];
		for (int i = 0; i < max_size; i++)
			vector[i] = NULL;
		size = 0;
	}
}

VectorObject2D::VectorObject2D(const VectorObject2D &v) {
	object = vector2D;
	max_size = v.max_size;
	vector = new Object2D*[max_size];
	for (int i = 0; i < max_size; i++) {
		if (v.vector[i] == NULL) {
			vector[i] = NULL;
			continue;
		}
		switch (v.vector[i]->GetObjectType()) {
		case rectangle2D: {
			vector[i] = new Rectangle(*dynamic_cast<Rectangle*>(v.vector[i]));
			break;
		}
		case ellipse2D: {
			vector[i] = new Ellipse(*dynamic_cast<Ellipse*>(v.vector[i]));
			break;
		}
		case star2D: {
			vector[i] = new Star(*dynamic_cast<Star*>(v.vector[i]));
			break;
		}
		case polygon2D: {
			vector[i] = new Polygon(*dynamic_cast<Polygon*>(v.vector[i]));
			break;
		}
		case text2D: {
			vector[i] = new Text(*dynamic_cast<Text*>(v.vector[i]));
			break;
		}
		}
	}
	size = v.size;

	saving_file = "";
}

VectorObject2D::VectorObject2D(VectorObject2D&& v) {
	object = vector2D;
	max_size = v.max_size;
	v.max_size = 0;

	vector = v.vector;
	v.vector = nullptr;

	size = v.size;
	v.size = 0;

	saving_file = "";
}

VectorObject2D::~VectorObject2D() {
	if (saving_file != "" && vector != nullptr) {
		ofstream fout(saving_file);
		if (fout)
			GetInformation(fout);
	}
	Delete();
	delete vector;
}

void VectorObject2D::SetSavingFile(const string &name) {
	saving_file = name;
}

void VectorObject2D::Add(const Rectangle &r) {
	vector[size] = new Rectangle(r);
	size++;
	if (size >= max_size)
		NewVectorSize(2 * max_size);
}

void VectorObject2D::Add(const Ellipse &e) {
	vector[size] = new Ellipse(e);
	size++;
	if (size >= max_size)
		NewVectorSize(2 * max_size);
}

void VectorObject2D::Add(const Star &s) {
	vector[size] = new Star(s);
	size++;
	if (size >= max_size)
		NewVectorSize(2 * max_size);
}

void VectorObject2D::Add(const Polygon &p) {
	vector[size] = new Polygon(p);
	size++;
	if (size >= max_size)
		NewVectorSize(2 * max_size);
}

void VectorObject2D::Add(const Text &t) {
	vector[size] = new Text(t);
	size++;
	if (size >= max_size)
		NewVectorSize(2 * max_size);
}

void VectorObject2D::NewVectorSize(const int new_size) {
	Object2D** new_v = new  Object2D*[new_size];
	for (int i = 0; i < new_size; i++)
		if (i < max_size)
			new_v[i] = vector[i];
		else
			new_v[i] = NULL;
	delete vector;
	vector = new_v;
	max_size = new_size;
}

void VectorObject2D::Delete() {
	for (int i = 0; i < size; i++) {
		if (vector[i] != NULL)
			switch (vector[i]->GetObjectType()) {
			case rectangle2D: {
				delete dynamic_cast<Rectangle*>(vector[i]);
				break;
			}
			case ellipse2D: {
				delete dynamic_cast<Ellipse*>(vector[i]);
				break;
			}
			case star2D: {
				delete dynamic_cast<Star*>(vector[i]);
				break;
			}
			case polygon2D: {
				delete dynamic_cast<Polygon*>(vector[i]);
				break;
			}
			case text2D: {
				delete dynamic_cast<Text*>(vector[i]);
				break;
			}
			}
		vector[i] = NULL;
	}
	size = 0;
}

void VectorObject2D::DeleteObject(const int n) {
	if (n >= size || n < 0)
		return;

	switch (vector[n]->GetObjectType()) {
	case rectangle2D: {
		delete dynamic_cast<Rectangle*>(vector[n]);
		break;
	}
	case ellipse2D: {
		delete dynamic_cast<Ellipse*>(vector[n]);
		break;
	}
	case star2D: {
		delete dynamic_cast<Star*>(vector[n]);
		break;
	}
	case polygon2D: {
		delete dynamic_cast<Polygon*>(vector[n]);
		break;
	}
	case text2D: {
		delete dynamic_cast<Text*>(vector[n]);
		break;
	}
	}
	for (int i = n; i < size; i++)
		vector[i] = vector[i + 1];
	size--;
	vector[size] = NULL;
}

VectorObject2D& VectorObject2D::operator =(const VectorObject2D &v) {
	if (&v == this)
		return *this;

	Delete();
	delete vector;

	max_size = v.max_size;
	vector = new Object2D*[max_size];
	for (int i = 0; i < max_size; i++) {
		if (v.vector[i] == NULL) {
			vector[i] = NULL;
			continue;
		}
		switch (v.vector[i]->GetObjectType()) {
		case rectangle2D: {
			vector[i] = new Rectangle(*dynamic_cast<Rectangle*>(v.vector[i]));
			break;
		}
		case ellipse2D: {
			vector[i] = new Ellipse(*dynamic_cast<Ellipse*>(v.vector[i]));
			break;
		}
		case star2D: {
			vector[i] = new Star(*dynamic_cast<Star*>(v.vector[i]));
			break;
		}
		case polygon2D: {
			vector[i] = new Polygon(*dynamic_cast<Polygon*>(v.vector[i]));
			break;
		}
		case text2D: {
			vector[i] = new Text(*dynamic_cast<Text*>(v.vector[i]));
			break;
		}
		}
	}
	size = v.size;

	return *this;
}

VectorObject2D& VectorObject2D::operator =(VectorObject2D&& v) {
	if (&v == this)
		return *this;

	Delete();
	delete vector;

	max_size = v.max_size;
	v.max_size = 0;

	vector = v.vector;
	v.vector = nullptr;

	size = v.size;
	v.size = 0;

	return *this;
}
