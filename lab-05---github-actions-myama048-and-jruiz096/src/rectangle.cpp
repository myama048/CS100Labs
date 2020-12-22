#include "../header/rectangle.hpp"

Rectangle::Rectangle(int w, int h){
	set_width(w);
	set_height(h);
}

int Rectangle::get_width(){
	return -1;
}
int Rectangle::get_height(){
	return -1;
}

void Rectangle::set_width(int w){
	this->width = -1;
}

void Rectangle::set_height(int h){
	this->height = -1;
}

int Rectangle::area(){
	return -1;
}

int Rectangle::perimeter(){
	return -1;
}

