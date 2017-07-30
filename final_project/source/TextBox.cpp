#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox(int width) {
	_width = width;
	_height = 2;
	_top = 0;
	_left = 0;
}


void TextBox::mousePressed(int x, int y, bool isLeft) {

}
void TextBox::keyDown(int keyCode, char charecter) {

}

bool TextBox::canGetFocus() {
	return true;
}

void TextBox::draw(Graphics& g, int x, int y, size_t layer)const {
	if (layer == getLayer()) {
		Control::draw(g, x , y , layer);
		g.write(x+getLeft()+1, getTop() + y+1,_text + wstring(getWidth() - _text.size(), ' '));
	}
	else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		//g.moveTo(getLeft() + x + _cursorPosition, getTop() + y);
		g.moveTo(getLeft() + x , getTop() + y);	

	}

}